#include "autocorrelation_data.h"
#include <stdio.h>

int main(void)
{

    int autocorrelation[50];

    printf("[");

    for (int k = 0; k < data_len; k++)
    {
        //Find the sum over where they both have a value
        int sum = 0;
        for (int n = 0; n < data_len - k; n++)
        {
            sum += data[n] * data[n+k];
        }
        autocorrelation[k] = sum/(data_len-k);
        //print output as we go, can't do what they did in bubblesort because
        //it won't allow for formatting
        printf("%d, ", autocorrelation[k]);
    }

    printf("]\n");

    return 0;
}
