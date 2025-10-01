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
 * @file stats.h
 * @brief This file contains all the function declarations that will be used
 *
 * <Add Extended Description Here>
 *
 * @author Sudharshan SS
 * @date 22.09.2025
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief Prints the statistics of an array
 *
 * This function takes in an array as an input and prints out the statistics including the maximum, minimum, mean and median
 *
 * @param arr The array of which the statistics are to be printed
 *
 */

void print_statistics(unsigned char *arr, unsigned int len);

/**
 * @brief Prints the array
 *
 * This function takes in an array as an input and prints it out
 *
 * @param arr The array which is to be printed
 * @param len The length of the array given as input
 *
 */

void print_array(unsigned char *arr, unsigned int len);


/**
 * @brief Returns the median value
 *
 * This function takes in an array as an input and returns the median for the values in it
 *
 * @param arr The array given as input
 * @param len The length of the array given as input
 * 
 *@return median The median value of the elements of the array
 */

float find_median(unsigned char *arr, unsigned int len);

/**
 * @brief Returns the mean value
 *
 * This function takes in an array as an input and returns the mean for the values in it
 *
 * @param arr The array given as input
 * @param len The length of the array given as input
 *
 * @return mean The mean value in the elements of the array
 */

float find_mean(unsigned char *arr, unsigned int len);

/**
 * @brief Returns the maximum value
 *
 * This function takes in an array as an input and returns the maximum value in it
 *
 * @param arr The array given as input
 * @param len The length of the array given as input
 *
 * @return max The maximum value in the elements of the array
 */

int find_maximum(unsigned char *arr, unsigned int len);

/**
 * @brief Returns the minimum value
 *
 * This function takes in an array as an input and returns the minimum value in it
 *
 * @param arr The array given as input
 * @param len The length of the array given as input
 *
 * return min The minimum value in the elements of the array
 */

int find_minimum(unsigned char *arr, unsigned int len);

/**
 * @brief Sorts the given array
 *
 * This function takes in an array as an input and sorts the array in descending order
 *
 * @param arr The array given as input
 * @param len The length of the array given as input
 *
 */

void sort_array(unsigned char *arr, unsigned int len);

#endif /* __STATS_H__ */
