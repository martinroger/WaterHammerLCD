void displayProgress()    //affiche le degré de progrès sur la ligne inférieure
{
  lcd.setCursor(0,1);
  lcd.print("Prog: ");
  lcd.print(progress);
  lcd.print("%");
  lcd.print("  ");
}
