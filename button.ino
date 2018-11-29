boolean button()    //la fonction retourne vrai si le bouton a été enfoncé. Ca affiche brièvement "BUTTON" pour le débug si nécessaire
{
  if(analogRead(buttonPin) < 1022)
  {
    //lcd.clear();
    //lcd.print("BUTTON");
    return true;
  }
  else
  {
    return false;
  }
}

