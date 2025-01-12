//
//  main.c
//  1008_Elevator
//
//  Created by Yi chang Zhang on 2024/11/1.
//
//  Sample Input:
//  3 2 3 1
//
//  Sample Output:
//  41

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    int n = 0;
    scanf("%d", &n);
    int num[1000];
    num[0]=0;
    int tempSum = 0;
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &num[i]);
        int move = num[i] -num[i-1];
        if (move > 0) {
            tempSum += move * 6; // 这里错写成5
            tempSum += 5;
            
        }
        else{
            tempSum += move * -4;
            tempSum += 5;
        }
    }
    printf("%d",tempSum);
    return 0;
}
