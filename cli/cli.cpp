#include "../include/tracker.hpp"
#include <iostream>
#include <vector>
#include <thread>
  
// (-i) --income; (-x) --expenses; (-c) --cashflow
// (-ibc) --income-by-category + str; (-xbc) --expenses-by-category + str
// (-u) --upload-to-file + str

void print_help (const std::string& s) {
    std::cout << "Usage: " << s << "\n";
}

int main(int argc, char** argv) {

    if (argc < 2)  {
        print_help("LACK OF ARGUMENTS");
        return 1;
    }
    expenses_tracker tracker;

    tracker.add_income("Social_help", 2000);
    std::this_thread::sleep_for(std::chrono::seconds(2));
    tracker.add_income("Salary", 20000);
    std::this_thread::sleep_for(std::chrono::seconds(2));
    tracker.add_income("Social_help", 5000);
    std::this_thread::sleep_for(std::chrono::seconds(2));
    tracker.add_expense("Food", 2500);
    std::this_thread::sleep_for(std::chrono::seconds(3));
    tracker.add_expense("Insurance", 9000);

    if (strcmp(argv[1],"-i") == 0 || strcmp(argv[1],"--income") == 0) 
        std::cout << tracker.total_income() << "\n";    
    else if (strcmp(argv[1],"-x") == 0 || strcmp(argv[1],"--expenses") == 0)
        std::cout << tracker.total_expenses() << "\n";
    else if (strcmp(argv[1],"-c") == 0 || strcmp(argv[1],"--cashflow") == 0) {
        auto flow = tracker.cash_flow();
        for (auto& it: flow) {
            std::time_t current_time = std::chrono::system_clock::to_time_t(it._time_point);
            std::cout << std::put_time(std::localtime(&current_time), "%Y-%m-%d %H:%M:%S") << " <--> " << it._category << " <--> " << it._funds << "\n";
        }
    }
    else if ((strcmp(argv[1],"-ibc") == 0 || strcmp(argv[1],"--income-by-category") == 0) && argc == 3) {
        std::cout << tracker.income_by_category(argv[2]) << "\n";
    }
    else if ((strcmp(argv[1],"-xbc") == 0 || strcmp(argv[1],"--expenses-by-category") == 0) && argc == 3) {
        std::cout << tracker.expenses_by_category(argv[2]) << "\n";
    }
    else if ((strcmp(argv[1],"-u") == 0 || strcmp(argv[1],"--upload-to-file") == 0) && argc == 3) {
        std::ofstream file(argv[2]);
        tracker.upload_cashflow_to_file(file);
        std::cout << "Cashflow was uploaded to the file!\n";
    }
    else {
        print_help("WRONG FLAG");
        return 1;
    }
}
