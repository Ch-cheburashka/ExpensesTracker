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
    [[nodiscard]] long double get_balance() const;
    [[nodiscard]] long double total_income() const;
    [[nodiscard]] long double total_expenses() const;
    [[nodiscard]] long double income_by_category(const std::string&) const;
    [[nodiscard]] long double expenses_by_category(const std::string&) const;
    [[nodiscard]] std::vector<transaction> cash_flow() const;
    void upload_cashflow_to_file(std::ofstream &);
};

#endif //EXPENSES_TRACKER_TRACKER_HPP
