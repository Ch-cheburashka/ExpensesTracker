#include "../include/account.hpp"
#include "../include/tracker.hpp"
#include <iostream>
#include <vector>
#include <thread>

int main() {
    account acc("Mariia");
    expenses_tracker tracker; 

    acc.receive_funds({std::chrono::system_clock::now(), 100}); 

    std::this_thread::sleep_for(std::chrono::seconds(5)); 
     
    acc.receive_funds({std::chrono::system_clock::now(), 500});

    tracker.add_account(acc); 
    std::vector<std::string> vec = {"Mariia"};
    auto sum = tracker.calculate_income(vec);
    std::cout << "Sum: " << sum << "\n";
}
