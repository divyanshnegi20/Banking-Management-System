#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100

// Structure to represent a bank account
struct Account
{
    int accountNumber;
    char name[50];
    float balance;
};

// Global array to store accounts
struct Account accounts[MAX_ACCOUNTS];
int numAccounts = 0;

// Function prototypes
void createAccount();
void displayAccount();
void deposit();
void withdraw();
void transfer();

// Main function
int main()
{
    int choice;

    do
    {
        printf("\nBanking Management System\n");
        printf("1. Create Account\n");
        printf("2. Display Account\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("5. Transfer\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            createAccount();
            break;
        case 2:
            displayAccount();
            break;
        case 3:
            deposit();
            break;
        case 4:
            withdraw();
            break;
        case 5:
            transfer();
            break;
        case 6:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Please enter a number between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}

// Function to create a new bank account
void createAccount()
{
    if (numAccounts == MAX_ACCOUNTS)
    {
        printf("Cannot create more accounts. Maximum limit reached.\n");
        return;
    }

    struct Account newAccount;
    printf("Enter account number: ");
    scanf("%d", &newAccount.accountNumber);

    printf("Enter name: ");
    scanf("%s", newAccount.name);

    printf("Enter initial balance: ");
    scanf("%f", &newAccount.balance);

    accounts[numAccounts] = newAccount;
    numAccounts++;

    printf("Account created successfully.\n");
}

// Function to display account information
void displayAccount()
{
    int accountNumber;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    int found = 0;
    for (int i = 0; i < numAccounts; i++)
    {
        if (accounts[i].accountNumber == accountNumber)
        {
            printf("Account Number: %d\n", accounts[i].accountNumber);
            printf("Name: %s\n", accounts[i].name);
            printf("Balance: $%.2f\n", accounts[i].balance);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Account not found.\n");
    }
}

// Function to deposit funds into an account
void deposit()
{
    int accountNumber;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    int found = 0;
    for (int i = 0; i < numAccounts; i++)
    {
        if (accounts[i].accountNumber == accountNumber)
        {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            accounts[i].balance += amount;
            printf("Deposit successful. New balance: $%.2f\n", accounts[i].balance);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Account not found.\n");
    }
}

// Function to withdraw funds from an account
void withdraw()
{
    int accountNumber;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    int found = 0;
    for (int i = 0; i < numAccounts; i++)
    {
        if (accounts[i].accountNumber == accountNumber)
        {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (amount > accounts[i].balance)
            {
                printf("Insufficient balance.\n");
            }
            else
            {
                accounts[i].balance -= amount;
                printf("Withdrawal successful. New balance: $%.2f\n", accounts[i].balance);
            }
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Account not found.\n");
    }
}

// Function to transfer funds between accounts
void transfer()
{
    int sourceAccount, targetAccount;
    float amount;

    printf("Enter source account number: ");
    scanf("%d", &sourceAccount);

    printf("Enter target account number: ");
    scanf("%d", &targetAccount);

    int foundSource = 0, foundTarget = 0;
    for (int i = 0; i < numAccounts; i++)
    {
        if (accounts[i].accountNumber == sourceAccount)
        {
            foundSource = 1;
        }
        if (accounts[i].accountNumber == targetAccount)
        {
            foundTarget = 1;
        }
        if (foundSource && foundTarget)
        {
            break;
        }
    }

    if (!foundSource)
    {
        printf("Source account not found.\n");
    }
    else if (!foundTarget)
    {
        printf("Target account not found.\n");
    }
    else
    {
        printf("Enter amount to transfer: ");
        scanf("%f", &amount);

        for (int i = 0; i < numAccounts; i++)
        {
            if (accounts[i].accountNumber == sourceAccount)
            {
                if (amount > accounts[i].balance)
                {
                    printf("Insufficient balance in source account.\n");
                }
                else
                {
                    accounts[i].balance -= amount;
                    printf("Transfer successful from source account. New balance: $%.2f\n", accounts[i].balance);
                }
            }
            if (accounts[i].accountNumber == targetAccount)
            {
                accounts[i].balance += amount;
                printf("Transfer successful to target account. New balance: $%.2f\n", accounts[i].balance);
            }
        }
    }
}
