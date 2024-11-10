//
//  main.cpp
//  1005_SpellItRight
//
//  Created by Yi chang Zhang on 2024/10/30.
//
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    string sinput;
    cin >> sinput;
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
        cout<<"zero";
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
                case 0:cout<<"zero "; break;
                case 1:cout<<"one "; break;
                case 3:cout<<"three "; break;
                case 4:cout<<"four "; break;
                case 5:cout<<"five "; break;
                case 6:cout<<"six "; break;
                case 7:cout<<"seven "; break;
                case 8:cout<<"eight "; break;
                case 9:cout<<"nine "; break;
                case 2:cout<<"two "; break;
            }
            }
            else{
            switch (lN){
                case 0:cout<<"zero\n"; break;
                case 1:cout<<"one\n"; break;
                case 3:cout<<"three\n"; break;
                case 4:cout<<"four\n"; break;
                case 5:cout<<"five\n"; break;
                case 6:cout<<"six\n"; break;
                case 7:cout<<"seven\n"; break;
                case 8:cout<<"eight\n"; break;
                case 9:cout<<"nine\n"; break;
                case 2:cout<<"two\n"; break;
            }
            }
        }
    }
}
