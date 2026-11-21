#include <stdio.h>

// Simple functions
void addExpense(float exp[]);
void showSummary(float exp[], float budget);

int main() {
    float budget;
    // 0: Food, 1: Travel, 2: Books, 3: Entertainment
    float exp[4] = {0, 0, 0, 0}; 
    int choice;

    printf("=== Personal Expense Tracker ===\n");
    printf("Enter your monthly budget: ");
    scanf("%f", &budget);

    while (budget <= 0) {
        printf("Invalid! Enter budget greater than 0: ");
        scanf("%f", &budget);
    }

    do {
        printf("\n--- Menu ---\n");
        printf("1. Add Expense\n");
        printf("2. View Summary\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(exp);
                break;
            case 2:
                showSummary(exp, budget);
                break;
            case 3:
                printf("Exiting... Thank you!\n");
                break;
            default:
                printf("Wrong choice! Enter 1, 2 or 3.\n");
        }
    } while (choice != 3);

    return 0;
}

void addExpense(float exp[]) {
    int cat;
    float amt;

    printf("\nCategories:\n");
    printf("1. Food\n");
    printf("2. Travel\n");
    printf("3. Books\n");
    printf("4. Entertainment\n");
    printf("Select category (1-4): ");
    scanf("%d", &cat);

    if (cat < 1 || cat > 4) {
        printf("Invalid category!\n");
        return;
    }

    printf("Enter amount: ");
    scanf("%f", &amt);

    if (amt <= 0) {
        printf("Invalid amount!\n");
        return;
    }

    // Array mein directly amount add karna
    exp[cat - 1] = exp[cat - 1] + amt;
    printf("Expense added!\n");
}

void showSummary(float exp[], float budget) {
    float total = 0;
    int maxIndex = 0;

    // Total aur highest category nikalne ke liye loop
    for (int i = 0; i < 4; i++) {
        total = total + exp[i];
        if (exp[i] > exp[maxIndex]) {
            maxIndex = i;
        }
    }

    printf("\n--- Expense Summary ---\n");
    printf("Food          : %.2f\n", exp[0]);
    printf("Travel        : %.2f\n", exp[1]);
    printf("Books         : %.2f\n", exp[2]);
    printf("Entertainment : %.2f\n", exp[3]);
    printf("-----------------------\n");
    printf("Total Spent   : %.2f\n", total);
    printf("Monthly Budget: %.2f\n", budget);

    if (total <= budget) {
        printf("Remaining Budget: %.2f\n", budget - total);
    } else {
        printf("WARNING! Budget exceeded by: %.2f\n", total - budget);
    }

    // Highest spending category print karna
    if (total == 0) {
        printf("Highest Spending: None\n");
    } else if (maxIndex == 0) {
        printf("Highest Spending: Food (%.2f)\n", exp[0]);
    } else if (maxIndex == 1) {
        printf("Highest Spending: Travel (%.2f)\n", exp[1]);
    } else if (maxIndex == 2) {
        printf("Highest Spending: Books (%.2f)\n", exp[2]);
    } else {
        printf("Highest Spending: Entertainment (%.2f)\n", exp[3]);
    }
}