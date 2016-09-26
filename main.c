#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "common.h"
#include "verify.h"
#include "compute.h"

int main(){
    char *input;
    input = get_input();
    if(!IS_ERR(input)){
        print_matrix(input, SIDE_LENGTH, 0);
    }
	return 0;
}
