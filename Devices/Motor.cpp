//
// Created by irena.ankerl on 09.05.2019.
//

#include "Motor.h"

Motor::Motor() {
    velocity = 0;
    acceleration = 0;
    position = 0;
}

double Motor::getVelocity() {
    return velocity;
}

void Motor::setVelocity(double vel) {
    velocity = vel;
}

double Motor::getAcceleration() {
    return acceleration;
}

void Motor::setAcceleration(double acc) {
    acceleration = acc;
}

double Motor::getPosition() {
    return position;
}

void Motor::setPosition(double pos) {
    position = pos;
}