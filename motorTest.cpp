#define MOTOR_IN1 11 // GPIO Pin for L298N IN1, physical pin 23
#define MOTOR_IN2 8 // GPIO Pin for L298N IN2, physical pin 24
#define MOTOR_ENA 18 // GPIO Pin forL298N enable (PWM Speed Control), currently connected to ground

#include "wirningPi.h"
#include <unistd.h>
#include <stdio.h>

void initDC();
void rotateMotor(bool clockwise);

int main() {


    printf("Initializing Motor:\n");
    initDC();

    printf("Rotating clockwise:\n");
    rotateMotor(true);

    printf("Rotating counter-clockwise:\n");
    rotateMotor(false);

    return 0;
}

void initDC() {
    // Uses BCM numbering of the GPIOs and directly accesses the GPIO registers.
    wiringPiSetupPinType(WPI_PIN_BCM);
    
    // Setup DC Motor Driver Pins
    pinMode(MOTOR_IN1, OUTPUT);
    pinMode(MOTOR_IN2, OUTPUT);
    // Frequency and pulse break ratio can be configured
    // pinMode(MOTOR_ENA, PWM_MS_OUTPUT);

    digitalWrite(MOTOR_IN1, LOW);
    digitalWrite(MOTOR_IN2, LOW);
    // pwmWrite(MOTOR_ENA, ###);

    
}

void rotateMotor(bool clockwise) {
    if (clockwise) {
        //this->logger.log("Rotating clockwise.");
        digitalWrite(MOTOR_IN1, HIGH);
        digitalWrite(MOTOR_IN2, LOW);
        // pwmWrite(MOTOR_ENA, 255); // Adjust speed
        usleep(1875000); // Rotate duration
        digitalWrite(MOTOR_IN1, LOW);
        digitalWrite(MOTOR_IN2, LOW); // HIGH,HIGH || LOW,LOW == off
      }
      else {
        //this->logger.log("Rotating counter-clockwise.");
        digitalWrite(MOTOR_IN1, LOW);
        digitalWrite(MOTOR_IN2, HIGH);
        // pwmWrite(MOTOR_ENA, 255);
        usleep(1875000);
        digitalWrite(MOTOR_IN1, LOW);
        digitalWrite(MOTOR_IN2, LOW);
      }
}
