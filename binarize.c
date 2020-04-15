#include "binarize.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
//
//
// TODO: Function incomplete, need to return binary address, not used - can ignore
int *string_to_binary(char *string_array)
{
  int string_array_length = strlen(string_array);

  int j; 
  int k = BYTE_LENGTH;
  int num;
  int binary[BYTE_LENGTH * string_array_length];

  for(int i = 0; i < BYTE_LENGTH*string_array_length; i++){
    binary[i] = 0;
  }
  
  for(int i = 0; i < string_array_length; i++)
  {
    j = k - 1;
    num = string_array[i];
    while(num != 0){
      binary[j--] = num % 2;
      num /= 2;
    }
    k += 9;
  }
  // TODO remove printf line below - inserted to prevent unused variable warning
  printf("%ls",binary);
  // The return below generates a compiler warning: function returns address of local variable
  // return binary;
  return 0;
}

//  
//
//
void print_binary(int *binary, char *string_array, int string_array_length)
{
  printf("%s\n", string_array);
  for(int i = 1; i < BYTE_LENGTH*string_array_length; i++)
  {
    printf("%d", binary[i - 1]);
    if(i % BYTE_LENGTH == 0){
      printf(" ");
    }
  }
  printf("\n");
}

//  
//
//
void convert_and_print_binary(char *string_array, int print_original_string)
{
    int string_array_length = strlen(string_array);

    int j; 
    int k = BYTE_LENGTH;
    int num;
    int binary[BYTE_LENGTH * string_array_length];

    for(int i = 0; i < BYTE_LENGTH*string_array_length; i++){
        binary[i] = 0;
    }
    
    for(int i = 0; i < string_array_length; i++)
    {
      j = k - 1;
      num = string_array[i];
      while(num != 0){
        binary[j--] = num % 2;
        num /= 2;
      }
      k += 9;
    }

    if(print_original_string == TRUE)
    {
      printf("%s\n", string_array);
    }

    for(int i = 1; i < BYTE_LENGTH*string_array_length; i++)
    {
      printf("%d", binary[i - 1]);
      if(i % BYTE_LENGTH == 0){
        printf(" ");
      }
    }
}

//
//
//
char *decimal_to_binary(int decimal_number)
{
   int character_length;
   int temp_digit;
   int count;
   char *pointer;
   
   count = 0;
   pointer = (char*)malloc(15+2);
   
   if (pointer == NULL)
      exit(EXIT_FAILURE);
     
   for (character_length = 15 ; character_length >= 0 ; character_length--)
   {
      temp_digit = decimal_number >> character_length;
     
      if (temp_digit & 1)
         *(pointer+count) = 1 + '0';
      else
         *(pointer+count) = 0 + '0';
     
      count++;
      if(count == BYTE_LENGTH)
      {
        *(pointer+count) =' ';
        count ++;
      }
   }
   *(pointer+count) = '\0';
   return  pointer;
}
