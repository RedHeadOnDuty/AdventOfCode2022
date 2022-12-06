//
// Created by Casual on 04.12.2022.
//

#include "../HelperClass.h"

inline void Day3()
{
    auto file = HelperClass::get_basic_ifstream(R"(Day3\SourceDay3.txt)");
    int priority_total = 0;

    std::string line;
    while (std::getline(file, line))
    {
        int half_line_size = (int)line.size() / 2;
        char line_half_1 [half_line_size];
        char line_half_2 [half_line_size];
        line.copy(line_half_1, half_line_size, 0);
        line.copy(line_half_2, half_line_size, half_line_size);

        for (int i = 0; i < half_line_size; ++i) {
            if(line_half_1[i] - line_half_2[i])
                for (int j = 0; j < ; ++j) {
                    
                }
                continue;
            else
            {
                int priority = (int)(line_half_2[i] / 'a')? line_half_2[i] - 'a' + 1 : line_half_2[i] - 'A' + 26;
                priority_total += priority;
                std::cout << line_half_2[i] << " -> " << priority;
                std::cout << "\t" << (int)(line_half_2[i] / 'a') << std::endl;
                break;
            }
        }


        std::printf("\nhalf line size = %d, line.size() = %d \n", half_line_size, (int)line.size());
        std::printf("Original: %s\n", line.c_str());
        line_half_1[half_line_size] = '\0';
        line_half_2[half_line_size] = '\0';
        std::printf("first half(%d): %s \t second half(%d): %s\n",
                    (int)sizeof(line_half_2), line_half_1, (int)sizeof line_half_2, line_half_2);
        

    }
    std::cout << priority_total << std::endl;
    std::cout << "Day3 Finished!" << std::endl;
}
