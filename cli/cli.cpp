#include "../include/tracker.hpp"
#include <iostream>
#include <vector>
#include <thread>
  
// (-i) --income <-> name(s) ; (-x) --expenses <-> name(s) ; (-c) --cashflow <-> name(s)      

void print_help (const std::string& s) {
    std::cout << "Usage: " << s << "\n";
}

int main(int argc, char** argv) {

    if (argc < 2)  {
        print_help("LACK OF ARGUMENTS");
        return 1;
    }
    expenses_tracker tracker;

    tracker.add_income("Social help", 2000);
    tracker.add_income("Salary", 20000);
    tracker.add_income("Social help", 5000);
    tracker.add_expense("Pohavat", 2500); 
    tracker.add_income("Salary", 20000);

    if (strcmp(argv[1],"-i") == 0 || strcmp(argv[1],"--income") == 0) 
        std::cout << tracker.total_income() << "\n";    
    if (strcmp(argv[1],"-x") == 0 || strcmp(argv[1],"--expenses") == 0)
        std::cout << tracker.total_expenses() << "\n";
    if (strcmp(argv[1],"-c") == 0 || strcmp(argv[1],"--cashflow") == 0) {
        auto flow = tracker.get_cash_flow();  
        for (auto& it: flow) {
            std::time_t current_time = std::chrono::system_clock::to_time_t(it._time_point);
            std::cout << std::put_time(std::localtime(&current_time), "%Y-%m-%d %H:%M:%S") << " <--> " << it._category << " <--> " << it._funds << "\n";
        }
    }

    else {
        print_help("WRONG FLAG");
        return 1;
    }
}
