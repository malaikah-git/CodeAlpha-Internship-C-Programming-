#include<iostream>
#include<fstream>

using namespace std;

void registerUser(){
    string username, password;
    cout << "Enter username: ";
    cin >> username;

    ifstream checkFile("user.txt");
    string User, Pass;
    while(checkFile >> User >> Pass){
        if(username == User){
            cout << "Username already exists." << endl;
            checkFile.close();
            return;
        }
    }
    checkFile.close();
    
    cout << "Enter password: ";
    cin >> password;

    ofstream file("user.txt", ios :: app);
    file << username << " " << password << endl;
    file.close();

    cout << "Registration successful!" << endl; 
}

bool loginUser(){
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file("user.txt");
    string User, Pass;
    
    while(file >> User >> Pass){
        if(User == username && Pass == password){
            file.close();
            return true;
        }
    }
    
    file.close();
    return false;
}

int main(){
    int choice;
    do{
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "3. Exit" << endl;
        cout << "Please enter your choice: ";
        cin  >> choice;

        switch(choice){
            case 1:
                cout << "You chose to login." << endl;
                if(loginUser())
                    cout << "Login successful!" << endl;
                else 
                    cout << "Invalid username or password." << endl;
                break;
            case 2:
                cout << "You chose to register." << endl;
                registerUser();
                break;
            case 3:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while(choice != 3);
    
    return 0;

}