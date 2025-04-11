#include "DHT.h"

// broche ou l'on a branché le capteur
#define DHTPIN 2 

// DHT 22 (AM2302)
#define DHTTYPE DHT22 


//déclaration du capteur
DHT capteur1(2, DHT22);
DHT capteur2 (7, DHT22);
DHT capteur3 (8, DHT22);

const float temp_cons = 28.70; 
int peltier = 4 ;


/*int in = A0;  // broche ou l'on a brnché la diode
const int t0 = 20.3;
const int vf0 = 573.44;
const float Vref = 1076.50;
int i;
float dtemp, dtemp_avg, t;*/


 
void setup()
{
  
/* analogReference(INTERNAL); */
 Serial.begin(9600);
/* pinMode(in, INPUT_PULLUP); */
 Serial.println("DHTxx test!");
 capteur1.begin();
 capteur2.begin();
 capteur3.begin();
 pinMode(peltier, OUTPUT);
}


void loop(){
/*  delay(2000);
  dtemp_avg = 0;
  for (i = 0; i < 1024; i++){
    float vf = analogRead(A0) * (Vref / 1023);
    dtemp = (vf - vf0) * 0.4545454;
    dtemp_avg = dtemp_avg + dtemp;
  }
  t = t0 - (dtemp_avg / 1024);
*/
  
 delay(2000);

 digitalWrite(peltier, HIGH);

 //on lit l'hygrometrie
 float hum1 = capteur1.readHumidity();
 float hum2 = capteur2.readHumidity();
 float hum3 = capteur3.readHumidity();

 //on lit la temperature en celsius 
 float temp1 = capteur1.readTemperature();
 float temp2 = capteur2.readTemperature();
 float temp3 = capteur3.readTemperature();
 
 //On verifie si la lecture a echoue, si oui on quitte la boucle pour recommencer.
 if (isnan(hum1) || isnan(temp1) || isnan(hum2) || isnan(temp2) || isnan(hum3) || isnan(temp3))
 {
   Serial.println("Le capteur n'a rien mesure! Est-il branche?");
   delay(2000);
   return;
 }

  if( temp1 >= temp_cons ){
    digitalWrite(peltier, LOW);
    Serial.print("Frigo OFF\t"); 
    delay(5000);
  }
  else {
    digitalWrite(peltier, HIGH);
    Serial.print("Frigo ON\t");
  }


 //Calcul du point de rosé
 float alpha = log(hum1 / 100) + (17.27 * temp1) / (237.3 + temp1);
 float pt_rosee = (237.3 * alpha) / (17.27 - alpha);
 
 //Affichages :
 Serial.print("Temperature int : ");
 Serial.print(temp1);
 Serial.print(" °C\t ");
 Serial.print("Humidite: ");
 Serial.print(hum1);
 Serial.print(" %\t ");
 Serial.print("Point de rosee: ");
 Serial.print(pt_rosee);
 Serial.print( " °C\t ");
 Serial.print("Temperature ext : ");
 Serial.print(temp2);
 Serial.print(" °C\t ");*/
 Serial.print("Temperature canette : ");
 Serial.print(temp3);
 Serial.println(" °C ");*/
 

}
