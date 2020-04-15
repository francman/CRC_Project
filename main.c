//  Copyright (c) 2020 Frank Manu

//  This source code is licensed under MIT license fount in the
//  LICENSE file in the root directory of this source tree

//  The script is created in fulfillment of required coursework
//  from the Coding and Information Theory class at UMass Lowell
//  EECE 5480 - Spring 2020

//***************************************************************
//                                       16   12   5
//  This is the CCITT CRC 16 Polynomial X  + X  + X  + 1 used
//***************************************************************

#include "crc.h"
#include "binarize.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
  char message[] = "hello";
  int * binary_array;
  unsigned short message_length;
  unsigned int crc;
  
  message_length = strlen(message);

  crc = crc16(message, message_length);
  convert_and_print_binary(message);
  printf("0x%X\n", crc);

  return 0; 
}
