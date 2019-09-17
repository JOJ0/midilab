// switch
const byte PIN_SW1 = 2;
bool swVal = LOW; // or just 0, it's the same
const int ccSwNum = 101;

void setup() {
    pinMode(PIN_SW1, INPUT);
    Serial.begin(9600);
}

void loop() {
    swVal = digitalRead(PIN_SW1);
    if (swVal == HIGH) {
        Serial.println("button pressed");
    }
}
