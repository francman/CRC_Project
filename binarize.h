//  Copyright (c) 2020 Frank Manu

//  This source code is licensed under MIT license fount in the
//  LICENSE file in the root directory of this source tree

//  The script is created in fulfillment of required coursework
//  from the Coding and Information Theory class at UMass Lowell
//  EECE 5480 - Spring 2020

#define BYTE_LENGTH 8
#define TRUE 1
#define FALSE 0

int *string_to_binary(char *string_array);
void print_binary(int *binary_array_ptr,char *string_array, int string_array_length);
void convert_and_print_binary(char *string_array, int print_original_string);
char *decimal_to_binary(int decimal_number);
