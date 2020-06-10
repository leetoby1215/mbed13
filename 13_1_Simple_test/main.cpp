#include "mbed.h"
#include "bbcar.h"
Ticker servo_ticker;
PwmOut pin13(D13), pin12(D12);
BBCar car(pin13, pin12, servo_ticker);

int main() {
    while(1) {
        car.goStraight(0);
        wait(1);
    }
}