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
#include <stdarg.h>
#include <ctype.h>

/**
 * typedef-ed function pointer for a function that accepts to ints and returns an int
 */
typedef int (*compPtr)(int, int);

/**
 * @properties next_ a pointer to a next Element
 * @properties prev_ a pointer to a previous Element
 * @properties val_ an int value
 */
typedef struct LElement {
    struct LElement *next_;
    struct LElement *prev_;
    int val_;
} Element;

/**
 * @properties nb_elements_ the number of Elements in the List
 * @properties head_ a pointer to the List's first Element
 * @properties tail_ a pointer to the List's last Element
 */
typedef struct LList {
    int nb_elements_;
    Element *head_;
    Element *tail_;
} List;

#define DEBUG printf("file %s; line %d\n", __FILE__, __LINE__);
#define FAIL_OUT DEBUG exit(EXIT_FAILURE);
#define MALLOC_FAIL printf("!_malloc failed_!\n"); FAIL_OUT
#define EMPTY_OR_NULL printf("this data structure doesn't have a positive int value as its size, or the pointer to it isn't valid\n");

#define BUFFER_SIZE 32768 //~4000 chars, 1000 ints, 500 long longs...

#define MAX(A, B) ({ \
                    typeof(A) _a = (A); \
                    typeof(B) _b = (B); \
                    _a > _b ? _a : _b;  \
                    })

//#define MAX(A, B) (A > B ? A : B)

#define GET_INPUT_FILL_MAT_F  printf("row: %d | col: %d | >", i + 1, j + 1); \
fgets(input, 20, stdin); x = strtof(input, &endptr); printf("%f\n", x);

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
 * makes a string that is a permutation of a previous string, based on a same-size permutation array of ints
 * (a permutation contains ints between 0 and n-1, and no same int twice)
 * @param orig the original string
 * @param arr the permutation array
 * @param n the size of the permutation array and of the string
 * @return a pointer to a new string, based on the original one and the permutation array ===============
 * ("ftw" and [201] -> "__f" -> "t_f" -> "twf")
 */
char *mkStrPerm(const char *orig, const int *arr, int n);

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

/**
 * makes an empty list
 * @return a pointer to the list
 */
List createList();

/**
 * finds the length of a list
 * @param list the list
 * @return the length of the list
 */
int listlen(List list);

/**
 * makes an Element with null next and previous properties
 * @param val the value to be contained in the Element
 * @return a pointer to the created Element
 */
Element *mkElement(int val);

/**
 * adds an Element with a given value to the end or to the beginning of a given List, depending on the chosen mode
 * @param listPtr
 * @param val
 * @param mode the chosen mode: 'e' for end (default), 's' for start
 * @return 1 if successful, 0 if not
 */
int addToList(List *listPtr, int val, char mode);

/**
 * finds the value in the last Element of a given List
 * @param list the List
 * @return the int value of the Element
 */
int endVal_list(List list);

/**
 * finds the value in the first Element of a given List
 * @param list the List
 * @return the int value of the Element
 */
int startVal_list(List list);

/**
 * prints a List's content to the console
 * @param list the List
 */
void showList(List list);

//=======================================TP2=================================================

/**
 * checks if a file was open successfully; exits with error if not
 * @param f a pointer to the FILE
 * @param f_name the name of the file
 */
void checkFopen(FILE *f, char *f_name);

/**
 * copies an existing file's contents into another file, or appends an existing file's contents onto another file's
 * @param f1_name the name of the source file
 * @param f2_name the name of the destination file
 * @param mode 'c' for copying, or 'a' for appending (default)
 */
void copyOrAppendFile(char *f1_name, char *f2_name, ...);

/**
 * prints to the console the first difference found between two files (line and char number)
 * @param f1_name the name of a file
 * @param f2_name the name of another file
 */
void showDiff(char *f1_name, char *f2_name);

/**
 * removes all vowels from a given file (diacritics not covered)
 * @param f_name the file name
 */
void removeVowels(char *f_name);

/**
 * modifies a string in place, using a same-size permutation array of ints
 * @param str the string to be modified
 * @param perm the permutation array
 * @param n the size of the permutation array and of the string
 */
void permSubStr(char *str, const int *perm, int n);

/**
 * makes a text file with a given name, that is a permutation of an original text file, using a permutation array of
 * ints and its size, and repeating it if it is shorter than the given text
 * @param txt_f_name the name of original text file
 * @param res_f_name the name of resulting text file
 * @param perm the permutation array
 * @param n the size of the permutation array
 */
void permuteString(char *txt_f_name, char *res_f_name, const int *perm, int n);

/**
 * makes a permutation array of ints from a text file (supposed to contain a permutation: ints separated by spaces
 * , like "2 0 1")
 * @param perm_f_name the name of the file containing the permutation
 * @param nPtr a pointer to an int
 * @return a permutation array of ints
 * @side_effect changes the value that nPtr points to, to the size of the created array
 */
int *findPerm(char *perm_f_name, int *nPtr);

/**
 * makes a text file with a given name, that is a permutation of an original text file, using a permutation sequence
 * from another file text, verifying the validity of the permutation, and repeating it if it is shorter than the given text
 * @param txt_f_name the name of original text file
 * @param perm_f_name the name of the permutation text file
 * @param res_f_name the name of resulting text file
 */
void encode(char *txt_f_name, char *perm_f_name, char *res_f_name);

/**
 * decodes a file that was encoded with the encode function, using the same permutation array if ints as key
 * @param txt_f_name the name of the encoded text file
 * @param perm_f_name the name of the permutation text file
 * @param res_f_name the name of the resulting text file
 */
void decode(char *txt_f_name, char *perm_f_name, char *res_f_name);

/**
 * makes a text file with a given name, that is a caesar's cypher of an original text file, using an int to determine the shift
 * @param txt_f_name the name of the original text file
 * @param txt_res_name the name of the enciphered text file
 * @param n the desired shift
 */
void caesar(char *txt_f_name, char *txt_res_name, int n);

/**
 * writes a List's contents into a text file of a given name, folowing the format: "list: [_size_] a, b, c, d"
 * @param l the List
 * @param txt_res_name the resulting file's name
 */
void writeListToFile(List l, char *txt_res_name);

/**
 * populates a given (presumably empty) List based on the contents of a text file, if it is formatted as follows:
 * "list: [_size_] a, b, c, d"
 * @param txt_f_name the name of the given file
 * @param lPtr a pointer to the given List
 */
void getListFromFile(char *txt_f_name, List *lPtr);

//=======================================TP3=================================================

/**
 * prints an array of strings to the console
 * @param arr
 * @param n
 */
void showStrArr(char **arr, int n);

/**
 * finds all ints in a given string and extracts them into an array of... strings
 * @param input the given string
 * @param count a pointer to an int; the value that it points to will contain the size of the resulting array
 * @return the array of strings that contains all the int values
 */
char **getIntsFromStr(char *input, int *count);

/**
 * imitates the behavior of 'wc' in shell: prints out the number of lines, of words, and of bytes / chars in a given
 * file, followed by the file's name
 * @param f_name the name of the file
 */
void myWc(char *f_name);

/**
 * calculates the average from any number of !!_ints_!!
 * @param n the number of !!_ints_!! that will be submitted to this function (not including this _n_ parameter)
 * @param ... any number of !!_ints_!!
 * @return the average of the submitted !!_ints_!!
 */
double avg(int n, ...);


//=======================================TP4=================================================

#endif //Y2_C_TOOLBOX_H
