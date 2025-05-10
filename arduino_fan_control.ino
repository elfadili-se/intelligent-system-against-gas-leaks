// Définition des broches et constantes
#define gasSensorPin A0  // Pin analogique où le capteur est connecté
#define RO 10.0          // Résistance de référence (RO) du capteur en air pur (en Kohms)
#define fanPin 9         // Broche PWM pour contrôler le ventilateur

void setup() {
  pinMode(fanPin, OUTPUT);     // Configurer la broche du ventilateur en sortie
  Serial.begin(9600);          // Initialiser la communication série
}

void loop() {
  // Lire la valeur brute du capteur
  int sensorValue = analogRead(gasSensorPin);

  // Convertir la valeur brute en tension
  float voltage = sensorValue * (5.0 / 1023.0);

  // Calculer la résistance du capteur (RS)
  float RS = ((5.0 - voltage) / voltage) * RO;

  // Calculer la concentration de gaz en PPM
  float ppm = pow(10, (2.3 * (log10(RS / RO)) - 0.2) / -0.45);

  // Afficher la concentration de gaz sur le moniteur série
  Serial.print("Concentration de gaz en PPM : ");
  Serial.println(ppm);

  // Contrôler la vitesse du ventilateur en fonction de la concentration de gaz
  int pwm = 0; // Initialiser la valeur PWM du ventilateur
  if (ppm < 10) {
    pwm = 0; // Ventilateur éteint pour faible concentration
  } else if (ppm >= 10 && ppm <= 500) {
    pwm = 0.045555 * ppm + 47.0556; // Vitesse proportionnelle à la concentration
  } else {
    pwm = 255; // Pleine vitesse pour haute concentration
  }

  // Appliquer la vitesse calculée au ventilateur
  analogWrite(fanPin, pwm);

  // Attendre 1 seconde avant la prochaine mesure
  delay(1000);
}
