# KKN-WaterMonitoring
Proyek KKN PPM UGM 2021 di Desa Nanggulan. <br>
**Sistem monitoring kualitas air kolam berbasis IoT**. <br>
![0816 - Dashboard](https://user-images.githubusercontent.com/77771888/129525431-ab387ffd-0690-47e1-be27-1555683be9c5.png)



## Tools
  1. Raspberry Pi
  2. RTC DS3231
  3. ESP32 
  4. Sensor Suhu D18B20
  5. Sensor pH 4502C
  6. Sensor Kekeruhan Gravity TDS SEN0244
  7. Router 
  8. Fan 5V
  9. Memory Card
  10. SD Card Reader
  11. HDMI Cable
  12. LAN Cable

## Software
  1. Mosquitto MQTT
  2. Node-Red
  3. InfluxDB
  4. Grafana
  5. Arduino IDE


## Refrensi
  1. ESP32 MQTT – Publish and Subscribe with Arduino IDE oleh Rui Santos di https://randomnerdtutorials.com/esp32-mqtt-publish-subscribe-arduino-ide/
  2. Installing InfluxDB & Grafana on Raspberry Pi oleh Simon Hearne di https://simonhearne.com/2020/pi-influx-grafana/
  3. Node-Red, InfluxDB, and Grafana Tutorial on a Raspberry Pi oleh di Andreas Spiess https://m.youtube.com/watch?v=JdV4x925au0
  4. Forum diskusi Raspberry Pi menjadi lambat di https://discourse.nodered.org/t/why-raspberry-pi-becomes-slow-while-running-for-a-long-time/35144/22
  5. Manage your database using InfluxQL di https://docs.influxdata.com/influxdb/v1.8/query_language/manage-database/
  6. Beginner for Node-RED, InfluxDB & Grafana oleh Nur Hanani Ahmad Puaad di https://www.youtube.com/watch?v=mvIuB1N0U7I
  7. InfluxDB refusing connections #8912 di https://github.com/influxdata/influxdb/issues/8912
  8. S. Pasika dan S. T. Gandla, “Smart water quality monitoring system with cost-effective using IoT,” Heliyon, vol. 6, no. 7, 2020
  9. A. Rifa'i, M. U. H. Rasyid dan A. I. Gunawan, “Sistem Pemantauan dan Kontrol Otomatis Kualitas Air Berbasis IoT Menggunakan Platform Node-RED untuk Budidaya Udang,” Jurnal Teknologi Terapan, vol. 7, no. 1, pp. 19-26, 2021. 
  10. K. M. dan Y. Irawan, “Smart Aquarium Design Using Raspberry Pi and Android Based,” Jurnal of Robotics and Control, vol. 2, no. 5, pp. 368-372, 2021.
  11.  M. Niswar, S. Wainalang, A. A. Ilham, Z. Zainuddin, Y. Fujaya, Z. Muslimin, A. W. Paundu, S. Kashihara dan D. Fall, “IoT-based Water Quality Monitoring System for”. 


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
  - Permasalahan : Failed to connect to http://localhost:8086: Get http://localhost:8086/ping: dial tcp [::1]:8086: getsockopt Please check your connection settings and ensure 'influxd' is running
  - Solusi Uninstal InfluxDB sebelumnya di hapus dulu semua dengan $ sudo chown -R influxdb:influxdb /var/lib/influxdb >> 
  - ![image](https://user-images.githubusercontent.com/77771888/129732011-85e5265b-e046-427c-a3ed-b59ff3486aee.png)
  - kemudian pakai kode $ sudo rm -r /var/lib/influxdb $ sudo apt-get remove influxdb >> lebih lengkap referensi 7
  - Install ulang InfluxDB dengan cara yang sama dengan sebelumnya pakai referensi 2
  - Jika diperlukan configurasi influxdb https://github.com/influxdata/influxdb/blob/1.7/etc/config.sample.toml

18 Agustus 2021
  - Melengkapi README.md
  - Memperbarui kode MQTT
  - Evaluasi sistem
