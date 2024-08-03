#include <iostream>
#include "../include/account.hpp"
//#include <format>

const std::string account::get_name() {
    return _name;
}

const cash_map account::get_cash_flow() {
    return _cash_flow;
}

void account::receive_funds(const cash_pair& pair) {
    _balance += pair.second;
    _cash_flow.insert(pair);
    auto ymd = pair.first;
    std::cout << static_cast<int>(ymd.year()) << ":" << static_cast<unsigned>(ymd.month()) << ":" << static_cast<unsigned>(ymd.day()) << " -- +" << pair.second << "\n";  
}
