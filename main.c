//                                      16   12   5
// this is the CCITT CRC 16 polynomial X  + X  + X  + 1.

#include <stdio.h>
#include <string.h>

#define POLY 0x1021
#define MSB_16 0x8000

unsigned short 
crc16(char *data_ptr, int message_length)
{
  int crc = 0;
  char message_byte;

  while (--message_length >= 0)
  {
    message_byte = 8;
    crc = crc ^ (((int) *data_ptr++) << message_byte);

    do
    {
      if (crc & MSB_16)
      crc = (crc << 1) ^ POLY;
      else
      crc = crc << 1;
    } while(--message_byte);
  }
  return (crc);
}

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