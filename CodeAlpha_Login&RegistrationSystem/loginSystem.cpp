# include<iostream>
# include<fstream>
# include<string>
using namespace std;

//registration
void registerUser()
{
    string username, password, u, p;
    bool exists = false;

    cout << "\n___Register___\n";
    cout << "Enter username: ";
    cin >> username;


    cout << "Enter Password: ";
    cin >> password;

    //duplicate checking
    ifstream check("users.txt");


    while(check >> u >>p)
    {
        if(u == username)
        {
            exists = true;
            break;
        }
    }
    check.close();

    if(exists)
    {
        cout << "Username already exists!...\n";
        return;
    }

    //new user
    ofstream file("users.txt", ios::app);
    file << username << " " << password << endl;
    file.close();

    cout << "Registration successful!..\n";

}

//login

void loginUser()
{
    string username, password, u, p;
    bool success = false;

    cout << "\n   LOGIN   \n";
    cout <<"Username: ";
    cin >> username;

    cout << "Password: ";
    cin >> password;

    ifstream file("users.txt");

    while(file >> u >>p)
    {
        if(u == username && p== password)
        {
            success = true;
            break;
        }
    }
    file.close();

    if(success)
        cout << "Login Successful ! Welcome " << username << endl;
    else
        cout << "Invalid username or password!\n";
}

int main()
{
    int choice;

    while (true)
    {
        cout << "\n1. Register";
        cout << "\n2. Login";
        cout << "\nEnter choice: ";
        cin >> choice;

        if(choice == 1)
            registerUser();

        else if(choice == 2)
            loginUser();

        else if(choice == 3)
            break;

        else 
            cout << "Invalid choice!\n";
    }
    return 0;
    
}