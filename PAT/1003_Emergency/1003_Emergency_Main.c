//
//  1003_Emergency_Main.c
//  1003_Emergency_Main
//
//  Created by Yi chang Zhang on 2025/3/2.
//
//  Sample Input:
//  5 6 0 2
//  1 2 1 5 3
//  0 1 1
//  0 2 2
//  0 3 1
//  1 2 1
//  2 4 1
//  3 4 1
//
//  Sample Output:
//  2 4
//

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_CITIES 500

typedef struct Road {
    int dest;       // 目标城市
    int length;     // 道路长度
    struct Road* next; // 下一条道路
} Road;

typedef struct {
    int num;        // 城市中的救援队数量
    Road* roads;    // 邻接表
} City;

City cities[MAX_CITIES]; // 城市数组
int dist[MAX_CITIES];    // 最短距离
int teams[MAX_CITIES];   // 最大救援队
int paths[MAX_CITIES];   // 最短路径数量

// 初始化数据
void init(int n, int start) {
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        teams[i] = 0;
        paths[i] = 0;
        cities[i].roads = NULL;
    }
    dist[start] = 0;
    paths[start] = 1;
}

// 添加道路（无向图）
void add_road(int c1, int c2, int length) {
    Road* road1 = (Road*)malloc(sizeof(Road));
    road1->dest = c2;
    road1->length = length;
    road1->next = cities[c1].roads;
    cities[c1].roads = road1;

    Road* road2 = (Road*)malloc(sizeof(Road));
    road2->dest = c1;
    road2->length = length;
    road2->next = cities[c2].roads;
    cities[c2].roads = road2;
}

// Dijkstra算法实现
void dijkstra(int start, int end, int n) {
    int visited[MAX_CITIES] = {0};
    teams[start] = cities[start].num;

    for (int i = 0; i < n; i++) {
        // 找到当前未访问的最近节点
        int u = -1, min_dist = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < min_dist) {
                u = j;
                min_dist = dist[j];
            }
        }
        if (u == -1) break; // 所有可达节点已处理
        if (u == end) return; // 提前终止优化

        visited[u] = 1;

        // 遍历所有邻接道路
        Road* road = cities[u].roads;
        while (road != NULL) {
            int v = road->dest;
            int new_dist = dist[u] + road->length;

            if (!visited[v]) {
                if (new_dist < dist[v]) { // 发现更短路径
                    dist[v] = new_dist;
                    teams[v] = teams[u] + cities[v].num;
                    paths[v] = paths[u];
                } else if (new_dist == dist[v]) { // 相同长度路径
                    paths[v] += paths[u];
                    if (teams[u] + cities[v].num > teams[v]) {
                        teams[v] = teams[u] + cities[v].num;
                    }
                }
            }
            road = road->next;
        }
    }
}

int main(int argc, const char * argv[]) {
    int N, M, C1, C2;
    scanf("%d %d %d %d", &N, &M, &C1, &C2);

    // 初始化城市救援队数量
    init(N, C1);
    for (int i = 0; i < N; i++) {
        scanf("%d", &cities[i].num);
    }

    // 添加道路
    for (int i = 0; i < M; i++) {
        int c1, c2, L;
        scanf("%d %d %d", &c1, &c2, &L);
        add_road(c1, c2, L);
    }

    // 执行算法
    dijkstra(C1, C2, N);

    // 输出结果
    printf("%d %d\n", paths[C2], teams[C2]);

    // 释放内存（可选，程序结束会自动释放）
    return 0;
}
