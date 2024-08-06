#include <iostream>
#include "../include/account.hpp"
//#include <format>

const std::string account::get_name() const {
    return _name;
}

const cash_map account::get_cash_flow() const {
    return _cash_flow;
}

void account::receive_funds(const cash_pair& pair) {
    _balance += pair.second;
    _cash_flow.insert(pair);
    std::time_t current_time = std::chrono::system_clock::to_time_t(pair.first);
    std::cout << std::put_time(std::localtime(&current_time), "%Y-%m-%d %H:%M:%S") << " -- +" << pair.second << "\n";  
}
