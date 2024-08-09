#include <../include/tracker.hpp>

const std::vector<expenses_tracker::m_transaction> expenses_tracker::get_cash_flow() const {
    return acc._cash_flow;
}

void expenses_tracker::add_income(const std::string& category, long double funds) {
    acc._balance += funds;
    acc._cash_flow.emplace_back(category, std::chrono::system_clock::now(), funds);
}

void expenses_tracker::add_expense(const std::string& category, long double expense) {
    acc._balance -= expense;
    acc._cash_flow.emplace_back(category, std::chrono::system_clock::now(), -expense);
}

long double expenses_tracker::total_income() {
    long double sum = 0.0;
    for (auto f: acc._cash_flow) {
        if (f._funds >= 0.0) 
            sum += f._funds;
    }
    return sum;
}

long double expenses_tracker::total_expenses() {
    long double sum = 0.0;
    for (auto f: acc._cash_flow) {
        if (f._funds < 0.0) 
            sum += f._funds;    
    }
    return (-sum);
}

long double expenses_tracker::income_by_category(const std::string& category) {
    long double sum = 0.0;
    for (auto f: acc._cash_flow) {
        if (f._funds >= 0.0 && f._category == category) 
            sum += f._funds;
    }
    return sum;
}

long double expenses_tracker::expenses_by_category(const std::string& category) {
    long double sum = 0.0;
    for (auto f: acc._cash_flow) {
        if (f._funds < 0.0 && f._category == category) 
            sum += f._funds; 
    }
    return (-sum); 
}

[[nodiscard]] long double expenses_tracker::get_balance() const {
    return acc._balance;
}





