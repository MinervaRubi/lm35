// Programa: Ejemplo de lectura analógica con LM35

const int LED = 3;          // El LED está conectado al pin 3
const int lm35 = A0;        // El sensor LM35 está conectado al pin analógico A0
int intensidad;             // Variable para la intensidad de brillo
float temperatura;          // Variable para almacenar la temperatura en grados Celsius

void setup() {
  // Configuramos el pin del LED como salida
  pinMode(LED, OUTPUT);  
}

void loop() {
  // Leemos el valor analógico del LM35
  int lecturaAnalogica = analogRead(lm35);

  // Convertimos la lectura a temperatura en grados Celsius
  // Fórmula: temperatura = (lectura * 5.0 / 1024) * 100
  temperatura = (lecturaAnalogica * 5.0 / 1024.0) * 100;

  // Normalizamos la temperatura para ajustar el brillo del LED
  // Suponemos un rango de temperatura entre 0°C y 50°C
  if (temperatura > 50) {
    temperatura = 50; // Limitar la temperatura máxima
  }
  intensidad = map(temperatura, 0, 50, 0, 255); // Escalamos a rango 0-255

  // Ajustamos el brillo del LED
  analogWrite(LED, intensidad);

  // Opcional: Añadimos un pequeño retraso para estabilizar la lectura
  delay(100);
}
