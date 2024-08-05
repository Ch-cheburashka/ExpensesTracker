#ifndef EXPENSES_TRACKER_ACCOUNT_HPP
#define EXPENSES_TRACKER_ACCOUNT_HPP

#include <iostream>
#include <map>
#include <chrono>

using cash_map = std::map<std::chrono::year_month_day,double>;
using cash_pair = std::pair<std::chrono::year_month_day,double>;

class account {
    size_t _balance = 0;
    cash_map _cash_flow;
    std::string _name;
public:

    account(std::string name): _name(name){}  

    const std::string get_name() const;

    const cash_map get_cash_flow() const;

    void receive_funds(const cash_pair&);
};

#endif //EXPENSES_TRACKER_ACCOUNT_HPP
