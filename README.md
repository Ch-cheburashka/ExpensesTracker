# Expenses Tracker

A simple command-line application to track and manage your income and expenses. The tracker allows you to categorize your transactions, view total income/expenses, and analyze cash flow by category.

## Table of Contents

- [Features](#features)
- [Commands](#commands)
- [Future Improvements](#future-improvements)

## Features

- **Income and Expenses Tracking:** Add and categorize your income and expenses.
- **Summary Reports:** Get a summary of total income, total expenses, and cash flow.
- **Category Breakdown:** View income and expenses by category.
- **File Upload:** Export cash flow to a file for backup or further analysis.
- **Unit Testing:** Comprehensive tests using Catch2 to ensure robustness.

## Commands

- `-i` or `--income` : Display total income.
- `-x` or `--expenses` : Display total expenses.
- `-c` or `--cashflow` : Display the cash flow with timestamps, categories, and amounts.
- `-ibc` or `--income-by-category <category>` : Display total income for a specific category.
- `-xbc` or `--expenses-by-category <category>` : Display total expenses for a specific category.
- `-u` or `--upload-to-file <filename>` : Upload the cash flow to a specified file.

## Future improvements

- **More Robust CLI Parsing:** Integrate a library for more advanced command-line parsing.
- **Graphical User Interface (GUI):** Develop a GUI version of the tracker.
