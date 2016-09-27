#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char *optString = "an";
int map[9][9];
FILE *fp_result;
int countall = 0;
int stepbysetp = 0;

void print_map(FILE *fp){
    int i, j;
    printf("%s", __func__);
    for(i = 0; i < 9; i++){//y
        fprintf(fp, "+-----------------------------------+\n");
        fprintf(fp, "| ");
        for(j = 0; j < 9; j++){//x
            fprintf(fp, "%d | ", map[i][j]);
        }
        fprintf(fp, "\b\n");
    }
    fprintf(fp, "+-----------------------------------+\n");
}


int verify(int x, int y){
    int i = 0, j, row, col;
    col = (y / 3) * 3;
    row = (x / 3) * 3; 
    //printf("%d, %d, %s, %d\n", x, y, __func__, __LINE__);
    for(i = 0; i < 9 ; i++){
    //printf("%s  %d\n", __func__,__LINE__);
        if(map[i][y] == map[x][y] && i != x){
    //printf("%s  %d\n", __func__,__LINE__);
            return -1;
        }
    }
    for(i = 0; i < 9 ; i++){
    //printf("%s  %d\n", __func__,__LINE__);
        if(map[x][y] == map[x][i] && y != i){
    //printf("%s  %d\n", __func__,__LINE__);
            return -1;
        }
    }
    for( i = col; i <= col + 2; i++){
        for( j = row; j <= row + 2; j++){
    //printf("%s  %d\n", __func__,__LINE__);
            if(map[x][y] == map[j][i] && x!=j && y!=i){
    //printf("%s  %d\n", __func__,__LINE__);
                return -1;
            }
        }
    } 
    //printf("%s  %d\n", __func__,__LINE__);
    return 0;
}


int answer = 0;

void walk(int count){
    int i, j, k;
    if(81 == count){
        if(stepbysetp) {
            if((fp_result = fopen("result.txt", "w")) == NULL){
                exit(EXIT_FAILURE);
            }
            print_map(fp_result);
            print_map(stdout);
            getchar();    
            fclose(fp_result);
        }
        else if(countall){
            answer++;
        }
        return;
    }
    j = count % 9;
    i = count / 9;
    if(map[i][j] == 0){
       for(k = 1; k <= 9 ;k++ ){
           map[i][j] = k;
           if(!verify(i, j)){
               walk(count + 1);
           }
       }    
       map[i][j] = 0;
    }
    else{
        walk(count + 1);
    }

}


int main(int argc, const char *argv[])
{
    int i,j;
    FILE *fp_data; 
    int opt = 0;
    opt = getopt(argc, argv, optString);
    while(opt != -1){
        switch(opt){
            case 'a':
                countall = 1; 
                break;
            case 'n':
                stepbysetp = 1;
                break;
            default:
                break;
        }
        opt = getopt(argc, argv, optString);
    }
    if((fp_data = fopen("data", "w+")) == NULL){
        return EXIT_FAILURE; 
    }

    for(i = 0; i < 9 ;i++){
        for(j = 0;j < 9 ;j++){
            map[i][j] = 0;
        }
    }
    FILE *fp = fopen("matrix.txt","rw");
    char c = '0';
    for (i = 0; i < 9 ; i++){
        for (j = 0; j < 9; j++)
        {
            fscanf(fp, "%c", &c);
    //        putchar(c);
            if(c == '.'){
                continue;
            }
            map[i][j] = c - '0';
        }
        fscanf(fp, "%c", &c);
    }
    printf("\n");
    walk(0);
    printf("total %d answer!\n", answer);
    fprintf(fp_data, "%d", answer);
    return 0;
}
