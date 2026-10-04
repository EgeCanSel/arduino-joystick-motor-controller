# Arduino Joystick Motor Controller

This project reads one axis of a joystick with an Arduino Uno and sends the requested position to a motor controller with a three-byte serial packet.

## Connections

| Joystick pin | Arduino Uno |
| --- | --- |
| VCC | 5V |
| GND | GND |
| VRx or VRy | A2 |

Connect the motor controller's serial input to the Arduino serial output required by your hardware. The controller must use **19200 baud** and accept the packet format below.

## Packet format

| Byte | Value |
| --- | --- |
| 0 | Instruction `0x1E` |
| 1 | Position low byte |
| 2 | Position high byte |

The joystick produces a value from `0` to `1023`. The sketch maps this value to the allowed motor position range from `818` to `511`, waits 100 ms between readings, and sends the resulting position.

## Upload

1. Open `JoystickMotorController.ino` in the Arduino IDE.
2. Select **Arduino Uno** and the correct port.
3. Verify and upload the sketch.
4. Move the joystick to command the motor position.
