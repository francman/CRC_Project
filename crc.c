//  Copyright (c) 2020 Frank Manu

//  This source code is licensed under MIT license fount in the
//  LICENSE file in the root directory of this source tree

//  The script is created in fulfillment of required coursework
//  from the Coding and Information Theory class at UMass Lowell
//  EECE 5480 - Spring 2020

#include "crc.h"

unsigned short 
crc16(char *data_ptr, int message_length)
{
  unsigned short crc = 0x00;
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