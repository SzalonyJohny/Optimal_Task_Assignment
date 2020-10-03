#include <iostream>

#include "import.h"
#include "choosing_algorithm.h"



using namespace std;

int main()
{
    import in_data;
    in_data.read_from_files("BnB.txt");
    in_data.display_ds();

    choosing_algorithm solution;
    solution.return_line( in_data );

    return 0;
}
