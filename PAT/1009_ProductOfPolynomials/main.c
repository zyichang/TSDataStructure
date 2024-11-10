//
//  main.c
//  1009_ProductOfPolynomials
//
//  Created by Yi chang Zhang on 2024/11/1.
//

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]){
    int k1 = 0, k2 =0, i = 0, t, count = 0, max1 = 0, max2 = 0;
    float num;
    float line1[1010] = {0};
    float line2[1010] = {0};
    float line[2010] = {0};

    scanf("%d", &k1);
    for(i = 0; i < k1; i++){
        scanf("%d %f", &t, &num);
        line1[t] += num;
        if(t > max1){
            max1 = t;
        }
    }
   
    scanf("%d", &k2);
    for(i = 0; i < k2; i++){
        scanf("%d %f", &t, &num);
        line2[t] += num;
        if(t > max2){
            max2 = t;
        }
    }

    for (int i = 0; i <= max1; i++) {
        if (line1[i] != 0) {
            for (int j = 0 ; j <= max2; j++) {
                if(line2[j] == 0) continue;
                float temp = line1[i] * line2[j];
                line[i+j] += temp;
            }
        }
    }
    
    for(i = 0; i <= (max1+max2); i++){
        if(line[i] != 0)
            count++;
    }
    
    printf("%d", count);
    for(i = (max1+max2); i >=0; i--){
        if(line[i] != 0){
            printf(" %d %.1f", i, line[i]);
        }
    }
    return 0;
}

