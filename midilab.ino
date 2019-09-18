#define p Serial.print
#define pln Serial.println

// switch
const byte SWITCH_PINS[4] = {2,3,4,5};
bool swVal[4] = {LOW,LOW,LOW,LOW}; // or just 0, it's the same
bool swValPrevious[4] = {LOW,LOW,LOW,LOW};
const int ccSwNum[4] = {101,102,103,104};
const byte midiCmdCC = 176; // this is a MIDI CC on channel 1

void setup() {
    pinMode(SWITCH_PINS[0], INPUT);
    pinMode(SWITCH_PINS[1], INPUT);
    pinMode(SWITCH_PINS[2], INPUT);
    pinMode(SWITCH_PINS[3], INPUT);
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
}
