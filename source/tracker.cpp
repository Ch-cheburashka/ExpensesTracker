#include <tracker.hpp>

[[nodiscard]] std::vector<expenses_tracker::transaction> expenses_tracker::cash_flow() const {
    return acc._cash_flow;
}

void expenses_tracker::add_income(const std::string& category, long double funds) {
    if (funds < 0)
        throw std::logic_error("Income error: funds cannot be less than zero");
    if (category.empty())
        throw std::logic_error("Income error: category cannot be empty");
    acc._balance += funds;
    acc._cash_flow.emplace_back(category, std::chrono::system_clock::now(), funds);
}

void expenses_tracker::add_expense(const std::string& category, long double expense) {
    if (category.empty())
        throw std::logic_error("Expense error: category cannot be empty");
    acc._balance -= abs(expense);
    acc._cash_flow.emplace_back(category, std::chrono::system_clock::now(), -abs(expense));
}

[[nodiscard]] long double expenses_tracker::total_income() const {
    long double sum = 0.0;
    for (auto& f: acc._cash_flow) {
        if (f._funds >= 0.0) 
            sum += f._funds;
    }
    return sum;
}

[[nodiscard]] long double expenses_tracker::total_expenses() const {
    long double sum = 0.0;
    for (auto& f: acc._cash_flow) {
        if (f._funds < 0.0) 
            sum += f._funds;    
    }
    return (-sum);
}

[[nodiscard]] long double expenses_tracker::income_by_category(const std::string& category) const {
    long double sum = 0.0;
    for (auto& f: acc._cash_flow) {
        if (f._funds >= 0.0 && f._category == category) 
            sum += f._funds;
    }
    return sum;
}

[[nodiscard]] long double expenses_tracker::expenses_by_category(const std::string& category) const {
    long double sum = 0.0;
    for (auto& f: acc._cash_flow) {
        if (f._funds < 0.0 && f._category == category) 
            sum += f._funds; 
    }
    return (-sum); 
}

[[nodiscard]] long double expenses_tracker::get_balance() const {
    return acc._balance;
}

void expenses_tracker::upload_cashflow_to_file(std::ofstream &file) {
    for (auto& it: acc._cash_flow) {
        std::time_t current_time = std::chrono::system_clock::to_time_t(it._time_point);
        file << std::put_time(std::localtime(&current_time), "%Y-%m-%d %H:%M:%S") << " <--> " << it._category << " <--> " << it._funds << "\n";
    }

    file.close();
}


