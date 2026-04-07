#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int trigPin = 9;
const int echoPin = 10;
const int rPin = 3;
const int gPin = 5;
const int bPin = 6;
const int buzzerPin = 11;

void setup()
{
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.setContrast(255);
  lcd.print("READY");
  delay(1000);
  lcd.clear();
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(rPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(bPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  // 1. MESAFE ÖLÇÜMÜ
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long sure = pulseIn(echoPin, HIGH);
  int mesafe = sure * 0.034 / 2;
  
  lcd.setCursor(0, 0);
  lcd.print("Mesafe: ");
  lcd.print(mesafe);
  lcd.print(" cm             ");
  
  lcd.setCursor(0, 1);
  
  // 2. RENK KARARI (Profesyonel Mantık)
  if (mesafe < 2 || mesafe > 330){// Kör Nokta ve Sınır Kontrolü
  	lcd.print("ERROR!          ");
    RenkAyarla(0, 0, 255);
    noTone(buzzerPin);
  }
  else if (mesafe > 50) {
    RenkAyarla(0, 255, 0); // Güvenli: YEŞİL
    lcd.print("CLEAR           ");
    noTone(buzzerPin);
  } 
  else if (mesafe <= 50 && mesafe > 20) {
    RenkAyarla(255, 255, 0); // Dikkat: SARI
    lcd.print("CAUTION!        ");
    BipSesi(mesafe * 10);
  } 
  else {
    RenkAyarla(255, 0, 0); // Tehlike: KIRMIZI
    lcd.print("STOP!           ");
    tone(buzzerPin, 200);
    delay(100);
  }

  Serial.print("Mesafe: ");
  Serial.println(mesafe);
  delay(20);
}

void RenkAyarla(int r, int g, int b){
	analogWrite(rPin, r);
  	analogWrite(bPin, b);
  	analogWrite(gPin, g);	
}

void BipSesi(float bekleme){
	tone(buzzerPin, 200);
  	delay(bekleme * 0.4);
  	noTone(buzzerPin);
  	delay(bekleme);
}
