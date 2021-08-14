// variabel untuk waktu pembacaan sensor
unsigned long tunggu=5000;
unsigned long waktuSebelumnya=0;
unsigned long waktuSekarang=0;

// nilai yang akan dikirim
float suhu;
float ph;
float tds;

// nilai yang akan dikirim
const int suhup = 13;
const int php = 14;
const int tdsp = 34;


void setup() {
  // put your setup code here, to run once:
  //pinMode(suhup, INPUT);
  //pinMode(php, INPUT);
  //pinMode(tdsp, INPUT);
  Serial.begin(115200);
  delay(1000);

}

void loop() {
  // put your main code here, to run repeatedly:
  suhu = analogRead(suhup);
  delay(100);
  ph = analogRead(php);
  delay(100);
  tds = analogRead(tdsp);
  delay(100);
  Serial.print(suhu);
  Serial.print("#");
  Serial.print(ph);
  Serial.print("#");
  Serial.println(tds);
  delay(100);
}
