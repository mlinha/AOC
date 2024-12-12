#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>
#include <boost/algorithm/string.hpp>
#include "day2.h"

using namespace day2;

std::vector<std::vector<int>> read_input() 
{
    std::vector<std::vector<int>> input_data;
    std::string line = "";

    std::ifstream input("/home/michal/Documents/AOC/src/day2/input.txt");

    while (std::getline (input, line)) {
        std::vector<std::string> split_data;
        boost::split(split_data, line, boost::is_any_of(" "), boost::token_compress_on);
        input_data.push_back(std::vector<int>());
        for (auto input_number : split_data)
        {
            input_data[input_data.size() - 1].push_back(std::stoi(input_number));
        }
    }
    input.close();

    return input_data;
}

std::unique_ptr<bool[]> is_record_safe(std::vector<int> &record)
{
    std::unique_ptr<bool[]> results(new bool[2]); //use smart pointer just to remind myself how it works
    results[0] = true;
    results[1] = true;
    bool is_error = false;
    if (record.size() == 0 || record.size() == 1)
    {
        return results;
    }
    short step = 1;
    short prev_orient = 0; //0 unknown, 1 asc, -1 desc,
    for (int i = 1; i < record.size(); i++)
    {
        int diff = record[i] - record[i - step];
        if (std::abs(diff) > 3 || diff == 0)
        {
            results[0] = false;
            if (step == 2)
            {
                step = 1;
                i--;
                continue;
            }
            if (is_error)
            {
                results[1] = false;
                return results;
            }
            is_error = true;
            step = 2;
        }
        if (diff > 0 && prev_orient == -1)
        {
            results[0] = false;
            if (is_error)
            {
                results[1] = false;
                return results;
            }
            is_error = true;
            step = 2;
        }
        else if (diff > 0)
        {
            prev_orient = 1;
            step = 1;
        }
        else if (diff < 0 && prev_orient == 1)
        {
            results[0] = false;
            if (is_error)
            {
                results[1] = false;
                return results;
            }
            is_error = true;
            step = 2;
        }
        else if (diff < 0)
        {
            prev_orient = -1;
            step = 1;
        }
    }

    return results;
}

void day2::get_solution()
{
    std::vector<std::vector<int>> input = read_input();

    int safe = 0;
    int safe_one_error = 0;
    for (auto record : input)
    {
        std::unique_ptr<bool[]> ret_val = is_record_safe(record);
        if (ret_val[0])
        {
            safe++;
        }
        if (ret_val[1])
        {
            safe_one_error++;
        }
    }


    std::cout << "Day2:" << std::endl;
    std::cout << safe << std::endl;
    std::cout << safe_one_error << std::endl;
    std::cout << "\n" << std::endl;
}
