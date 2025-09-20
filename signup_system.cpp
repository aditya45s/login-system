#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool usernameExists(const string& username) {
    string u, p;
    ifstream file("users.txt");
    while (file >> u >> p) {
        if (u == username) {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

void signup() {
    string username, password;
    cout << "Enter new username: ";
    cin >> username;

    if (usernameExists(username)) {
        cout << "Username already exists! Try a different one.\n";
        return;
    }

    cout << "Enter new password: ";
    cin >> password;

    ofstream file("users.txt", ios::app);
    file << username << " " << password << endl;
    file.close();

    cout << "Signup successful! You can now login.\n";
}

bool login() {
    string username, password, u, p;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");
    while (file >> u >> p) {
        if (u == username && p == password) {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

int main() {
    int choice;
    cout << "===== Welcome to Login/Signup System =====\n";

    do {
        cout << "\nMenu:\n1. Signup\n2. Login\n3. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                signup();
                break;
            case 2:
                if (login())
                    cout << "Login successful! Welcome.\n";
                else
                    cout << "Invalid username or password.\n";
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 3);

    return 0;
}
