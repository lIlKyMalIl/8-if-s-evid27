#include <Smartcar.h>

Odometer encoderLeft(190), encoderRight(190); //Βάλτε τους δικούς σας παλμούς ανά μέτρο
Gyroscope gyro(13); //Βάλτε την κατάλληλη τιμή σύμφωνα με το γυροσκόπιό σας
Car folkracer;

SR04 front;
const int TRIGGER_PIN = 6; //Βάλτε την κατάλληλη τιμή για το pin που είναι συνδεδεμένο στο trigger
const int ECHO_PIN = 7; //Βάλτε την κατάλληλη τιμή για το pin που είναι συνδεδεμένο στο echo

void setup() {
  front.attach(TRIGGER_PIN, ECHO_PIN); //αρχικοποιεί τον υπέρηχο
  gyro.attach(); //αρχικοποιεί το γυροσκόπειο
  encoderLeft.attach(3); //αρχικοποιεί το encoder
  encoderRight.attach(2);
  encoderLeft.begin();//ξεκινάει τις μετρήσεις στον encoder
  encoderRight.begin();
  folkracer.begin(encoderLeft, encoderRight, gyro); //ξεκινάει το αυτοκίνητο χρησιμοποιώντας τα encoders και το γυροσκόπειο
  folkracer.enableCruiseControl();
  gyro.begin(); //ξεκινάει τις μετρήσεις στο γυροσκόπειο
  folkracer.setSpeed(0.5); //θέτει την ταχύτητα στο αυτοκινητάκι στα 0.5 μέτρα ανά δευτερόλεπτο
}

void loop() {
  folkracer.updateMotors(); //διατήρησε την ταχύτητα του αυτοκινήτου σταθερή
  int distance = front.getDistance(); //μέτρησε την απόσταση και αποθήκευσέ την στη μεταβλητή distance

  //TO-DO: Κάντε το αυτοκινητάκι να στρίβει 90 μοίρες προς τα αριστερά όταν βρίσκει ένα κοντινό εμπόδιο και να συνεχίζει την πορεία του
}
