//
//  main.c
//  Fib_Recur
//
//  Created by Yi chang Zhang on 2024/11/1.
//

#include <stdio.h>
#include "Fib_Recur.h"

int main(int argc, const char * argv[]) {
    printf("Please input how to calculate Fib (default is Recur. 1 is Recur. 2 is Dynamic Plan 01.):");
    int type = 0;
    scanf("%d", &type);
    int a;
    printf("Please enter the number of terms to calculate the Fibonacci series:");
    scanf("%d", &a);
    int result = 0;
    switch (type) {
        case 1:
            result = Fib_Recur(a);
            break;
        case 2:
            result = Fib_DyP01(a);
            break;
        default:
            break;
    }
    printf("Result is %d.\n", result);
    return 0;
}
