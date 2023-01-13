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
uint32_t start_man = 0;

void setup(){
    Serial.begin(115200);
    Serial.setTimeout(1);
    myTransfer.begin(Serial);
    
    trig.attach(15);
    yaw.attach(2);
    pitch.attach(0);

    trig.write(90); //stanby = 90; tembak = 100;
    yaw.write(25);
    pitch.write(73);
}

void loop(){
    start_man = millis();
    while(millis()-start_man<=10000){
        sudut_yaw = random(128, 135);
        sudut_pitch = random(98, 103);
        yaw.write(sudut_yaw);
        pitch.write(sudut_pitch);
        delay(1000);
    }
    yaw.write(131);
    pitch.write(99);
    delay(500);
    trig.write(100);
    delay(5000);
    trig.write(90);
}
