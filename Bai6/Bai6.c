/*
 * Bai6.c
 *
 * Created: 10/30/2020 9:21:16 AM
 * Author: Dell
 * Viet chuong trinh hien thi hello world len glcd
 */

#include <io.h>
#include <glcd.h>
#include <delay.h>
#include <font5x7.h>
#include <stdio.h>
#define LEG_G PORTD.5

unsigned int gia_tri_adc, i;
unsigned char buffer[10];

#define ADC_VREF_TYPE ((0<<REFS1) | (0<<REFS0) | (0<<ADLAR))

// Read the AD conversion result
unsigned int read_adc(unsigned char adc_input)
{
ADMUX=adc_input | ADC_VREF_TYPE;
// Delay needed for the stabilization of the ADC input voltage
delay_us(10);
// Start the AD conversion
ADCSRA|=(1<<ADSC);
// Wait for the AD conversion to complete
while ((ADCSRA & (1<<ADIF))==0);
ADCSRA|=(1<<ADIF);
return ADCW;
}

void main(void)
{
GLCDINIT_t glcd_init_data;
glcd_init_data.font = font5x7;
glcd_init_data.temp_coef = 90;
glcd_init_data.bias = 4;
glcd_init_data.vlcd = 60;
glcd_init(&glcd_init_data);
ADMUX=ADC_VREF_TYPE;
ADCSRA=(1<<ADEN) | (0<<ADSC) | (0<<ADFR) | (0<<ADIF) | (0<<ADIE) | (0<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);
SFIOR=(0<<ACME);
//DDRD = 0xA0;
DDRF = 0x00;
PORTF = 0x02;
//PORTD = 0x00;
while (1)
    {      
        if (PINF.1 == 0)
        {
            for (i = 0; i < 4; i++)
            {
                gia_tri_adc = read_adc(i);
                sprintf(buffer, "%d  ", gia_tri_adc);
                glcd_outtextxy(10, i*10, buffer);     
            }     
        }
             
            
        //delay_ms(250);
        /*   
        if (gia_tri_adc <= 700)
        {
            PORTD.5 = 1;
            PORTD.7 = 0;
        }              
        else
        {
            PORTD.5 = 0;
            PORTD.7 = 1;
        }   
        */
    }
}
