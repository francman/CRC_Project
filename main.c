#include <stdio.h>
#include <string.h>

#define POLY 0x8408

unsigned short crc16(char *data_p, unsigned short length){
    unsigned char i;
    unsigned int data;
    unsigned int crc = 0xffff;

    if (length == 0){
        return (~crc);
    }

    do{
        for(i=0, data=(unsigned int)0xff & *data_p++; i<8;i++, data >>= 1){
            if((crc & 0x0001) ^ (data & 0x0001)){
                crc = (crc >> 1) ^ POLY;
            }
            else{
                crc >>=1;
            }
        }
    }while(--length);
    crc = ~crc;
    data = crc;
    crc = (crc<<8) | (data>>8 & 0xff);

    return (crc);
}

int main(){
    char *message;
    unsigned short message_length;
    unsigned short returned_from_crc;
    *message = 'h';
    message_length = strlen(message);

    returned_from_crc = crc16(message, message_length);
    printf("0x%X\n", returned_from_crc);

    return 0; 
}