#ifndef IMPORT_H
#define IMPORT_H


#include "choosing_algorithm.h"
#include<fstream>
#include<stdlib.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string>
#include <numeric>
#include <string_view>

struct person{
    std::string time;
    std::string name;
    std::vector<int> priorities_of_task;
};


class import
{
private:
    int number_of_people=0;
    int number_of_tasks=0;
    int number_of_priorities=0;
    std::vector<person> data_osoby;

public:
    import();
    void read_from_files(std::string data);
    void display_ds();
};

#endif // IMPORT_H
