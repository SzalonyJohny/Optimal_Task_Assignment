#ifndef CHOOSING_ALGORITHM_H
#define CHOOSING_ALGORITHM_H

#include <iostream>
#include <map>
#include <string>
#include <bits/stdc++.h>
#include <fstream>
#include "import.h"

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

int calculateCost(std::vector< int > master_vec, int x, int y, bool assigned[], int width);

// Comparison object to be used to order the heap
struct comp
{
    bool operator()(const Node* lhs,
                const Node* rhs) const
    {
        return lhs->cost > rhs->cost;
    }
};

int findMinCost(std::vector< int > master_vec,int width);







class choosing_algorithm
{
private:
    std::map<int, int> value_map;
    std::vector< int > master_vec;

public:
    choosing_algorithm();
    void return_line(  import Data );

};

#endif // CHOOSING_ALGORITHM_H
