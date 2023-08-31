#include <Servo.h>

#define dirPin 5
#define YdirPin 6
#define stepPin 2
#define YstepPin 3
#define stepsPerRevolution 2000
#define YstepsPerRevolution 1000
#define RelayPin 7

int steptest = 500;
int lamasiram = 1000;

void setup() {
  
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(YstepPin, OUTPUT);
  pinMode(YdirPin, OUTPUT);
  pinMode(RelayPin, OUTPUT);
  pinMode(8, OUTPUT);
  digitalWrite(RelayPin, LOW);
  //digitalWrite(8, LOW); // aktif
  digitalWrite(8, HIGH); // non aktif
  delay(5000);

}

void loop() {
  
  //ujimekanik();
  //tesjarak();
  //tesxpos();
  //tesxmin();
  //tesypos();
  //tesymin();

  //algo1();
  //algo2();
  //algo2();
  //algo2();
  //algo2();
  //algo2();
  //algo2();
  //algo2();

}

void algo1() {
  tanaman1();
  tanaman2();
  tanaman3();
  tanaman12();
  tanaman13();
  tanaman23();
  tanaman123();
}

void algo2() {
  delay(2000);

  //tanaman 1
  digitalWrite(8, LOW); // aktif
  digitalWrite(dirPin, HIGH);
  for (int i = 0; i < 1000; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
  }
  digitalWrite(8, HIGH); // non aktif
  delay(1000);

  //tanaman 2
  digitalWrite(8, LOW); // aktif
  digitalWrite(dirPin, HIGH);
  for (int i = 0; i < 1000; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
  }
  digitalWrite(8, HIGH); // non aktif
  delay(1000);

  //tanaman 3
  digitalWrite(8, LOW); // aktif
  digitalWrite(dirPin, HIGH);
  for (int i = 0; i < 1000; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
  }
  digitalWrite(8, HIGH); // non aktif
  delay(1000);

  digitalWrite(8, LOW); // aktif
  digitalWrite(dirPin, LOW);
  for (int i = 0; i < 3000; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
  }
  digitalWrite(8, HIGH); // non aktif
  delay(1000);
}

void tesjarak() {
  delay(2000);
  digitalWrite(8, LOW); // aktif
  digitalWrite(YdirPin, HIGH);
  for (int i = 0; i < steptest; i++) {
    // These four lines result in 1 step:
    digitalWrite(YstepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(YstepPin, LOW);
    delayMicroseconds(500);
  }
  digitalWrite(8, HIGH); // non aktif
  delay(15000);
  digitalWrite(8, LOW); // aktif
  digitalWrite(YdirPin, LOW);
  for (int i = 0; i < steptest; i++) {
    // These four lines result in 1 step:
    digitalWrite(YstepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(YstepPin, LOW);
    delayMicroseconds(500);
  }
  digitalWrite(8, HIGH); // non aktif
  delay(10000);
}

void tesxpos() {
  digitalWrite(8, LOW); // aktif
  digitalWrite(dirPin, HIGH);
  for (int i = 0; i < stepsPerRevolution; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
  }
  digitalWrite(8, HIGH); // non aktif
  delay(1000);
}

void tesxmin() {
  digitalWrite(8, LOW); // aktif
  digitalWrite(dirPin, LOW);
  for (int i = 0; i < stepsPerRevolution; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
  }
  digitalWrite(8, HIGH); // non aktif
  delay(1000);
}

void tesypos() {
  digitalWrite(8, LOW); // aktif
  digitalWrite(YdirPin, LOW);
  for (int i = 0; i < YstepsPerRevolution; i++) {
    // These four lines result in 1 step:
    digitalWrite(YstepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(YstepPin, LOW);
    delayMicroseconds(500);
  }
  digitalWrite(8, HIGH); // non aktif
  delay(1000);
}

void tesymin() {
  digitalWrite(8, LOW); // aktif
  digitalWrite(YdirPin, HIGH);
  for (int i = 0; i < YstepsPerRevolution; i++) {
    // These four lines result in 1 step:
    digitalWrite(YstepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(YstepPin, LOW);
    delayMicroseconds(500);
  }
  digitalWrite(8, HIGH); // non aktif
  delay(1000);
}

void ujimekanik() {

  siram();
  ybawah();
  siram();
  yatas();
 
  xkanan();
  siram();
  ybawah();
  siram();
  yatas();
 
  xkanan();
  siram();
  ybawah();
  siram();
  yatas();

  xkanan();
  siram();
  ybawah();
  siram();
  yatas();
 
  xkanan();
  siram();
  ybawah();
  siram();
  yatas();

  xkiri();


delay(100000);

}

void siram() {
  digitalWrite(RelayPin, HIGH);
  delay(lamasiram);
  digitalWrite(RelayPin, LOW);
}

void ybawah() {
  digitalWrite(8, LOW); // aktif
  digitalWrite(YdirPin, HIGH);
  for (int i = 0; i < YstepsPerRevolution; i++) {
    // These four lines result in 1 step:
    digitalWrite(YstepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(YstepPin, LOW);
    delayMicroseconds(500);
  }
  digitalWrite(8, HIGH); // non aktif
  delay(1000);
}

void yatas() {
  digitalWrite(8, LOW); // aktif
  digitalWrite(YdirPin, LOW);
  for (int i = 0; i < YstepsPerRevolution; i++) {
    // These four lines result in 1 step:
    digitalWrite(YstepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(YstepPin, LOW);
    delayMicroseconds(500);
  }
  digitalWrite(8, HIGH); // non aktif
  delay(1000);
}

void xkanan() {
  digitalWrite(8, LOW); // aktif
  digitalWrite(dirPin, HIGH);
  for (int i = 0; i < stepsPerRevolution; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
  }
  digitalWrite(8, HIGH); // non aktif
  delay(1000);
}

void xkiri() {
  digitalWrite(8, LOW); // aktif
  digitalWrite(dirPin, LOW);
  for (int i = 0; i < 4000; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
  }
  digitalWrite(8, HIGH); // non aktif
  delay(1000);
}

void tanaman1() {
  Serial.println("Menyiram tanaman 1...");
  delay(2000);
  digitalWrite(8, LOW); // aktif
  digitalWrite(dirPin, HIGH);
  for (int i = 0; i < 1000; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
  }
  digitalWrite(8, HIGH); // non aktif
  delay(1000);
  digitalWrite(8, LOW); // aktif
  digitalWrite(dirPin, LOW);
  for (int i = 0; i < 1000; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
  }
  digitalWrite(8, HIGH); // non aktif
  delay(1000);
}

void tanaman2() {
  Serial.println("Menyiram tanaman 2...");
  delay(2000);
  digitalWrite(8, LOW); // aktif
  digitalWrite(dirPin, HIGH);
  for (int i = 0; i < 2000; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
  }
  digitalWrite(8, HIGH); // non aktif
  delay(1000);
  digitalWrite(8, LOW); // aktif
  digitalWrite(dirPin, LOW);
  for (int i = 0; i < 2000; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
  }
  digitalWrite(8, HIGH); // non aktif
  delay(1000);
}

void tanaman3() {
  Serial.println("Menyiram tanaman 3...");
  delay(2000);
  digitalWrite(8, LOW); // aktif
  digitalWrite(dirPin, HIGH);
  for (int i = 0; i < 3000; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
  }
  digitalWrite(8, HIGH); // non aktif
  delay(1000);
  digitalWrite(8, LOW); // aktif
  digitalWrite(dirPin, LOW);
  for (int i = 0; i < 3000; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
  }
  digitalWrite(8, HIGH); // non aktif
  delay(1000);
}

void tanaman12() {
  Serial.println("Menyiram tanaman 1 & 2...");
  delay(2000);
  digitalWrite(8, LOW); // aktif
  digitalWrite(dirPin, HIGH);
  for (int i = 0; i < 1000; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
  }
  digitalWrite(8, HIGH); // non aktif
  delay(1000);
  digitalWrite(8, LOW); // aktif
  digitalWrite(dirPin, HIGH);
  for (int i = 0; i < 1000; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
  }
  digitalWrite(8, HIGH); // non aktif
  delay(1000);
  digitalWrite(8, LOW); // aktif
  digitalWrite(dirPin, LOW);
  for (int i = 0; i < 2000; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
  }
  digitalWrite(8, HIGH); // non aktif
  delay(1000);
}

void tanaman13() {
  Serial.println("Menyiram tanaman 1 & 3...");
  delay(2000);
  digitalWrite(8, LOW); // aktif
  digitalWrite(dirPin, HIGH);
  for (int i = 0; i < 1000; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
  }
  digitalWrite(8, HIGH); // non aktif
  delay(1000);
  digitalWrite(8, LOW); // aktif
  digitalWrite(dirPin, HIGH);
  for (int i = 0; i < 2000; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
  }
  digitalWrite(8, HIGH); // non aktif
  delay(1000);
  digitalWrite(8, LOW); // aktif
  digitalWrite(dirPin, LOW);
  for (int i = 0; i < 3000; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
  }
  digitalWrite(8, HIGH); // non aktif
  delay(1000);
}

void tanaman23() {
  Serial.println("Menyiram tanaman 2 & 3...");
  delay(2000);
  digitalWrite(8, LOW); // aktif
  digitalWrite(dirPin, HIGH);
  for (int i = 0; i < 2000; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
  }
  digitalWrite(8, HIGH); // non aktif
  delay(1000);
  digitalWrite(8, LOW); // aktif
  digitalWrite(dirPin, HIGH);
  for (int i = 0; i < 1000; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
  }
  digitalWrite(8, HIGH); // non aktif
  delay(1000);
  digitalWrite(8, LOW); // aktif
  digitalWrite(dirPin, LOW);
  for (int i = 0; i < 3000; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
  }
  digitalWrite(8, HIGH); // non aktif
  delay(1000);
}

void tanaman123() {
  Serial.println("Menyiram tanaman 1, 2, dan 3...");
  delay(2000);
  digitalWrite(8, LOW); // aktif
  digitalWrite(dirPin, HIGH);
  for (int i = 0; i < 1000; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
  }
  digitalWrite(8, HIGH); // non aktif
  delay(1000);
  digitalWrite(8, LOW); // aktif
  digitalWrite(dirPin, HIGH);
  for (int i = 0; i < 1000; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
  }
  digitalWrite(8, HIGH); // non aktif
  delay(1000);
  digitalWrite(8, LOW); // aktif
  digitalWrite(dirPin, HIGH);
  for (int i = 0; i < 1000; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
  }
  digitalWrite(8, HIGH); // non aktif
  delay(1000);
  digitalWrite(8, LOW); // aktif
  digitalWrite(dirPin, LOW);
  for (int i = 0; i < 3000; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
  }
  digitalWrite(8, HIGH); // non aktif
  delay(1000);
}
