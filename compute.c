#include "common.h"

//compute the cells the number belongs to, cells number from 1 ~ 9
/*       cell 1(0,0)    cell 2(1,0)    cell 3(2,0)
         0    0    0    0    0    0    0    0    0
         0    0    0    0    0    0    0    0    0
         0    0    0    0    0    0    0    0    0
         cell 4(0,1)    cell 5(1,1)    cell 6(2,1)
         0    0    0    0    0    0    0    0    0
         0    0    0    0    0    0    0    0    0
         0    0    0    0    0    0    0    0    0
         cell 7(0,2)    cell 8(1,2)    cell 9(2,2)
         0    0    0    0    0    0    0    0    0
         0    0    0    0    0    0    0    0    0
         0    0    0    0    0    0    0    0    0
*/
int cells(int x, int y){
    return x / 3 + (y / 3) * 3 + 1;
}

void look_num_in_one_cell(int (* matrix)[][SIDE_LENGTH], int x, int y){
    int cell;
    int i, j;
    int middle_x,middle_y;

    cell = cells(x, y);
    //assert(!IN_CELL(cell, x, y));

    middle_y = ((cell - 1)/ 3) * 3 + 1;
    middle_x = (cell % 3 - 1) * 3 + 1; 
    for(i = middle_x - 1; i <= middle_x + 1; i++){
        for(j =  middle_y - 1; j <= middle_y + 1; j++){
            if ((*matrix)[i][j] !=' ')
            {
                bitmap_per_num[x][y] &= 1<<(int)num((*matrix)[i][j]);
            }
        }
    }
}

void look_num_in_x_y(int (* matrix)[][SIDE_LENGTH], int x, int y){
    int i;

    for(i = 0; i < SIDE_LENGTH; i++){
        if ((*matrix)[x][i] !=' '){
            bitmap_per_num[x][y] &= 1<<(int)num((*matrix)[x][i]);
        }
    }

    for(i = 0; i < SIDE_LENGTH; i++){
        if ((*matrix)[i][y] !=' '){
            bitmap_per_num[x][y] &= 1<<(int)num((*matrix)[i][y]);
        }
    }
      
}

void look_one_num(int (* matrix)[][SIDE_LENGTH], int x, int y){
    int cell;
    assert((x < 10) && (x >= 0));
    assert((y < 10) && (y >= 0));

    cell = cells(x, y);
    if((*matrix)[x][y] != ' '){
        bitmap_per_num[x][y] &= 1<<(int)num((*matrix)[x][y]);
    }
    look_num_in_one_cell(matrix, x, y);
    look_num_in_x_y(matrix, x, y);
}


