/*
   LoRaLib Receive Example

   This example listens for LoRa transmissions and tries to
   receive them. To successfully receive data, the following
   settings have to be the same on both transmitter
   and receiver:
    - carrier frequency
    - bandwidth
    - spreading factor
    - coding rate
    - sync word
    - preamble length

   For more detailed information, see the LoRaLib Wiki
   https://github.com/jgromes/LoRaLib/wiki

   For full API reference, see the GitHub Pages
   https://jgromes.github.io/LoRaLib/
*/

// include the library
#include <LoRaLib.h>

// create instance of LoRa class using SX1278 module
// this pinout corresponds to RadioShield
// https://github.com/jgromes/RadioShield
// NSS pin:   10 (4 on ESP32/ESP8266 boards)
// DIO0 pin:  2
// DIO1 pin:  3
SX1278 lora = new LoRa;
int Vrdata = 0;

String data;
int nilai_soil1, nilai_soil2, nilai_soil3;
float nilai_cahaya;
float suhu, kelembaban;
float phTanah;
float phTanah2;
float phTanah3;
int timer;
void setup() {
  Serial.begin(9600);

  // initialize SX1278 with default settings
  Serial.print(F("Initializing ... "));
  // carrier frequency:           434.0 MHz
  // bandwidth:                   125.0 kHz
  // spreading factor:            9
  // coding rate:                 7
  // sync word:                   0x12
  // output power:                17 dBm
  // current limit:               100 mA
  // preamble length:             8 symbols
  // amplifier gain:              0 (automatic gain control)
  int state = lora.begin();
  if (state == ERR_NONE) {
    Serial.println(F("success!"));
  } else {
    Serial.print(F("failed, code "));
    Serial.println(state);
    while (true);
  }
}

void loop() {
  Serial.print(F("Waiting for incoming transmission ... "));

  // you can receive data as an Arduino String
  // NOTE: receive() is a blocking method!
  //       See example ReceiveInterrupt for details
  //       on non-blocking reception method.
  // NOTE: for spreading factor 6, the packet length
  //       must be known in advance, and provided to
  //       receive() method!
  String str;
  int state = lora.receive(str);

  // you can also receive data as byte array
  /*
    size_t len = 8;
    byte byteArr[len];
    int state = lora.receive(byteArr, len);
  */

  if (state == ERR_NONE) {
    // packet was successfully received
    Serial.println(F("success!"));

    // print data of the packet
    Serial.print(F("Data:\t\t\t"));
    Serial.println(str);

    // print RSSI (Received Signal Strength Indicator)
    // of the last received packet
    Serial.print(F("RSSI:\t\t\t"));
    Serial.print(lora.getRSSI());
    Serial.println(F(" dBm"));

    // print SNR (Signal-to-Noise Ratio)
    // of the last received packet
    Serial.print(F("SNR:\t\t\t"));
    Serial.print(lora.getSNR());
    Serial.println(F(" dB"));

    // print frequency error
    // of the last received packet
    Serial.print(F("Frequency error:\t"));
    Serial.print(lora.getFrequencyError());
    Serial.println(F(" Hz"));

    data = str;

    String data_nilai0 = getValue(data, ',', 0);
    String data_nilai1 = getValue(data, ',', 1);
    String data_nilai2 = getValue(data, ',', 2);
    String data_nilai3 = getValue(data, ',', 3);
    String data_nilai4 = getValue(data, ',', 4);
    String data_nilai5 = getValue(data, ',', 5);
    String data_nilai6 = getValue(data, ',', 6);
    String data_nilai7 = getValue(data, ',', 7);
    String data_nilai8 = getValue(data, ',', 8);

    nilai_soil1   = data_nilai0.toInt();
    nilai_soil2   = data_nilai1.toInt();
    nilai_soil3   = data_nilai2.toInt();
    nilai_cahaya  = data_nilai3.toFloat();
    suhu          = data_nilai4.toFloat();
    kelembaban    = data_nilai5.toFloat();
    phTanah       = data_nilai6.toFloat();
    phTanah2       = data_nilai7.toFloat();
    phTanah3       = data_nilai8.toFloat();


    Serial.print("Soil1: ");
    Serial.print(nilai_soil1);
    Serial.print("  Soil2: ");
    Serial.print(nilai_soil2);
    Serial.print("  Soil3: ");
    Serial.println(nilai_soil3);

    Serial.print("Nilai Cahaya: ");
    Serial.print(nilai_cahaya);
    Serial.println(" lux");

    Serial.print("kelembaban: ");
    Serial.print(kelembaban);
    Serial.print(" ");
    Serial.print("suhu: ");
    Serial.println(suhu);

    Serial.print("pH Tanah= ");
    Serial.println(phTanah);
    Serial.print("pH Tanah2= ");
    Serial.println(phTanah2);
    Serial.print("pH Tanah3= ");
    Serial.println(phTanah3);


    timer++;
    Serial.print("Timer: ");
    Serial.println(timer);

    Serial.println();

    delay(100);


  } else if (state == ERR_RX_TIMEOUT) {
    // timeout occurred while waiting for a packet
    Serial.println(F("timeout!"));

  } else if (state == ERR_CRC_MISMATCH) {
    // packet was received, but is malformed
    Serial.println(F("CRC error!"));

  }

}
String getValue(String data, char separator, int index) {
  int found = 0;
  int strIndex[] = { 0, -1 };
  int maxIndex = data.length() - 1;
  for (int i = 0; i <= maxIndex && found <= index; i++) {
    if (data.charAt(i) == separator || i == maxIndex) {
      found++;
      strIndex[0] = strIndex[1] + 1;
      strIndex[1] = (i == maxIndex) ? i + 1 : i;
    }
  }
  return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}
