#include <iostream>
#include "../include/account.hpp"

void account::receive_funds(const cash_pair& pair) {
    _balance += pair.second;
    _cash_flow.insert(pair); 
    std::cout << "received " << pair.second << " money. Your balance is " << _balance << " now.\n";
}
