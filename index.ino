#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // La longueur de l'écran, en pixels
#define SCREEN_HEIGHT 64 // La hauteur de l'écran, en pixels

// Declaration d'un objet de type Adafruit_SSD1306
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

int bp1 = 2;
int bp2 = 3;
unsigned long val10;
unsigned t = 100;
unsigned long previousMillis = 0; // Initialisation de la variable qui servira à stocker le dernier temps
const long interval = 100;   // Intervalle de temps entre deux mesures

void setup() {
    pinMode(bp1, INPUT);
    pinMode(bp2, INPUT);

    Serial.begin(115200);
    
    delay(2000);
    display.clearDisplay();
}

void loop () {
unsigned long currentMillis = millis();


    if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;

        if (digitalRead(bp1) == LOW || digitalRead(bp2) == LOW && t > 0) {
            t = t - 5;
        }
        else if (t < 100){
            t = 100;
        }
    }
    
    if (digitalRead(bp1) == HIGH) {
        val10 = val10 + 1;
    }

    if (digitalRead(bp2) == HIGH) {
        val10 = val10 - 1;
    }

    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.println(val10);

    display.setTextSize(1);
    display.setCursor(0, 30);
    display.println(val10, BIN);
    display.display();
    delay(t);
}
