//
//  main.c
//  1011_World_Cup_Betting
//
//  Created by Yi chang Zhang on 2024/11/3.
//

//  Sample Input:
//  1.1 2.5 1.7
//  1.2 3.1 1.6
//  4.1 1.2 1.1
//
//  Sample Output:
//  T T W 39.31

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    float game[3][3];
    for (int i = 0; i < 3; i++) {
        scanf("%f %f %f", &game[i][0],  &game[i][1],  &game[i][2]);
    }
    float totalOdd = 1;
    for (int i = 0; i < 3; i++) {
        float temp = 0;
        int flag = 0;
        for (int j = 0; j < 3; j++) {
            flag = (game[i][j] > temp) ? j : flag;
            temp = (game[i][j] > temp) ? game[i][j] : temp;
        }
        totalOdd *= temp;
        switch (flag) {
            case 0:
                printf("W ")); break;
            case 1:
                printf("T ")); break;
            case 2:
                printf("L ")); break;
        }
    }
    printf("%.2f", (totalOdd * 0.65 - 1) *2);
    return 0;
}
