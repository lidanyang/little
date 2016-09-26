#include "common.h"

int verify_correction(char *input){
    unsigned int bitmap[2] = {0};
    int i = 0;
    int j = 0;

    printf("verify the correctness of the result!\n");
    char matrix[SIDE_LENGTH][SIDE_LENGTH];
    convert_input(input, SIDE_LENGTH, &matrix);    
    for(i = 0 ; i < SIDE_LENGTH ; i++){
        for(j = 0 ; j < SIDE_LENGTH ; j++){
            switch(matrix[i][j]){
                case '0':
                    bitmap[0] &= 1<<0;
                    break;
                case '1':
                    bitmap[0] &= 1<<1;
                    break;
                case '2':
                    bitmap[0] &= 1<<2;
                    break;
                case '3':
                    bitmap[0] &= 1<<3;
                    break;
                case '4':
                    bitmap[0] &= 1<<4;
                    break;
                case '5':
                    bitmap[0] &= 1<<5;
                    break;
                case '6':
                    bitmap[0] &= 1<<6;
                    break;
                case '7':
                    bitmap[0] &= 1<<7;
                    break;
                case '8':
                    bitmap[0] &= 1<<8;
                    break;
                case '9':
                    bitmap[0] &= 1<<9;
                    break;
                default:
                    perror("verify failed!\n");
                    return -ERRFAIL;
            }
            switch(matrix[j][i]){
                case '0':
                    bitmap[1] &= 1<<0;
                    break;
                case '1':
                    bitmap[1] &= 1<<1;
                    break;
                case '2':
                    bitmap[1] &= 1<<2;
                    break;
                case '3':
                    bitmap[1] &= 1<<3;
                    break;
                case '4':
                    bitmap[1] &= 1<<4;
                    break;
                case '5':
                    bitmap[1] &= 1<<5;
                    break;
                case '6':
                    bitmap[1] &= 1<<6;
                    break;
                case '7':
                    bitmap[1] &= 1<<7;
                    break;
                case '8':
                    bitmap[1] &= 1<<8;
                    break;
                case '9':
                    bitmap[1] &= 1<<9;
                    break;
                default :
                    perror("verify failed!\n");
                    return -ERRFAIL;
            }
        }
        if(bitmap[0] != (1<<10 - 1) || bitmap[1] != (1<<10 - 1)){
            perror("verify failed!\n");
            return -ERRFAIL;
        }
    }
    printf("Verify Successfully!\n");
    return 0;
}

void verify_rest_number(int x, int y){
    int i = 0;
    printf("x: %d, y: %d", x, y);
    while(i++ < SIDE_LENGTH){
        if(!((bitmap_per_num[x][y]<<i)&1))
            printf("%d  ", i);
    }
    printf("\n");
}
