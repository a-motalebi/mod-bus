uint16_t k=0;
int i;
char a;
#define S1ADR 0X05
#define S2ADR 0X07

void read_coil(uint16_t address, uint16_t data)
{
    Serial2.write(address);

    Serial2.write(0x01);

    Serial2.write(data);
}

void write_coil(uint16_t address, uint16_t p, uint16_t pm)
{
    Serial2.write(address);

    Serial2.write(0x05);

    Serial2.write(p);

    Serial2.write(pm);
}

void read_reg(uint16_t address, uint16_t data)
{
    Serial2.write(address);

    Serial2.write(0x04);

    Serial2.write(data);
}
void setup() {
    Serial2.begin(9600);
    Serial.begin(9600);

}

void loop() {
  if(Serial.available())
  {
a=Serial.read();    
    if(a=='C')
      read_coil(S1ADR,0x16);
    else if(a=='V')
      read_coil(S1ADR,0x17);
    else if(a=='M')
      read_reg(S2ADR,0X01);
    else if(a=='W')
      write_coil(S1ADR,0X16,0x01);
    else if(a=='Q')
      write_coil(S1ADR,0X16,0x00);
    else if(a=='E')
      write_coil(S1ADR,0X17,0x00);
    else if(a=='R')
      write_coil(S1ADR,0X17,0x01);
  }  

  if(Serial2.available())
  {
    Serial.println(Serial2.read()); 
    Serial.println(Serial2.read());
    Serial.println(Serial2.read());
    Serial.println(Serial2.read());
    Serial.println("jjjjjjjjjjjjjjjjjjjjjjjjjj");
  }
delay(10000);
if(i==2)
{
  i=0;
  read_reg(S2ADR,0X01);
        read_coil(S1ADR,0x16);
      read_coil(S1ADR,0x17);

}
i++;

}
//QEWRRWEQEWEQRWEQWEQRWEQEWEQRWEQRWEQRWEQRWEQWQEQEQEWRWRWWQEWRQWEQWEQRQWEQRWEWQEWRQWEWEQERRWEW
