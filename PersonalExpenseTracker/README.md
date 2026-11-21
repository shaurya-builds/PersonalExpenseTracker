# Personal Expense Tracker (C Programming Mini Hackathon)

## Team Details
* **Team Name:** Tech Titans
* **Batch:**38
* **Team Members:**
1. Shaurya Awasthi

## Problem Statement
Build a simple, menu-driven Personal Expense Tracker in C to help a student manage a monthly budget, categorize expenses (Food, Travel, Books, Entertainment), calculate total spending and remaining budget, identify the highest-spending category, and display a warning if the budget is exceeded.

## Objectives & Features
* Input and validate a positive monthly budget.
* Record multiple expenses across 4 categories: Food, Travel, Books, and Entertainment.
* Calculate category-wise totals and overall spending.
* Show remaining budget or a warning message if the monthly budget is exceeded.
* Find and display the category with the highest expenditure.

## C Programming Concepts Used
* Variables and Operators
* 1D Arrays (`float exp[4]`)
* User-Defined Functions (`addExpense()`, `showSummary()`)
* Conditional Statements (`if-else`, `switch-case`)
* Loops (`do-while`, `while`, `for`)
* Input Validation

## Algorithm
1. **Start** the program.
2. Input the monthly `budget` and validate that it is greater than `0`.
3. Initialize a 1D array `exp[4] = {0, 0, 0, 0}` to store category-wise totals.
4. Display the main menu using a `do-while` loop:
   - `1`: Add Expense
   - `2`: View Summary
   - `3`: Exit
5. **If Choice = 1:** Call `addExpense(exp)` to select a category (`1-4`), validate the amount (`> 0`), and add it to `exp[cat - 1]`.
6. **If Choice = 2:** Call `showSummary(exp, budget)` to compute total spending, check budget status (remaining or exceeded warning), and find the highest spending category using a `for` loop.
7. **If Choice = 3:** Exit the program.
8. **Stop**.

## How to Compile and Run
```bash
gcc expense_tracker.c -o expense_tracker
./expense_tracker