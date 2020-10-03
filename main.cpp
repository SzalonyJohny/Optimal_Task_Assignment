#include <iostream>
#include <import.h>
using namespace std;

int main()
{
    import i;
    i.read_from_files("data_in.csv");
    i.display_ds();
    return 0;
}
