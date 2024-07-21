#include "../include/account.hpp"

int main() {
    account acc;

    acc.receive_funds({std::chrono::year_month_day(std::chrono::floor<std::chrono::days>(std::chrono::system_clock::now())), 100}); 

}
