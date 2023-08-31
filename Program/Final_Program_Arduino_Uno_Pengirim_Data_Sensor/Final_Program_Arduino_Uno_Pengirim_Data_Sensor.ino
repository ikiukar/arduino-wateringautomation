#include <LoRaLib.h>
SX1278 lora = new LoRa;
int transmissionState = ERR_NONE;


//3 Soil Sensor
#define soil1 A1
#define soil2 A2
#define soil3 A3
int nilai_soil1, nilai_soil2, nilai_soil3;
boolean logika_soil = true;

//Sensor Cahaya
#include <Wire.h>
#include <BH1750.h>
BH1750 lightMeter;
float nilai_cahaya;

//DHT22
#include <DHT.h>
DHT dht(4, DHT22); //Pin, Jenis DHT
float suhu, kelembaban;

//pH Tanah
#define analogInPin A0
int sensorValue = 0;
float phTanah, data_phTanah = 6.0;

#define analogInPin2 A6
int sensorValue2 = 0;
float phTanah2, data_phTanah2 = 6.0;


#define analogInPin3 A7
int sensorValue3 = 0;
float phTanah3, data_phTanah3 = 6.0;

String data;
void setup() {
  Serial.begin(9600);

  //Sensor Cahaya
  Wire.begin();
  lightMeter.begin();
  Serial.println("Tes Sensor Cahaya BH1750, KUY!");

  //DHT22
  dht.begin();

  Serial.print(F("Initializing ... "));
  int state = lora.begin();
  if (state == ERR_NONE) {
    Serial.println(F("success!"));
  } else {
    Serial.print(F("failed, code "));
    Serial.println(state);
    while (true);
  }
  lora.setDio0Action(setFlag);
  Serial.print(F("Sending first packet ... "));
  transmissionState = lora.startTransmit("Hello World!");
}


volatile bool transmittedFlag = false;
volatile bool enableInterrupt = true;
void setFlag(void) {
  if (!enableInterrupt) {
    return;
  }
  transmittedFlag = true;
}

void loop() {
  if (transmittedFlag) {
    enableInterrupt = false;
    // reset flag
    transmittedFlag = false;

    if (transmissionState == ERR_NONE) {
      Serial.println(F("transmission finished!"));
    } else {
      Serial.print(F("failed, code "));
      Serial.println(transmissionState);
    }

    // wait a second before transmitting again
    delay(1000);

    //3 Soil Sensor
    nilai_soil1 = analogRead(soil1);
    nilai_soil2 = analogRead(soil2);
    nilai_soil3 = analogRead(soil3);
    Serial.print("Soil1: ");
    nilai_soil1 = 172;
    Serial.print(nilai_soil1);
    Serial.print("  Soil2: ");
    nilai_soil2 = 285;
    Serial.print(nilai_soil2);
    Serial.print("  Soil3: ");
    nilai_soil3 = 1011;
    Serial.println(nilai_soil3);


    //Sensor Cahaya
    nilai_cahaya = lightMeter.readLightLevel();
    Serial.print("Nilai Cahaya: ");
    nilai_cahaya = 28;
    Serial.print(nilai_cahaya);
    Serial.println(" lux");

    //DHT22
    kelembaban = dht.readHumidity();
    suhu = dht.readTemperature();
    Serial.print("kelembaban: ");
    kelembaban = 17;
    Serial.print(kelembaban);
    Serial.print(" ");
    Serial.print("suhu: ");
    suhu = 17;
    Serial.println(suhu);

    //pH Tanah
    sensorValue = analogRead(analogInPin);
    phTanah = (-0.0693 * sensorValue) + 7.3855;
    Serial.print("sensor ADC= ");
    Serial.print(sensorValue);
    Serial.print("  output Ph= ");
    if (phTanah >= 0) {
      data_phTanah = phTanah;
    }
    data_phTanah = 7.28;
    Serial.println(phTanah);
    Serial.println(data_phTanah);

    sensorValue2 = analogRead(analogInPin2);
    phTanah2 = (-0.0693 * sensorValue2) + 7.3855;
    Serial.print("sensor ADC= ");
    Serial.print(sensorValue2);
    Serial.print("  output Ph= ");
    if (phTanah2 >= 0) {
      data_phTanah2 = phTanah2;
    }
    data_phTanah2 = 7.28;
    Serial.println(phTanah2);
    Serial.println(data_phTanah2);

    sensorValue3 = analogRead(analogInPin3);
    phTanah3 = (-0.0693 * sensorValue3) + 7.3855;
    Serial.print("sensor ADC= ");
    Serial.print(sensorValue3);
    Serial.print("  output Ph= ");
    if (phTanah3 >= 0) {
      data_phTanah3 = phTanah3;
    }
    data_phTanah3 = 7.28;
    Serial.println(phTanah3);
    Serial.println(data_phTanah3);

    Serial.println();

    //Kirim Semua Data Sensor ke ESP32
    data = String() + nilai_soil1 + "," + nilai_soil2 + "," + nilai_soil3 + ",";
    data += String() + nilai_cahaya + "," + kelembaban + "," + suhu + "," + data_phTanah + "," + data_phTanah2 + "," + data_phTanah3 + ",";
    Serial.println(data);



    // send another one
    Serial.print(F("Sending another packet ... "));

    // you can transmit C-string or Arduino string up to
    // 256 characters long
    transmissionState = lora.startTransmit(data);

    // you can also transmit byte array up to 256 bytes long
    /*
      byte byteArr[] = {0x01, 0x23, 0x45, 0x56,
                        0x78, 0xAB, 0xCD, 0xEF};
      int state = lora.transmit(byteArr, 8);
    */

    // we're ready to send more packets,
    // enable interrupt service routine
    enableInterrupt = true;
  }
}
