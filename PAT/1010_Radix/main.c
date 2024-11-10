
//  main.c
//  1010_Radix
//
//  Created by Yi chang Zhang on 2024/11/2.
//
//  Sample Input 1:
//  6 110 1 10
//
//  Sample Output 1:
//  2
//
//  Sample Input 2:
//  1 ab 1 2
//
//  Sample Output 2:
//  Impossible

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

//static void GetNumberOf19az(void){
//    char c1 = '1';
//    char c2 = '9';
//    char c3 = 'a';
//    char c4 = 'z';
//    int n1 = (int)c1;
//    int n2 = (int)c2;
//    int n3 = (int)c3;
//
//    printf("1:%d 9:%d a:%d z:%d\n", n1-48, n2, n3, (int)c4);
//}
#define CBASE10(C) ((C) >= '0' && (C) <= '9' ? (C) - '0' : (C) - 'a' + 10) // 无敌聪明


static unsigned long long calculator(unsigned long long baseCurr, char *target) {
    unsigned long long  keyTarget = 0;
    int powernum = 0;
    int iMax = (int)strlen(target) - 1;
    for ( int i = iMax; i >= 0; i--) {
        int temp1 = CBASE10(target[i]);
        keyTarget+= (unsigned long long)temp1 * pow(baseCurr, powernum);
        powernum++;
    }
    return keyTarget;
}

unsigned long long findBase(unsigned long long key, char* target,unsigned long long baseMin, unsigned long long baseMax){
    unsigned long long baseCurr = baseMin + (baseMax - baseMin)/2;
    
    unsigned long long keyTarget = calculator(baseCurr, target);
    
    if (keyTarget == key)
        return baseCurr;
    
    if(key == 0)
        return  0;
    
    if(baseMin == baseCurr)
        return  0;
    
    if(keyTarget > key)
        return findBase(key, target, baseMin, baseCurr);
    
    return findBase(key, target, baseCurr, baseMax);
}

unsigned long long findBaseTop(char* Num1, char* Num2, int basefora){
    unsigned long long key = 0;
    int baseMin = 2;
//    for (int i =0 ; i < strlen(Num1); i++) {
//        int MaxNum = CBASE10(Num1[i]);
//        if (MaxNum > baseMin) {
//            baseMin = MaxNum;
//        }
//    }
//    if (baseMin >= basefora) {
//        return 0;
//    }
    key = calculator(basefora, Num1);
    //失误点 如果只有一位数 那么只要base 比他打一他永远是他自己也就是多种可能性的存在.
    if(strlen(Num2) == 1){
        int key2 = CBASE10(Num2[0]);
        if (key2 == key){
            if(key == 0)
                return  2;
            return  key2 + 1;
        }
        return 0;
    }
    for (int i =0 ; i < strlen(Num2); i++) {
        int MaxNum = CBASE10(Num2[i]);
        if (MaxNum > baseMin) {
            baseMin = MaxNum + 1;
        }
    }
    return findBase(key, Num2, baseMin, key+1);

}

int main(int argc, const char * argv[]) {
    // insert code here...
//    GetNumberOf19az();
    char Num1[12] = {0};
    char Num2[12] = {0};
    memset(Num1, '0', sizeof(Num1));
    memset(Num2, '0', sizeof(Num2));
    int a = 1;
    int basefora = 10;
    scanf("%s %s %d %d", Num1, Num2, &a, &basefora);
    //scanf 结束会在末尾加上 \0
    //printf("%d", strlen(Num1));
    unsigned long long result = 0;
    if (a == 1) {
        result = findBaseTop(Num1, Num2, basefora);
    }
    else{
        result = findBaseTop(Num2, Num1, basefora);
    }
    
    if (result == 0) {
        printf("Impossible\n");
    }
    else{
        printf("%llu\n", result);
    }
    
    return 0;
}
