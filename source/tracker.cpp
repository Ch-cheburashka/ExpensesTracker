#include <../include/tracker.hpp>
#include <../include/account.hpp>
long double expenses_tracker::calculate_income(const std::vector<std::string>& names) {
    long double income = 0;
    for (auto name: names) {
        try {
            for (auto it: accounts.at(name).get_cash_flow()) {
                if (it.second > 0)
                    income += it.second;
            }
        }
        catch(...) {
            break;
        }
    }
    return income;
}

void expenses_tracker::add_account(const account& acc) {
    accounts.emplace(acc.get_name(), acc);
}
