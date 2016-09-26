#ifndef COMPUTE_H
#define COMPUTE_H


int cells(int x, int y);

#define IN_CELL(cell, x, y) (cells(x, y) == cell)

#endif /* ifndef SYMBOL */
