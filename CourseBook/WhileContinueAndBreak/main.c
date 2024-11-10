//
//  main.c
//  WhileContinueAndBreak
//
//  Created by Yi chang Zhang on 2024/11/9.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int flag = 0;
    int K = 1001;
    int breakPoint = 0;
    while ( flag < 1000) {
        for (int i =0; i < K; i++) {
            printf("xuhuan:%dci\n", i);
            if (breakPoint > 10) {
                break;
            }
            
            breakPoint ++;
        }
        flag ++;
        break;
    }
    printf("flag: %d   breakPoint: %d\n", flag, breakPoint);
    int test = 0;
    while (1) {
        test ++;
        printf("test: %d", test);
        if(test > 10) break;
    }
    return 0;
}
