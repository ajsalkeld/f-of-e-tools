#include "autocorrelation.h"
#include "autocorrelation_data.h"

int main(void)
{

    int autocorrelation[50];
    //set debugPin to be low
    *debugPin = 0x00;
    
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

    //set debugPin to be high to signify end of program
    *debugPin = 0xFF;

    return 0;
}
