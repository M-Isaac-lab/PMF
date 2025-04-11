// bibliothèque DHT d'Adafruit:
#include <DHT.h>;

#define DHTTYPE DHT22  // pour définir le type du capteur

//Déclaration des capteurs
DHT dhtint(2, DHTTYPE);
DHT dhtext(7, DHTTYPE);

int peltier = 4; //Le MOSFET canal N est sur la broche 4
const float temp_cons = 27.00;

void setup(){

Serial.begin(9600);
Serial.println("le test peut commencer!");
dhtint.begin();
dhtext.begin();

pinMode(peltier, OUTPUT);
}

void loop(){

//----graph-------
int y1 = digitalRead(2);
Serial.println(y1);
   
  // lecture des mesures du capteur
  //lecture de l'hygrométrie
  float humint = dhtint.readHumidity();
  float humext = dhtext.readHumidity();

  //lecture de la température
  float tempint = dhtint.readTemperature();
  float tempext = dhtext.readTemperature();

  // on s'assure qu'une mesure a été prise
  if (isnan(humint) || isnan(humext) || isnan(tempint) || isnan(tempext))
  {
    Serial.println("Le capteur n'a rien mesure! Est-il branche?");
    delay(3000);
    return;
  }

 // calcul du point de rosée  (formule de Heinrich Gustav Magnus-Tetens)
  float alpha = log(humint / 100) + (17.27 * tempint) / (237.3 + tempint);
  float pt_rosee = (237.3 * alpha) / (17.27 - alpha);

  //affichage :
  //Serial.print(tempint";"humint";"pt_rosee";"tempext";"humtext);
  
  // Affichages : 
  Serial.print("Temperature int: ");
  Serial.print(tempint);
  Serial.print(" °C\t ");

  Serial.print("Humidite int: ");
  Serial.print(humint);
  Serial.print(" %\t ");

  Serial.print("Point de rosee: ");
  Serial.print(pt_rosee);
  Serial.print(" °C\t ");

  Serial.print("Temperature ext: ");
  Serial.print(tempext);
  Serial.print(" °C\t ");

  Serial.print("Humidite ext: ");
  Serial.print(humext);
  Serial.println(" %\t ");

  delay(3000);
  
  /*if (tempint  <= temp_cons) {
  digitalWrite(peltier, LOW); 
  delay(5000);
  }
  else if (tempint > temp_cons) {
    Serial.println("allumage du module à effet peltier");*/
    digitalWrite(peltier, HIGH); 
  }
