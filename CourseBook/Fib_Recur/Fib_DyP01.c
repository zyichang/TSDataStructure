//
//  Fib_DyP01.c
//  CourseBook
//
//  Created by Yi chang Zhang on 2024/11/2.
//
#include "Fib_Recur.h"

int Fib_DyP01(int n){
    if (n<=1) {
        return n;
    }
    
    int dp[3] = {0};
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    
    for (int i = 1; i < n; i++) {
        dp[2] = dp[0] + dp[1];
        dp[0] = dp[1];
        dp[1] = dp[2];
    }
    
    return dp[2];
}
