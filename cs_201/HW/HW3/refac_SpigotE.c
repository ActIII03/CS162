#include <stdio.h>

void SpigotE(unsigned char* output, unsigned long* workbuffer, unsigned long n)
{
	long i, j;
	unsigned char q;
	unsigned long temp;

	output[0] = 2;
    i = n + 1;
	while(i >= 0)
	{
		workbuffer[i] = 1;
        i--;
	}

    j = 1;
	while(j < n)
	{
		q = 0;
        i = n + 1;
		while(i >= 0)
		{
			temp = 10 * workbuffer[i] + q;
			q = temp / (i + 2);
			workbuffer[i] = temp % (i + 2);
            i--;
		}

		output[j] = q;
        j++;
	}
	
	return;
}
