/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c
 * @brief To calculate the statistics of the array
 *
 * Calculates the statistics of the given array and prints it out to the screen
 *
 * @author Sudharshan SS
 * @date 22.09.2025
 *
 */



#include <stdio.h>
#include "stats.h"
#include "platform.h"

/* Size of the Data Set */
#define SIZE (40)

void print_array(unsigned char *arr, unsigned int len){         //Definition for print_array function

  #ifdef VERBOSE
  for (int i = 0; i<len; i++){
    PRINTF("Element at index %d: %d\n", i, *(arr + i));
  }
  PRINTF("\n");
  #endif

}

float find_mean(unsigned char * arr, unsigned int len){         //Definition for find_mean function

  unsigned int sum = 0;
  float mean;

  for (int i = 0; i<len;i++){
    sum += *(arr + i);
  }

  mean = (float) sum/len;
  return mean; 
}

int find_maximum(unsigned char * arr, unsigned int len){        //Definition for find_maximum function

  unsigned int max = 0;
  
  for (int i = 0; i<len;i++){
    if (*(arr + i) > max){ 
      max = *(arr+i);
    }
  }

  return max; 
}

int find_minimum(unsigned char * arr, unsigned int len){        //Definition for find_maximum function

  unsigned int min = 0;
  
  for (int i = 0; i<len;i++){
    if (*(arr + i) < min){
      min = *(arr+i);
    }
  }

  return min; 
}

void sort_array(unsigned char *arr, unsigned int len){          //Definition for sort_array function
  for (int i = 0; i<len; i++){
    for (int j = i+1; j<len; j++){
      if (*(arr + i) < *(arr + j)){                             //sorts the array in desccending order 
        unsigned int temp = *(arr +i);                            
        *(arr + i) = *(arr + j);
        *(arr + j) = temp;
      }
    }
  }
}

float find_median(unsigned char *arr, unsigned int len){        //Definition for find_median function
  sort_array(arr, len);
  unsigned int median;
  if (len%2 == 0){                                              //median if array is of even length
    median = (*(arr + (len/2) - 1) + *(arr + (len/2)));
  }
  else{
    median = *(arr + ((len-1)/2) + 1);                          //median if array is of odd length
  }

  return median;
}

void print_statistics(unsigned char *arr, unsigned int len){    //Definition for print_statistics function
  
  unsigned int max = find_maximum(arr, len);
  unsigned int min = find_minimum(arr, len);
  float mean = find_mean(arr, len);
  float median = find_median(arr, len);

  printf("Maximum value of the array: %d\n", max);
  printf("Minimum value of the array: %d\n", min);
  printf("Mean value of the array: %f\n", mean);
  printf("Median value of the array: %f\n", median);

}

/*
void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,           //input array
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};


  print_array(test, SIZE);                              
  print_statistics(test, SIZE);

}

*/