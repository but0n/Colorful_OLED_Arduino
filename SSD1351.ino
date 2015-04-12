/* 
 *
 * SSD1351.ino
 * 
 * Created by Jack, April 12, 2015.
 * 
 *
 * OLED INFORMATION:
 * ------------->1.5' 128*128 (RGB)
 * ------------->Driver IC: SSD1351
 *
 * INTERFACE       : 4-wire SPI.
 * 
 * E-mail          :       but0n@freeattack.com
 * 
 * Copyright <c> Jack
 *
 */
#define SCLK 2  //D0
#define SDIN 3 //D1
#define DC 4
#define RST 5
#define CS 6

void OLED_init ();
void w_cmd (uint8_t c);
void w_data (uint8_t d);
//=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=

void setup () {OLED_init ();}
void loop () {while (1) {}}

//=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=
//    OLED_init
//=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=
void OLED_init (){
                  pinMode (SDIN, OUTPUT); 
                  pinMode (SCLK, OUTPUT);   
                  pinMode (DC, OUTPUT); 
                  pinMode (RST, OUTPUT);
                  pinMode (CS, OUTPUT); 
                  
                  digitalWrite (RST, HIGH);
                  delay (1);
                  
                  digitalWrite (RST, LOW);
                  delay(10);
                  
                  digitalWrite (RST, HIGH); 
                  
                    //Command Lock 
                    w_cmd (0xFD);
                    w_cmd (0x12);
                    
                    //Command Lock 
                    w_cmd (0xFD);
                    w_cmd (0xB1);
                    
                    //Set Sleep Mode On 
                    w_cmd (0xAE);
                    
                    //Set Display Clock Divide Ratio/Oscillator Frequency 
                    w_cmd (0xB3);
                    w_cmd (0xF1);
                    
                    //Set Multiplex Ratio 
                    w_cmd (0xCA);
                    w_cmd (0x7F);
                    
                    //Set Display Offset 
                    w_cmd (0xA2);
                    w_cmd (0x00);
                    
                    //Set Display Start Line 
                    w_cmd (0xA1);
                    w_cmd (0x00);
                    
                    //Set Re-Map & Color Depth 
                    w_cmd (0xA0);
                    w_cmd (0xB4);
                    
                    //Set GPIO 
                    w_cmd (0xB5);
                    w_cmd (0x00);
                    
                    
                    //Function Selection 
                    w_cmd (0xAB);
                    w_cmd (0x01);
                    
                    //Set Segment Low Voltage 
                    w_cmd (0xB4);
                    w_cmd (0xA0);
                    w_cmd (0xB5);
                    w_cmd (0x55);
                    
                    //Set Contrast Current 
                    w_cmd (0xC1);
                    w_cmd (0xC8);
                    w_cmd (0x80);
                    w_cmd (0xC8);
                    
                    //Set Master Current Control 
                    w_cmd (0xC7);
                    w_cmd (0x0F);
                    
                    //Gamma Look up Table 
                    w_cmd (0xB8);
                    w_cmd (0x02);
                    w_cmd (0x03);
                    w_cmd (0x04);
                    w_cmd (0x05);
                    w_cmd (0x06);
                    w_cmd (0x07);
                    w_cmd (0x08);
                    w_cmd (0x09);
                    w_cmd (0x0A);
                    w_cmd (0x0B);
                    w_cmd (0x0C);
                    w_cmd (0x0D);
                    w_cmd (0x0E);
                    w_cmd (0x0F);
                    w_cmd (0x10);
                    w_cmd (0x11);
                    w_cmd (0x12);
                    w_cmd (0x13);
                    w_cmd (0x15);
                    w_cmd (0x17);
                    w_cmd (0x19);
                    w_cmd (0x1B);
                    w_cmd (0x1D);
                    w_cmd (0x1F);
                    w_cmd (0x21);
                    w_cmd (0x23);
                    w_cmd (0x25);
                    w_cmd (0x27);
                    w_cmd (0x2A);
                    w_cmd (0x2D);
                    w_cmd (0x30);
                    w_cmd (0x33);
                    w_cmd (0x36);
                    w_cmd (0x39);
                    w_cmd (0x3C);
                    w_cmd (0x3F);
                    w_cmd (0x42);
                    w_cmd (0x45);
                    w_cmd (0x48);
                    w_cmd (0x4C);
                    w_cmd (0x50);
                    w_cmd (0x54);
                    w_cmd (0x58);
                    w_cmd (0x5C);
                    w_cmd (0x60);
                    w_cmd (0x64);
                    w_cmd (0x68);
                    w_cmd (0x6C);
                    w_cmd (0x70);
                    w_cmd (0x74);
                    w_cmd (0x78);
                    w_cmd (0x7D);
                    w_cmd (0x82);
                    w_cmd (0x87);
                    w_cmd (0x8C);
                    w_cmd (0x91);
                    w_cmd (0x96);
                    w_cmd (0x9B);
                    w_cmd (0xA0);
                    w_cmd (0xA5);
                    w_cmd (0xAA);
                    w_cmd (0xAF);
                    w_cmd (0xB4);
                    w_cmd (0x00);
                    
                    //Set Phase Length 
                    w_cmd (0xB1);
                    w_cmd (0x32);
                    
                    
                    //Enhance Driving Scheme Capability 
                    w_cmd (0xB2);
                    w_cmd (0xA4);
                    w_cmd (0x00);
                    w_cmd (0x00);
                    
                    //Set Pre-Charge Voltage 
                    w_cmd (0xBB);
                    w_cmd (0x17);
                    
                    //Set Second Pre-Charge Period 
                    w_cmd (0xB6);
                    w_cmd (0x01);
                    
                    //Set VCOMH Voltage 
                    w_cmd (0xBE);
                    w_cmd (0x05);
                    
                    //Set Display Mode 
                    w_cmd (0xA6);
                    
                    //Clear Screen 
                    
                    //Set Sleep Mode Off 
                    w_cmd (0xAF);

}

void w_cmd (uint8_t c) {
          digitalWrite (CS,LOW);
          digitalWrite (DC,LOW);
          shiftOut (SDIN, SCLK, MSBFIRST, c);
          digitalWrite (CS,HIGH);
}
void w_data (uint8_t d) {
          digitalWrite (CS,LOW);
          digitalWrite (DC,HIGH);
          shiftOut (SDIN, SCLK, MSBFIRST, d);
          digitalWrite (CS,HIGH);
}
