#include <stdio.h>
#include <stdlib.h>
#include  <stdint.h>
#include <math.h>

uint8_t add_quarter(uint8_t x, uint8_t y){

    uint8_t x_sign = x >> 7;
    uint8_t y_sign = y >>7;

    uint8_t x_exp = (x << 1); x_exp = x_exp >> 4;
    uint8_t y_exp = (y << 1); y_exp = y_exp >> 4;

    uint8_t sig_x = (x<<5); sig_x = sig_x >> 5; 
    uint8_t sig_y = (y<<5); sig_y = sig_y >> 5; 

if (y_exp == 0b1111 && sig_y != 0b000)return NAN; if (x_exp == 0b1111 && sig_x != 0b000) return NAN;


if (x_exp == 0b1111){
        if (x_sign == 0){
            if (y_exp == 0b1111){
                if (y_sign == 1){return NAN;
                }else return x;}
        }else if (x_sign == 1){
                if (y_exp == 0b1111){
                    if (y_sign == 1){
                        return x ;
                    }else return NAN;
                }else return x;
        }
        
    }
else if (y_exp == 0b1111){
        if (y_sign == 0){
            if (x_exp == 0b1111){
                if (x_sign == 1){
                    return NAN;
                } else{
                    return y;
                }
            }else{
                return y;
            }
        }else if (y_sign == 1){
            if (x_exp == 0b1111){
                if (x_sign == 1){
                    return y;
                }else{
                    return NAN;
                }
            }else{
                return y;
            }}}

if (x_exp == 0){
    x_exp++;
}else{
    sig_x = 0b1000 | sig_x;
}
if (y_exp ==0){
    y_exp++;
}else{
    sig_y = 0b1000 | sig_y;
}
    while (x_exp < y_exp){
        sig_y = sig_y << 1;
        y_exp--;}

    while (y_exp < x_exp){
        sig_x = sig_x << 1;
        x_exp--;}

    uint8_t sum_sign = 0;
    uint8_t sum_exp = x_exp;
    uint8_t sum_sig = 0;

    if (x_sign == y_sign){
        sum_sig = sig_x + sig_y;
        sum_sign = x_sign;

    }else{
        if (sig_x < sig_y){
            sum_sig = sig_y - sig_x;
            sum_sign = y_sign;
        }if (sig_x > sig_y){
            sum_sig = sig_x - sig_y;
            sum_sign = x_sign;
        }
    }if (sum_sig & 0b00010000){
        sum_sig = sum_sig >> 1;
        sum_exp++;
    }while ((sum_sig | 0b00000000) <= 0b000000111){
        sum_sig = sum_sig << 1;
        sum_exp--;
    }
    uint8_t sum = (sum_sign << 7)|(sum_exp << 3)| (sum_sig & 0b00000111);

    return sum;
}


int main(){
    // add_quarter(0b01010111,0b01010110);
    uint8_t res = add_quarter(0b00000111,0b01111000);
    printf("%d", res);
    // uint8_t num1 = 0b1010; 
    // uint8_t num2 = 0b1101;
    // uint8_t res = (num<<1); res = res >> 4;
    // printf("%d", num1+num2);
    return 0;
}