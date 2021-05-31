#include "autocorrelation_data.h"
#include <printf.h> //For sunflower simulation

int main(void)
{

    float autocorrelation[1];

    printf_("[");

    for (int k = 0; k < K; k++)
    {
        //Find the sum over where they both have a value
        float sum = 0;
        for (int n = 0; n < data_len - k; n++)
        {
            sum += data[n] * data[n+k];
        }
        autocorrelation[k] = sum/(data_len-k);
        //print output as we go, can't do what they did in bubblesort because
        //it won't allow for formatting
        printf_("%s, ", autocorrelation[k]);
    }

    printf_("]\n")

    return 0;
}