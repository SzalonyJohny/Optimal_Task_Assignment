#include <iostream>
#include "import.h"
#include "choosing_algorithm.h"


using namespace std;

int main()
{
    int costMatrix[N][N];
    std::map<char, int> value_map = {
        { '1', 1 },
        { '2', 8 },
        { '3', 12 },
        { '4', 17 },
        { '5', 23 }

    };



    std::vector < int > dane = return_line(value_map);

    int licznik = 0;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {

            costMatrix[j][i] = dane[licznik];
            licznik++;

        }

    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {

           cout<< costMatrix[j][i] << " ";


        }
        cout << endl;

    }





    cout << "\nOptimal Cost is "
        << findMinCost(costMatrix);

    return 0;
}
