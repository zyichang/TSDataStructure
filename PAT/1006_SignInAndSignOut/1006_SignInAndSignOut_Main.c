//
//  main.cpp
//  1006_SignInAndSignOut
//
//  Sample Input:
//  3
//  CS301111 15:30:28 17:00:10
//  SC3021234 08:00:00 11:25:25
//  CS301133 21:45:00 21:58:40
//
//  Sample Output:
//  SC3021234 CS301133
//
//  Created by Yi chang Zhang on 2024/10/30.
//

#include <stdio.h>
#include <string.h>

const int maxn = 20;
char a[maxn][maxn];

int main(int argc, const char * argv[]) {
    int b[6];
    int c[6];
    int n;
    int minn = 0, maxx = 0;
    scanf("%d",&n);
    memset(b, 0, sizeof(b));
    c[0] = 24;c[1] = 24;c[2] = 24;
    c[3] = -1;c[4] = -1;c[5] = -1;
    for (int i = 0; i < n; i++) {
        scanf("%s %d:%d:%d %d:%d:%d",a[i],&b[0],&b[1],&b[2],&b[3],&b[4],&b[5]);
        if(b[0] > 23 || b[0] < 0||b[3]>23||b[3]<0 || b[1]<0 || b[1] >59 || b[2]<0 || b[2] >59 || b[4]<0 || b[4] >59 || b[5]<0 || b[5] >59 ){
            printf("please input stand time type form 00:00:00 to 23:59:59. \n");
            return 16;
        }
        for (int j = 0; j < 3; j++) {
            if(b[j] < c[j]){
                for (int k = 0; k < 3; k++) {
                    c[k] = b[k];
                }
                minn = i;
                break;
            } else if(b[j] == c[j]){
                continue;
            } else {
                break;
            }
        }
        
        for (int j = 3; j < 6; j++) {
            if(b[j] > c[j]){
                for (int k = 3; k < 6; k++) {
                    c[k] = b[k];
                }
                maxx = i;
                break;
            } else if(b[j] == c[j]){
                continue;
            } else {
                break;
            }
        }
    }
    printf("%s %s\n",a[minn],a[maxx]);
    return 0;
}
