int n[40];
#define adr 0x05

void read_coil(int r)
{
  Serial.println("CCCCCCCCCCCCCCCCCCCCCC");
  delay(5);
  Serial2.write(adr);
  Serial2.write(0x01);
  Serial2.write(n[r]);   
}
void write_coil(int p , int out)
{
    Serial.println("WWWWWWWWWWWWWWWWWWWWWWWWW");

  digitalWrite(p,out);
  n[p]=out;
  Serial2.write(adr);
  Serial2.write(0x05);
  if(p==22)
    Serial2.write(0x16);
  else
    Serial2.write(0x17);
  if(out==0)
    Serial2.write(0x00);
  else
    Serial2.write(0x01);
}
void setup() {
  Serial2.begin(9600);
  Serial.begin(9600);
  pinMode(23,OUTPUT);
  pinMode(22,OUTPUT);
}

void loop() {
  if (Serial2.available()) {
    if(Serial2.read()==adr)
      {
        Serial.println("adress");
        if(Serial2.read()== 0x01)
        {
            Serial.println("coil");
           if(Serial2.read()==0x16)
              read_coil(22);
           else 
              read_coil(23);
        }
        else
        {
           if(Serial2.read()==0x16)
           {
              if(Serial2.read()==0x00)
                write_coil(22,0);
              else
                write_coil(22,1);
           }
           else 
           {
              if(Serial2.read()==0x00)
                write_coil(23,0);
              else
                write_coil(23,1);
           }
        }
      }
  }
}
