//  main.c
//  1012_TheBestRank
//
//  Created by Yi chang Zhang on 2024/11/5.
//
//  Sample Input:
//  3 2 3
//  1 2
//  1 3
//  1 2 3
//
//  Sample Output:
//  1
//  0
//  0

#include<stdio.h>
#include<string.h>
 
#define max 1001
int edge[max][max];
int visited[max];
int query[max];
int N; // the total number of cities
int M; // the number of remaining highways
int K; // the number of cities to be checked
 
void dfs(int t)
{
    visited[t] = 1;
    int i;
    for(i=1; i<=N; i++)
    {
        if(!visited[i] && edge[i][t] == 1)
            dfs(i);
    }
}
 
 
 
int main(int argc, const char * argv[])
{
    int i,j;
    int a,b;
    scanf("%d%d%d",&N,&M,&K);
    for(i=0; i<M; i++)
    {
        scanf("%d%d",&a,&b);
        edge[a][b] = 1;
        edge[b][a] = 1;
    }
    int temp;
    int num;
    for(i=0; i<K; i++)
    {
        num = 0;
        scanf("%d",&temp);
        memset(visited,0,sizeof(visited));
        visited[temp] = 1;
        for(j=1; j<=N; j++)
        {
            if(visited[j] == 0)
            {
                dfs(j);
                num ++;
            }
        }
        printf("%d\n",num-1);
    }
 
}
