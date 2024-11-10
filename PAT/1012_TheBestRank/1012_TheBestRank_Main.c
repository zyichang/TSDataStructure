//
//  main.c
//  1012_TheBestRank
//
//  Created by Yi chang Zhang on 2024/11/5.
//
//
//  Sample Input:
//  5 6
//  310101 98 85 88
//  310102 70 95 88
//  310103 82 87 94
//  310104 91 91 91
//  310105 85 90 90
//  310101
//  310102
//  310103
//  310104
//  310105
//  999999
//
//  Sample Output:
//  1 C
//  1 M
//  1 E
//  1 A
//  3 A
//  N/A

#include <stdio.h>


int main(int argc, const char * argv[]) {
    int inputNum = 0;
    int outputNum = 0;
    scanf("%d %d", &inputNum, &outputNum);
    int Records[inputNum][11];
    
    for (int i = 0; i < inputNum; i++) {
        scanf("%d %d %d %d", &Records[i][0], &Records[i][2] , &Records[i][3], &Records[i][4]);
        Records[i][1] = (Records[i][4] + Records[i][2]+ Records[i][3]) / 3.0;
        
        Records[i][5] = 1;
        Records[i][6] = 1;
        Records[i][7] = 1;
        Records[i][8] = 1;
        for (int j = 0; j < i; j++) {
            for (int k = 5; k < 9; k++) {
                if (Records[i][k-4] > Records[j][k-4]) {
                    Records[j][k]++;
                }else if(Records[i][k-4] < Records[j][k-4]){
                    Records[i][k]++;
                }
            }
        }
    }
    
    for (int i = 0; i < inputNum; i++) {
        Records[i][9] = inputNum;
        for (int k = 5; k < 9; k++) {
            if (Records[i][k] < Records[i][9]) {
                Records[i][9] = Records[i][k];
                Records[i][10] = k;
            }
        }
    }
    
    int ID[outputNum];
    for (int i = 0; i < outputNum; i++) {
        scanf("%d", &ID[i]);
    }
    for (int i = 0; i < outputNum; i++) {
        int bestRank = 0;
        int course = 0;
        for (int i2 = 0; i2 < inputNum; i2++) {
            if (ID[i] == Records[i2][0]) {
                bestRank = Records[i2][9];
                course = Records[i2][10];
            }
        }
        if (bestRank == 0) {
            printf("N/A\n");
        }
        switch (course) {
            case 5 :
                printf("%d A\n", bestRank);
                break;
            case 6 :
                printf("%d C\n", bestRank);
                break;
            case 7 :
                printf("%d M\n", bestRank);
                break;
            case 8 :
                printf("%d E\n", bestRank);
                break;
            default:
                break;
        }
    }
    
    return 0;
}
