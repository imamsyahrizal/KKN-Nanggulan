//Deklarasi Library
#include <OneWire.h>
#include <DallasTemperature.h>
#include<PubSubClient.h>
#include <Wire.h>
#include<WiFi.h>

//Pendefinisian Pin dan Nilai Awal Sensor 
const int oneWireBus = 4;
const int ph_Pin  = 34;
float Po = 0;
float PH_step;
int nilai_analog_PH;
double TeganganPh;
int sensorPin = 15;
float volt;
float ntu;

//Variabel Kalibrasi Sensor PH
float PH4 = 3.226;
float PH7 = 2.691;

//Pendefinisan WiFi
const char* ssid = "YO123";
const char* password = "kknppmugm";

//Pendefinisian IP Broker
const char* mqtt_server = "192.168.1.100";

//Pendefinisian PubSub
WiFiClient espClient;
PubSubClient client(espClient);

OneWire oneWire(oneWireBus);
DallasTemperature sensors(&oneWire);

//Pendefinisian Variabel Waktu Pembacaan Sensor
long waktuSebelumnya = 0;
char msg[50];
int value = 0;

void setup(){
  //Inisiasi Pin dan Kecepatan Komunikasi Serial
  pinMode (ph_Pin, INPUT);
  Serial.begin(9600);
  sensors.begin();

  //Setup WiFi dan MQTT
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);

}

//Fungsi Setup WiFi
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

// Fungsi Subscribe
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
}

// Fungsi Pengecekkan Koneksi WiFi
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

void loop(){
    //Pengecekkan Sambungan WiFi
    if(!client.connected()){
    reconnect();
    }
    client.loop();

    //Pengecekkan Waktu untuk Update
    long sekarang = millis();
    if(sekarang - waktuSebelumnya > 600000){
        waktuSebelumnya = sekarang;

        //int val = analogRead(15);
        //nilai_analog_TB = analogRead(tb_Pin);
        nilai_analog_PH = analogRead(ph_Pin);
        //Serial.print("Nilai ADC Ph: ");
        //Serial.println(nilai_analog_PH);
        TeganganPh = 3.3 / 1024.0 * nilai_analog_PH;
        //Serial.print("TeganganPh: ");
        //Serial.println(TeganganPh, 3);

        PH_step = (PH4 - PH7) / 3;
        Po = 7.00 + ((PH7 - TeganganPh) / PH_step);     //Po = 7.00 + ((teganganPh7 - TeganganPh) / PhStep);
        char PoString[8];
        dtostrf(Po, 1, 2, PoString);
        Serial.print("Nilai PH cairan: ");
        Serial.println(Po, 2);
        client.publish("kolam1/ph", PoString);

        sensors.requestTemperatures(); 
        float temperatureC = sensors.getTempCByIndex(0);
        //float temperatureF = sensors.getTempFByIndex(0);
        char tempString[8];
        dtostrf(temperatureC, 1, 2, tempString);
        Serial.print("Nilai Temperature: ");
        Serial.print(temperatureC);
        Serial.println("ºC");
        client.publish("kolam1/suhu", tempString);
        //Serial.print(temperatureF);
        //Serial.println("ºF");

            volt = 0;
            for(int i=0; i<800; i++)
            {
                volt += ((float)analogRead(sensorPin)/1023)*5;
            }
            volt = volt/800;
            //volt = round_to_dp(volt,1);
         if(volt < 2.5){
           ntu = 3000;
            }else{
              ntu = -1120.4*sq(volt)+5742.3*volt-4353.8; 
            }
            
        char ntuString[8];
        dtostrf(ntu, 1, 2, ntuString);
        Serial.print("Nilai TB: ");
        Serial.println(ntu);
        client.publish("kolam1/tds", ntuString);
        //delay(3000);
    }
}

/*
 * PH step = (tegangan PH4 – tegangan PH7) / (PH7 - PH4)
             = (3.1 – 2.5)/(7-4)
             = 0.6/3
             = 0.2
 */
