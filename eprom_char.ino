#include <avr/eeprom.h>

byte e_in;  
byte e_out; 
unsigned int addr = 1,ie=2; 
char data[100]="",c,datao[100]="";

void setup() {
 for(int i=0;i<=10;i++){addr=i;e_out= eeprom_read_byte((unsigned char *) addr);datao[i]= (char )e_out;}
 Serial.begin(9600);
 }

void loop() {

while (Serial.available()) {
//Serial.print(ie);Serial.println(c);
  c=Serial.read();
  ie++;
  if(ie>=3)data[ie]=c;
  if(c==';'){ie=0; for(int i=0;i<=100;i++){datao[i]=data[3+i];} for(int i=0;i<=100;i++){addr=i;eeprom_write_byte((unsigned char *) addr,datao[i]);}}

}
Serial.println(datao);
delay(500);
} 
