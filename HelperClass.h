//
// Created by Casual on 02.12.2022.
//

#pragma once

#include <sstream>
#include <fstream>
#include <string>
#include <iostream>

#ifndef ADVENTOFCODE_HELPERCLASS_H
#define ADVENTOFCODE_HELPERCLASS_H

#endif //ADVENTOFCODE_HELPERCLASS_H

class HelperClass{
public:
    //HelperClass() = delete;

    static std::string ProjectPath;

    template <typename Enumeration>
    inline static auto as_integer(Enumeration const value)
        -> typename std::underlying_type<Enumeration>::type //return Type
    {
        return static_cast<typename std::underlying_type<Enumeration>::type>(value);
    }

    inline static std::ifstream get_basic_ifstream(const std::string& relative_path)
    {
        //std::cout << "new Path \t" << ProjectPath + relative_path << std::endl;
        return std::ifstream (ProjectPath + relative_path);
    }
};


