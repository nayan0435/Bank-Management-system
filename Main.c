#include <stdio.h>
#include <string.h>

struct BankAccount {
    int accountNumber;
    char name[50];
    float balance;
};

int main() {
    struct BankAccount account;
    int choice;
    float amount;

    account.accountNumber = 0;
    account.balance = 0;

    while (1) {
        printf("\n===== BANK MANAGEMENT SYSTEM =====\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Account Details\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (account.accountNumber != 0) {
                    printf("Account already exists!\n");
                } else {
                    printf("Enter Account Number: ");
                    scanf("%d", &account.accountNumber);
                    printf("Enter Account Holder Name: ");
                    scanf(" %[^\n]", account.name);
                    printf("Account created successfully!\n");
                }
                break;

            case 2:
                if (account.accountNumber == 0) {
                    printf("No account found. Create an account first.\n");
                } else {
                    printf("Enter amount to deposit: ");
                    scanf("%f", &amount);
                    if (amount > 0) {
                        account.balance += amount;
                        printf("Deposit successful!\n");
                    } else {
                        printf("Invalid amount.\n");
                    }
                }
                break;

            case 3:
                if (account.accountNumber == 0) {
                    printf("No account found. Create an account first.\n");
                } else {
                    printf("Enter amount to withdraw: ");
                    scanf("%f", &amount);
                    if (amount > 0 && amount <= account.balance) {
                        account.balance -= amount;
                        printf("Withdrawal successful!\n");
                    } else {
                        printf("Insufficient balance or invalid amount.\n");
                    }
                }
                break;

            case 4:
                if (account.accountNumber == 0) {
                    printf("No account found.\n");
                } else {
                    printf("\n--- Account Details ---\n");
                    printf("Account Number: %d\n", account.accountNumber);
                    printf("Account Holder: %s\n", account.name);
                    printf("Balance: %.2f\n", account.balance);
                }
                break;

            case 5:
                printf("Thank you for using the Bank Management System.\n");
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
