/*Potansiyometrenin biri motor hızını kontrol edecek, pot ortadayken motor hızı 0, pot en soldayken
motor hızı saat tersi yönde maksimum, pot en sağdayken motor hızı saat yönünde maksimum olacak
ve potun diğer konumlarında ara hızlar görülecek. Motorun hızı aynı zamanda 4-5 bacakları
haricindeki 8 LED’e yansıtılacak. Şöyleki, pot ortadayken ortadaki iki LED yanacak, pot sola doğru
gittikçe ortadaki LED’lerden solda kalan ve motorun hızıyla orantılı olacak şekilde daha soldaki
LED’ler de yanacak. Benzer şekilde pot sağa doğru gittikçe ortadaki LED’lerden sağda kalan ve
motorun hızıyla orantılı olacak şekilde daha sağdaki LED’ler de yanacak.*/

int atop = 255 / 1023;

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
}

void loop()
{  
  int pot = analogRead(A0);
  if (pot >= 0 && pot < 490)
  {
    
  }
  else if (pot >= 490 && pot <= 530)
  {

  }
  else if (pot > 530 && pot < 1024)
  {

  }

}
