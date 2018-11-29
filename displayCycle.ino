void displayCycleState()    //affiche "Cycle: " puis l'état du cycle en fonciton des variables d'état
{
  lcd.setCursor(0,0);
  lcd.print("Cycle: ");
  if(running && !leakage)
  {
    lcd.print("ON  ");
  }
  else
  {
    if(leakage)
    {
      lcd.print("LEAK");
    }
    else
    {
      lcd.print("OFF ");
    }
  }
}
