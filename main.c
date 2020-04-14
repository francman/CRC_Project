//                                      16   12   5
// this is the CCITT CRC 16 polynomial X  + X  + X  + 1.
#include "crc.h"
#include <stdio.h>
#include <string.h>

int main()
{
  char message[2];
  unsigned short message_length;
  int crc;
  message_length = 2;
  message[0] = 'h';
  message[1] = 'i';

  crc = crc16(&message[0], message_length);
  printf("0x%X\n", crc);

  return 0; 
}