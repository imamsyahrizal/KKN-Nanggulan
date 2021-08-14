// menambahkan library yang diperlukan
#include<WiFi.h>
#include<PubSubClient.h>
#include<Wire.h>

// define Pin
#define suhuPin 32
#define phPin 35
#define tdsPin 34

// define WiFi
const char* ssid = "YO123";
const char* password = "kknppmugm";

// Definisi IP mqtt broker http://raspberrypi.local/
const char* mqtt_server = "192.168.1.100";

// Definisi objek WiFiClient dan PubSubClient
WiFiClient espClient;
PubSubClient client(espClient);

// variabel untuk waktu pembacaan sensor
long waktuSebelumnya = 0;
char msg[50];
int value = 0;

// variable untuk menyimpan suhu dan kelembaban
float suhu = 0;
float ph = 0;
float tds = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); // memulai Sambungan serial usb dengan baudrate 115200

  // Kebutuhan setup WiFi dan mqtt
  setup_wifi();
  client.setServer(mqtt_server, 1883); // port 1883 sebagai default mqtt
  client.setCallback(callback); // callback digunakan untuk subscribe mqtt
}

//Fungsi setup WiFi
void setup_wifi(){
  delay(10);
  Serial.println();
  Serial.print("Berusaha terhubung ke ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

// Fungsi yang akan melakukan subscribe topik 
void callback(char* topic, byte* message, unsigned int length){
  Serial.print("Pesan diterima dengan topik : ");
  Serial.print(topic);
  Serial.print(". Pesan : ");
  String messageTemp;

  for (int i=0; i<length; i++){
  Serial.print((char)message[i]);
  messageTemp += (char)message[i];
  }
  Serial.println();

  /*if(String(topic) == "esp32/output"){
    if(messageTemp == "change"){
      Serial.print("Tombol LED ditekan pada dashboard");
      ledState = ~ledState;
      digitalWrite(ledPin, ledState);

      // kirim status LED ke topik esp32/led
      char statusString[8];
      dtostrf(ledState, 1, 2, statusString);
      Serial.print("LED State : ");
      Serial.println(statusString);
      client.publish("esp32/led", statusString);
    }
  }*/
}

// Fungsi untuk memastikan akan selalu Terkoneksi dengan WiFi
void reconnect(){
  while(!client.connected()){
    Serial.print("Berusaha menghubungkan MQTT...");
    if(client.connect("ESP8266Client")){
      Serial.println("Terhubung");
      client.subscribe("esp32/output");
    }else{
      Serial.print("gagal, rc=");
      Serial.print(client.state());
      Serial.println(" coba lagi dalam 5 seconds");
      delay(5000);
    }
  }
}


void loop() {
  // put your main code here, to run repeatedly:
  // Cek Sambungan WiFi
  if(!client.connected()){
    reconnect();
  }
  client.loop();

  // Cek waktu untuk update, jika sudah sesuai lakukan publish data
  long sekarang = millis();
  if(sekarang - waktuSebelumnya > 500){
    waktuSebelumnya = sekarang;

    suhu = analogRead(suhuPin);
    suhu = map(suhu,0,4095,0,3000);
    suhu = suhu/100;
    char suhuString[8];
    dtostrf(suhu, 1, 2, suhuString);
    Serial.print("Suhu: ");
    Serial.print(suhu);
    Serial.print("  ");
    Serial.println(suhuString);
    client.publish("kolam1/suhu", suhuString);

    ph = analogRead(phPin);
    ph = map(ph,0,4095,0,1400);
    ph = ph/100;
    char phString[8];
    dtostrf(ph, 1, 2, phString);
    Serial.print("pH: ");
    Serial.print(ph);
    Serial.print("  ");
    Serial.println(phString);
    client.publish("kolam1/ph", phString);

    tds = analogRead(tdsPin);
    tds = map(tds,0,4095,0,100000);
    tds = tds/100;
    char tdsString[8];
    dtostrf(tds, 1, 2, tdsString);
    Serial.print("Kekeruhan: ");
    Serial.print(tds);
    Serial.print("  ");
    Serial.println(tdsString);
    client.publish("kolam1/tds", tdsString);
  }

  

}
