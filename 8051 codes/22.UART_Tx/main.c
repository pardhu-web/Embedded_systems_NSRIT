#include<reg51.h>
sbit light = P1^0;
sbit fan = P1^1;

void delay(int  time);

void serial_begin()
{
  TMOD = 0x20;
  TH1= 0xFD;
  SCON = 0X50;
  TR1=1;
}

void UART_send(unsigned char str[])
{
 unsigned int i=0;
 for(i=0;str[i]!='\0';i++)
 {
  SBUF = str[i];
  while(TI==0);
  TI=0;
 }
}
unsigned char Data;
void main()
{
  serial_begin();
  light = 0;
  while(1)
  {
	  while(RI == 0);
	  RI=0;
	  Data = SBUF;
	  if(Data == 'L')
	  {
	  light = 1;
	  UART_send("Light ON\r\n");
	  }
	    if(Data == 'S')
	  {
	  light = 0;
	  UART_send("Light OFF\r\n");
	  }
  }
  
}


void delay(int  time)
{
 unsigned int x,y;
 for(x=0;x<=time;x++)
 {
 	for(y=0;y<=1000;y++);
 }
}