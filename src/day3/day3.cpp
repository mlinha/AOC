#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>
#include <boost/algorithm/string.hpp>
#include "day3.h"
#include "recursive_parser.h"

using namespace day3;

std::string read_input_day3() 
{
    std::string input_data;
    std::string line = "";

    std::ifstream input("/home/michal/Documents/AOC/src/day3/input.txt");

    while (std::getline (input, line)) {
        input_data = input_data + line;
    }
    input.close();

    return input_data;
}

void day3::get_solution()
{
    std::string input = read_input_day3();

    RecursiveParser parser(input);

    parser.start();
    int result = parser.get_result();
    int result_better = parser.get_result_better();


    std::cout << "Day3:" << std::endl;
    std::cout << result << std::endl;
    std::cout << result_better << std::endl;
    std::cout << "\n" << std::endl;
}
