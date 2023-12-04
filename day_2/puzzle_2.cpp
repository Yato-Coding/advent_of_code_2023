#include <iostream>
#include <regex>
#include <fstream>
#include <vector>

int main(){
    const int red{12}; 
    const int green{13};
    const int blue{14};
    int sum{0};

    std::string line{};

    const std::regex pattern{R"([^\S]\b\w+)"};
    std::smatch matches{};

    std::ifstream puzzle_input("puzzle_input");

    while(getline(puzzle_input, line)){
        std::vector<std::string> colors = {};
        std::vector<std::string> numbers = {};
        int counter{0};
        std::string index{};
        while(std::regex_search(line, matches, pattern)){
            if(counter == 0){
                counter++;
                continue;
            }
            else if(counter == 1){
                counter++;
                continue;
            }
            else if(counter == 2){
                index = matches.str();
            }
            else if(counter % 2 == 0){
                colors.push_back(matches.str());
            }
            else{
                numbers.push_back(matches.str());
            }
            line = matches.suffix();
            counter++;
        }

        bool valid{true};
        int min_r{0};
        int min_b{0};
        int min_g{0};
        for(auto i{0}; i < colors.size(); i++){           
            if(colors[i] == " red"){
                if(std::stoi(numbers[i]) > min_r){
                   min_r = std::stoi(numbers[i]);
                }
            }
            if(colors[i] == " blue"){
                if(std::stoi(numbers[i]) > min_b){
                   min_b = std::stoi(numbers[i]);
                }
            }
            if(colors[i] == " green"){
                if(std::stoi(numbers[i]) > min_g){
                   min_g = std::stoi(numbers[i]);
                }
            }
       }
       sum += (min_r*min_b*min_g);
    }
    std::cout << sum << '\n';
    return 0;
}
