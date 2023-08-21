int dotLED = 2;   // Digital pin for the dot LED (e.g., red LED)
int dashLED = 3;  // Digital pin for the dash LED (e.g., green LED)
const int maxWordLength = 20;
String message1 = "";
String message2 = "";
void setup() {
  Serial.begin(9600);  // Initialize serial communication
  while (!Serial) {
    // Wait for serial port to connect
  }
  pinMode(dotLED, OUTPUT);
  pinMode(dashLED, OUTPUT);
}

void loop() {
Serial.println("Enter word 1:");
  while (Serial.available() == 0) {
    // Wait for input
  }
  delay(100); // Give some time for the complete input to arrive
  message1 = Serial.readStringUntil('\n'); // Read input until newline character
  message1.trim(); // Remove leading and trailing whitespace

  // Prompt for input word 2
  Serial.println("Enter word 2:");
  while (Serial.available() == 0) {
    // Wait for input
  }
  delay(100); // Give some time for the complete input to arrive
  message2 = Serial.readStringUntil('\n'); // Read input until newline character
  message2.trim(); // Remove leading and trailing whitespace

  // Print the stored messages
  Serial.print("Message 1: ");
  Serial.println(message1);
  Serial.print("Message 2: ");
  Serial.println(message2);
  // Define Morse code messages (you can add more messages)
  // String message1 = "hello";     // Example: "HELLO"
  // String message2 = "world";    // Example: "WORLD"

  // Send Message 1
  sendMorseCode(message1);

  // Delay between messages
  delay(2000);

  // Send Message 2
  sendMorseCode(message2);

  // Delay between messages
  delay(2000);
}

void sendMorseCode(String message) {
  for (int i = 0; i < message.length(); i++) {
    char character = message.charAt(i);
    if (character == ' ') {
      // Space between words
      delay(3000);  // 3-second pause
    } else {
      // Translate character to Morse code
      String morseCode = charToMorseCode(character);
      
      // Send Morse code
      for (int j = 0; j < morseCode.length(); j++) {
        char symbol = morseCode.charAt(j);
        if (symbol == '.') {
          digitalWrite(dotLED, HIGH);
          delay(200);  // Dot duration (adjust as needed)
          digitalWrite(dotLED, LOW);
          delay(200);  // Short pause between dots
        } else if (symbol == '-') {
          digitalWrite(dashLED, HIGH);
          delay(600);  // Dash duration (adjust as needed)
          digitalWrite(dashLED, LOW);
          delay(200);  // Short pause between dots and dashes
        }
      }
      
      // Space between characters
      delay(1000);  // 1-second pause
    }
  }
}

String charToMorseCode(char character) {
  // Define Morse code mapping for characters
  switch (character) {
    case 'A': return ".-";
    case 'B': return "-...";
    case 'C': return "-.-.";
    case 'D': return "-..";
    case 'E': return ".";
    case 'F': return "..-.";
    case 'G': return "--.";
    case 'H': return "....";
    case 'I': return "..";
    case 'J': return ".---";
    case 'K': return "-.-";
    case 'L': return ".-..";
    case 'M': return "--";
    case 'N': return "-.";
    case 'O': return "---";
    case 'P': return ".--.";
    case 'Q': return "--.-";
    case 'R': return ".-.";
    case 'S': return "...";
    case 'T': return "-";
    case 'U': return "..-";
    case 'V': return "...-";
    case 'W': return ".--";
    case 'X': return "-..-";
    case 'Y': return "-.--";
    case 'Z': return "--..";
    case '0': return "-----";
    case '1': return ".----";
    case '2': return "..---";
    case '3': return "...--";
    case '4': return "....-";
    case '5': return ".....";
    case '6': return "-....";
    case '7': return "--...";
    case '8': return "---..";
    case '9': return "----.";
    // Add more characters as needed
    default: return "";
  }
}