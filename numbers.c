#include <stdint.h>
#include <stdio.h>

//int8_t is a synonym for char
int8_t is_ascii(char c) { //theres numbers from 0-127 and -128 to -1
                        //char in C is a signed type. The most significant bit has a special meaning
                        //signed interpretation: -2^7, 2^6, 2^5, ... 2^0 (only 2^7 is negative)
                        //0b10000001: Unsigned: (2^7 * 1) +..+ (2^0 * 1) = 129 Signed: (-2^7 * 1)+...+ (2^0 * 1) = -127
                        //(For un & s): 0b00000000: 0 --> 0b01111111: 127

                        //Unsigned: 128 129 130 ... 255 (0b11111111)
                        //Sign: -128 -127 -126 ... -1 (0b11111111)
                        //2's complement representation ^^             
    return c <= 128;
}

void test_is_ascii(char c) {
    printf("is_ascii(%c %d) = %s\n", c, c, is_ascii(c) ? "true" : "false");
}
void tests_is_ascii() {
    test_is_ascii('a');
    test_is_ascii(0b10000000);
    test_is_ascii(0b01111111);
    for(int i = 0b00000000; i <= 0b11111111; i += 1) {
        test_is_ascii(i);
    }
}

int main() {           
    tests_is_ascii(); 
}