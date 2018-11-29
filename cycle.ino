void cycle(int x, int y)    //fonction de cyclage. Envoie HIGH pendant x millisecondes puis LOW pendant Y millis
{
  digitalWrite(valvePin,HIGH);
  delay(x);
  digitalWrite(valvePin,LOW);
  delay(y);
}
