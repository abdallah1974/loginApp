// FCAI – Programming 1 – 2022 - Assignment 4
// Program Name: CS112-203-2nd–s15-20210234-20210041-20210566-A4-LoginAppFunctions.cpp
// Last Modification Date: 15/5/2022
// Abdallah hassan abdallah  20210234
// Ahmed mamdouh mohamed     20210041
// Abdelrahman ahmed ibrahim 20210566

#include "CS112-2022-2nd–s15-20210234-20210041-20210566-A4-LoginAppFunctions.h"
userProfil user;

void loadExistingUsers(fstream& usersFile,vector<userProfil>& users){

    usersFile.open("users.txt");
    if(usersFile){
        while (!usersFile.eof()){
            userProfil nextUser;
            usersFile >> nextUser.fname;
            usersFile >> nextUser.age;
            usersFile >> nextUser.gender;
            usersFile >> nextUser.mobilenumber;
            usersFile >> nextUser.username;
            usersFile >> nextUser.email;
            usersFile>> nextUser.password;


            users.push_back(nextUser);
        }

    }
    for (auto one = users.begin(); one != users.end(); one++)
	{
        one->password = decryption(one->password);
	}
    usersFile.close();
}

//--------------------------------------------
string userfullname(userProfil newUser){

    cout << "Enter your first name : ";
    cin >> newUser.fname;
    cout << "Enter your last name : ";
    cin >> newUser.lname;

    regex n("([a-zA-Z]+[ ]+[a-zA-Z]+)");

    cout << endl ;
    return newUser.fname;
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
    cout << "user_name like AhmedMamdoh  " << endl ;
    cout << "Enter user_name: "  ;
    cin >> newUser.username;
    regex u("([a-zA-Z]+[a-zA-Z]+)");
    while (true){
        if (regex_match(newUser.username.begin(), newUser.username.end(), u)){
            cout << "Valid user_name" << endl ;
            break;
        }else {
            cout << "unvaild user name" << endl;
            cout << "user_name like AhmedMamdoh  " << endl ;
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
    usersFile << encryption(Password(newUser, users)) << " ";
    cout << "u have registered succrssfully\n" << endl;

}

//--------------------------------------------
bool isValidName(string name)
{
	string rule = "[a-zA-z-]*";
	regex r(rule);
	if (regex_match(name, r)) // check if the name passed follow the rules or not
		return true;
	else
		return false;
}

bool isValidpass(string pass)
{
	regex match("(?=.*[0-9])(?=.*[a-z])(?=.*[A-Z])(?=.*[!@#$%^&*-+=<>? ]).{8,}");
	if (regex_match(pass, match))
	{
		return true;
	}

	else
	{
		return false;
	}
}

string takePass()
{
	char chara;
	string pass , repass;
	cout << "password must contain: \n"
		 << "at least one letter \n "
		 << "at least one number \n"
		 << "at least one special character !@#$%^&*-+=<>? \n"
		 << "at least 8 characters \n";

	cout << "please enter password : ";

	chara = getch();
	while ( chara != 13)
	{
		if (chara == 127 || chara == 8)
		{
			if(pass.size() != 0 ){
			cout<< "\b \b";
			pass.pop_back();
			}
		}
		else
		{
			putchar('*');
			pass += chara;
		}
		chara = getch();
	}

	// check if password is strong enough
	if (isValidpass(pass))
	{
	// repeat password again
	repeatPassword:
	    cout << endl;
		cout << "please enter password again : ";
		chara = getch();
		while ( chara != 13)
		{
				if (chara == 127 || chara == 8)
		{
			if(repass.size() != 0 )
			{
			cout<< "\b \b";
			repass.pop_back();
			}
		}
			else
			{
				putchar('*');
				repass += chara;
			}
			chara = getch();
		}
		cout<<endl;
		if (pass == repass)
		{
			user.password = pass;
			//cout <<	"\n\nyour password is :  " <<	user.password;
		}
		else if (pass != repass)
		{
		choose:
			string choice;
			cout << "password dosn't match first one\n[ 1 ] try again\n[ 2 ]change password\n>> ";
			getline(cin, choice);
			if (choice == "1")
			{
				goto repeatPassword;
			}
			else if (choice == "2")
			{
				takePass();
			}
			else
			{
				goto choose;
			}
		}
	}
	else
	{
	    cout<<endl;
		cout << "invalid password \ntry again \n";
		takePass();
	}
	return pass;
}

void changePassword(vector<userProfil> users,string userName)
{
    char chara;
    string pass;
    bool foundPass = false;
    cout << "Please enter the old password : ";
    chara = getch();
    while (chara != 13)
    {
        if (chara == 127 || chara == 8)
        {
            if(pass.size() != 0 ){
                cout<< "\b \b";
                pass.pop_back();
            }
        }
        else
        {
            putchar('*');
            pass += chara;
        }
        chara = getch();
    }

    for (auto one = users.begin(); one != users.end(); one++)
    {
        if (userName == one->username && pass == one->password)
        {
            foundPass = true;
        }
    }
    if (foundPass)
    {
        string nPass = takePass();
        for (auto one = users.begin(); one != users.end(); one++)
        {
            if (userName == one->username)
            {
                one-> password = nPass;
            }
        }
    }
}

//--------------------------------------------
void login(vector<userProfil> users)
{
    int chances = 3;
    string pass, userName, fName;
    while (chances--)
    {
        char chara;
        bool foundUser = false, foundPass = false;
        cout << "Please enter your UserName : ";
        cin >> userName;
        cout << "Please enter your Password : ";
        chara = getch();
        while (chara != 13)
        {
            if (chara == 127 || chara == 8)
            {
                if(pass.size() != 0 ){
                    cout<< "\b \b";
                    pass.pop_back();
                }
            }
            else
            {
                putchar('*');
                pass += chara;
            }
            chara = getch();
        }

        for (auto one = users.begin(); one != users.end(); one++)
        {
            if (userName == one->username)
            {
                foundUser = true;
                fName = one-> fname;
            }
            if (pass == one->password)
            {
                foundPass = true;
            }
        }

        if (foundUser)
        {
            if (foundPass)
            {
                cout << "\nSuccessful login, welcome " << fName << endl;
                chances = 3;
                break;
            }
            else
            {
                cout << "\nLogin failed, incorrect Password" << endl;
            }
        }
        else
        {
            cout << "\nLogin failed, username not found" << endl;
        }
        if (chances > 0)
            cout << "\nPlease Try Again : ";
    }
    if (chances <= 0)
    {
        cout << "Unfortunately we have to deny you from accessing the system\n";
    }
    else
    {
        int x;
        cout << "To change password please press 1 :";
        cin >> x;
        if (x == 1)
        {
            changePassword(users,userName);
        }
    }
}

int mod(int x, int y)
{

	return (x % y + y) % y;
}

string encryption(string input)
{
    string str;
	for (int i = 0; i < input.size(); i++)
	{
        int constValue = 0, newChar = 0;
        if(isalpha(input[i]))
        {
            if (isupper(input[i]))
            {
                constValue = 65;
                newChar = (5 * (toascii(input[i]) - constValue) + 8) % 26 + constValue;
            }
            else if (islower(input[i]))
            {
                constValue = 97;
                newChar = (5 * (toascii(input[i]) - constValue) + 8) % 26 + constValue;
            }
        }
        else
        {
            newChar = toascii(input[i]) - 6;
        }

        str += char(newChar);
	}
	return str;
}

string decryption(string input)
{
    string str;
	for (int i = 0; i < input.size(); i++)
	{
        int constValue = 0, newChar = 0;
        if(isalpha(input[i]))
        {
            if (isupper(input[i]))
            {
                constValue = 65;
                newChar = mod(21 * (toascii(input[i]) - constValue - 8), 26) + constValue;
            }
            else if (islower(input[i]))
            {
                constValue = 97;
                newChar = mod(21 * (toascii(input[i]) - constValue - 8), 26) + constValue;
            }
        }
        else
        {
            newChar = toascii(input[i]) + 6;
        }

        str += char(newChar);
	}
	return str;
}
