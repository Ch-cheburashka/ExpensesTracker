#include <tracker.hpp>
#include <catch2/catch_test_macros.hpp>

TEST_CASE("expenses_tracker_test") {
    SECTION("add_income_test") {
        expenses_tracker tracker;
        REQUIRE(tracker.get_balance() == 0.0);
        tracker.add_income("Salary", 20000);
        REQUIRE(tracker.get_balance() == 20000.0);
        REQUIRE_THROWS_AS (
                tracker.add_income("Salary", -20000),
                std::logic_error
                );
        REQUIRE_THROWS_AS(
                tracker.add_income("", 20),
                std::logic_error
                );
    }
    SECTION("add_expense_test") {
        expenses_tracker tracker;
        tracker.add_expense("Supermarket",2000);
        REQUIRE(tracker.get_balance() == -2000.0);
        REQUIRE_THROWS_AS(
                tracker.add_expense("", 20),
                std::logic_error
        );
    }
    SECTION("total_income_test") {
        expenses_tracker tracker;
        tracker.add_income("Salary", 20000);
        tracker.add_income("Social help", 5000);
        REQUIRE(tracker.get_balance() == 25000.0);
        REQUIRE(tracker.total_income() == 25000.0);
    }
    SECTION("total_expenses_test") {
        expenses_tracker tracker;
        tracker.add_expense("Supermarket",2000);
        tracker.add_expense("Entertainment", 3000);
        REQUIRE(tracker.get_balance() == -5000.0);
        REQUIRE(tracker.total_expenses() == 5000.0);
    }
    SECTION("income_by_category_test") {
        expenses_tracker tracker;
        tracker.add_income("Social help", 5000);
        tracker.add_income("Salary", 25000);
        tracker.add_income("Salary", 20000);
        tracker.add_income("Social help", 5000);
        REQUIRE(tracker.income_by_category("Social help") == 10000.0);
        REQUIRE(tracker.income_by_category("Salary") == 45000.0);
        REQUIRE(tracker.income_by_category("Cashback") == 0.0);
    }
    SECTION("expenses_by_category_test") {
        expenses_tracker tracker;
        tracker.add_expense("Supermarket",2000);
        tracker.add_expense("Entertainment", 3000);
        tracker.add_expense("Supermarket", 5000);
        tracker.add_expense("Entertainment", 3000);
        REQUIRE(tracker.expenses_by_category("Supermarket") == 7000.0);
        REQUIRE(tracker.expenses_by_category("Entertainment") == 6000.0);
        REQUIRE(tracker.expenses_by_category("Insurance") == 0.0);
    }
}