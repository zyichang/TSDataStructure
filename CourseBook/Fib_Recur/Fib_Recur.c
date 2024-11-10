//
//  Fib_Recur.c
//  Fib_Recur
//
//  Created by Yi chang Zhang on 2024/11/1.
//

#include "Fib_Recur.h"

int Fib_Recur(int n){
    if (n <= 1) {
        return n;
    }
    printf("Fib_Recur(%d): Fib_Recur(%d) + Fib_Recur(%d)\n", n, n-1,n-2);
    return Fib_Recur(n - 1) + Fib_Recur(n - 2);
}
