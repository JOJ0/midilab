#define p Serial.print
#define pln Serial.println

// switch
const byte PIN_SW1 = 2;
bool swVal = LOW; // or just 0, it's the same
bool swValPrevious = LOW;
const int ccSwNum = 101;
const byte midiCmdCC = 176; // this is a MIDI CC on channel 1

void setup() {
    pinMode(PIN_SW1, INPUT);
    Serial.begin(31250);
}

void loop() {
    swVal = digitalRead(PIN_SW1);
    if (swVal != swValPrevious) {
        if (swVal == HIGH) {
            //p("Sending out MIDI CC _on_ "); pln(ccSwNum);
            Serial.write(midiCmdCC);
            Serial.write(ccSwNum);
            Serial.write(127);
        }
        else {
            //p("Sending out MIDI CC _off_ "); pln(ccSwNum);
            Serial.write(midiCmdCC);
            Serial.write(ccSwNum);
            Serial.write(0);
        }
    }
    swValPrevious = swVal;
}
