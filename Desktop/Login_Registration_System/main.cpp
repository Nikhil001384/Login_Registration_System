
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Registration Function
void registerUser()
{
    string username, password, u, p;

    cout << "\nEnter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    ifstream readFile("users.txt");

    while (readFile >> u >> p)
    {
        if (u == username)
        {
            cout << "\nUsername already exists!" << endl;
            readFile.close();
            return;
        }
    }

    readFile.close();

    ofstream writeFile("users.txt", ios::app);

    if (!writeFile)
    {
        cout << "File could not be opened!" << endl;
        return;
    }

    writeFile << username << " " << password << endl;
    writeFile.close();

    cout << "\nRegistration Successful!" << endl;
}

// Login Function
void loginUser()
{
    string username, password, u, p;
    bool found = false;

    cout << "\nEnter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    ifstream readFile("users.txt");

    while (readFile >> u >> p)
    {
        if (u == username && p == password)
        {
            found = true;
            break;
        }
    }

    readFile.close();

    if (found)
    {
        cout << "\nLogin Successful!" << endl;
        cout << "Welcome, " << username << "!" << endl;
    }
    else
    {
        cout << "\nInvalid Username or Password!" << endl;
    }
}

// Main Function
int main()
{
    int choice;

    do
    {
        cout << "\n================================" << endl;
        cout << "   LOGIN & REGISTRATION SYSTEM" << endl;
        cout << "================================" << endl;

        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                registerUser();
                break;

            case 2:
                loginUser();
                break;

            case 3:
                cout << "\nThank you for using our system!" << endl;
                break;

            default:
                cout << "\nInvalid Choice! Try Again." << endl;
        }

    } while (choice != 3);

    return 0;
}
