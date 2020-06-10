#include "mbed.h"
#include "bbcar.h"

Ticker servo_ticker;
PwmOut pin12(D12), pin13(D13);
BBCar car(pin12, pin13, servo_ticker);

int main() {
    // please contruct you own calibration table with each servo
    double pwm_table0[] = {-150, -120, -90, -60, -30, 0, 30, 60, 90, 120, 150};
    double speed_table0[] = {-43.382, -42.427, -39.874, -31.979, -16.109, 0.000, 12.919, 28.550, 37.881, 41.470, 43.065};
    double pwm_table1[] = {-150, -120, -90, -60, -30, 0, 30, 60, 90, 120, 150};
    double speed_table1[] = {-16.747, -16.508, -15.631, -12.760, -6.539, 0.000, 5.343, 11.564, 15.073, 16.348, 16.907};
    // first and fourth argument : length of table
    car.setCalibTable(11, pwm_table0, speed_table0, 11, pwm_table1, speed_table1);

    while (1) {
        car.goStraightCalib(15);
        wait(5);
        car.stop();
        wait(5);
    }
}