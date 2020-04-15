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
#include <stdlib.h>

int main(int argc, char *argv[])
{
  char message[] = "HELLO\n";
  char user_message[50];
  unsigned short message_length;
  unsigned short user_message_length;
  unsigned int my_crc;
  unsigned int user_crc;
  char *my_crc_ptr;
  char *user_crc_ptr;

  message_length = strlen(message);
  my_crc = crc16(message, message_length);
  
  convert_and_print_binary(message, FALSE);
  my_crc_ptr = decimal_to_binary(my_crc);
  printf(" %s\n",my_crc_ptr);
  printf("\n0x%X\n", my_crc);
  printf("\n");
  
  do
  {
    printf("***************MY MESSAGE IS \"HELLO\" ALL CAPS WITH NEW LINE CHARACTER***************\n\n");
    printf("Repeat my message: ");
    fgets(user_message, sizeof(user_message), stdin);
    user_message_length = strlen(user_message);
    user_crc = crc16(user_message, user_message_length);
    convert_and_print_binary(user_message, FALSE);
    user_crc_ptr = decimal_to_binary(user_crc);
    printf(" %s\n",user_crc_ptr);
    printf("\n0x%X\n", user_crc);

    if(crc_checker(my_crc, user_crc))
    {
      printf("Your message is valid\n");
    }

    else
    {
      printf("Error in your message\n\n");
    }
  }while(!crc_checker(my_crc, user_crc));

  free(my_crc_ptr);
  free(user_crc_ptr);
  return 0; 
}
