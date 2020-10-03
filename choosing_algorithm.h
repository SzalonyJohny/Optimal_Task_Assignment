#ifndef CHOOSING_ALGORITHM_H
#define CHOOSING_ALGORITHM_H

#include <iostream>
#include <map>
#include <string>
#include <bits/stdc++.h>
#include <fstream>

using namespace std;
#define N 6
#define BASE 100

// state space tree node
struct Node
{
    // stores parent node of current node
    // helps in tracing path when answer is found
    Node* parent;

    // contains cost for ancestors nodes
    // including current node
    int pathCost;

    // contains least promising cost
    int cost;

    // contain worker number
    int workerID;

    // contains Job ID
    int jobID;

    // Boolean array assigned will contains
    // info about available jobs
    bool assigned[N];
};

Node* newNode(int x, int y, bool assigned[], Node* parent);

int calculateCost(int costMatrix[N][N], int x, int y, bool assigned[]);

// Comparison object to be used to order the heap
struct comp
{
    bool operator()(const Node* lhs,
                const Node* rhs) const
    {
        return lhs->cost > rhs->cost;
    }
};

int findMinCost(int costMatrix[N][N]);

std::vector < int > return_line( std::map<char, int> value_map );

class choosing_algorithm
{
    std::map < std::string, int[5] > choice_localization;       //mapa wyborów uczestników klucz = (string) nr indeksu dane [indeks_wybór_1, ... , indeks_wybór_5]

public:
    choosing_algorithm();

};

#endif // CHOOSING_ALGORITHM_H
