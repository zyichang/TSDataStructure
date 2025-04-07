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

// Could Work in Linux but mac and windows Could not.
void PrintMoneyWithSetLocale(int total){
    setlocale(LC_ALL,"");
    printf("%'d", total);
}

void PrintMoneyManually(int TotalMoney){
    if (TotalMoney < 0)
    {
        TotalMoney = - TotalMoney;
        printf("-");
    }
    else if (TotalMoney < 999)
    {
        printf("%d", TotalMoney);
        return;
    }
    
    int Base10[7] = {0};
    int Num = 0;
    for (int i = 0; i < 7; i++)
    {
        if(TotalMoney == 0) break;
        Base10[i] = TotalMoney % 10;
        TotalMoney = TotalMoney / 10;
        Num++;
    }
    for (int i = Num-1; i >= 0; i--)
    {
        if (i == 0)
        {
            printf("%d\n", Base10[i]);
            break;
        }
        else{
            printf("%d", Base10[i]);
        }
        if (i % 3 == 0)
        {
            printf(",");
        }
    }
}

int main(int argc, const char * argv[])
{
    int a, b, total;
    scanf("%d%d", &a, &b);
    total = a +b ;
    PrintMoneyManually(total);
    return 0;
}
