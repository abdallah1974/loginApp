#include <iostream>
#include <bits/stdc++.h>
#include <regex>
#include <conio.h>

using namespace std;

struct userProfil{
    string email;
    string password;
    string phoneNumber;
};

void loadExistingUsers(vector<userProfil>& users){
    fstream usersFile;
    usersFile.open("users.txt");
    while (!usersFile.eof()){
        userProfil nextUser;
        usersFile >> nextUser.email;
        usersFile >> nextUser.password;
        usersFile >> nextUser.phoneNumber;
        users.push_back(nextUser);
    }
}

void showCondtions(){
    cout << "..... create a Password ....." << endl;
    cout << "it should contain at least\nan uppercase letter, lowercase letter, number and special char"<<endl;
    cout << "special chars like (!@#_$ or space)" << endl;
    cout << "and it must be 12 char or more ... " << endl;
    cout << "enter ur password: ";
}

string secretPassword(string& password)
{

    char c;

    do{
        c = getch();
        switch(c){

            case 13:
                cout<<endl;
                break;
            case 8:
                if(password.length()>0){
                    password.erase(password.end()-1);
                    cout<<c<<' '<<c;
                }
                break;
            default:
                password += c;
                cout<<'*';
                break;
        }
    }while(c!=13);

    return password;
}

void checkValidation(string& password){

    string lowercase = "(?=.*[a-z])";
    string uppercase = "(?=.*[A-Z])";
    string numbers = "(?=.*[0-9])";
    string specialChar = "(?=.*[^a-z^A-Z^0-9])";
    string minChars = "(?=.*[12,])";
    string checkAll = lowercase + uppercase + numbers + specialChar + minChars;

    regex validation(checkAll);
    while(true){
        bool isValid = regex_search(password.begin(),password.end(), validation);
        if(isValid){
            cout << "\npassword is vaild and strong enough" << endl;
            break;
        }else{
            cout << "\npassword does not match conditions" << endl;
            cout << "plz enter a valid password: ";

            secretPassword(password);
        }
    }
}

void reEnterPassword(string& password){
    string repeatedPassword;
    cout << "plz reEnter password to ensure: ";

    secretPassword(repeatedPassword);

    while (true){
        if (repeatedPassword != password){
            cout << "it does not match .. plz try again: ";

            repeatedPassword.clear();
            secretPassword(repeatedPassword);
        }else{
            break;
        }
    }
}



void Password(){

    string  password;
    showCondtions();
    secretPassword(password);
    checkValidation(password);
    reEnterPassword(password);
    // storePassword(password); {still working on it}
}

int main()
{
    vector<userProfil> users;
    cout << "welcome to login App"<< endl;
    loadExistingUsers(users);
    for(userProfil user: users){
        cout << user.email << " " << user.password << " " << user.phoneNumber << endl;
    }

    Password();

    return 0;
}
