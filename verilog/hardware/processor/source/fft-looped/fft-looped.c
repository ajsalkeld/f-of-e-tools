//#include <stdio.h>
#include <math.h>
#include <complex.h>
 
double PI;
typedef double complex cplx;

void _fft(cplx buf[], cplx out[], int n, int step)
{
	if (step < n) {
		_fft(out, buf, n, step * 2);
		_fft(out + step, buf + step, n, step * 2);
 
		for (int i = 0; i < n; i += 2 * step) {
			//cplx t = cexp(-I * PI * i / n) * out[i + step];
			cplx t = (cos(-PI * i / n) + I * sin(-PI * i / n) ) * out[i + step];
			buf[i / 2]     = out[i] + t;
			buf[(i + n)/2] = out[i] - t;
		}
	}
}
 
void fft(cplx buf[], int n)
{
	cplx out[n];
	for (int i = 0; i < n; i++) out[i] = buf[i];
 
	_fft(buf, out, n, 1);
}
 
int main()
{
	volatile unsigned int *debugPin = (unsigned int *)0x2000;
	unsigned char output = 0xFF;
	*debugPin = output;

	while (1) {
		PI = atan2(1, 1) * 4;
		cplx buf[] = {1, 1, 1, 1, 0, 0, 0, 0};
	 
		fft(buf, 8);
		output = ~output;
		*debugPin = output;
 	}
	return 0;
}
