#include "crc.h"

unsigned short 
crc16(char *data_ptr, int message_length)
{
  unsigned short crc = 0x0;
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