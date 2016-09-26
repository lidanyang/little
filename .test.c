#include<stdio.h>
#include<string.h>
int main(int argc, const char *argv[])
{
    char temp[10];
    fgets(temp, 10 , stdin);
    printf("%s", temp);
    return 0;
}
