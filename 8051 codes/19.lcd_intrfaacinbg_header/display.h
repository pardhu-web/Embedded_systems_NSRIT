
#include<stdio.h> // sprint

#define lcd P2   //lcd data pins
sbit en = P3^1;	 //Enable
sbit rs = P3^0;	 //Register select

void delay(unsigned int time);
void lcd_cmd(unsigned char ch);
void lcd_data(unsigned char ch);
void lcd_print(char str[]);
void int_lcd(int num);
void float_lcd(float num);






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

void lcd_print(char str[])
{
	unsigned int k=0;
	for(k=0;str[k]!='\0';k++)
	{
	  lcd_data(str[k]);
	}	
}

void int_lcd(int num)
{
   char buffer[16];
   sprintf(buffer,"%d",num);  
   lcd_print(buffer);
}

void float_lcd(float num)
{
   char buffer[16];
   sprintf(buffer,"%.2f",num);  
   lcd_print(buffer);
}


