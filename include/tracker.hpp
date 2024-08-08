#ifndef EXPENSES_TRACKER_TRACKER_HPP
#define EXPENSES_TRACKER_TRACKER_HPP

#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>

class expenses_tracker {
    struct m_transaction {
        std::string _category;
        std::chrono::time_point<std::chrono::system_clock> _time_point;
        long double _funds;
        m_transaction(std::string category, std::chrono::time_point<std::chrono::system_clock> time_point, long double funds): _category(category), _time_point(time_point), _funds(funds) {}    
    };

    struct account {
        size_t _balance = 0;
        std::vector<m_transaction> _cash_flow;
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
