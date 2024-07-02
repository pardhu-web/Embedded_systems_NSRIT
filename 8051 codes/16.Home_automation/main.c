#include<reg51.h> //header file
#include<stdio.h> // sprint

#define lcd P2   //lcd data pins
sbit en = P3^1;	 //Enable
sbit rs = P3^0;	 //Register select

sbit ldr = P1^0;
sbit temp = P1^1;

sbit light = P3^2;

sbit in1 = P3^3;
sbit in2 = P3^4;


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

int ldr_data;
int temp_data;

void main()  //main programs
{
	lcd_cmd(0x38); //select 8bit 2lines
	lcd_cmd(0x01); //clear display
	lcd_cmd(0x0E); //display on coursor blink
	lcd_cmd(0x06); //Increment from leftg to right
 
	lcd_cmd(0x80); lcd_print("   WELCOME   ");
	lcd_cmd(0xc0); lcd_print("Home Automation"); delay(500);
   
	while(1)
	{
	  lcd_cmd(0x01);
	  lcd_cmd(0x80); lcd_print("LDR:");
      lcd_cmd(0x8A); lcd_print("Temp:"); 
	  lcd_cmd(0xC0); lcd_print("L:");
      lcd_cmd(0xCA); lcd_print("F:");

	  ldr_data = ldr;
	  temp_data = temp;
	  lcd_cmd(0x84); int_lcd(ldr_data);
	  lcd_cmd(0x8f); int_lcd(temp_data);
	  if(ldr_data == 0)
	  {
	  lcd_cmd(0xc2);
	  lcd_print("ON ");
	  light = 1;
	  }
	  else
	  {
	   lcd_cmd(0xc2);
	  lcd_print("OFF");
	  light = 0;
	  }

	  if(temp_data == 0)
	  {
	  lcd_cmd(0xcc);
	  lcd_print("ON ");
	  in1=1;
	  in2=0;
	  }
	  else
	  {
	   lcd_cmd(0xcc);
	  lcd_print("OFF");
	  in1=0;
	  in2=0;
	  }
	  
	  delay(100);
	}		
} 