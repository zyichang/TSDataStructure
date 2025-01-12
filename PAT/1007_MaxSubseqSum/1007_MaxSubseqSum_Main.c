//
//  main.c
//  1007_MaxSubseqSum
//
//  Created by Yi chang Zhang on 2024/10/31.
//
//  Sample Input:
//  10
//  -10 1 2 3 4 -5 -23 3 7 -21
//
//  Sample Output:
//  10 1 4

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//typedef struct Linknode{
//    int data ; // 数 据 域
//    int start;
//    int end;
//    struct Linknode *next; // 指 针 域
//} LinkNode,*LinkList;

int main(int argc, const char * argv[]) {
    
//    const int maxn = 600000;
//    int a[1000];
//    char input[maxn];
//
//    int c[6];
//    int n;
//    int minn = 0, maxx = 0;
//    scanf("%d",&n);
//    scanf("%s",input);
//    //we need a core. Obviously the core is the most large sum collection.
//    int core = 0;
    //Solution 1 trverse all possibility max collection with one number, with two number with three number ....
    //Solution 2 from first num find a collection larger than zero,then form next of last num begin to find the large
    //还是用中文吧。首先从数组第一项开始，遍历累加（从第一个正数开始）构建第一个集合c1，找到第一个累加之后使c1值减小的项item1（这一项为负数），然后从这一项开始开始构建集合c2，同样操作找到第一个使集合c2减小的项item2。
    //此时c2>0 则c2并入C1。重新开始c2
    //此时c2<0 则直接开始c3
    //假设n次后结束如果最后一个collection 排除集合第一项进入对比。
    //抽象出来对集合进行同样的操作
    //以上Solution2思路完全错乱。搞得太复杂
    //Solution 3 首先把正负号完全合并。结果集变成 正负交替。ABA 很明显只有AB> 0 ABA才有合并的意义。
//    int changFlag = 0;
//    LinkList chgNum = malloc(sizeof(LinkNode));
//    LinkList p,q;
//    chgNum->next = p;
//    
//    for (int i = 1; i < n; i++) {
//        if (a[i-1]<0) {
//            if (a[i]>=0) {
//                p = (LinkList) malloc(sizeof(LinkNode));
//                p->data = a[i-1];
//                chgNum->next=p;
//                
//                p=p->next;
//                changFlag++;
//                continue;
//            }
//            a[i-1]=a[i-1]+a[i];
//            a[i]=a[i-1];
//        }
//        else{
//            if (a[i]<0) {
//                p = (LinkList) malloc(sizeof(LinkNode));
//                p->data = a[i-1];
//                p=p->next;
//                changFlag++;
//                continue;
//            }
//            a[i-1]=a[i-1]+a[i];
//            a[i]=a[i-1];
//        }
//    }
    int n = 0;
    scanf("%d", &n);
    int num[n];
    
    int max = -1;
    int leftK=0;
    int rightK=n-1;
    int tempSum = 0;
    int tempLeftK = 0;
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
        tempSum += num[i];
        if (tempSum<0) {
            tempSum = 0;
            tempLeftK = i+1;
            
        }
        else{
            if (tempSum>max) {
                max = tempSum;
                rightK = i;
                leftK = tempLeftK;
            }
        }
        
    }
    if(max<0)max=0;
    //max的初值设为了-1，而计算方法是直接舍去负值，只计算正值，所以最后结果<0的情况只有max=-1，即所有数都为负数，此时的left和right也刚好没有被更新过，仍然是0和k-1
    printf("%d %d %d",max,num[leftK],num[rightK]);
    return 0;
}

