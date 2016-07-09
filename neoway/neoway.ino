// звоним по событию
#include <SoftwareSerial.h>

SoftwareSerial gsm(9, 8); // RX, TX

void setup() {
  Serial.begin(9600);
  gsm.begin(115200);

}

void loop() {
      while(1){             // проверяем готовность модема
        gsm.println("AT+CPAS");
        if (gsm.find("0")) break;
        Serial.println("error 1");
        delay(100);  
      }
      gsm.println("ATD+79217025761;"); // звоним по указаному номеру
      delay(100);
      //if (gsm.find("OK")) Serial.println("OK!");
      //else Serial.println("error 2");
      while(1){ 
        if (gsm.available())
        Serial.write(gsm.read());
      }

}
