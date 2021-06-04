//#include <stdio.h>
#define PI 3

int cos(int x) {
	return 1-x*x/2 + x*x*x*x/24;
}

int sin(int x) {
	return x - x*x*x/6 + x*x*x*x*x / 120;
}

void _fft(int buf_r[], int buf_i[], int out_r[], int out_i[], int n, int step)
{
	if (step < n) {
	  _fft(out_r, out_i, buf_r, buf_i, n, step * 2);
	  _fft(out_r + step, out_i + step, buf_r + step, buf_i + step, n, step * 2);
 
		for (int i = 0; i < n; i += 2 * step) {
			int real = cos(-PI * i / n) * out_r[i + step];
			int imag = sin(-PI * i / n) * out_i[i + step];

			buf_r[i / 2]     = out_r[i] + real;
			buf_r[(i + n)/2] = out_r[i] - real;

			buf_i[i / 2]     = out_i[i] + imag;
			buf_i[(i + n)/2] = out_i[i] - imag;
		}
	}
}

void fft(int buf_r[], int buf_i[], int n)
{
	int out_i[n];
	int out_r[n];
	for (int i = 0; i < n; i++) out_r[i] = buf_r[i];
	for (int i = 0; i < n; i++) out_i[i] = buf_i[i];
 
	_fft(buf_r, buf_i, out_r, out_i, n, 1);
}
/*
void show(const char * s, int buf_r[], int buf_i[]) {
	printf("%s", s);
	for (int i = 0; i < 8; i++)
		    printf("(%i, %i) ", buf_r[i], buf_i[i]);
		    }*/
 
int main()
{
  //volatile unsigned int *debugPin = (unsigned int *)0x2000;
  int placeholder;
  int *debugPin = &placeholder;
  unsigned char output = 0xFF;
  *debugPin = output;

  while (1) {
    int buf_r[] = {1, 1, 1, 1, 0, 0, 0, 0};
    int buf_i[] = {0, 0, 0, 0, 0, 0, 0, 0};
    fft(buf_r, buf_i, 8);
    //show("\n\nFFT : ", buf_r, buf_i);
    if (output==0xFF) output = 0x00;
    else output = 0xFF;
    *debugPin = output;
    }
  return 0;
}
