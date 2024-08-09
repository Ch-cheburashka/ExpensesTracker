#ifndef EXPENSES_TRACKER_TRACKER_HPP
#define EXPENSES_TRACKER_TRACKER_HPP

#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <utility>
#include <fstream>

class expenses_tracker {
    struct transaction {
        std::string _category;
        std::chrono::time_point<std::chrono::system_clock> _time_point;
        long double _funds;
        transaction(std::string category, std::chrono::time_point<std::chrono::system_clock> time_point, long double funds): _category(std::move(category)), _time_point(time_point), _funds(funds) {}
    };

    struct account {
        long double _balance = 0;
        std::vector<transaction> _cash_flow;
   };

    account acc;
public:  
    void add_expense(const std::string&, long double);
    void add_income(const std::string&, long double);  
    long double total_income();
    long double total_expenses();
    long double income_by_category(const std::string&);
    long double expenses_by_category(const std::string&);   
    const std::vector<m_transaction> get_cash_flow() const; 
};

#endif //EXPENSES_TRACKER_TRACKER_HPP
