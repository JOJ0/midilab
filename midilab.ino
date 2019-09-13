#define p Serial.print
#define pln Serial.println

const int PIN_LED = 13;

// pot
const int PIN_POT = A0;
int potVal = 0;
int ccNum = 21
// switch
bool swVal = false; // or just 0, it's the same
int ccNum = 101

void setup() {
  while(!Serial); // wait until Serial is accessible
  Serial.begin(9600); // common serial rate
  //Serial.begin(31250); // MIDI serial rate
}

void loop() {


}
