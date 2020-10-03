#include "import.h"
#include <stdlib.h>


import::import()
{

}

void import::read_from_files(std::string data)
{
    std::fstream file(data);
    if (file.is_open()) {

        std::string line;
        std::getline(file, line);
        number_of_tasks = std::count(line.begin(),line.end(),',')-1;


        while (std::getline(file, line)) {

            std::stringstream str(line);
            person temp_person;
            temp_person.priorities_of_task.resize(number_of_tasks);

            std::getline(str,temp_person.time,',');
            std::getline(str,temp_person.name,',');
            number_of_people++;
            for(int i_tasks = 1; i_tasks <= number_of_tasks; i_tasks++){ // start with 0;
                std::string prioritet_str;
                std::getline(str,prioritet_str, ',');
                if(prioritet_str.size()>MIN_CHAR_IN_TAB){
                    prioritet_str.erase(std::remove_if(prioritet_str.begin(),
                                                       prioritet_str.end(),
                                                       [](unsigned char x){return !std::isdigit(x);}),
                                        prioritet_str.end());

                    int prioritet = std::stoi(prioritet_str);
                    if(prioritet>number_of_priorities)number_of_priorities = prioritet;
                    if(prioritet<MAX_PRIORITET && prioritet>MIN_PRIORITET)temp_person.priorities_of_task.at(prioritet-1) = i_tasks;
                }
            }
            data_osoby.emplace_back(temp_person);
        }
    }
    else {
        std::cout<<"nie otwiera";
    }
}

void import::display_ds()
{
    std::cout<<number_of_tasks<<std::endl;
    std::cout<<number_of_people<<std::endl;
    std::cout<<number_of_priorities<<std::endl;
    for(auto &el:data_osoby){
        std::cout<<el.name<<" "<<el.time<<std::endl;
        for(auto &k:el.priorities_of_task)std::cout<<k<<" ";
        std::cout<<std::endl;
    }
}

std::vector<person> import::getdata()
{
    return data_osoby;
}

int import::get_numberoftasks()
{
    return number_of_tasks;
}

int import::get_numberofpriorities()
{
    return number_of_priorities;
}

