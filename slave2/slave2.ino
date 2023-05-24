
#define adr 0x07

void read_reg()
{
  Serial.println("CCCCCCCCCCCCCCCCCCCCCC");
  delay(5);
  Serial2.write(adr);
  Serial2.write(0x04);
  Serial2.write(0x18);   
}

void setup() {
  Serial2.begin(9600);
  Serial.begin(9600);
}

void loop() {
  if (Serial2.available()) {
    if(Serial2.read()==adr)
      {
        Serial.println("adress");
        if(Serial2.read()== 0x04)
        {
            Serial.println("readreg");
           if(Serial2.read()==0x01)
              read_reg();
        }
      }
  }
}
