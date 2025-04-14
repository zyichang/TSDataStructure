//
//  1002A+BforPolynomimals_Main.c
//  1002A+BforPolynomimals
//
//  Created by Yi chang Zhang on 2025/2/23.
//
//
// Sample Input:
// 2 1 2.4 0 3.2
// 2 2 1.5 1 0.5
//
// Sample Output:
// 3 2 1.5 1 2.9 0 3.2
//
//
//
//
/*
但需要测试一些边界情况：

测试用例1：

输入：
2 1 2.4 0 3.2
2 2 1.5 1 0.5

输出：3 2 1.5 1 2.9 0 3.2 → 正确。

测试用例2：

输入：
1 0 -3.2
1 0 3.2

相加后，系数为0.0。四舍五入后为0.0，所以count为0。输出0，后面没有项。

测试用例3：

输入：
2 1 0.05 2 0.15
2 1 0.05 2 0.15

相加后，指数1的系数是0.1，指数2的系数是0.3。四舍五入到一位小数是0.1和0.3。所以输出2 2 0.3 1 0.1。但按降序输出，所以先2，后1。输出应该是2 2 0.3 1 0.1。

但实际运行代码中，数组的处理是否正确？是的。相加后的指数1的系数是0.1，四舍五入到一位小数后是0.1，所以保留。输出顺序是2，1。

测试用例4：

输入：
1 3 0.0
1 3 0.0

处理后的系数是0.0。四舍五入后是0.0，所以count为0，输出0。

测试用例5：

输入：
1 5 0.06
1 5 0.04

相加后的系数是0.10。四舍五入到一位小数是0.1，所以输出项5 0.1。

测试用例6：

输入：
1 5 0.09
1 5 0.01

相加后的系数是0.10。四舍五入到一位小数是0.1。输出5 0.1.

测试用例7：

输入两个项，导致系数相加后的值为0.049：

例如，输入：

1 5 0.049
0

处理后的系数是0.049。四舍五入到一位小数是0.0，所以count为0，输出0.

另一个例子，输入：

1 5 0.0500000000001

此时系数在四舍五入到一位小数时是0.1，所以输出项5 0.1.

这样，代码的处理是正确的。

现在需要考虑浮点数的四舍五入是否正确。例如，round函数是否能够正确将数值四舍五入到一位小数。

例如，0.05乘以10等于0.5，round(0.5)是1，除以10得到0.1。但0.049乘以10是0.49，round得到0，除以10得到0.0。这样处理是正确的。

因此，代码应该能够正确处理所有情况。

另外，需要注意的是，在C语言中，浮点数的比较是否准确。例如，在判断四舍五入后的rounded是否等于0.0时，是否会有精度问题。例如，假设四舍五入后的值是0.0，但是由于浮点数的精度问题，rounded可能存储为0.0或者非常接近零的值。

例如，假设某个系数在四舍五入后的值是0.0，那么rounded变量应该等于0.0。例如，rounded是通过round计算得到的，所以如果round后的结果确实是0，那么rounded变量应该精确等于0.0。例如：

round(0.0499 * 10) = round(0.499) = 0 → 0/10 = 0.0.

round(0.05 * 10) = round(0.5) = 1 → 0.1.

因此，在代码中，rounded的值要么是整数倍的0.1，或者0.0。例如，rounded的值只能是0.0、0.1、0.2等。因此，判断rounded != 0.0是安全的，因为rounded的构造方式使得它只能是这些离散的值。

因此，在代码中，判断rounded是否为零是准确的，不会有浮点数的精度问题。

综上所述，这样的代码应该可以正确处理所有情况。*/

#include "1002_A+BforPolynomimals_Main.h"

int APlusBforPolynomimalsFinalVersion(){
    // int K = 0, exp = 0, effi = 0; 
    // Error: effi should be bype folat.
    int K = 0, exp = 0;
    double effi = 0;
    //Error:  int N[1001] = {0};
    //Collection N shoud be a float collection if set to int type , 0.5 for example will be 0.
    double N[1001] = {0.0};
    int A = 0;

    // First Row
    scanf("%d", &K);
    for (int i = 0; i < K; i++){
        scanf("%d %lf", &exp, &effi);
        N[exp] += effi;
    }
    // Second Row
    scanf("%d", &K);
    for (int i = 0; i < K; i++){
        scanf("%d %lf", &exp, &effi);
        N[exp] += effi;
    }
    
    // Print All no zore items
    // Error: for (int i = 0; i < 1000; i++){
    // max number should be 1000 so the collection max index should be N[1000] which means i < 1001 be right,

    //Error    
    //Error    if (N[i] != 0) {A ++;} 
    //
    for (int i = 0; i < 1001; i++){
        double rounded = round(N[i] * 10) / 10;
        if (rounded != 0.0) {
            A ++;
        }
    }
    printf("%d", A);

    // Print exp and effi
    for (int i = 1001; i >= 0; i--)
    {
        double rounded = round(N[i] * 10) / 10;
        if (rounded != 0.0) {
            printf(" %d %.1f", i, rounded);
        }
    }
    return 0;
}