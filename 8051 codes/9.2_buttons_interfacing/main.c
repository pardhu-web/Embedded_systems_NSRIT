#include<reg51.h>

sbit b1 = P2^0;
sbit b2 = P2^1;

#define output P1
unsigned int i=0;
void main()
{
	output = 0;
	while(1)
	{
		if(b1 == 0)
		{
		while(b1 == 0);
		i++;
		}
		if(b2 == 0)
		{
		while(b2 == 0);
		 i--;
		}
		output = i;
	}
}