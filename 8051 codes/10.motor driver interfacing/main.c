#include<reg51.h>
sbit b1 = P1^0;
sbit b2 = P1^1;

int val = 1;
int val2 = 128;
void delay(int time)
{
	unsigned int i,j;
	for(i=0;i<=time;i++)
	{
		for(j=0;j<=1000;j++);
	}
}

void main()
{
 while(1)
 {
 while(b1 == 0)
 {
  P2 = val;
  delay(50);
  val <<= 1;
 }

  while(b2 == 0)
 {
   P2 = val2;
  delay(50);
  val >>= 1;
 }
 }
	
}
