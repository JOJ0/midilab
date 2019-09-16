// switch
const int PIN_SW1 = 2;
bool swVal = false; // or just 0, it's the same
int ccSwNum = 101;

void setup() {
    pinMode(PIN_SW1, INPUT);
}

void loop() {
    if (digitalRead(PIN_SW1) == HIGH) {
        Serial.println("button pressed");
    }
}
