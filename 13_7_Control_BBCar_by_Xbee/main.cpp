#include "mbed.h"
#include "bbcar.h"
#include "bbcar_rpc.h"

Ticker servo_ticker;
PwmOut pin9(D9), pin8(D8);
Serial xbee(D12, D11);
BBCar car(pin8, pin9, servo_ticker);

int main() {
    double pwm_table0[] = {-150, -120, -90, -60, -30, 0, 30, 60, 90, 120, 150};
    double speed_table0[] = {-43.382, -42.427, -39.874, -31.979, -16.109, 0.000, 12.919, 28.550, 37.881, 41.470, 43.065};
    double pwm_table1[] = {-150, -120, -90, -60, -30, 0, 30, 60, 90, 120, 150};
    double speed_table1[] = {-16.747, -16.508, -15.631, -12.760, -6.539, 0.000, 5.343, 11.564, 15.073, 16.348, 16.907};
    car.setCalibTable(11, pwm_table0, speed_table0, 11, pwm_table1, speed_table1);
    char buf[256], outbuf[256];
    while (1) {
        for( int i=0; ;i++ ) {
            buf[i] = xbee.getc();
            if(buf[i] == '\n') break;
        }

        RPC::call(buf, outbuf);
        xbee.printf("%s\r\n", outbuf);
    }
}