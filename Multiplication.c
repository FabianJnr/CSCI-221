#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>


uint8_t round_to_even(uint8_t round, int number){
    uint8_t midway = 0b00000001;
    midway = midway << (number - 1);
    uint8_t left_shift = round << (8-number);
    uint8_t right_shift = left_shift >> (8-number);
    uint8_t test = 0b11111111;
    test = test << number;
    uint8_t res = round & test;
    if (right_shift < midway){
        return res;
    }else if (right_shift > midway){
        uint8_t d = (1 << (number));
       res = res + d;
    return res;
    }else{
        uint8_t value = (1 << (number));
        value = round & value;
        if (value == 0){
            return res;

        }else{
            return (res + (1 << (number)));
        }
    }
}

uint8_t multiply_quarter(uint8_t x, uint8_t y) {

    uint8_t x_sign = x >> 7;
    uint8_t y_sign = y >>7;

    uint8_t x_exp = (x << 1); x_exp = x_exp >> 4; 
    uint8_t y_exp = (y << 1); y_exp = y_exp >> 4;
    
    uint8_t x_sig = (x<<5); x_sig = x_sig >> 5; 
    uint8_t y_sig = (y<<5); y_sig = y_sig >> 5; 

if (y_exp == 0b1111 && y_sig != 0b000)return NAN; if (x_exp == 0b1111 && x_sig != 0b000) return NAN;

if (x_exp == 0b1111){
        if (x_sign == 0){
            if (y_exp == 0b1111){
                if (y_sign == 1){return NAN;
                }else return x;}else if (y_sign == 0) {return x;}
                    else if (y_sign == 1) {return  (0b10000000 ) | (x_exp << 3) | (x_sig);}
        }else if (x_sign == 1){
                if (y_exp == 0b1111){
                    if (y_sign == 1){
                        return x;
                    }else return NAN;
                } else if (y_sign == 0) return x;
                else if (y_sign == 1) {x = x << 1; x = x >> 1; return x;}
        }}
else if (y_exp == 0b1111){
        if (y_sign == 0){
            if (x_exp == 0b1111){
                if (x_sign == 1){
                    return NAN;}else return y;}else if (x_sign == 0) {return y;}
                    else if (x_sign == 1) {return  (0b10000000 ) | (y_exp << 3) | (y_sig);}
        }else if (y_sign == 1){ 
            if (x_exp == 0b1111){
                if (x_sign == 1){
                    return y;} 
                else return NAN;
                } else if (x_sign == 0) return y;
                else if (x_sign == 1) {y = y << 1; y = y >> 1; return y;
        }
        }}

if(x_exp == 0){
    x_exp++;
}else{
    x_sig = 0b1000 | x_sig;
}
if (y_exp ==0){
    y_exp++;
}else{
    y_sig = 0b1000 | y_sig;
}

    uint8_t res_sign = 0;
    uint8_t res_exp = 0;
    uint8_t res_sig = 0;


    if (x_sign!= y_sign) {
        res_sign = 1;
    }
    
    res_exp = x_exp + y_exp;
    // printf("%d\n", res_exp);
    if (res_exp > 15){
        res_exp = res_exp & 0b11110000;}
    // }printf("%d\n", res_exp);


    res_sig = x_sig * y_sig;
    // printf("%d\n", res_sig);
    if (res_sig > 0b111){
        int trun = 0;
        if (res_sig <= 31){
            trun = 1;
        }else if (res_sig > 31 && res_sig <= 61){
            trun = 2;
        }else {
            trun = 4;}
        res_sig = round_to_even(res_sig, trun);
        res_sig = 0b0111 & res_sig;
    }
    else res_sig = 0b01110000;
    // printf("%d\n", res_sig);

uint8_t result = (res_sign << 7) | ((res_exp & 0b00001111) << 3) | (res_sig & 0x07);

return result;
}

int main(){
    uint8_t res = multiply_quarter(0b11111000,0b11111000);
    printf("%d", res);
    return 0;
}
