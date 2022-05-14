#include <iostream>
#include <bits/stdc++.h>
#include <regex>
#include <conio.h>

using namespace std;

struct userProfil{
    string name ;
    string email;
    string password;
    string gender;
    string username;
    string age;
    string mobilenumber;
};

string userfullname();
string userage();
string useremail();
string usergender();
string usermobile();
string user_name();
string userpassword();



void loadExistingUsers(vector<userProfil>& users){
    fstream usersFile;
    usersFile.open("users.txt");
    while (!usersFile.eof()){
        userProfil nextUser;
        usersFile >> nextUser.email;
        usersFile >> nextUser.password;
        usersFile >> nextUser.mobilenumber;
        users.push_back(nextUser);
    }
    usersFile.close();
}
//--------------------------------------------
string userfullname(userProfil newUser){

    cout << "Enter your full name : ";
    getline(cin , newUser.name);
    regex n("([a-zA-Z]+[ ]+[a-zA-Z]+)");
    while (true){
        if (regex_match(newUser.name.begin(), newUser.name.end(), n) ){
            cout << "Hello " << newUser.name << "\n";
            break;
        }else {
            cout << "Wrong name please try again \n";
            cout << "\nEnter your full name : ";
            getline(cin , newUser.name);
        }
    }

    cout << endl ;
    return newUser.name;
}
//--------------------------------------------
string userage(userProfil newUser){
    cout << "Enter your age: " ;
    cin >> newUser.age ;
    regex a("([0-9]+)");
    while (true){
        if (regex_match(newUser.age.begin(), newUser.age.end(), a) ){
              cout << "Valid age \n" ;
              cout << endl ;
              break;
        }
        else {
            cout << "Wrong age please try again \n" << "Enter only numbers \n" ;
            cout << "Enter your age: " ;
            cin >> newUser.age ;
        }
    }
    return newUser.age;
}
//--------------------------------------------
string useremail(userProfil newUser,vector<userProfil> users){
    int sum = 0 ;
    string elements ;


    cout << "email ex examble@gmail.com " << endl ;
    cout << "Enter email :"  ;
    cin >> newUser.email ;
    regex e("(\\w+@gmail.com)");

    while (true){
       if (regex_match(newUser.email.begin(), newUser.email.end(), e)){
            cout << "right syntax email" << endl;
            for(int i = 0; i < users.size(); i++){
                if(users[i].email == newUser.email){
                    cout << "email is already registered" <<endl;
                    cout << "please enter email has not registered: ";
                    cin >> newUser.email;
                    i = 0;
                }
            }
            break;
       }else {
            cout << "\nNot Valid syntax" << endl ;
            cout << "email ex examble@gmail.com " << endl ;
            cout << "Enter email :"  ;
            cin >> newUser.email ;
       }
    }
    return newUser.email;
}
//-------------------------------------------
string usergender(userProfil newUser){
    cout << "Enter your gender (male or female) : ";
    cin >> newUser.gender ;
    regex g("([male]*[female]*)");
    while (true){
        if (regex_match(newUser.gender.begin(), newUser.gender.end(), g)){
            cout << "Valid gender \n" ;
            break;

        }else {
            cout << "Wrong answer please try again \n" << "Enter only from above choices \n" ;
            cout << "Enter your gender (male or female) : ";
            cin >> newUser.gender ;
        }
    }
    return newUser.gender;
}
//--------------------------------------------
string usermobile(userProfil newUser){
    cout << "\nuser mobile number ex 01*********" << endl ;
    cout << "Enter mobile number: "  ;
    cin >> newUser.mobilenumber ;
    regex m("([01]{2}[0-9]{9})") ;
    while(true){
        if (regex_match(newUser.mobilenumber.begin(), newUser.mobilenumber.end(), m)){
            cout << "Valid mobile number \n" << endl ;
            break;
        }else{
            cout << "unvalid number" << endl;
            cout << "\nuser mobile number ex 01*********" << endl ;
            cout << "Enter mobile number: "  ;
            cin >> newUser.mobilenumber ;
        }
    }
    return newUser.mobilenumber;
}
//--------------------------------------------
string user_name(userProfil newUser){
    cout << "user_name like examble_login  " << endl ;
    cout << "Enter user_name: "  ;
    cin >> newUser.username;
    regex u("([a-zA-Z]+[_]?[a-zA-Z]+)");
    while (true){
        if (regex_match(newUser.username.begin(), newUser.username.end(), u)){
            cout << "Valid user_name" << endl ;
            break;
        }else {
            cout << "unvaild user name" << endl;
            cout << "user_name like examble_login  " << endl ;
            cout << "Enter user_name: "  ;
            cin >> newUser.username;
        }
    }
    return newUser.username;
}
//--------------------------------------------
void showCondtions(){


    cout << "\n..... create a Password ....." << endl;
    cout << "it should contain at least\nan uppercase letter, lowercase letter, number and special char"<<endl;
    cout << "special chars like (!@#_$ or space)" << endl;
    cout << "and it must be 12 char or more ... " << endl;
    cout << "enter ur password: ";
}
//--------------------------------------------
string secretPassword(string& password){
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
//--------------------------------------------
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
//--------------------------------------------
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
//--------------------------------------------
string Password(userProfil newUser,vector<userProfil> users){

    string  password;
    showCondtions();
    secretPassword(password);
    checkValidation(password);
    reEnterPassword(password);

    return password;
}
//-----------------------------------
void registerUser(userProfil newUser,vector<userProfil> users){
    fstream usersFile;
    usersFile.open("users.txt", ios::app);
    usersFile << endl;
    usersFile << userfullname(newUser) << " ";
    usersFile << userage(newUser)<< " ";
    usersFile << usergender(newUser)<< " ";
    usersFile << usermobile(newUser)<< " ";
    usersFile << user_name(newUser)<< " ";
    usersFile << useremail(newUser,users)<< " ";
    usersFile << Password(newUser, users)<< " ";

}

//--------------------------------------------

int main()
{
    vector<userProfil> users;
    userProfil newUser;
    int choice;

    cout << "welcome to login App"<< endl;
    loadExistingUsers(users);

    cout << "enter 1 to Register" << endl;
    cout << "enter 2 to Login" << endl;
    cout << "enter 3 to change password" << endl;
    cout << "enter 4 to Exit" << endl;
    cin >> choice;
    if (choice == 1){
        registerUser(newUser,users);
    }else if (choice == 4){
        _Exit(0);
    }


    return 0;
}
