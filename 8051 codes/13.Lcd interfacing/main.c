#include<reg51.h> //header file

#define lcd P2   //lcd data pins
sbit en = P3^0;	 //Enable
sbit rs = P3^1;	 //Register select


void delay(unsigned int time)	  //delay function
{
	unsigned int i,j;
	for(i=0;i<=time;i++)
	{
		for(j=0;j<=1000;j++);
	}

}

void lcd_cmd(unsigned char ch)	 //command function
{
  lcd = ch;
  rs=0;
  en=1;
  delay(2);
  en=0;
}

void lcd_data(unsigned char ch)	 //data function
{
  lcd = ch;
  rs=1;
  en=1;
  delay(2);
  en=0;
}




void main()  //main programs
{
	lcd_cmd(0x38); //select 8bit 2lines
	lcd_cmd(0x01); //clear display
	lcd_cmd(0x0E); //display on coursor blink
	lcd_cmd(0x06); //Increment from leftg to right
    while(1)
	{
	lcd_cmd(0x80);	//Select position
	lcd_data('H');  	delay(200);
	lcd_data('E'); 	delay(200);
	lcd_data('L'); 	delay(200);
	lcd_data('L');		delay(200);
	lcd_data('O');		delay(200);
	delay(200);
	}
	
		
} 