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
vector<string>v;
vector<string>v2;
fstream myfile ;
string name , gender , country , username , password , email, age , id , mobilenumber;
void userfullname();
void userage();
void useremail();
void usergender();
void usercountry();
void usermobile();
void user_name();
void userpassword();
void userid();


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
void userfullname(){

 cout << "Enter your full name : ";
    getline(cin , name) ;
    regex n("([a-zA-Z]+[ ]+[a-zA-Z]+)");
    if (regex_match(name.begin(), name.end(), n) ){
        cout << "Hello " << name << "\n" ;
            myfile << name << "\n" ;
    }
    else {
        cout << "Wrong name please try again \n" << "restart your program \n" ;
    }
    cout << endl ;
}
void userage(){
cout << "Enter your age " << name << " : " ;
    cin >> age ;
    regex a("([0-9]+)");
    if (regex_match(age.begin(), age.end(), a) ){
          cout << "Valid age \n" ;
              cout << endl ;
              myfile << age << "\n" ;
    }
    else {
        cout << "Wrong age please try again \n" << "Enter only numbers \n" ;
    }
}
void useremail(){
int sum = 0 ;
cout << "email ex examble@gmail.com " << endl ;
cout << "Enter email :"  ;
cin >> email ;
regex e("(\\w+@gmail.com)") ;
if (regex_match(email.begin(), email.end(), e)){
    cout << "right syntax email" << endl ;
    ifstream myfile2 ("regesteredusers");
string elements ;
while (myfile2 >> elements)
{
    v.push_back(elements) ;
}
for (int i = 0 ; i < v.size() ; i++){
            if (v[i] == email  || v[i] == email)
                cout << "This email is taken" << endl ;
else
        sum++;

}
if (sum == v.size())
    myfile << email << "\n" ;
}
    else {
    cout << "Not Valid syntax" << endl ;
    }
}
void usergender(){
cout << "Enter your gender (male or female) : "  ;
    cin >> gender ;
            regex g("([male]*[female]*)");
        if ( regex_match(gender.begin(), gender.end(), g) ){
          cout << "Valid gender \n" ;
              myfile << gender << "\n" ;
    }
    else {
        cout << "Wrong answer please try again \n" << "Enter only from above choices \n" ;
 }
}
void usercountry(){
cout << "Enter your country : "  ;
    cin >> country ;
            regex c("([a-zA-Z]+)");
        if ( regex_match(country.begin(), country.end(), c) ){
          cout << "Valid country \n" ;
              cout << endl ;
              myfile << country << "\n" ;
}
}
void usermobile(){
cout << "user mobile number ex 01*********" << endl ;
cout << "Enter mobile number :"  ;
cin >> mobilenumber ;
regex m("([01]{2}[0-9]{9})") ;
if (regex_match(mobilenumber.begin(), mobilenumber.end(), m)){
    cout << "Valid mobile number \n" << endl ;
    myfile << mobilenumber << "\n" ;
}
}
void user_name(){
cout << "user_name like examble_login  " << endl ;
cout << "Enter user_name :"  ;
cin >> username ;
regex u("([a-zA-Z]+[_]?[a-zA-Z]+)") ;
if (regex_match(username.begin(), username.end(), u)){
    cout << "Valid user_name" << endl ;
    myfile << username << "\n" ;
}
else {
    cout << "read the rules of user name again and restart program" << endl ;
}
}
void userpassword(){
cout << "strong password ex. 123EXample!*# or Example123!*#  " << endl ;
cout << "Enter password :"  ;
cin >> password ;
regex p("(\\w+[!*#]+)") ;
if (regex_match(password.begin(), password.end(), p)){
    cout << "Valid pass" << endl ;
    myfile << password << "\n" ;
}
else {
    cout << "read the rules of strong pass again and restart program" << endl ;
}
}
void userid (){
int sum = 0 ;
cout << "id ex 20210011 " << endl ;
cout << "Enter id :"  ;
cin >> id ;
regex t("([0-9]+)") ;
if (regex_match(id.begin(), id.end(), t)){
    cout << "right syntax id" << endl ;
    ifstream myfile3 ("regesteredusers");
string elements ;
while (myfile3 >> elements)
{
    v2.push_back(elements) ;
}
for (int i = 0 ; i < v2.size() ; i++){
            if (v2[i] == id )
                cout << "This id is taken" << endl ;
else
        sum++;

}
if (sum == v2.size())
    myfile << id << "\n" ;
}
    else {
    cout << "Not Valid syntax" << endl ;
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
    userfullname() ;
    userage();
    usergender();
    usercountry();
    usermobile();
    user_name();
    useremail();
    userpassword();
    userid();
    Password();

    return 0;
}
