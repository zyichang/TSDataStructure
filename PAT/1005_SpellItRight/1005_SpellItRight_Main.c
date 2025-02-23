//
//  main.cpp
//  1005_SpellItRight
//
//  Created by Yi chang Zhang on 2024/10/30.
//
// Sample Input:
// 12345

// Sample Output:
// one five

#include <stdio.h>
#include <string.h>
#include <math.h>

int main(int argc, const char * argv[])
{
    char sinput[100];
    scanf("%s",sinput);
    long Result = 0;
    int length = strlen(sinput);
    for(int i = 0; i < length; i++ ){
        Result = Result + (sinput[i] - '0');
    }
    //1*length <  value of Result < 9 * length
    //length =1000 1000< Result < 9000
    // length = 100 100< Result < 900
    //length = 200 200M< Result < 1800
    //l =999 999< R < 9000
    if(Result==0){
        printf("zero");
        return 0;
    }
    
    int squaredN = 0;
    
    while(pow(10, squaredN) < length){
        squaredN = squaredN+1;
    }
    
    int BeginFlag = 0;
    for(squaredN; squaredN >= 0;squaredN--){
        int lN = 0;
        int divider = pow(10,squaredN);
        lN = Result / divider;
        Result = Result % divider;
        
        if(lN != 0){
            BeginFlag = 1;
        }
        
        if(BeginFlag == 1 ){
            if(squaredN !=0){
            switch (lN){
                case 0:printf("zero "); break;
                case 1:printf("one "); break;
                case 2:printf("two "); break;
                case 3:printf("three "); break;
                case 4:printf("four "); break;
                case 5:printf("five "); break;
                case 6:printf("six "); break;
                case 7:printf("seven "); break;
                case 8:printf("eight "); break;
                case 9:printf("nine "); break;
            }
            }
            else{
            switch (lN){
                case 0:printf("zero\n"); break;
                case 1:printf("one\n"); break;
                case 2:printf("two\n"); break;
                case 3:printf("three\n"); break;
                case 4:printf("four\n"); break;
                case 5:printf("five\n"); break;
                case 6:printf("six\n"); break;
                case 7:printf("seven\n"); break;
                case 8:printf("eight\n"); break;
                case 9:printf("nine\n"); break;
            }
            }
        }
    }
}
