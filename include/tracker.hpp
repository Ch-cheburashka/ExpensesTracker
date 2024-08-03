#ifndef EXPENSES_TRACKER_TRACKER_HPP
#define EXPENSES_TRACKER_TRACKER_HPP

#include <iostream>
#include "account.hpp"
#include <unordered_map>
#include <memory>

class expenses_tracker {
    std::unordered_map<std::string, account> accounts;

public:

    void add_account(const account&);

    long double calculate_income(const std::vector<std::string>&);

};

#endif //EXPENSES_TRACKER_TRACKER_HPP
