//
//  1001_APlusBFormat_Main.c
//  1001_APlusBFormat
//
//  Created by Yi chang Zhang on 2025/1/28.
//
//  Sample Input:
//
//  -1000000 9
//  Sample Output:
//
//  -999,991

#include <stdio.h>
#include <locale.h>

int main(int argc, const char * argv[])
{
    int a, b;
    scanf("%d%d", &a, &b);
    setlocale(LC_ALL,"");
    printf("%'d", a + b);
    return 0;
}
