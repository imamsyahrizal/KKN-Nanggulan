# KKN-WaterMonitoring
Proyek KKN PPM UGM 2021 di Desa Nanggulan. <br>
**Sistem monitoring kualitas air kolam berbasis IoT**. <br>
Menggunakan <br> 
  1. Raspberry Pi<br> 
  2. Node-RED, <br>
  3. RTC DS3231
  4. ESP32 <br>
  5. Sensor Suhu D18B20
  6. Sensor pH 4502C
  7. Sensor Kekeruhan Gravity TDS SEN0244


## Used tutorial 
https://randomnerdtutorials.com/esp32-mqtt-publish-subscribe-arduino-ide/

<br><br>
## Tentang Sistem
Sistem Operasi : Raspbian OS
![System Overview-01](https://user-images.githubusercontent.com/77771888/127804773-7466d698-bb92-4034-89a1-a5c3fa98a4c5.png)
![MQTT](https://user-images.githubusercontent.com/77771888/128625034-4c7409f8-faa7-4f1f-bfc2-dbc7deacfc13.png) <br>


## Log Github
31 Juli 2021 <br>
  - Sistem Selesai dibuat, tetapi belum ada integrasi antara server dan node<br>
  - File-file Log Sistem, Set-Up Sistem, Paper, dan Poster Sistem Selesai dibuat, tapi belum diunggah ke Github

08 Agustus 2021 <br>
  - Upload Digram MQTT <br>
  - Perbaikan pada [01] Log Sistem dan [02] Set-Up Sistem


13 Agustus 2021 <br>
  - Upload Poster, Report, Set-Up, dan Logbook Sistem 


14 Agustus 2021 <br>
  - Mengunggah kode Node-RED dan gambar flows <br>
  - Mengunggah kode testing ESP untuk test komunikasi MQTT dan Node-RED, pin ESP32 32 35 34 sebagai masukkkan ADC
  - Mengunggah Library pubsubclient yang diambil dari Random Nerd

15 Agustus 2021 <br>
  - Evaluasi tahap 2
  - Membuat flow baru dengan menghapus chart >> first solution untuk masalah semakin lama raspberrypi menjadi berat
  - FOR NEXT DEVELPOMENT PLEASE add InfluxDB and Grafana
