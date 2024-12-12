#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>
#include <boost/algorithm/string.hpp>
#include "day1.h"

using namespace day1;

std::string read_input() 
{
    std::string input_data = "";
    std::string line = "";

    std::ifstream input("/home/michal/Documents/AOC/src/day1/input.txt");

    while (std::getline (input, line)) {
        input_data = input_data + line + "\n";
    }
    input.close();

    if (input_data.size() > 0)
    {
        input_data.pop_back();
    }

    return input_data;
}

void day1::get_solution()
{
    std::string input = read_input();

    std::string current;
    std::stringstream ss(input);

    std::vector<int> listA;
    std::vector<int> listB;

    std::vector<std::string> input_lines;

    boost::split(input_lines, input, boost::is_any_of("\n"));

    for (auto line : input_lines)
    {
        std::vector<std::string> split_data;
        boost::split(split_data, line, boost::is_any_of(" "), boost::token_compress_on);
        listA.push_back(std::stoi(split_data[0]));
        listB.push_back(std::stoi(split_data[1]));
    }

    std::sort(listA.begin(), listA.end());
    std::sort(listB.begin(), listB.end());

    int distance_result = 0;
    int similarity_result = 0;

    for (int i = 0; i < listA.size(); i++)
    {
        distance_result = distance_result + std::abs(listA[i] - listB[i]);
    }

    std::map<int, int> occurrences;

    for (auto value : listB)
    {
        if (occurrences.find(value) == occurrences.end())
        {
            occurrences[value] = 1;
        }
        else {
            occurrences[value] = occurrences[value] + 1;
        }
    }

    for (auto value : listA)
    {
        similarity_result = similarity_result + value * occurrences[value];
    }

    std::cout << "Day 1:" << std::endl;
    std::cout << distance_result << std::endl;
    std::cout << similarity_result << std::endl;
    std::cout << "\n" << std::endl;
}