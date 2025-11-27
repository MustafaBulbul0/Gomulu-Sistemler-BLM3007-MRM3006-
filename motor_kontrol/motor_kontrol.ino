/*Potansiyometrenin biri motor hızını kontrol edecek, pot ortadayken motor hızı 0, pot en soldayken
motor hızı saat tersi yönde maksimum, pot en sağdayken motor hızı saat yönünde maksimum olacak
ve potun diğer konumlarında ara hızlar görülecek. Motorun hızı aynı zamanda 4-5 bacakları
haricindeki 8 LED’e yansıtılacak. Şöyleki, pot ortadayken ortadaki iki LED yanacak, pot sola doğru
gittikçe ortadaki LED’lerden solda kalan ve motorun hızıyla orantılı olacak şekilde daha soldaki
LED’ler de yanacak. Benzer şekilde pot sağa doğru gittikçe ortadaki LED’lerden sağda kalan ve
motorun hızıyla orantılı olacak şekilde daha sağdaki LED’ler de yanacak.*/

void pinReset();
void turnLeft(int pot);
void turnRight(int pot);

void setup()
{
  int i = 31;

  while (i <= 45)
  {
    pinMode (i, OUTPUT);
    i += 2;
  }

  pinMode (8, OUTPUT);
  pinMode (9, OUTPUT);
  pinMode (10, OUTPUT);

  pinMode (A0, INPUT);

  Serial.begin(9600);
}

void loop()
{
  int pot = analogRead(A0);

  Serial.println(pot);

  if (0 <= pot && pot < 490)
    turnRight(pot);
  else if (534 < pot && pot <= 1023)
    turnLeft(pot);
  else
  {
      pinReset();
      digitalWrite(39, 1);
      digitalWrite(37, 1);
  }
  delay(10);
}

void turnRight(int pot)
{
  int speed = map(pot, 0, 489, 255, 0);
  int first = 35;
  int end = 31 + (pot / 80);

  pinReset();

  digitalWrite(8, 1);
  digitalWrite(9, 0);
  analogWrite(10, speed);

  while (first >= end)
  {
    digitalWrite(first, 1);
    first -= 2;
  }
}

void turnLeft(int pot)
{
  int n_pot = (pot - 534);
  int first = 41;
  int end = 41 + 2 * (n_pot / 160);
  int speed = map(pot, 535, 1023, 0, 255);

  pinReset();

  digitalWrite(8, 0);
  digitalWrite(9, 1);
  analogWrite(10, speed);
  
  while (first <= end)
  {
    digitalWrite(first, 1);
    first += 2;
  }
}

void pinReset()
{
  int i = 31;

  while (i <= 45)
  {
    digitalWrite (i, 0);
    i += 2;
  }
}
