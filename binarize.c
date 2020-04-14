#include "binarize.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
//
// 
int * string_to_binary(char *string_array)
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
  return binary;
}

//  
//
//
void print_binary(int *binary, int string_array)
{
  int string_array_length = strlen(string_array);

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
void convert_and_print_binary(char *string_array)
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
