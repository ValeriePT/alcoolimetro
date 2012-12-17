/*
  Projecto Arduino - Alcoolimetro
*/

const int pAnalogic0 = A0;
int firstTime = 1;
const int pDigital7 = 7;
int vIni = 0;
int vfinal = 0;

void setup()
{
  Serial.begin(9600); // open a serial connection to your computer
  pinMode(pDigital7, INPUT);

}

void loop() 
{
  if (firstTime == 1)
  {
    Serial.print("A iniciar");
    for (int seg=30; seg >= 0; seg--)
    {
      Serial.print("..");
      Serial.print(seg);
      delay(1000);
      if (seg == 0)
      {
        vIni = analogRead(pAnalogic0);
        firstTime = 0;
      }
    }
  }
  int vDigital7 = digitalRead(pDigital7);
  double vAnalogic0 = analogRead(pAnalogic0);
  Serial.print("\n");
  Serial.print("Alcool: ");
  Serial.print(vDigital7);
  Serial.print(" - ");
  Serial.print("Valor alcool: ");
  double vAlcool = vAnalogic0 - vIni;
  Serial.print(vAlcool);
  Serial.print(" - Percentagem: ");
  double percAlcool = vAlcool / 1000;
  Serial.print(percAlcool);
  delay(1000);
}
