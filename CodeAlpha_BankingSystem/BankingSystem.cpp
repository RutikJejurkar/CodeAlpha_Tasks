# include<iostream>
#include <fstream>
#include <string>
using namespace std;

class Account {
    public:
    int accNo;
    string name;
    float balance;

    void createAccount()
    {
        cout << "Enter Account No: ";
        cin >> accNo;

        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Initial Balance: ";
        cin >> balance;

        ofstream file("account.txt",ios::app);
        file << accNo << " "<< name << " "<< balance << endl;
        file.close();

        cout << "Account Created Successfully!\n";

    }
    
    void deposit()
    {
        float amt;
        cout << "Enter amount to deposite: ";
        cin >> amt;

        balance += amt;

        ofstream t("trnsaction.txt",ios::app);
        t << accNo << " Deposit " << amt << endl;
        t.close();

        cout << "Deposit Successful!\n";
    }

    void withdraw()
    {
        float amt;
        cout << "Enter amount to withdraw: ";
        cin >> amt;

        if(amt > balance )
        {
            cout << "Insufficiant Balance!..\n";
            return;
        }

        balance -= amt;

        ofstream t("transaction.txt", ios::app);
        t << accNo << "Withdraw " <<amt <<endl;
        t.close();

        cout << "Withdraw Successful!...\n";

    }

    void show()
    {
        cout << "\nAccount No: " << accNo;
        cout << "\nName: " << name;
        cout << "\nBalance: " << balance << endl;
    }
};

int main()
{
    Account a;
    int choice;

    while(true)
    {
        cout << "\n1. Create Account";
        cout << "\n2. Deposite";
        cout << "\n3. Withdraw";
        cout << "\n4. Show Details";
        cout << "\n5.Exit";
        cout << "\nEnter choice:";
        cin >> choice;

        if(choice == 1)
            a.createAccount();

        else if(choice == 2)
            a.deposit();

        else if(choice == 3)
            a.withdraw();

        else if(choice == 4)
            a.show();

        else if(choice == 5)
            break;

        else
            cout << "Invalid choice!..\n";
    }

    return 0;
}