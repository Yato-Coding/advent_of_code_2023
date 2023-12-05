#include <iostream>
#include <fstream>
#include <vector>
#include <regex>

int main(){

    std::string line{};
    std::ifstream puzzle_input{"example_input"};
    std::string pattern{"."};

    std::vector<std::string> input = {};

    while(getline(puzzle_input, line)){
        size_t pos = line.find(pattern);
        std::cout << pos << '\n';        
    }

    return 0;
}