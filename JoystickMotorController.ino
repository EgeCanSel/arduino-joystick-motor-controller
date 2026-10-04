// Converts the joystick position into the serial protocol expected by the motor.
const uint8_t JOYSTICK_PIN = A2;
const unsigned long SAMPLE_INTERVAL_MS = 100UL;
const uint8_t GOAL_POSITION_INSTRUCTION = 0x1E;

// The motor's 0..300 degree range corresponds to position codes 0..1023.
const long MOTOR_LOW_POSITION = (240L * 1023L) / 300L;  // 818
const long MOTOR_HIGH_POSITION = (150L * 1023L) / 300L; // 511

void setup() {
    Serial.begin(19200);
}

void loop() {
    delay(SAMPLE_INTERVAL_MS);

    const int joystickValue = analogRead(JOYSTICK_PIN);
    const long mappedPosition = map(joystickValue, 0L, 1023L,
                                    MOTOR_LOW_POSITION, MOTOR_HIGH_POSITION);

    const uint16_t goalPosition = static_cast<uint16_t>(
        constrain(mappedPosition, MOTOR_HIGH_POSITION, MOTOR_LOW_POSITION));

    uint8_t packet[3] = {
        GOAL_POSITION_INSTRUCTION,
        lowByte(goalPosition),
        highByte(goalPosition)
    };

    Serial.write(packet, sizeof(packet));
}
