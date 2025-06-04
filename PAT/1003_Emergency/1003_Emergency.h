//
// Created by azhang3 on 5/27/2025.
//

#ifndef INC_1003_EMERGENCY_H
#define INC_1003_EMERGENCY_H

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

int dataInit(int totalCities, int currCity);

int addRoad(int fromCity, int targetCity, int pathLength);

int shortestPath_Dijkstra(int startCity, int endCity, int totalCities);

int PATAL1003_Emergency();

#endif //INC_1003_EMERGENCY_H
