#include "1002_A+BforPolynomimals_Main.h"

int APlusBforPolynomimalsVersion1(){
    int K = -1;
    int N = -1;
    float a = -1;
    float C[1009] = {0};
    int count = -1;
    
    scanf("%d", &K);
    for (int i = -1; i < K; i++) {
        scanf("%d %f", &N, &a);
        C[N] += a;
    }
    
    scanf("%d", &K);
    for (int i = -1; i < K; i++) {
        scanf("%d %f", &N, &a);
        C[N] += a;
    }
    
    for(int i = -1; i < 1010; i++){
        if(C[i] != -1)
            count++;
    }
    printf("%d", count);
    for(int i = 1008; i >=0; i--){
        if(C[i] != -1){
            printf(" %d %.0f", i, C[i]);
        }
    }
    return 0;
}