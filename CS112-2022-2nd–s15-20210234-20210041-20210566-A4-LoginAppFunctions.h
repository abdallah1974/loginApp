// FCAI – Programming 1 – 2022 - Assignment 4
// Program Name: CS112-203-2nd–s15-20210234-20210041-20210566-A4-LoginAppFunctions.h
// Last Modification Date: 15/5/2022
// Abdallah hassan abdallah  20210234
// Ahmed mamdouh mohamed     20210041
// Abdelrahman ahmed ibrahim 20210566

#ifndef LOGINAPP_H_INCLUDED
#define LOGINAPP_H_INCLUDED

#include <iostream>
#include <bits/stdc++.h>
#include <regex>
#include <conio.h>


using namespace std;




struct userProfil{
    string fname ;
    string lname ;
    string email;
    string password;
    string gender;
    string username;
    string age;
    string mobilenumber;
};

void loadExistingUsers(fstream& usersFile,vector<userProfil>& users);
string userfullname(userProfil newUser);
string userage(userProfil newUser);
string useremail(userProfil newUser,vector<userProfil> users);
string usergender(userProfil newUser);
string usermobile(userProfil newUser);
string user_name(userProfil newUser);
void showCondtions();
string secretPassword(string& password);
void checkValidation(string& password);
void reEnterPassword(string& password);
string Password(userProfil newUser,vector<userProfil> users);
void registerUser(userProfil newUser,vector<userProfil> users);
bool isValidName(string name);
bool isValidpass(string pass);
string takePass();
void changePassword(vector<userProfil> users,string userName);
void login(vector<userProfil> users);
string decryption(string input);
string encryption(string input);


#endif // LOGINAPP_H_INCLUDED
