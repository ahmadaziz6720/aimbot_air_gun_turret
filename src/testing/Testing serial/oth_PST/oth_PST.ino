#include "SerialTransfer.h"


SerialTransfer myTransfer;

int32_t X1[2];

char message[5];

void setup()
{
  Serial.begin(115200);
  myTransfer.begin(Serial, true);
}

void loop()
{
  if(myTransfer.available())
  {
    uint16_t recSize = 0;

      recSize = myTransfer.rxObj(X1, recSize);
      

  
      uint16_t sendSize = 0;
      
      sendSize = myTransfer.txObj(X1, sendSize);
      
      myTransfer.sendData(sendSize);
     
  }
//  X1[0] = X1[0] + 1;
//  X1[1] = X1[1] + 1;
}
