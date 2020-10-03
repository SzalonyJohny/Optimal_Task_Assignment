#include "choosing_algorithm.h"

choosing_algorithm::choosing_algorithm()
{

}

#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <map>
using namespace std;
#define N 6
#define BASE 100



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
int calculateCost(int costMatrix[N][N], int x, int y, bool assigned[])
{
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
int findMinCost(int costMatrix[N][N])
{
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
            calculateCost(costMatrix, i, j, child->assigned);

        // Add child to list of live nodes;
        pq.push(child);
        }
    }
    }
}

std::vector < int > return_line( std::map<char, int> value_map )
{
    int  size = N * N, row_number = 0;                    //size is number of numbers in finnal aray/matrix
    std::vector < int > master_tab;
    string line;
    ifstream myfile ("BnBtest.txt");



    for(int i = 0; i < N; i++)
    {
        getline(myfile,line);

        for(int j = 0; j < line.length(); j++)
        {

         if(line[j] == ',')
         {

             if(j == 0)
             {

                master_tab.push_back( BASE );

             } else {

                 if(line[j-1] == ',')
                 {
                     master_tab.push_back( BASE );

                 } else {

                     master_tab.push_back( value_map[ line[j-1] ] );

                 }

             }
             row_number++;
         }

        if( j == line.length()-1 )
        {
            if(line[j] == ',')
            {
                master_tab.push_back( BASE );

            } else {

                master_tab.push_back( value_map[ line[j] ] );

            }

            row_number++;
        }
        }
    }


    myfile.close();




    return master_tab;
}


//int costMatrix[N][N];
//std::map<char, int> value_map = {
//    { '1', 1 },
//    { '2', 8 },
//    { '3', 12 },
//    { '4', 17 },
//    { '5', 23 }

//};

//for(int i = 0; i < N; i++)
//{
//    for(int j = 0; j < N; j++)
//    {

//        costMatrix[j][i] = dane[licznik];
//        licznik++;

//    }

//}
