//
//  main.cpp
//  1005_SpellItRight
//
//  Created by Yi chang Zhang on 2024/10/30.
//
#include <stdio>
#include <string>
#include <cmath>

int main()
{
    char sinput[100];
    scanf("%s\n",sinput);
    long Result = 0;
    int length = sinput.length();
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
                case 0:print("zero "); break;
                case 1:print("one "); break;
                case 2:print("two "); break;
                case 3:print("three "); break;
                case 4:print("four "); break;
                case 5:print("five "); break;
                case 6:print("six "); break;
                case 7:print("seven "); break;
                case 8:print("eight "); break;
                case 9:print("nine "); break;
            }
            }
            else{
            switch (lN){
                case 0:print("zero\n"); break;
                case 1:print("one\n"); break;
                case 2:print("two\n"); break;
                case 3:print("three\n"); break;
                case 4:print("four\n"); break;
                case 5:print("five\n"); break;
                case 6:print("six\n"); break;
                case 7:print("seven\n"); break;
                case 8:print("eight\n"); break;
                case 9:print("nine\n"); break;
            }
            }
        }
    }
}
