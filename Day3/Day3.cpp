//
// Created by Casual on 04.12.2022.
//

#include <set>
#include "../HelperClass.h"

inline int calculate_priority(char item){
    return ((int)(item / 'a')? item - 'a' + 1 : item - 'A' + 26 + 1);
}

inline int Day3_1()
{
    std::ifstream file (R"(..\Day3\SourceDay3.txt)");
    int priority_total = 0;

    std::string line;
    while (std::getline(file, line))
    {
        int half_line_size = (int)line.size() / 2;
        char line_half_1 [half_line_size];
        char line_half_2 [half_line_size];

        line.copy(line_half_1, half_line_size, 0);
        line.copy(line_half_2, half_line_size, half_line_size);

        std::set<char> line_half_1_set(line_half_1, line_half_1 + sizeof(line_half_1));
        std::set<char> line_half_2_set(line_half_2, line_half_2 + sizeof(line_half_2));

        for (auto set_1_item : line_half_1_set)
        {
            for (auto set_2_item: line_half_2_set)
            {
                if(set_1_item == set_2_item)
                {
                    priority_total += calculate_priority(set_2_item);
                    std::cout << set_2_item << " -> " << calculate_priority(set_2_item) << std::endl;
                }
            }
        }
        std::printf("\nhalf line size = %d, line.size() = %d \n", half_line_size, (int)line.size());
        std::printf("Original: %s\n", line.c_str());
        line_half_1[half_line_size] = '\0';
        line_half_2[half_line_size] = '\0';
        std::printf("first half(%d): %s \t second half(%d): %s\n",
                    (int)sizeof(line_half_2), line_half_1, (int)sizeof line_half_2, line_half_2);
    }
    return priority_total;
}


inline int Day3_2()
{
    std::ifstream file (R"(..\Day3\SourceDay3.txt)");
    int priority_total = 0;
    std::string line_array[3];
    while (
        std::getline(file, line_array[0]) &&
        std::getline(file, line_array[1]) &&
        std::getline(file, line_array[2])   )
    {

        std::set<char> line_1_set(std::begin(line_array[0]), std::end(line_array[0]));
        std::set<char> line_2_set(std::begin(line_array[1]), std::end(line_array[1]));
        std::set<char> line_3_set(std::begin(line_array[2]), std::end(line_array[2]));

        for (auto set_1_item : line_1_set)
            for (auto set_2_item: line_2_set)
                if(set_1_item == set_2_item)
                    for (auto set_3_item: line_3_set)
                        if(set_1_item == set_3_item)
                        {
                            priority_total += calculate_priority(set_2_item);
                            std::cout << set_2_item << " -> " << calculate_priority(set_2_item) << std::endl;
                            std::cout << set_2_item << " -> " << calculate_priority(set_2_item) << std::endl;
                        }
    }
    return priority_total;
}

inline void Day3(){
    std::cout << "Priority 1 Total: " << Day3_1() << std::endl;
    std::cout << "Priority 2 Total: " << Day3_2() << std::endl;
    std::cout << "Day3 Finished!" << std::endl;
}
