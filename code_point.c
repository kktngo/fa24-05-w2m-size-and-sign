#include <stdio.h>
#include <stdint.h>

int32_t code_point2(char c1, char c2) {
    return (c1 & 0b00011111) * 64 + (c2 & 0b00111111);
}

int32_t code_point3(char c1, char c2, char c3) {
    return (c1 & 0b00001111) * 4096 + (c2 & 0b00111111) * 64 + (c3 & 0b00111111);
}

int main() {
    char joseph[] = "Joséph";
    printf("Code point: %d\n", code_point2(joseph[3], joseph[4])); //233 (unicode cp for é) 
                                                                    //é: (0b110)00011 and (0b10)101001   after () make up é
                                                                    //   (2byte)          (cont)
                                                                    //233: 0b00011[101001]
                                                                    //masking: & 0b00011111 for both byte codes
                                                                    //to get: 0b00000011 and 0b00101001
                                                                    //want [101001] to go 6 bytes to left. so you multiply by 64
                                                                    //to get: 0b11000000 + 0b00101001
                                                                    //int32_t to make it big enough to fit everything, char is too small

    char pika[] = "ピカチュウ";
    printf("Code point: %d\n", code_point3(pika[0], pika[1], pika[2]));

}