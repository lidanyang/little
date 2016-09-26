#ifndef COMMON_H
#define COMMON_H

#include<error.h>
#include<errno.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<assert.h>
#define SIDE_LENGTH 10

//error number
#define ERRFORMAT 1
#define ERRIO 2
#define ERRFAIL 3 
//convert char to number
#define num(c) ((int)(c - 48))

//error judge
#define IS_ERR(e) (((unsigned long)e) > (1 << (32 - 1)))

//for test
void print_matrix(char *matrix, int length, int isdigit);

//get the input number
char *get_input(void);

//convert one dimension array to two dimension array
int convert_input(char *input, int length, char (* matrix)[][SIDE_LENGTH]);

//bitmap record every line and row's rest number
unsigned int bitmap_per_num[10][10] = {0};
#endif
