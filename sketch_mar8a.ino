void setup() {
    Serial.begin(9600);  // Start serial communication
    pinMode(12, OUTPUT);  // Red LED (Bad Form)
    pinMode(8, OUTPUT);   // Green LED (Good Form)
}

void loop() {
    if (Serial.available() > 0) {  
        String received = Serial.readStringUntil('\n'); 
        received.trim();  

        Serial.print("Received: ");  
        Serial.println(received);    

        if (received == "good") {
            digitalWrite(8, LOW);  // Turn ON Green LED (Good Form)
            digitalWrite(12, HIGH); // Turn OFF Red LED
        } 
        else if (received == "bad_forward_lean") {
            digitalWrite(8, HIGH);  // Turn ON Red LED (Bad Form)
            digitalWrite(12, LOW); // Turn OFF Green LED
        }
        else if (received == "bad_knees_over_toes") {
            digitalWrite(8, HIGH);  // Turn ON Red LED (Bad Form)
            digitalWrite(12, LOW); // Turn OFF Green LED
        }
        else if (received == "") {  // If feedback is NULL (standing position)
            digitalWrite(8, LOW);  // Turn OFF both LEDs
            digitalWrite(12, LOW);
        }
    }
}
