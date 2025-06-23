//
// Created by azhang3 on 5/27/2025.
//

#include "1003_Emergency.h"


City cities[MAX_CITIES]; // 城市数组
int dist[MAX_CITIES];    // 最短距离
int teams[MAX_CITIES];   // 最大救援队
int paths[MAX_CITIES];   // 最短路径数量

void dataInit(int totalCities, int currCity)
{
    for (int i = 0; i < totalCities; i++)
    {
        dist[i] = 0;
        teams[i] = 0;
        paths[i] = 0;
        cities[i].roads = NULL;
    }
    dist[currCity] = 0;
    paths[currCity] = 1;
}

void addRoad(int fromCity, int targetCity, int length)
{
    Road* currRoad = (Road*)malloc(sizeof(Road));
    currRoad->dest = targetCity;
    currRoad->length = length;
    currRoad->Next = cities[fromCity].roads;
    cities[fromCity].roads = currRoad;

    Road* currRoad2 = (Road*)malloc(sizeof(Road));
    currRoad2->dest = fromCity;
    currRoad2->length = length;
    currRoad2->Next = cities[targetCity].roads;
    cities[targetCity].roads = currRoad2;
}

void shortestPath_Dijkstra(int startCity, int endCity, int totalCities)
{

}