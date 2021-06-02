#include "autocorrelation_data.h"


int main(void)
{

    float autocorrelation[50];

    for (int k = 0; k < data_len; k++)
    {
        //Find the sum over where they both have a value
        float sum = 0;
        for (int n = 0; n < data_len - k; n++)
        {
            sum += data[n] * data[n+k];
        }
        autocorrelation[k] = sum/(data_len-k);
	}	

    return 0;
}
