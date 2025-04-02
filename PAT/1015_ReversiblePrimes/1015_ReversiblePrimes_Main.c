//
//  main.c
//  1015_ReversiblePrimes
//
//  Created by Yi chang Zhang on 2024/11/9.
//
//  Sample Input:
//  73 10
//  23 2
//  23 10
//  -2
//
//  Sample Output:
//  Yes
//  Yes
//  No
//

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

static int isPrime(int n) {
    if (n <= 1) {
        return 0;  // Numbers less than 2 are not prime
    }
    if (n <= 3) {
        return 1;   // 2 and 3 are prime numbers
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return 0;  // Eliminate multiples of 2 and 3
    }
    
    // Check for divisors up to the square root of n
    for (int i = 5; i <= sqrt(n); i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return 0;
        }
    }
    return 1;
}

static int isReversePrime(int N, int D){
    node* L = NULL;
    node* P = NULL;
    node* T = NULL;
    L = (node*)malloc(sizeof(node));// Head Node
    L->next = NULL;
    P = L;
    while (1) {
        if (N == 0) break;
        int currDigit;
        T = malloc(sizeof(node));
        currDigit = N%D;
        N=N/D;
        T->data = currDigit;
        T->next = NULL;
        T->next = L->next;
        L->next = T;
    }
    P = L->next;
    int power = 0;
    int reverseN = 0;
    while (1) {
        if(P == NULL) break;
        reverseN += P->data * pow(D, power);
        power++;
        P = P->next;
    }
    while (L != NULL) {
        P = L;
        L = L->next;
        free(P);
    }
    return isPrime(reverseN);
}


int main(int argc, const char * argv[]) {
    while (1) {
        int N;
        int D;
        scanf("%d", &N);
        if (N <= 0) break;

        scanf("%d", &D);
        if (N > 100000 || D > 10) break;
        
        if (isPrime(N) == 0) {
            printf("No\n");
            continue;
        }
        
        if (isReversePrime(N, D) == 1) {
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
    return 0;
}
