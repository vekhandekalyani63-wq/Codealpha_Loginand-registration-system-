
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void registration()
{
    string username, password, u, p;
    bool found = false;

    cout << "\n--- Registration ---\n";
    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    ifstream fin("users.txt");

    while (fin >> u >> p)
    {
        if (u == username)
        {
            found = true;
            break;
        }
    }
    fin.close();

    if (username.empty() || password.empty())
    {
        cout << "Username and password cannot be empty!\n";
    }
    else if (found)
    {
        cout << "Username already exists!\n";
    }
    else
    {
        ofstream fout("users.txt", ios::app);
        fout << username << " " << password << endl;
        fout.close();

        cout << "Registration successful!\n";
    }
}

void login()
{
    string username, password, u, p;
    bool found = false;

    cout << "\n--- Login ---\n";
    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    ifstream fin("users.txt");

    while (fin >> u >> p)
    {
        if (u == username && p == password)
        {
            found = true;
            break;
        }
    }
    fin.close();

    if (found)
        cout << "Login successful! Welcome, " << username << "!\n";
    else
        cout << "Invalid username or password!\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n===== LOGIN AND REGISTRATION =====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                registration();
                break;

            case 2:
                login();
                break;

            case 3:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 3);

    return 0;
}
Add login and registration system 
