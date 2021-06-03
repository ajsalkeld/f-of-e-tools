#include "autocorrelation.h"
#include "autocorrelation_data.h"

int main(void)
{

    int autocorrelation[50];
    //set debugPin to be low
    unsigned char out = 0x00;
    *debugPin = out;

    while (1) {
        for (int k = 0; k < data_len; k++)
        {
            int sum = 0;
            //Find the sum over where they both have a value
            for (int n = 0; n < data_len - k; n++)
            {
                sum += data[n] * data[n+k];
            }
            autocorrelation[k] = sum/(data_len-k);
        }

        //toggle output pin
        out = ~out;
        *debugPin = out;
    }

    return 0;
}
