#define p Serial.print
#define pln Serial.println

const byte midiCmdCC = 176; // this is a MIDI CC on channel 1
// 4 switches arrays and variables
const byte SWITCH_PINS[4] = {2,3,4,5};
bool swVal[4] = {LOW,LOW,LOW,LOW}; // or just 0, it's the same
bool swValPrevious[4] = {LOW,LOW,LOW,LOW};
const int ccSwNum[4] = {101,102,103,104};
// 2 pots arrays and variables
const byte POT_PINS[2] = {A0,A1};
int potVal[2] = {LOW,LOW};
int potValPrevious[2] = {LOW,LOW};
const int ccPotNum[2] = {81,82};
int ccVal[2] = {0,0};
int ccValPrevious[2] = {0,0};

void setup() {
    // set the pinMode for the switches pins
    pinMode(SWITCH_PINS[0], INPUT);
    pinMode(SWITCH_PINS[1], INPUT);
    pinMode(SWITCH_PINS[2], INPUT);
    pinMode(SWITCH_PINS[3], INPUT);
    // set the pinMode for the pot pins
    pinMode(POT_PINS[0], INPUT);
    pinMode(POT_PINS[1], INPUT);
    Serial.begin(31250); // this is the MIDI bitrate
    //Serial.begin(9600); // this is a common serial bitrate (debugging)
}

void loop() {
    for (byte swNumber = 0; swNumber < 4; swNumber++) { 
        swVal[swNumber] = digitalRead(SWITCH_PINS[swNumber]);
        if (swVal[swNumber] != swValPrevious[swNumber]) {
            if (swVal[swNumber] == HIGH) {
                //p("Sending out MIDI CC _on_ "); pln(ccSwNum[swNumber]);
                Serial.write(midiCmdCC);
                Serial.write(ccSwNum[swNumber]);
                Serial.write(127);
            }
            else {
                //p("Sending out MIDI CC _off_ "); pln(ccSwNum[swNumber]);
                Serial.write(midiCmdCC);
                Serial.write(ccSwNum[swNumber]);
                Serial.write(0);
            }
        }
        swValPrevious[swNumber] = swVal[swNumber];
    }
    for (byte potNumber = 0; potNumber < 2; potNumber++) {
        potVal[potNumber] = analogRead(POT_PINS[potNumber]);
        ccVal[potNumber] = map(potVal[potNumber],0,1023,0,127);
        //p("potVal, ccVal: "); p(potVal[potNumber]);
        //p(", "); pln(ccVal[potNumber]);
        if (ccVal[potNumber] != ccValPrevious[potNumber]) {
            Serial.write(midiCmdCC);
            Serial.write(ccPotNum[potNumber]);
            Serial.write(ccVal[potNumber]);
        }
        ccValPrevious[potNumber] = ccVal[potNumber];
    }
}
