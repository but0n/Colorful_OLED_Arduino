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
void fill_ram (uint8_t h, uint8_t l);
//=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=

void setup () {OLED_init ();int color = 0;}
void loop () {

uint8_t ch = (color >> 8) & 0x00FF;
uint8_t ch = color & 0x00FF;
fill_ram (ch, cl);
delay (100);
if (color == 0xFFFF) color = 0;
else color++;
}

//=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=
//                 OLED_init
//=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=

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
                    w_data (0x12);
                    
                    //Command Lock 
                    w_cmd (0xFD);
                    w_data (0xB1);
                    
                    //Set Sleep Mode On 
                    w_cmd (0xAE);
                    
                    //Set Display Clock Divide Ratio/Oscillator Frequency 
                    w_cmd (0xB3);
                    w_data (0xF1);
                    
                    //Set Multiplex Ratio 
                    w_cmd (0xCA);
                    w_data (0x7F);
                    
                    //Set Display Offset 
                    w_cmd (0xA2);
                    w_data (0x00);
                    
                    //Set Display Start Line 
                    w_cmd (0xA1);
                    w_data (0x00);
                    
                    //Set Re-Map & Color Depth 
                    w_cmd (0xA0);
                    w_data (0xB4);
                    
                    //Set GPIO 
                    w_cmd (0xB5);
                    w_data (0x00);
                    
                    
                    //Function Selection 
                    w_cmd (0xAB);
                    w_data (0x01);
                    
                    //Set Segment Low Voltage 
                    w_cmd (0xB4);
                    w_data (0xA0);
                    w_data (0xB5);
                    w_data (0x55);
                    
                    //Set Contrast Current 
                    w_cmd (0xC1);
                    w_data (0xC8);
                    w_data (0x80);
                    w_data (0xC8);
                    
                    //Set Master Current Control 
                    w_cmd (0xC7);
                    w_data (0x0F);
                    
                    //Gamma Look up Table 
                    w_cmd (0xB8);
                    w_data (0x02);
                    w_data (0x03);
                    w_data (0x04);
                    w_data (0x05);
                    w_data (0x06);
                    w_data (0x07);
                    w_data (0x08);
                    w_data (0x09);
                    w_data (0x0A);
                    w_data (0x0B);
                    w_data (0x0C);
                    w_data (0x0D);
                    w_data (0x0E);
                    w_data (0x0F);
                    w_data (0x10);
                    w_data (0x11);
                    w_data (0x12);
                    w_data (0x13);
                    w_data (0x15);
                    w_data (0x17);
                    w_data (0x19);
                    w_data (0x1B);
                    w_data (0x1D);
                    w_data (0x1F);
                    w_data (0x21);
                    w_data (0x23);
                    w_data (0x25);
                    w_data (0x27);
                    w_data (0x2A);
                    w_data (0x2D);
                    w_data (0x30);
                    w_data (0x33);
                    w_data (0x36);
                    w_data (0x39);
                    w_data (0x3C);
                    w_data (0x3F);
                    w_data (0x42);
                    w_data (0x45);
                    w_data (0x48);
                    w_data (0x4C);
                    w_data (0x50);
                    w_data (0x54);
                    w_data (0x58);
                    w_data (0x5C);
                    w_data (0x60);
                    w_data (0x64);
                    w_data (0x68);
                    w_data (0x6C);
                    w_data (0x70);
                    w_data (0x74);
                    w_data (0x78);
                    w_data (0x7D);
                    w_data (0x82);
                    w_data (0x87);
                    w_data (0x8C);
                    w_data (0x91);
                    w_data (0x96);
                    w_data (0x9B);
                    w_data (0xA0);
                    w_data (0xA5);
                    w_data (0xAA);
                    w_data (0xAF);
                    w_data (0xB4);
                    w_data (0x00);
                    
                    //Set Phase Length 
                    w_cmd (0xB1);
                    w_data (0x32);
                    
                    
                    //Enhance Driving Scheme Capability 
                    w_cmd (0xB2);
                    w_data (0xA4);
                    w_data (0x00);
                    w_data (0x00);
                    
                    //Set Pre-Charge Voltage 
                    w_cmd (0xBB);
                    w_data (0x17);
                    
                    //Set Second Pre-Charge Period 
                    w_cmd (0xB6);
                    w_data (0x01);
                    
                    //Set VCOMH Voltage 
                    w_cmd (0xBE);
                    w_data (0x05);
                    
                    //Set Display Mode 
                    w_cmd (0xA6);
                    
                    //Clear Screen 
                    fill_ram (0x00, 0x00);
                    
                    //Set Sleep Mode Off 
                    w_cmd (0xAF);

}

//=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=
//
//                   Write Data & Command
//
//=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=void w_cmd (uint8_t c) {
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
//=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=
//
//                 Fill Screen
//                 
//                 h ---------> High Byte Of Data
//                 l ---------> Low Byte Of Data
//
//                 Data mode: 
//                                    RRRRRGGG
//                                    GGGBBBBB
//
//                 Mode Select With Command "0xA0"
//
//=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=
void fill_ram (uint8_t h, uint8_t l) {
int i, c;
w_cmd (0x15);
w_data (0x00);
w_data (0x7F);

w_cmd (0x75);
w_data (0x00);
w_data (0x7F);

w_cmd (0x5C);

for (i = 0; i < 128; i++) {
for (c = 0; c < 128; c++) {w_data (h); w_data (l);}
}

}