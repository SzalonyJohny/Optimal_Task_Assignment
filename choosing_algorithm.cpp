#include "choosing_algorithm.h"
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <map>
using namespace std;
#define N 6
#define BASE 150


choosing_algorithm::choosing_algorithm()
{
    value_map = {
        { 0, BASE },
        { 1, 1 },
        { 2, 20 },
        { 3, 35 },
        { 4, 40 },
        { 5, 50 }
    };
}

// Function to allocate a new search tree node
// Here Person x is assigned to job y
Node* newNode(int x, int y, bool assigned[],
            Node* parent)
{
    Node* node = new Node;

    for (int j = 0; j < N; j++)
        node->assigned[j] = assigned[j];
    node->assigned[y] = true;

    node->parent = parent;
    node->workerID = x;
    node->jobID = y;

    return node;
}

// Function to calculate the least promising cost
// of node after worker x is assigned to job y.
int calculateCost(std::vector< int > master_vec, int x, int y, bool assigned[], int width)
{
    int costMatrix[width][width], counter = 0;

    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < width; j++)
        {
            costMatrix[i][j] = master_vec[counter];
            counter++;
        }

    }

    int cost = 0;

    // to store unavailable jobs
    bool available[N] = {true};

    // start from next worker
    for (int i = x + 1; i < N; i++)
    {
        int min = INT_MAX, minIndex = -1;

        // do for each job
        for (int j = 0; j < N; j++)
        {
            // if job is unassigned
            if (!assigned[j] && available[j] &&
                costMatrix[i][j] < min)
            {
                // store job number
                minIndex = j;

                // store cost
                min = costMatrix[i][j];
            }
        }

        // add cost of next worker
        cost += min;

        // job becomes unavailable
        available[minIndex] = false;
    }

    return cost;
}


// print Assignments
void printAssignments(Node *min)
{
    if(min->parent==NULL)
        return;

    printAssignments(min->parent);
    cout << "Assign Worker " << char(min->workerID + 'A')
        << " to Job " << min->jobID << endl;

}

// Finds minimum cost using Branch and Bound.
int findMinCost(std::vector< int > master_vec,int width)
{
    int costMatrix[width][width], counter = 0;

    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < width; j++)
        {
            costMatrix[i][j] = master_vec[counter];
            counter++;
        }
    }
    // Create a priority queue to store live nodes of
    // search tree;
    priority_queue<Node*, std::vector<Node*>, comp> pq;

    // initailize heap to dummy node with cost 0
    bool assigned[N] = {false};
    Node* root = newNode(-1, -1, assigned, NULL);
    root->pathCost = root->cost = 0;
    root->workerID = -1;

    // Add dummy node to list of live nodes;
    pq.push(root);

    // Finds a live node with least cost,
    // add its childrens to list of live nodes and
    // finally deletes it from the list.
    while (!pq.empty())
    {
    // Find a live node with least estimated cost
    Node* min = pq.top();

    // The found node is deleted from the list of
    // live nodes
    pq.pop();

    // i stores next worker
    int i = min->workerID + 1;

    // if all workers are assigned a job
    if (i == N)
    {
        printAssignments(min);
        return min->cost;
    }

    // do for each job
    for (int j = 0; j < N; j++)
    {
        // If unassigned
        if (!min->assigned[j])
        {
        // create a new tree node
        Node* child = newNode(i, j, min->assigned, min);

        // cost for ancestors nodes including current node
        child->pathCost = min->pathCost + costMatrix[i][j];

        // calculate its lower bound
        child->cost = child->pathCost +
            calculateCost(master_vec, i, j, child->assigned, width);

        // Add child to list of live nodes;
        pq.push(child);
        }
    }
    }
}

void choosing_algorithm::return_line( import Data )
{
    int width = Data.get_numberoftasks();
    int master_tab[width][width];

    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < width; j++) master_tab[i][j] = BASE;
    }


    std::vector<person> vec_of_persons = Data.getdata();
    int position = 0, counter = 0;              // postioton is in witch row of master_tab we are; counter shows witch prioryty this position has

    for(auto &el : vec_of_persons)
    {

        for(auto &position_of_priority : el.priorities_of_task)
        {
           if(position_of_priority != 0
                   && counter <= Data.get_numberofpriorities() )
               master_tab[position][position_of_priority-1] = value_map[counter + 1];

            counter++;
        }
        counter = 0;
        position++;
    }

    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < width; j++) cout << master_tab[i][j] << " ";
        cout << endl;
    }

    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < width; j++) master_vec.emplace_back(master_tab[i][j]);

    }

    findMinCost(master_vec, width);

}


