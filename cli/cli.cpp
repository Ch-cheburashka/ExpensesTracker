#include "../include/account.hpp"
#include "../include/tracker.hpp"
#include <iostream>
#include <vector>

int main() {
    account acc("Mariia");
    expenses_tracker tracker; 

    acc.receive_funds({std::chrono::year_month_day(std::chrono::floor<std::chrono::days>(std::chrono::system_clock::now())), 100}); 

    tracker.add_account(acc); 
    std::vector<std::string> vec = {"Mariia"};
    auto sum = tracker.calculate_income(vec);
    std::cout << sum << "\n";
}
