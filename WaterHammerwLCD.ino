#include <LiquidCrystal.h>
//Le pinout est pour un Arduino Mega avec le LCD Keypad Shield monté dessus

//Déclaration des numéros de pins. Préférablement utiliser les Analog vu qu'il y a le shield ...

int valvePin = A8;        //la valve est placée sur A8 en mode digital
int buttonPin = A0;       // on lit le bouton sur A0 en analog
int leak_wirePin = A9;    // le fil de détection d'une fuite...

boolean running=false;    //Cycle en cours ou interrompu
boolean leakage = false;    //Présence de fuite ou pas

int counter = 0;
unsigned long cycle_number = 500000;
float progress = 0.0;

LiquidCrystal lcd(8,9,4,5,6,7);    //Initialisation du lcd

void setup()
{
  pinMode(valvePin,OUTPUT);
  pinMode(leak_wirePin,INPUT);
  lcd.begin(16,2);    //creation du premier curseur
}

void loop()
{
  //lcd.clear();
  displayCycleState();    //Fonctions de mise à jour de l'écran
  displayProgress();
  if(running == false)    //Cycle STOP, en attente du bouton
  {
    if(button())    //bouton enfoncé, on passe en running et reset de l'indicateur de fuite
    {
      while(button()){}
      running = true;
      leakage = false;
    }
  }
  else    //Si le cycle est en running...
  {
    if(leak())    //polling pour savoir s'il y a une fuite
    {
      running = false;
      leakage = true;
      digitalWrite(valvePin,LOW);    //On arrete le cycle, on ferme la valve par securite
    }
    else
    {
      if(counter<cycle_number)
      {
        cycle(10,10);
        counter++;
        progress = 100.0*(float)counter/(float)cycle_number;
      }
    }
    if(button())    //Polling du bouton pour savoir s'il faut mettre en pause ou non. A ce stade un cycle a été complété, la valve est FERMÉE
    {
      while(button()){}
      running = false;
    }
   }
}

