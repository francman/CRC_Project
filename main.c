//  Copyright (c) 2020 Frank Manu

//  This source code is licensed under MIT license fount in the
//  LICENSE file in the root directory of this source tree

//  The script is created in fulfillment of required coursework
//  from the Coding and Information Theory class at UMass Lowell
//  EECE 5480 - Spring 2020


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