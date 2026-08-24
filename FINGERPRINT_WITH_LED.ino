#include <Adafruit_Fingerprint.h>
int  a = 0;
int  b = 0;
int  c = 0;
int Sw1 = 6;
int Sw2 = 7;
int Sw3 = 8;
int Sw4 = 9;

#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3);

Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

void setup()
{
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(Sw1, INPUT_PULLUP);
  pinMode(Sw2, INPUT_PULLUP);
  pinMode(Sw3, INPUT_PULLUP);
  pinMode(Sw4, INPUT_PULLUP);
  Serial.begin(9600);
  while (!Serial);
  delay(100);

  finger.begin(57600);

  if (finger.verifyPassword()) {
    Serial.println("election starts from now!!!");
    Serial.println("you are requested to caste your vote");
  } else {
    Serial.println("election has been stoped :(");    while (1) {
      delay(1);
    }
  }

  finger.getTemplateCount();

}

void loop()                     // run over and over again
{
  if (digitalRead(Sw1) == 0)
  {
    getFingerprintIDez();
    delay(50);            //don't ned to run this at full speed.
    digitalWrite(5, HIGH);
  }
  if (digitalRead(Sw2) == 0)
  {
    getFingerprintIDez1();
    delay(50);            //don't ned to run this at full speed.
    digitalWrite(5, HIGH);
  }
  if (digitalRead(Sw3) == 0)
  {
    getFingerprintIDez2();
    delay(50);            //don't ned to run this at full speed.
    digitalWrite(5, HIGH);
  }
  if (digitalRead(Sw4) == 0)
  {
    Serial.println("final results of the election");
    Serial.print("vote for a =");
    Serial.println(a);
    Serial.print("vote for b =");
    Serial.println(b);
    Serial.print("vote for c =");
    Serial.println(c);
     if (a > b & a > c) {
      Serial.print("party A wins by:");
      if (b > c) {
        Serial.println(a - b);
      }
      else {
        Serial.println(a - c);
      }
    }
    if (b > a & b > c) {
      Serial.print("party B wins by:");
      if (a > c) {
        Serial.println(b - a);
      }
      else {
        Serial.println(b - c);
      }
    }
    if (c > b & c > a) {
      Serial.print("party C wins by: ");
      if (b > a) {
        Serial.println(c - b);
      }
      else {
        Serial.println(c - a);
      }
    }
    delay(5000);
  }
}

uint8_t getFingerprintID() {
  uint8_t p = finger.getImage();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
      Serial.print("finger not detected");
      Serial.println("No finger detected");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.print("error in communication");
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Imaging error");
      return p;
    default:
      Serial.print("an unknown error");
      Serial.println("Unknown error");
      return p;
  }

  // OK success!

  p = finger.image2Tz();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.print("finger print matched");
      Serial.println("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.print("finger print position too messy");
      Serial.println("Image too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.print("communication error");
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      Serial.print("finger print features not found");
      Serial.println("Could not find fingerprint features");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.print("finger print not matched");
      Serial.println("Could not find fingerprint features");
      return p;
    default:
      Serial.print("error is unknown");
      Serial.println("Unknown error");
      return p;
  }

  // OK converted!
  p = finger.fingerFastSearch();
  if (p == FINGERPRINT_OK) {
    Serial.print("found a print match finger print");
    Serial.println("Found a print match!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Communication error");
    return p;
  } else if (p == FINGERPRINT_NOTFOUND) {
    Serial.print("Did not find a match finger print");
    Serial.println("Did not find a match");
    return p;

  } else {
    Serial.print("error is unknown");
    Serial.println("Unknown error");
    return p;
  }

  // found a match!
  Serial.print("Found ID #"); Serial.print(finger.fingerID);
  Serial.print(" with confidence of "); Serial.println(finger.confidence);

  return finger.fingerID;
}

// returns -1 if failed, otherwise returns ID #
int getFingerprintIDez() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  return -1;

  // found a match!
  digitalWrite(5, LOW);
  a = a + 1;
  digitalWrite(4, HIGH);

  digitalWrite(4, LOW);

  Serial.print("PARTY a="); Serial.println(a);
  return finger.fingerID;
  delay(5000);
}
int getFingerprintIDez1() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  return -1;

  // found a match!
  digitalWrite(5, LOW);
  b = b + 1;
  digitalWrite(4, HIGH);

  digitalWrite(4, LOW);

  Serial.print("PARTY b="); Serial.println(b);
  return finger.fingerID;
  delay(5000);
}
int getFingerprintIDez2() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  return -1;

  // found a match!
  digitalWrite(5, LOW);
  c = c + 1;
  digitalWrite(4, HIGH);

  digitalWrite(4, LOW);

  Serial.print("PARTY c="); Serial.println(c);
   
 
  return finger.fingerID;
  delay(5000);
}
