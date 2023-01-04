#include <Servo.h>
#include "SerialTransfer.h"

SerialTransfer myTransfer;

Servo trig;
Servo yaw;
Servo pitch;

#define pot1 34
#define pot2 35

#define S_trig 15
#define S_yaw 2
#define S_pitch 0

int read_pot1;
int read_pot2;

int sudut_yaw = 90;
int sudut_pitch = 90;

String xy;
int i = 0;

int x;
int y;

int32_t X1[2];

void setup(){
    Serial.begin(115200);
    Serial.setTimeout(1);
    myTransfer.begin(Serial);
    
    trig.attach(15);
    yaw.attach(2);
    pitch.attach(0);

    //default position
    trig.write(90); //stanby = 90; tembak = 100;
    yaw.write(90);
    pitch.write(90);

    delay(10000);
}

void loop(){

	if(myTransfer.available()){
		uint16_t recSize = 0;
		recSize = myTransfer.rxObj(X1, recSize);
		x = X1[0];
		y = X1[1];
		uint16_t sendSize = 0;
		sendSize = myTransfer.txObj(X1, sendSize);
		myTransfer.sendData(sendSize);

		if(x < 250){
			sudut_yaw++;
			if(sudut_yaw > 180){
				sudut_yaw =90;
			}
		}
		if(x > 350){
			sudut_yaw--;
			if(sudut_yaw<10){
				sudut_yaw = 90;
			}
		}

		if(y< 150){
			sudut_pitch++;
			if(sudut_pitch>138){
				sudut_pitch = 90;
			}
		} 
		if(y>250){
			sudut_pitch--;
			if(sudut_pitch<48){
				sudut_pitch = 90;
			}
		}
	} 
	// else{
	// 	read_pot1 = analogRead(pot1); // 48-138 pitch
	// 	read_pot2 = analogRead(pot2); // 3-180 yaw
	// 	trig.write(map(read_pot2, 0, 4095, 0, 180)); //stanby = 90; tembak = 100;
	// 	yaw.write(map(read_pot2, 0, 4095, 0, 180));
	// 	pitch.write(map(read_pot1, 0, 4095, 0, 180));
	// 	Serial.print(map(read_pot2, 0, 4095, 0, 180));
	// 	Serial.print(" < ");
	// 	Serial.println(map(read_pot1, 0, 4095, 0, 180));
	// 	delay(10);
	// }

	

   yaw.write(sudut_yaw);
   pitch.write(sudut_pitch);
//    delay(10);

}
