#include "common.h"

char *get_input(void){
    int i = 0;
    char x,y,num;
    char *input;
    char temp[100];
    char *ret;
    
    input = malloc(SIDE_LENGTH * SIDE_LENGTH * sizeof(char));
    memset(input, ' ', SIDE_LENGTH * SIDE_LENGTH * sizeof(char));
    printf("(0,0) is the top left conner.if end, input quit.\n");
    for(;;){
        printf("input x axis y axis num like this format \"x y num\"\n<<");
        if(!(ret = fgets(temp, 100, stdin)) || !strncmp(ret, "\n", 1)){
            printf("input nothing!\n");
            continue;
        }

        if(!strncmp(temp, "quit", 4)){
            return input;
        }
        else if(sscanf(temp, "%c %c %c", &x, &y, &num) != 3){
            perror("input format error!\n");
            return (char *)-ERRFORMAT;
        }
        else{
            input[num(x) + num(y) * 10] = num;
            printf("%c\n", num);
        }
    }
}

void print_matrix(char *matrix, int lengthi, int digit){
    int i, j;
    if(!digit){
        for(i = 0; i < SIDE_LENGTH; i++){//y
            printf("+---------------------------------------+\n");
            printf("| ");
            for(j = 0; j < SIDE_LENGTH; j++){//x
                printf("%c | ", matrix[j + i * SIDE_LENGTH]);
            }
            printf("\b\n");
        }
        printf("+---------------------------------------+\n");
    }
    else{
        for(i = 0; i < SIDE_LENGTH; i++){//y
            printf("+---------------------------------------+\n");
            printf("| ");
            for(j = 0; j < SIDE_LENGTH; j++){//x
                printf("%d | ", matrix[j + i * SIDE_LENGTH]);
            }
            printf("\b\n");
        }
    }
}

/*
 * input: input array
 * length: edge length should be SIDE_LENGTH
 */ 
int convert_input(char *input, int length, char (* matrix)[][SIDE_LENGTH]){
//    char matrix[length][length];
    int i = 0, j = 0;
    int index = 0;

    for(i = 0;i < SIDE_LENGTH; i++){
        for(j = 0;j < SIDE_LENGTH;j++)
            (*matrix)[i][j] = input[index++];
    }
}


