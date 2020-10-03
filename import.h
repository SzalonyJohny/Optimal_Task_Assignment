#ifndef IMPORT_H
#define IMPORT_H


#include<fstream>
#include<stdlib.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string>
#include <numeric>
#include <string_view>

#define MIN_CHAR_IN_TAB (2)
#define MAX_PRIORITET 10
#define MIN_PRIORITET 0

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
    std::vector<person> getdata();
};

#endif // IMPORT_H
