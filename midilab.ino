//#define p Serial.print
//#define pln Serial.println

//const int PIN_LED = 13;

// pot
//const int PIN_POT = A0;
//int potVal = 0;
//int ccPotNum = 21;

// switch
const int PIN_SW1 = 2;
bool swVal = false; // or just 0, it's the same
int ccSwNum = 101;

void setup() {
    pinMode(PIN_SW1, INPUT);
    //while(!Serial); // wait until Serial is accessible
    //Serial.begin(9600); // common serial rate
    //Serial.begin(31250); // MIDI serial rate
}

void loop() {
    if (digitalRead(PIN_SW1) == HIGH) {
        Serial.println("button pressed");
    }
}
