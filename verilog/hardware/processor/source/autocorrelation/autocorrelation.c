#include "autocorrelation_data.h"

int main(void)
{

    float autocorrelation[1];

    for (int k = 0; k < K; k++)
    {
        float sum = 0;
        for (int n = 0; n < N; n++)
        {
            sum += data[n] * data[n+k];
        }
        autocorrelation[k] = sum/N;
    }

    for (int i = 0; i < K; i++)

    return 0;
}