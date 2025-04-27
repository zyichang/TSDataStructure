//
//  1002A+BforPolynomimals_Main.c
//  1002A+BforPolynomimals
//
//  Created by Yi chang Zhang on 2025/2/23.
//
//
// Sample Input:
// 2 1 2.4 0 3.2
// 2 2 1.5 1 0.5
//
// Sample Output:
// 3 2 1.5 1 2.9 0 3.2
//
//
//
//

#include "1002_A+BforPolynomimals_Main.h"

int mainErrorCode(int argc, const char * argv[]) {
    int K = 0;
    int N = 0;
    float a = 0;
    float C[1010] = {0};
    int count = 0;
    
    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        scanf("%d %f", &N, &a);
        C[N] += a;
    }
    
    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        scanf("%d %f", &N, &a);
        C[N] += a;
    }
    
    for(int i = 0; i < 1010; i++){
        if(C[i] != 0)
            count++;
    }
    printf("%d", count);
    for(int i = 1009; i >=0; i--){
        if(C[i] != 0){
            printf(" %d %.1f", i, C[i]);
        }
    }
    return 0;
}