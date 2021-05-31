int main(void)
{
	int inpt[8] = {0x00, 0x01, 0x00, 0xFF, 0x00, 0x01, 0x00, 0xFF};
	int otpt[8];
	volatile unsigned int *debugLEDs = (unsigned int *)0x2000;

	otpt[0] = - inpt[0];
	otpt[1] = - inpt[1] + 3 * inpt[0];
	for (int i = 2; i < 8; i++)
		otpt[i] = - inpt[i] + 3 * inpt[i-1] - inpt[i-2];
	while(1)
	{
		for (int i = 0; i < 8; i++)
		{
			*debugLEDs = otpt[i];
			for (int j = 1; j < 40000; j++)
				;
		}
	}
}
