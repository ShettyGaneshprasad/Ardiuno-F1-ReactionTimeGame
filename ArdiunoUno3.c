#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int red_pin = 10;
int blue_pin = 9;
int green_pin = 8;

int buttonState = 0;

int firstReactionTime = 0;
int secondReactionTime = 0;
int thirdReactionTime = 0;
int average = 0;

void SET_RGB_color(int red_value, int green_value, int blue_value)
{
  analogWrite(red_pin, red_value);
  analogWrite(green_pin, green_value);
  analogWrite(blue_pin, blue_value);
}

void randomWait()
{
  delay(random(2000, 10000));
}

void menu()
{
  lcd.setCursor(1, 0);
  lcd.print("Reaction  Test");
  lcd.setCursor(1, 1);
  lcd.print("Press To Start");
}

void ready()
{
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("Get Ready...");
  SET_RGB_color(255, 0, 0);
}

void firstAttempt()
{
  lcd.setCursor(6, 1);
  lcd.print("Go!!");
  SET_RGB_color(0, 255, 0);
  buttonState = digitalRead(1);
  while (buttonState == LOW)
  {
    firstReactionTime++;
    delay(1);
    buttonState = digitalRead(1);
  }
}

void secondAttempt()
{
  lcd.setCursor(6, 1);
  lcd.print("Go!!");
  SET_RGB_color(0, 255, 0);
  buttonState = digitalRead(1);
  while (buttonState == LOW)
  {
    secondReactionTime++;
    delay(1);
    buttonState = digitalRead(1);
  }
}

void thirdAttempt()
{
  lcd.setCursor(6, 1);
  lcd.print("Go!!");
  SET_RGB_color(0, 255, 0);
  buttonState = digitalRead(1);
  while (buttonState == LOW)
  {
    thirdReactionTime++;
    delay(1);
    buttonState = digitalRead(1);
  }
}

void firstAttemptResults()
{
  if (buttonState == HIGH)
  {
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("Reaction Time:");
    lcd.setCursor(5, 1);
    lcd.print(firstReactionTime);
    lcd.setCursor(9, 1);
    lcd.print("ms!");
  }
}

void secondAttemptResults()
{
  if (buttonState == HIGH)
  {
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("Reaction Time:");
    lcd.setCursor(5, 1);
    lcd.print(secondReactionTime);
    lcd.setCursor(9, 1);
    lcd.print("ms!");
  }
}

void thirdAttemptResults()
{
  if (buttonState == HIGH)
  {
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("Reaction Time:");
    lcd.setCursor(5, 1);
    lcd.print(thirdReactionTime);
    lcd.setCursor(9, 1);
    lcd.print("ms!");
  }
}

void finalAverageResult()
{
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Final Results:");
  lcd.setCursor(5, 1);
  average = (firstReactionTime + secondReactionTime + thirdReactionTime) / 3;
  lcd.print(average);
  lcd.setCursor(9, 1);
  lcd.print("ms");
}

void restart()
{
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("PRESS TO");
  lcd.setCursor(3, 1);
  lcd.print("PLAY AGAIN");
}

void setup()
{
  lcd.begin(16, 2);
  pinMode(1, INPUT);
  pinMode(red_pin, OUTPUT);
  pinMode(green_pin, OUTPUT);
  pinMode(blue_pin, OUTPUT);
  menu();
}

void loop()
{
  buttonState = digitalRead(1);
  if (buttonState == HIGH)
  {
    ready();
    randomWait();
    firstAttempt();
    firstAttemptResults();
    delay(1500);

    ready();
    randomWait();
    secondAttempt();
    secondAttemptResults();
    delay(1500);

    ready();
    randomWait();
    thirdAttempt();
    thirdAttemptResults();
    delay(1500);

    finalAverageResult();
    delay(2500);
    restart();
  }
  else
  {
    SET_RGB_color(0, 0, 255);
  }
}