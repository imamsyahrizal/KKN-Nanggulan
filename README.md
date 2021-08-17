# KKN-WaterMonitoring
Proyek KKN PPM UGM 2021 di Desa Nanggulan. <br>
**Sistem monitoring kualitas air kolam berbasis IoT**. <br>
![0816 - Dashboard](https://user-images.githubusercontent.com/77771888/129525431-ab387ffd-0690-47e1-be27-1555683be9c5.png)



## Use
  1. Raspberry Pi : Server
  2. Mosquitto MQTT : Transfer data dari node
  3. Node-RED : Menerima data dari node dan menghubungkan ke database
  4. InfluxDB : Mengumpulkan data menjadi database
  5. Grafana : Menampilkan data parameter sistem
  6. RTC DS3231 : Time
  7. ESP32 
  8. Sensor Suhu D18B20
  9. Sensor pH 4502C
  10. Sensor Kekeruhan Gravity TDS SEN0244


## Used tutorial 
  1. https://randomnerdtutorials.com/esp32-mqtt-publish-subscribe-arduino-ide/
  2. https://simonhearne.com/2020/pi-influx-grafana/
  3. https://m.youtube.com/watch?v=JdV4x925au0
  4. https://discourse.nodered.org/t/why-raspberry-pi-becomes-slow-while-running-for-a-long-time/35144/22
  5. https://docs.influxdata.com/influxdb/v1.8/query_language/manage-database/
  6. https://www.youtube.com/watch?v=mvIuB1N0U7I
  7. https://github.com/influxdata/influxdb/issues/8912

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
  - Evaluasi tahap 1 : sistem tidak kuat (hanya bertahan kurang lebih 10 menit) penyebab mirip refrensi no 4

15 Agustus 2021 <br>
  - Evaluasi tahap 2
  - Membuat flow baru dengan menghapus chart >> first solution untuk masalah semakin lama raspberrypi menjadi berat
  - instal InfluxDB dan Grafana
  - Pembaruan program di Node-RED
  - Membuat DATABASE KUALITAS
  - Node-RED >> measurements :  suhu1, ph1, tds1 (saran next data ditambah kolam:1 jadi nanti tinggal pakai where kolam = 1 atau 2 atau 3 dst)
  - Membuat Dashboard di Grafana

16 Agustus 2021 <br>
  -  Evaluasi tahap 2 >> edit2 minor untuk dashboard
  -  Tampilan Dashboard sekarang
  -  ![0816 - Dashboard](https://user-images.githubusercontent.com/77771888/129511771-ad139c05-0a78-4234-82c7-f95cdc490a36.png)
  -  Semua file di Github belum diperbarui

17 Agustus 2021 <br>
  - Update Logbook sistem dan Set-Up
  - Pembaruan metode yang ditampilkan menjadi last() >> dengan interval tertentu
  - Evaluasi dengan ditest sekitar 8 jam data dikirim tiap 10 detik >> Influx jadi rusak  https://stackoverflow.com/questions/47833787/how-to-uninstall-influxdb-with-all-its-data-and-configuration-files 
  - Solusi Uninstal InfluxDB sebelumnya di hapus dulu semua dengan $ sudo chown -R influxdb:influxdb /var/lib/influxdb >> 
  - ![image](https://user-images.githubusercontent.com/77771888/129732011-85e5265b-e046-427c-a3ed-b59ff3486aee.png)
  - kemudian pakai kode $ sudo rm -r /var/lib/influxdb $ sudo apt-get remove influxdb >> lebih lengkap referensi 7
  - Install ulang InfluxDB dengan cara yang sama dengan sebelumnya pakai referensi 2
