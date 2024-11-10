//
//  main.c
//  PointerInC
//
//  Created by Yi chang Zhang on 2024/11/3.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void changeintVar(int intVar){
    intVar = 1;
}
void changeintVar2(int* intVar){
    *intVar = 1;
}
void changArrayItem(int* arrayVar){
    arrayVar[0] = 1;
    arrayVar[1] = 1;
}
void changArrayItem2(int** arrayVar){
    **arrayVar = 2;
    *(*arrayVar + 1) = 2;
}
int main(int argc, const char * argv[]) {
    int a = ((2+2+4))/3+0.5;
    printf("%d\n", a);
    int intVar = 0;
    int* arrayVar = (int*) malloc(3 * sizeof(int));//int *ptr = (int *)malloc(sizeof(int) * 10);
    *arrayVar = 0;
    *(arrayVar+1) = 0;
    *(arrayVar+2) =  0;
    changeintVar(intVar);
    printf("Use Fn changeintVar(int intVar) change intVar: %d\n", intVar);
    changeintVar2(&intVar);
    printf("Use Fn changeintVar(int intVar) change intVar: %d\n", intVar);
    changArrayItem(arrayVar);
    printf("%d\n",&arrayVar);
    printf("Use Fn changArrayItem(int* arrayVar) change Array Item: %d %d\n", arrayVar[0], arrayVar[1]);
    int** b = &arrayVar;
    changArrayItem2(b);
    printf("Use Fn changArrayItem(int&* arrayVar) change Array Item: %d %d\n", arrayVar[0], arrayVar[1]);
    return 0;
}
