#include <iostream>
#include <fstream>
#include <unordered_map>
#include <chrono>

int main(){
    auto start_time = std::chrono::high_resolution_clock::now();

    std::unordered_map<std::string, int> patterns = { 
        {"one", 1},
        {"1", 1},
        {"two", 2},
        {"2", 2},
        {"three", 3},       
        {"3", 3},       
        {"four", 4}, 
        {"4", 4},
        {"five", 5}, 
        {"5", 5},
        {"six", 6}, 
        {"6", 6},
        {"seven", 7}, 
        {"7", 7},
        {"eight", 8},
        {"8", 8},
        {"nine", 9},
        {"9", 9}
    };

    std::ifstream puzzle_input("puzzle_input");
    std::string line{" "};

    int sum{0};

    while(std::getline(puzzle_input, line)){
        size_t low{100};
        size_t high{0};
        size_t low_num{};
        size_t high_num{}; 
        int counter{0};

        for(const auto& entry : patterns){  
            const std::string& pattern = entry.first;
            size_t numberEntry = entry.second;
            size_t pos = line.find(pattern);
            
            while(pos != std::string::npos && pos != -1){
                if(low > pos){
                    low = pos;
                    low_num = numberEntry;
                }
                if(high < pos+pattern.length()-1){
                    high = pos+pattern.length()-1;
                    high_num = numberEntry;
                }
                counter++;
                pos = line.find(pattern, pos + 1);
            }
        }
        std::string number{};
        if(counter == 1){
            number = std::to_string(low_num) + std::to_string(low_num);
        }
        else{
            number = std::to_string(low_num) + std::to_string(high_num);
        }
        sum = sum + std::stoi(number);
    }
    

    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    std::cout << sum << '\n';
    std::cout << "Time taken: " << duration.count() << " milliseconds" << '\n';
    return 0;
}
