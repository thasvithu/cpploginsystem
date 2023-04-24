#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to register a new user
void signup(){
    string userName, password;

    // Prompt the user to enter their username and password
    cout << "\nEnter user name: " << endl;
    cin >> userName;
    cout << "Enter password: " << endl;
    cin >> password;

    // create register file
    ofstream file("register.txt", ios::app);
    
    // Write the new user's to the database file
    file << userName << "," << password << endl;

    // Close the file
    file.close();

    // Notify the user that registration was successful
    cout << "Registration successful!" << endl;
}

// Function to authenticate a user
bool authenticateUser(){
    string userName, password;
    bool authenticated = false;

    // Prompt the user to enter their username and password
    cout << "\nEnter username: " << endl;
    cin >> userName;
    cout << "Enter password: " << endl;
    cin >> password;

    // Open the user database file in read mode
    ifstream file("register.txt");

    string line;
    while (getline(file, line)) {
        // Split the line into username and password fields
        size_t comma = line.find(",");
        string storedUsername = line.substr(0, comma);
        string storedPassword = line.substr(comma + 1);

        // Check if the entered credentials match the current user
        if (userName == storedUsername && password == storedPassword) {
            authenticated = true;
            break;
        }
    }

    // Close the file
    file.close();

    // Return whether the user was authenticated
    return authenticated;
}


int main(){
    int select;

    cout << "--Welcome--" << endl;
    cout << "1 - Login" << endl;
    cout << "2 - Signup" << endl;

    cout << "\nMake choice:" << endl;
    cin >> select;

    switch (select) {
        case 1:
            if (authenticateUser())
                cout << "Login successful!" << endl;
            else 
                cout << "Login failed." << endl;
            break;
        case 2:
            signup();
            break;
        default:
            cout << "Invalid choice.\n";
            break;
    }

    return 0;
}