/*Potansiyometrenin biri motor hızını kontrol edecek, pot ortadayken motor hızı 0, pot en soldayken
motor hızı saat tersi yönde maksimum, pot en sağdayken motor hızı saat yönünde maksimum olacak
ve potun diğer konumlarında ara hızlar görülecek. Motorun hızı aynı zamanda 4-5 bacakları
haricindeki 8 LED’e yansıtılacak. Şöyleki, pot ortadayken ortadaki iki LED yanacak, pot sola doğru
gittikçe ortadaki LED’lerden solda kalan ve motorun hızıyla orantılı olacak şekilde daha soldaki
LED’ler de yanacak. Benzer şekilde pot sağa doğru gittikçe ortadaki LED’lerden sağda kalan ve
motorun hızıyla orantılı olacak şekilde daha sağdaki LED’ler de yanacak.*/

int atop = 255 / 490;

void pinReset();
void setup() {
  pinMode (31, OUTPUT);
  pinMode (33, OUTPUT);
  pinMode (35, OUTPUT);
  pinMode (37, OUTPUT);
  pinMode (39, OUTPUT);
  pinMode (41, OUTPUT);
  pinMode (43, OUTPUT);
  pinMode (45, OUTPUT);

  pinMode (A0, INPUT);
  pinMode (10, OUTPUT);
  pinMode (9, OUTPUT);

  Serial.begin(115200);
}

void loop()
{
  int speed;
  int i;
  int j; 
  int pot = analogRead(A0);

  Serial.println(pot);

  if (pot >= 0 && pot < 490)
  {
    speed = 255 - (pot * atop);
    analogWrite(10, speed);
    pinReset();
    i = speed / 85 + 1;
    j = 0;
    while (i != 0)
    {
      digitalWrite(41 + j, 1);
      j+=2;
      i--;
    }
  }
  else if (pot >= 490 && pot <= 534)
  {
    speed = 0;
    analogWrite(10, speed);
    pinReset();
    digitalWrite(37, 1);
    digitalWrite(39, 1);
  }
  else if (pot > 534 && pot < 1024)
  {
    speed = (pot - 534) * atop;
    analogWrite(9, speed);
    pinReset();
    i = speed / 85 + 1;
    j = 0;
    while (i != 0)
    {
      digitalWrite(35 - j, 1);
      j+=2;
      i--;
    }
  }

}

void pinReset()
{
  digitalWrite (31, 0);
  digitalWrite (33, 0);
  digitalWrite (35, 0);
  digitalWrite (37, 0);
  digitalWrite (39, 0);
  digitalWrite (41, 0);
  digitalWrite (43, 0);
  digitalWrite (45, 0);
}
