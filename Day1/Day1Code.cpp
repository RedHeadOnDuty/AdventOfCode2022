#include "..\HelperClass.h"

inline void Day1() {
    int max_ant_calories[] = { 0, 0, 0 };
    //std::ifstream file("sourceday1.txt");
    auto file = HelperClass::get_basic_ifstream(R"(Day1\SourceDay1.txt)");

    int current_ant_calories = 0;
    std::string line;
    while(std::getline(file, line))
    {
        if(line.empty())
        {
            if (max_ant_calories[0] < current_ant_calories)
            {

                max_ant_calories[2] = max_ant_calories[1];  // 1 -> 2
                max_ant_calories[1] = max_ant_calories[0];  // 0 -> 1
                max_ant_calories[0] = current_ant_calories; // new -> 0
            }
            else if (max_ant_calories[1] < current_ant_calories)
            {
                max_ant_calories[2] = max_ant_calories[1];
                max_ant_calories[1] = current_ant_calories;
            }
            else if (max_ant_calories[2] < current_ant_calories)
                max_ant_calories[2] = current_ant_calories;


            current_ant_calories = 0;
            std::cout<<std::endl;
            continue;
        }

        std::istringstream line_ss(line);
        int line_value;
        line_ss >> line_value;

        current_ant_calories += line_value;
        std::printf("Max: %d, CurrentYet: %d Current: %d\n", max_ant_calories[0], current_ant_calories, line_value);
    }

    file.close();
    std::printf("Max Ant Calories 1 = %d, 2 = %d, 3 = %d -> %d\n",
                max_ant_calories[0], max_ant_calories[1],max_ant_calories[2],
                max_ant_calories[0] + max_ant_calories[1] + max_ant_calories[2]
                );
    std::cout << "Day1 Finished!" << std::endl;
}

