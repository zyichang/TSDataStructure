//
//  1004_CountingLeaves_Main.c
//  1004_CountingLeaves_Main
//
//  Created by Yi chang Zhang on 2025/3/3.
//
/*
Sample Input:
2 1
01 1 02
 
Sample Output:
0 1
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int child_count;
    int *children;
};

struct Node nodes[100];

int main(int argc, const char * argv[]) {
    int N, M;
    scanf("%d", &N);
    if (N == 0) return 0;
    scanf("%d", &M);
    
    // 初始化所有节点
    for (int i = 0; i < 100; i++) {
        if (nodes[i].children != NULL) {
            free(nodes[i].children);
            nodes[i].children = NULL;
        }
        nodes[i].child_count = 0;
    }
    
    // 读取M个非叶子节点
    for (int i = 0; i < M; i++) {
        char id_str[3];
        scanf("%s", id_str);
        int id = atoi(id_str);
        
        int k;
        scanf("%d", &k);
        nodes[id].child_count = k;
        nodes[id].children = (int *)malloc(k * sizeof(int));
        
        for (int j = 0; j < k; j++) {
            char child_str[3];
            scanf("%s", child_str);
            nodes[id].children[j] = atoi(child_str);
        }
    }
    
    // 层次遍历初始化
    int queue[100];
    int front = 0, rear = 0;
    int levels[100] = {0};
    int depth = 0;
    
    queue[rear++] = 1; // 根节点ID是01，转为整数1
    
    while (front < rear) {
        int level_size = rear - front;
        int count = 0;
        
        for (int i = 0; i < level_size; i++) {
            int node = queue[front++];
            if (nodes[node].child_count == 0) {
                count++;
            } else {
                for (int j = 0; j < nodes[node].child_count; j++) {
                    int child = nodes[node].children[j];
                    queue[rear++] = child;
                }
            }
        }
        
        levels[depth++] = count;
    }
    
    // 输出结果
    for (int i = 0; i < depth; i++) {
        if (i > 0) printf(" ");
        printf("%d", levels[i]);
    }
    printf("\n");
    return 0;
}
