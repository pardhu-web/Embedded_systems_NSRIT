#include<reg51.h>
#include"display.h"

#define adc_data P3
sbit rd = P1^0;
sbit wr = P1^1;
sbit Int = P1^2;

int sensor_data=0;

void read_adc();
void main()
{
 lcd_cmd(0x38);
 lcd_cmd(0x01);
 lcd_cmd(0x0E);
 lcd_cmd(0x06);
 while(1)
 {
 read_adc();
 lcd_cmd(0x01);
 lcd_cmd(0x80);
 lcd_print("S_data:");
 int_lcd(sensor_data);
 
 if(sensor_data>100)
 {
 lcd_cmd(0xc0);
 lcd_print("Sensor detected    ");
 }
 else
 {
   lcd_cmd(0xc0);
   lcd_print("Sensor Not detected");
 }
 delay(200);
 }

}

void read_adc()
{
 wr = 0;
 rd = 1;
 wr = 1;
 while(Int == 1);
 rd = 0;
 sensor_data = adc_data; 
}