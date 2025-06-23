//
// Created by azhang3 on 5/27/2025.
//

#ifndef INC_1003_EMERGENCY_H
#define INC_1003_EMERGENCY_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_CITIES 500

typedef struct Road
{
    int dest;
    int length;
    struct Road* Next;
} Road;

typedef struct City
{
    int rescueTeamNum;
    Road* roads;
} City;

void dataInit(int totalCities, int currCity);

void addRoad(int fromCity, int targetCity, int pathLength);

void shortestPath_Dijkstra(int startCity, int endCity, int totalCities);

void PATAL1003_Emergency();

#endif //INC_1003_EMERGENCY_H
