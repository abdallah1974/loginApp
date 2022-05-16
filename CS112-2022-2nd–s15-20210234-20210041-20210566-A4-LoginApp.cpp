// FCAI – Programming 1 – 2022 - Assignment 4
// Program Name: CS112-203-2nd–s15-20210234-20210041-20210566-A4-LoginApp.cpp
// Last Modification Date: 15/5/2022
// Abdallah hassan abdallah  20210234
// Ahmed mamdouh mohamed     20210041
// Abdelrahman ahmed ibrahim 20210566

#include "CS112-2022-2nd–s15-20210234-20210041-20210566-A4-LoginAppFunctions.h"




int main()
{
    fstream usersFile;
    vector<userProfil> users;
    userProfil newUser;
    int choice;

    cout << "welcome to login App"<< endl;
    loadExistingUsers(usersFile,users);

    for(int i = 0; i < users.size(); i++)
    {
        cout << users[i].username << endl;
    }

    cout << "enter 1 to Register" << endl;
    cout << "enter 2 to Login" << endl;
    cout << "enter 3 to change password" << endl;
    cout << "enter 4 to Exit" << endl;
    cin >> choice;
    if (choice == 1){
        registerUser(newUser,users);
    }else if (choice == 2){
        login(users);
    }else if (choice == 4){
        _Exit(0);
    }


    return 0;
}
