#include <iostream>
#include <fstream>
#include <regex>
#include <chrono>

int main(){
    auto start_time = std::chrono::high_resolution_clock::now();

    const std::regex pattern{"\\d+"};

    std::string line{" "};
    std::smatch matches{};
    std::ifstream puzzle_input("puzzle_input");
    int sum{};
    
    while(getline(puzzle_input, line)){
        std::string temp_number{};
        while(std::regex_search(line, matches, pattern)){
            temp_number += matches.str();
            line = matches.suffix();
        }

        std::string number{};
        for(int i{0}; i < temp_number.length(); i++){

            if(i < 1 || i == temp_number.length()-1){
                number += temp_number[i];
                
            }
            if(i < 1 && i == temp_number.length()-1){
                number += temp_number[i];
            }
        }
        sum = sum + std::stoi(number);
    }
    std::cout << sum << '\n';
    
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    std::cout << "Time taken: " << duration.count() << " milliseconds" << '\n';
    return 0;

}
