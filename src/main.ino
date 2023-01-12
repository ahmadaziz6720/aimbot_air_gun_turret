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

float sudut_yaw = 90.0;
float sudut_pitch = 90.0;

float increment = 0.25;

String xy;
int i = 0;

int x;
int y;

int32_t X1[2];

int32_t X2[2];

uint32_t start_man = 0;

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
	start_man = millis();
}

void loop(){

	if(myTransfer.available()){
		
		uint16_t recSize = 0;
		recSize = myTransfer.rxObj(X1, recSize);
		x = X1[0];
		y = X1[1];
		uint16_t sendSize = 0;
		sendSize = myTransfer.txObj(X2, sendSize);
		myTransfer.sendData(sendSize);
		X2[0] = sudut_yaw;
		X2[1] = sudut_pitch;

		if(millis() - start_man < 15000){
		if(x < 280){
			sudut_yaw+= increment;
			if(sudut_yaw > 180){
				sudut_yaw =90;
			}
		}
		if(x > 320){
			sudut_yaw-= increment;
			if(sudut_yaw<10){
				sudut_yaw = 90;
			}
		}

		if(y< 170){
			sudut_pitch+= increment+0.1;
			if(sudut_pitch>138){
				sudut_pitch = 90;
			}
		} 
		if(y>230){
			sudut_pitch-= increment+0.1;
			if(sudut_pitch<48){
				sudut_pitch = 90;
			}
		}

		yaw.write(sudut_yaw);
   		pitch.write(sudut_pitch);
		// delay(15);
		}else{
		 //stanby = 90; tembak = 100;
		X1[0] = -1;
		X1[1] = -1;
		delay(2000);
		yaw.write(95);
		pitch.write(100);
		delay(500);
		trig.write(100);
		delay(1000);
		trig.write(90);
		start_man = millis();
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
}