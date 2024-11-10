//
//  main.c
//  1014_WaitinginLine
//
//  Created by Yi chang Zhang on 2024/11/7.
//
//  Sample Input:
//  2 2 7 5
//  1 2 6 4 3 534 2
//  3 4 5 6 7
//
//  Sample Output:
//  08:07
//  08:06
//  08:10
//  17:00
//  Sorry
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    int front;
    int rear;
    int* data;
    int* coID;
} SqQueue;

int main(int argc, const char * argv[]) {
    
    int N = 0; // ≤20, windows provide service.
    int M = 0; // ≤10, waiting area
    int K = 0; // ≤1000, number of customers
    int Q = 0; // ≤1000, number of customer queries
    scanf("%d %d %d %d", &N, &M, &K, &Q);
    if (N == 0 || M == 0 || K ==0) {
        return 0;
    }
    int T[K];
    memset(T, 0, sizeof(T)); // the processing time of the K customers
    for (int i=0; i < K; i++) {
        scanf("%d", &T[i]);
    }
    SqQueue coQueue[N];
    for (int i = 0; i < N; i++) {
        coQueue[i].front = 0;
        coQueue[i].rear = 0;
        coQueue[i].data = (int*)malloc((M + 1) * sizeof(int));
        coQueue[i].coID = (int*)malloc((M + 1) * sizeof(int));
    }
    
    int flag = 0;
    // initial
    for (int i = 0; i < M ; i++) {
        if (flag >= K) break;
        for (int j = 0; j < N ; j++) {
            flag = i*N+j;
            if (flag >= K) break;
            coQueue[j].data[coQueue[j].rear] = T[flag];
            coQueue[j].coID[coQueue[j].rear] = flag;
            coQueue[j].rear = (coQueue[j].rear + 1) % (M + 1);
        }
        
    }
    int Times = 0;
    int Tick = 540;
    int close[N];
    memset(close, 0, sizeof(close));
    
    // Customers waiting outside the yellow line exist.
    while (flag < (K)) {
        Tick = 540;
        for (int i = 0; i < N; i++) {
            if (coQueue[i].data[coQueue[i].front] < Tick) {
                Tick = coQueue[i].data[coQueue[i].front];
            }
        }
        
        for (int i = 0; i < N; i++) {
            coQueue[i].data[coQueue[i].front] -= Tick;
            if (coQueue[i].data[coQueue[i].front] == 0) {
                if (close[i] == 1) {
                    T[coQueue[i].coID[coQueue[i].front]] = -1;
                }else{
                    T[coQueue[i].coID[coQueue[i].front]] = (Times+Tick);
                }
                if ((Times + Tick)>=540) {
                    close[i] = 1;
                }
                coQueue[i].front = (coQueue[i].front + 1) % (M + 1);
                if (flag >= K) break;//没必要。代码当flag < k -1 时循环已经结束。
                flag++;
                coQueue[i].data[coQueue[i].rear] = T[flag];
                coQueue[i].coID[coQueue[i].rear] = flag;
                coQueue[i].rear = (coQueue[i].rear + 1) % (M + 1);
            }
        }
       
        Times += Tick;
    }
    // 这里有两种结束循环的方案 flag < k ; if (flag >= K) break; 和flag < k-1.
    // 第一种出现问题在于。break; 会直接结束循环也就 假设i = 1break之后。从2 - N的情况都不会被执行。也就是说此时2-N应该减少的Tick都没有被减少然后。进入下一环节就导致全部多次Tick的时间。
    // 4 1 5 5
    // 2 2 2 2 4
    
    //All customers are already lined up separately at each window within the yellow line.
    for (int i = 0; i < N; i++) {
        int TimesNow = Times;
        while (coQueue[i].front != coQueue[i].rear) {
            if (close[i] == 1) {
                TimesNow += coQueue[i].data[coQueue[i].front];
                T[coQueue[i].coID[coQueue[i].front]] = -1;
                coQueue[i].front = (coQueue[i].front + 1) % (M + 1);
                continue;
            }
            TimesNow += coQueue[i].data[coQueue[i].front];
            T[coQueue[i].coID[coQueue[i].front]] = TimesNow;
            coQueue[i].front = (coQueue[i].front + 1) % (M + 1);
            if (TimesNow >= 540) {
                close[i] = 1;
            }
            
        }
    }
    
    
    
    int out = 0;
    for (int i = 0; i < Q; i++) {
        scanf("%d", &out);
        if (T[out - 1] == -1) {
            printf("Sorry\n");
        }else{
            printf("%02d:%02d\n", 8+T[out - 1]/60,T[out - 1]%60);
        }
    }
    return 0;
}
