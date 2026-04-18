#define TRIG_L 12
#define ECHO_L 13
#define TRIG_R 10
#define ECHO_R 11

int EN1 = A4, IN1 = 5, IN2 = 4, EN2 = A5, IN3 = 7, IN4 = 8;
int ENA = 3, ENB = 6;
int truoc_R = A0, truoc_L = A1;
int sau_R = A2, sau_L = A3;
int trai = 2, phai = 9;
int sensor1, sensor2, sensor3, sensor4, sensor5, sensor6;

//khoang cach tim line
const int DISTANCE_THRESHOLD = 40;
//muc doc analog cua line
const int SENSOR_THRESHOLD = 500;
const int gan = 20;

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_L, OUTPUT);
  pinMode(ECHO_L, INPUT);
  pinMode(TRIG_R, OUTPUT);
  pinMode(ECHO_R, INPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(EN1, OUTPUT);
  pinMode(EN2, OUTPUT);
  digitalWrite(EN1, 1);
  digitalWrite(EN2, 1);
  pinMode(truoc_R, INPUT);
  pinMode(truoc_L, INPUT);
  pinMode(sau_R, INPUT);
  pinMode(sau_L, INPUT);
  pinMode(trai, INPUT);
  pinMode(phai, INPUT);
}

void loop() {
  int distanceLeft = khoangcach(TRIG_L, ECHO_L);
  int distanceRight = khoangcach(TRIG_R, ECHO_R);
  Serial.print(distanceLeft);
  Serial.print(" ");
  Serial.print(distanceRight);
  Serial.print(" ");
  find(distanceLeft,distanceRight);
  // Serial.print("sensor5: ");
  // Serial.println(sensor5);
  // Serial.print("sensor:6 ");
  // Serial.println(sensor6);
}

int khoangcach(int trig, int echo) {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(5);
  digitalWrite(trig, LOW);
  unsigned long duration = pulseIn(echo, HIGH);
  int distance = int(duration / 2 / 29.412);
  delay(10);
  return distance;
}

void tien() {
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void go_ahead(int speed) {
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void tiendoline(int speedA, int speedB) {
  Serial.println("tien.");
  analogWrite(ENA, speedA);
  analogWrite(ENB, speedB);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void lui() {
  digitalWrite(EN1, 1);
  digitalWrite(EN2, 1);
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void quaytraimanh() {
  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void quayphaimanh() {
  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void luidoline(int speedA, int speedB) {
  Serial.println("lui");
  analogWrite(ENA, speedA);
  analogWrite(ENB, speedB);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void quaytrai() {
  analogWrite(ENA, 130);
  analogWrite(ENB, 130);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void quayphai() {
  analogWrite(ENA, 180);
  analogWrite(ENB, 180);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void dung() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void doc_sensor() {
  sensor1 = analogRead(truoc_R);
  sensor2 = analogRead(truoc_L);
  sensor3 = analogRead(sau_R);
  sensor4 = analogRead(sau_L);
  sensor5 = digitalRead(trai);
  sensor6 = digitalRead(phai);
}

void line() {
  //   Serial.print("sensor1: ");
  // Serial.println(sensor1);
  // Serial.print("sensor2: ");
  // Serial.println(sensor2);
  // Serial.print("sensor3: ");
  // Serial.println(sensor3);
  // Serial.print("sensor4: ");
  // Serial.println(sensor4);
  if (sensor1 < SENSOR_THRESHOLD && sensor2 > SENSOR_THRESHOLD && sensor3 > SENSOR_THRESHOLD && sensor4 > SENSOR_THRESHOLD) {
    luidoline(255, 255);
    Serial.println("linetruoc");
    delay(250);
    quayphaimanh();
    delay(100);
  }

  else if (sensor1 > SENSOR_THRESHOLD && sensor2 < SENSOR_THRESHOLD && sensor3 > SENSOR_THRESHOLD && sensor4 > SENSOR_THRESHOLD) {
    luidoline(255, 255);
    Serial.println("linetruoc");
    delay(250);
    quaytraimanh();
    delay(100);
  }

  else if (sensor1 > SENSOR_THRESHOLD && sensor2 > SENSOR_THRESHOLD && sensor3 < SENSOR_THRESHOLD && sensor4 > SENSOR_THRESHOLD) {
    tiendoline(255, 255);
    Serial.println("linesau");
    delay(100);
  }

  else if (sensor1 > SENSOR_THRESHOLD && sensor2 > SENSOR_THRESHOLD && sensor3 > SENSOR_THRESHOLD && sensor4 < SENSOR_THRESHOLD) {
    tiendoline(255, 255);
    Serial.println("linesau");
    delay(100);
  }

  else if (sensor1 < SENSOR_THRESHOLD && sensor2 < SENSOR_THRESHOLD && sensor3 > SENSOR_THRESHOLD && sensor4 > SENSOR_THRESHOLD) {
    luidoline(255, 255);
    Serial.println("linetruoc");
    delay(250);
    quaytraimanh();
    delay(150);
  }

  else if (sensor1 > SENSOR_THRESHOLD && sensor2 > SENSOR_THRESHOLD && sensor3 < SENSOR_THRESHOLD && sensor4 < SENSOR_THRESHOLD) {
    tiendoline(255, 255);
    Serial.println("linesau");
    delay(100);
  }

  else if (sensor1 < SENSOR_THRESHOLD && sensor2 > SENSOR_THRESHOLD && sensor3 < SENSOR_THRESHOLD && sensor4 > SENSOR_THRESHOLD) {
    quaytrai();
    delay(150);
    tien();
    delay(100);
  }

  else if (sensor1 > SENSOR_THRESHOLD && sensor2 < SENSOR_THRESHOLD && sensor3 > SENSOR_THRESHOLD && sensor4 < SENSOR_THRESHOLD) {
    quayphai();
    delay(150);
    tien();
    delay(100);
  }

  else if (sensor1 < SENSOR_THRESHOLD && sensor2 > SENSOR_THRESHOLD && sensor3 > SENSOR_THRESHOLD && sensor4 < SENSOR_THRESHOLD) {
    quayphai();
    delay(150);
    tien();
    delay(100);
  }

  else if (sensor1 > SENSOR_THRESHOLD && sensor2 < SENSOR_THRESHOLD && sensor3 < SENSOR_THRESHOLD && sensor4 > SENSOR_THRESHOLD) {
    quaytrai();
    delay(150);
    tien();
    delay(100);
  }


  if (sensor1 < SENSOR_THRESHOLD || sensor2 < SENSOR_THRESHOLD) {
    luidoline(255, 255);
    Serial.println("linetruoc");
    delay(300);
    quaytraimanh();
    delay(100);
  }
  if (sensor3 < SENSOR_THRESHOLD || sensor4 < SENSOR_THRESHOLD) {
    tiendoline(255, 255);
    Serial.println("linesau");
    delay(250);
  }
}
void linetrang() {
  Serial.print("sensor1: ");
  Serial.println(sensor1);
  Serial.print("sensor2: ");
  Serial.println(sensor2);
  Serial.print("sensor3: ");
  Serial.println(sensor3);
  Serial.print("sensor4: ");
  Serial.println(sensor4);
  if (sensor1 > SENSOR_THRESHOLD && sensor2 < SENSOR_THRESHOLD && sensor3 < SENSOR_THRESHOLD && sensor4 < SENSOR_THRESHOLD) {
    luidoline(255, 255);
    Serial.println("linetruoc");
    delay(400);
    quayphaimanh();
    delay(150);
  }

  else if (sensor1 < SENSOR_THRESHOLD && sensor2 > SENSOR_THRESHOLD && sensor3 < SENSOR_THRESHOLD && sensor4 < SENSOR_THRESHOLD) {
    luidoline(255, 255);
    Serial.println("linetruoc");
    delay(400);
    quayphaimanh();
    delay(150);
  }

  else if (sensor1 < SENSOR_THRESHOLD && sensor2 < SENSOR_THRESHOLD && sensor3 > SENSOR_THRESHOLD && sensor4 < SENSOR_THRESHOLD) {
    quayphai();
    delay(150);
    Serial.println("linesau");
  }

  else if (sensor1 < SENSOR_THRESHOLD && sensor2 < SENSOR_THRESHOLD && sensor3 < SENSOR_THRESHOLD && sensor4 > SENSOR_THRESHOLD) {
    quaytrai();
    delay(150);
    Serial.println("linesau");
  }

  else if (sensor1 > SENSOR_THRESHOLD && sensor2 > SENSOR_THRESHOLD && sensor3 < SENSOR_THRESHOLD && sensor4 < SENSOR_THRESHOLD) {
    luidoline(255, 255);
    Serial.println("linetruoc");
    delay(400);
    quayphaimanh();
    delay(150);
  }

  else if (sensor1 < SENSOR_THRESHOLD && sensor2 < SENSOR_THRESHOLD && sensor3 > SENSOR_THRESHOLD && sensor4 > SENSOR_THRESHOLD) {
    tiendoline(255, 255);
    Serial.println("linesau");
    delay(400);
  }

  else if (sensor1 > SENSOR_THRESHOLD && sensor2 < SENSOR_THRESHOLD && sensor3 > SENSOR_THRESHOLD && sensor4 < SENSOR_THRESHOLD) {
    quaytrai();
    delay(150);
    tien();
    delay(100);
  }

  else if (sensor1  < SENSOR_THRESHOLD && sensor2 > SENSOR_THRESHOLD && sensor3 < SENSOR_THRESHOLD && sensor4 > SENSOR_THRESHOLD) {
    quayphai();
    delay(150);
    tien();
    delay(100);
  }

  // else if (sensor1 < SENSOR_THRESHOLD && sensor2 > SENSOR_THRESHOLD && sensor3 > SENSOR_THRESHOLD && sensor4 < SENSOR_THRESHOLD) {
  //   quayphai();
  //   delay(150);
  //   tien();
  //   delay(100);
  // }

  // else if (sensor1 > SENSOR_THRESHOLD && sensor2 < SENSOR_THRESHOLD && sensor3 < SENSOR_THRESHOLD && sensor4 > SENSOR_THRESHOLD) {
  //   quaytrai();
  //   delay(150);
  //   tien();
  //   delay(100);
  // }
}

void vatcan() {
  if (sensor5 == 0) {
    while (sensor5 == 0) {
      doc_sensor();
      linetrang();
      luidoline(255, 255);
      Serial.println(sensor5);
    }
    lui();
    delay(100);
  }
  if (sensor6 == 0) {
    while (sensor6 == 0) {
      doc_sensor();
      linetrang();
      luidoline(255, 255);
      Serial.println(sensor6);
    }
    lui();
    delay(100);
    quayphai();
    delay(150);
  }
}



void find(int distanceLeft, int distanceRight) {
  doc_sensor();
  vatcan();
  linetrang();
  if (distanceLeft <= DISTANCE_THRESHOLD && distanceRight >= DISTANCE_THRESHOLD) {
    quaytrai();
    linetrang();
    vatcan();
    Serial.println("quay trai");

    if (distanceLeft <= DISTANCE_THRESHOLD && distanceRight <= DISTANCE_THRESHOLD) {
      quayphaimanh();
      linetrang();
      vatcan();
      delay(40);
      while (distanceLeft <= DISTANCE_THRESHOLD && distanceRight <= DISTANCE_THRESHOLD) {
        doc_sensor();
        if(distanceLeft <= DISTANCE_THRESHOLD && distanceRight <= DISTANCE_THRESHOLD && ( sensor1 < SENSOR_THRESHOLD || sensor2 < SENSOR_THRESHOLD)){
          tien();
          Serial.println("tien");
        }
        else if(distanceLeft <= DISTANCE_THRESHOLD && distanceRight <= DISTANCE_THRESHOLD && ( sensor1 >= SENSOR_THRESHOLD || sensor2 >= SENSOR_THRESHOLD)  ){
          linetrang();
          vatcan();
        }
        distanceLeft = khoangcach(TRIG_L, ECHO_L);
        distanceRight = khoangcach(TRIG_R, ECHO_R);
      }
    } else if (distanceLeft <= gan || distanceRight <= gan) {
      while (distanceLeft <= gan || distanceRight <= gan) {
        doc_sensor();
        if(distanceLeft <= DISTANCE_THRESHOLD && distanceRight <= DISTANCE_THRESHOLD && ( sensor1 < SENSOR_THRESHOLD || sensor2 < SENSOR_THRESHOLD)){
          tien();
          Serial.println("tien");
        }
        else if(distanceLeft <= DISTANCE_THRESHOLD && distanceRight <= DISTANCE_THRESHOLD && ( sensor1 >= SENSOR_THRESHOLD || sensor2 >= SENSOR_THRESHOLD)  ){
          linetrang();
          vatcan();
        }
        distanceLeft = khoangcach(TRIG_L, ECHO_L);
        distanceRight = khoangcach(TRIG_R, ECHO_R);
      }
    }
  } else if (distanceRight <= DISTANCE_THRESHOLD && distanceLeft >= DISTANCE_THRESHOLD) {
    quayphai();
    linetrang();
    vatcan();
    Serial.println("quay phai");

    if (distanceLeft <= DISTANCE_THRESHOLD && distanceRight <= DISTANCE_THRESHOLD) {
      quaytraimanh();
      delay(40);
      linetrang();
      vatcan();
      while (distanceLeft <= DISTANCE_THRESHOLD && distanceRight <= DISTANCE_THRESHOLD) {
        doc_sensor();
        if(distanceLeft <= DISTANCE_THRESHOLD && distanceRight <= DISTANCE_THRESHOLD && ( sensor1 < SENSOR_THRESHOLD || sensor2 < SENSOR_THRESHOLD)){
          tien();
          Serial.println("tien");
        }
        else if(distanceLeft <= DISTANCE_THRESHOLD && distanceRight <= DISTANCE_THRESHOLD && ( sensor1 >= SENSOR_THRESHOLD || sensor2 >= SENSOR_THRESHOLD)  ){
          linetrang();
          vatcan();
        }
        distanceLeft = khoangcach(TRIG_L, ECHO_L);
        distanceRight = khoangcach(TRIG_R, ECHO_R);
      }
    } else if (distanceLeft <= gan || distanceRight <= gan) {
      while (distanceLeft <= gan || distanceRight <= gan) {
        doc_sensor();
        if(distanceLeft <= DISTANCE_THRESHOLD && distanceRight <= DISTANCE_THRESHOLD && ( sensor1 < SENSOR_THRESHOLD || sensor2 < SENSOR_THRESHOLD)){
          tien();
          Serial.println("tien");
        }
        else if(distanceLeft <= DISTANCE_THRESHOLD && distanceRight <= DISTANCE_THRESHOLD && ( sensor1 >= SENSOR_THRESHOLD || sensor2 >= SENSOR_THRESHOLD)  ){
          linetrang();
          vatcan();
        }
        distanceLeft = khoangcach(TRIG_L, ECHO_L);
        distanceRight = khoangcach(TRIG_R, ECHO_R);
      }
    }
  } else if (distanceRight >= DISTANCE_THRESHOLD && distanceLeft >= DISTANCE_THRESHOLD) {
    quaytrai();
    Serial.println("quay trai");
    doc_sensor();
    linetrang();
    vatcan();
  } else if (distanceLeft <= DISTANCE_THRESHOLD && distanceRight <= DISTANCE_THRESHOLD) {
    if (distanceRight > distanceLeft) {
      quaytrai();
      Serial.println("quay trai");
      doc_sensor();
      vatcan();
      linetrang();
    }
    if (distanceRight < distanceLeft) {
      quayphai();
      Serial.println("quay phai");
      doc_sensor();
      linetrang();
      vatcan();
    }
    doc_sensor();
    if(distanceLeft <= DISTANCE_THRESHOLD && distanceRight <= DISTANCE_THRESHOLD && ( sensor1 < SENSOR_THRESHOLD || sensor2 < SENSOR_THRESHOLD)){
          tien();
          Serial.println("tienh");
        }
        else if(distanceLeft <= DISTANCE_THRESHOLD && distanceRight <= DISTANCE_THRESHOLD && ( sensor1 >= SENSOR_THRESHOLD || sensor2 >= SENSOR_THRESHOLD)  ){
          linetrang();
          vatcan();
        }
  }
}


