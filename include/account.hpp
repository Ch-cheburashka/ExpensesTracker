#include <iostream>
#include <map>
#include <chrono>

using cash_map = std::map<std::chrono::year_month_day,double>;
using cash_pair = std::pair<std::chrono::year_month_day,double>;

class account {
    size_t _balance = 0;
    cash_map _cash_flow;
public:

    void receive_funds(const cash_pair&);
};


