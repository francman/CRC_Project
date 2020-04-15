//  Copyright (c) 2020 Frank Manu

//  This source code is licensed under MIT license fount in the
//  LICENSE file in the root directory of this source tree

//  The script is created in fulfillment of required coursework
//  from the Coding and Information Theory class at UMass Lowell
//  EECE 5480 - Spring 2020

#define POLY 0x1021
#define MSB_16 0x8000
#define TRUE 1
#define FALSE 0


unsigned short crc16(char *data_ptr, int message_length);
int crc_checker(unsigned short crc_1, unsigned short crc_2);
