#include <Servo.h>

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

void setup(){
    Serial.begin(250000);
    Serial.setTimeout(1);
    
    trig.attach(15);
    yaw.attach(2);
    pitch.attach(0);

    trig.write(90); //stanby = 90; tembak = 100;
    yaw.write(25);
    pitch.write(73);

    delay(10000);

    for(int i=73; i<100; i++){
      pitch.write(i);
      delay(50);
    }
    delay(1000);
    for(int i=25; i<160; i++){
      yaw.write(i);
      delay(50);
    }
    delay(1000);
    for(int i=100; i<130; i++){
      pitch.write(i);
      delay(50);
    }

    for(int i=130; i>70; i--){
      pitch.write(i);
      delay(50);
    }

    delay(21000);
    for(int i=160; i>60; i--){
      int j = map(i, 160, 60, 70, 120);
      pitch.write(j);
      yaw.write(i);
      delay(50);
    }
    delay(1000);
    trig.write(100);
}

void loop(){
  //yaw pitch
  //25  73  ok
  //25  100
  //160 100
  //60  100
  //

  
  


//    while (!Serial.available()){
//       read_pot1 = analogRead(pot1); // 48-138 pitch
//       read_pot2 = analogRead(pot2); // 3-180 yaw
////       trig.write(map(read_pot2, 0, 4095, 0, 180)); //stanby = 90; tembak = 100;
//       yaw.write(map(read_pot2, 0, 4095, 0, 180));
//       pitch.write(map(read_pot1, 0, 4095, 0, 180));
//       Serial.print(map(read_pot2, 0, 4095, 0, 180));
//       Serial.print(" < ");
//       Serial.println(map(read_pot1, 0, 4095, 0, 180));
//       delay(10);
//    }
//    xy = Serial.readString();
//    i = xy.indexOf("*");
//  
//    x = xy.substring(0, i).toInt();
//    y = xy.substring(i + 1, xy.length()).toInt();
//    xy = "";
//
//     Serial.print(y);
//
//    if(x < 280){
//        sudut_yaw++;
//        if(sudut_yaw > 180){
//          sudut_yaw =90;
//        }
//    }
//    if(x > 320){
//        sudut_yaw--;
//        if(sudut_yaw<10){
//          sudut_yaw = 90;
//        }
//    }
//
//    if(y< 190){
//        sudut_pitch++;
//        if(sudut_pitch>138){
//          sudut_pitch = 90;
//        }
//    } 
//    if(y>230){
//        sudut_pitch--;
//        if(sudut_pitch<48){
//          sudut_pitch = 90;
//        }
//    }
//
//    yaw.write(sudut_yaw);
//    pitch.write(sudut_pitch);
//    delay(100);

}
