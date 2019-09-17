#define p Serial.print
#define pln Serial.println

// switch
const byte PIN_SW1 = 2;
bool swVal = LOW; // or just 0, it's the same
bool swValPrevious = LOW;
const int ccSwNum = 101;

void setup() {
    pinMode(PIN_SW1, INPUT);
    Serial.begin(9600);
}

void loop() {
    swVal = digitalRead(PIN_SW1);
    if (swVal != swValPrevious) {
        if (swVal == HIGH) {
            p("Sending out MIDI CC on "); pln(ccSwNum);
        }
        else {
            p("Sending out MIDI CC off "); pln(ccSwNum);
        }
    }
    swValPrevious = swVal;
}
