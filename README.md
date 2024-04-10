# RFID-Access-Control-with-Visual-Feedback
This is an Arduino-based system using RFID technology for secure access control. It features an MFRC522 RFID reader, OLED display for real-time feedback, and LED indicators for access status.

## Features

- **RFID Access Control**: Uses the MFRC522 RFID reader to read the unique ID of an RFID card and compare it with a predefined authorized ID.
- **Visual Feedback**: Includes an OLED display that provides real-time feedback to the user. It displays messages such as "Scan Your Card...", "ACCESS GRANTED!", or "ACCESS DENIED!" depending on the system state. The display also shows the ID of the scanned card.
- **LED Indicators**: Includes a green LED that lights up when access is granted and a red LED that lights up when access is denied.

## Usage

1. Load the Arduino sketch onto your Arduino board.
2. Connect your MFRC522 RFID reader, OLED display, and LEDs to the appropriate pins on your Arduino board.
3. Present an RFID card to the reader. The OLED display will show whether access is granted or denied, and the appropriate LED will light up.

## Contributing

Contributions are welcome! Please read the contributing guidelines before getting started.

## License

This project is licensed under the MIT License. See the LICENSE file for details.
