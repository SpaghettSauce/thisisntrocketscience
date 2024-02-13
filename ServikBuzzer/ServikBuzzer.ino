//сервомотор, мотор на 180 градусов 
//провода: коричневый(черный) - земля, красный - плюс, желтый - управление
//для сервика используем электрические конденсатор (черный цилиндр, ножка минус короче)
//конденсатор это по сути мини аккумулятор, он хранит в себе заряд, а потом дает больше тока чтоб двигать сервик

//сервик, крутящийся в зависимости от потенциометра, если достигает максимума или минимума то писщит сигналка

#include <Servo.h>

#define Buzzer 8 // пин для пищалки
#define Max_Angle 270.0 //максимальный угол потенциометра
Servo Servik; //объявляем переменную сервик, будем к ней обращаться для любое действия с ним

void setup() {
  pinMode(Buzzer,OUTPUT);// пин выхода для пищалки
  Servik.attach(9);//attach это по сути PinMode для сервика
}

void loop() {
  int val = analogRead(A0);//в val будет потенциометр
  int angle = int(val/1024.0 * Max_Angle); //вычисляем угол поворота потенциометра
  angle = constrain(angle,0,180);//у потенциометра 360 градусов, у сервика 180, о оу, задаем границы
  Servik.write(angle);//подаем сервику на какой угол крутиться
  if (angle == 180 || angle == 0){ //если угол максимальный или минимальный
    int frequency = 3500 + 500;//пищи на этой тональности(+ пойнты если подберешь самый ужасный )
    tone(Buzzer,frequency,20); //подаем пищалке тональность,20 миллисекунд
  }

}

