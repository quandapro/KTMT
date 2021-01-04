/*
 * Bai8.c
 *
 * Created: 11/13/2020 9:25:17 AM
 * Author: Dell    
 * 
 */

#include <io.h>
#include <alcd.h>
#include <delay.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#define DHT_ER 0
#define DHT_OK 1

#define DHT_DATA_IN PINB.7
#define DHT_DATA_OUT PORTB.7
#define DHT_DDR_DATA DDRB.7

char data[16];
unsigned char dht_nhiet_do, dht_do_am;

unsigned char DHT_GetTemHumi(unsigned char *tem, unsigned char *humi)
{
    unsigned char buffer[5] = {0, 0, 0, 0, 0}; 
    unsigned char i, ii;
    unsigned char checksum;     
    DHT_DDR_DATA = 1;
    DHT_DATA_OUT = 1;
    delay_us(40);
    DHT_DATA_OUT = 0;
    delay_ms(38);
    DHT_DATA_OUT = 1;  
    DHT_DDR_DATA = 0;
    delay_us(40);
    if (DHT_DATA_IN)
    {
        return DHT_ER;
    }
    else while(!(DHT_DATA_IN));
    delay_us(40);     
    if (!DHT_DATA_IN){
        return DHT_ER;
    }                 
    else while ((DHT_DATA_IN));
    for (i = 0; i < 5; i++)
    {
        for (ii = 0; ii < 8; ii++)
        {
            
            while((!DHT_DATA_IN));
            delay_us(30);
            if (DHT_DATA_IN)
            {
                buffer[i] |= (1 << (7 - ii));
                while ((DHT_DATA_IN));
            }
        }
    }
    checksum = buffer[0] + buffer[1] + buffer[2] + buffer[3];
    if (checksum != buffer[4]){
        return DHT_ER;
    }                 
    
    *tem = buffer[2];
    *humi = buffer[0];
    return DHT_OK;
}

void main(void)
{
DDRD = 0x80;
PORTD = 0x80;

DDRC = 0x01;
PORTC = 0x00;

lcd_init(16);
lcd_clear();

while (1)
    {
    // Please write your application code here
        if (DHT_GetTemHumi(&dht_nhiet_do, &dht_do_am))
        {
            lcd_clear();
            lcd_gotoxy(0,0);
            sprintf(data, "Do Am %u", (uint8_t) dht_do_am);
            lcd_puts(data);
            lcd_gotoxy(0, 1);
            sprintf(data, "Nhiet Do %u", (uint8_t) dht_nhiet_do);
            lcd_puts(data);
            delay_ms(300);
        }
        if (dht_nhiet_do > 28 && PORTC == 0x00)
        {
            PORTC = 0x01;
            delay_ms(250);
        }                  
        else if (dht_nhiet_do <= 28)
        {
            PORTC = 0x00;
            delay_ms(250);
        }
    }
}
