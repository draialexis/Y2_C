//
// Created by draia on 14/11/2021.
//

#ifndef Y2_C_TOOLBOX_H
#define Y2_C_TOOLBOX_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <errno.h>


#define DEBUG printf("file %s; line %d\n", __FILE__, __LINE__);
#define FAIL_OUT DEBUG exit(EXIT_FAILURE);
#define MALLOC_FAIL printf("!_malloc failed_!\n"); FAIL_OUT
#define EMPTY_OR_NULL printf("this data structure doesn't have a positive int value as its size, or the pointer to it isn't valid\n");

//=======================================TP1=================================================
/**
 * finds a random int in a range
 * @param min the lower bound
 * @param max the higher bound
 * @return a random int in the range
 */
int randInRange(int min, int max);

/**
 * allocates memory for an empty string
 * @param n the desired size of the string
 * @return a pointer to an empty string of that size
 */
char *mkStr(int n);

/**
 * allocates memory for an empty array on ints
 * @param n the desired size of the array
 * @return a pointer to an empty array of that size
 */
int *mkIntArr(int n);

/**
 * prints an array of ints to the console
 * @param T the array
 * @param n the size of the array
 */
void showIntArr(int *T, int n);

/**
 * fills an array of ints with random values in a range
 * @param T the array
 * @param n the size of the array
 * @param min the lower bound of the range
 * @param max the higher bound of the range
 */
void fillIntArrRdm(int *T, int n, int min, int max);

/**
 * recursively finds the member of the fibonacci sequence at U_n
 * @param n
 * @return the n^th member of the fibonacci sequence
 */
int fiboRec(int n);

/**
 * non-recursively finds the member of the fibonacci sequence at U_n
 * @param n 
 * @return the n^th member of the fibonacci sequence
 */
int fiboImp(int n);

/**
 * makes an array of ints containing the first _n_ members of the fibonacci sequence
 * @param n
 * @return a pointer to a fibonacci array of size n
 */
int *mkFiboArr(int n);

/**
 * checks if a given array of ints is a permutation
 * (a permutation contains ints between 0 and n-1, and no same int twice)
 * @param arr the array to be checked
 * @param n the size of the array
 * @return 1 if true, 0 if false
 */
int isPermutation(const int *arr, int n);

/**
 * makes an array of ints that is a random permutation
 * (a permutation contains ints between 0 and n-1, and no same int twice)
 * @param n the desired size of the array
 * @return a pointer to a random permutation array of size n
 */
int *mkRdmPerm(int n);

/**
 * makes a string that is a permutation of a previous string, based on a permutation array of ints
 * (a permutation contains ints between 0 and n-1, and no same int twice)
 * @param orig the original string
 * @param arr the permutation array
 * @param n the size of the permutation array
 * @return a pointer to a new string, based on the original one and the permutation array ===============
 * ("ftw" and [201] -> "__f" -> "t_f" -> "twf")
 */
char *permuteString(const char *orig, const int *arr, int n);

/**
 * prints an 2D array of floats, as a matrix, to the console
 * @param mat the matrix to be printed
 * @param rows the size of the outer array
 * @param cols the size of the inner arrays
 */
void showMat_f(float **mat, int rows, int cols);

/**
 * allocates memory for an empty 2D array of floats, and for the inner arrays
 * @param rows the size of the outer array
 * @param cols the size of the inner arrays
 * @return a pointer to the 2D array of floats
 */
float **mkMat_f(int rows, int cols);

/**
 * fills a 2D array of floats, as a matrix, using console input
 * @param mat the 2D array of floats to be filled
 * @param rows the size of the outer array
 * @param cols the size of the inner arrays
 */
void fillMat_f(float **mat, int rows, int cols);

/**
 * makes a 2D array of floats, as a matrix, that is a right-rotation of a given matrix
 * @param mat the original matrix
 * @param mrows the original size of the outer array
 * @param mcols the original size of the inner arrays
 * @return a pointer to a new 2D array of floats that is a right-rotation of the given matrix
 */
float **rotateRightMat_f(float **mat, int mrows, int mcols);

/**
 * frees the allocated memory of a 2D array of floats
 * @param mat the 2D array of floats to be freed
 * @param rows the size of the outer array
 * @param cols the size of the inner arrays
 */
void freeMat_f(float **mat, int rows, int cols);

/**
 * makes a 2D array of ints that represents Pascal's Triangle, and prints it to the console
 * @param n the desired size of Pascal's Triangle (i.e. the size of the outer array, the number of rows)
 * @return a pointer to a 2D array of ints that represents Pascal's Triangle, of size n
 */
int **pascalsTriangle(int n);

//=======================================TP2=================================================

//=======================================TP3=================================================

//=======================================TP4=================================================

#endif //Y2_C_TOOLBOX_H
