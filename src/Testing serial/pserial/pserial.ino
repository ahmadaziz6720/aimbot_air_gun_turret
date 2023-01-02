String xy;
int x;
int y;

int i = 0;

void setup() {
  Serial.begin(115200);
  Serial.setTimeout(1);
}

void loop() {
 while (!Serial.available());
 xy = Serial.readString();
  i = xy.indexOf(" ");
  
  x = xy.substring(0, i).toInt();
  y = xy.substring(i + 1, xy.length()).toInt();
  
  Serial.print(y+x);
}
