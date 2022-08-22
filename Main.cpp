// Header files
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//declaring funtions to be defined & called later in program 
void loginp();
void rprocess();
int main();

//main process and starter
int main()
{
	// initalizing number for login and responce
	int num;

	// Login and registation numbers
	cout << "1 : Register" << endl;
	cout << "2 : Login" << endl;

	//taking input from user
	cout << "Type input here : ";
	cin >> num;

	//linking funtions to user input
	if (num == 1)
	{
		rprocess();
	}
	else if (num == 2)
	{
		loginp();
	}
	else
	{
		cout << "You have not entered either of the numbers below. Please proceed to try again..." << endl;
	}

	return 0;
}

//Login Process
void loginp()
{
	// taking user responce
	int resp;

	//intializing variables being up and username/password;
	string username, password, un, pw;

	//getting user input, username and passowrd
	cout << "Enter Username: "; cin >> username;
	cout << "Now enter password: "; cin >> password;

	//opening the file
	ifstream  read(username + ".txt");

	//setting un & pw to be the original username and password inputted to check for the correctness
	getline(read, un);
	getline(read, pw);
	
	//checking for username and password correctness
	if (un == username && pw == password)
	{
		cout << "You have entered the correct username and password! Welcome :)" << endl;
	}
	// having user input 1 or 2 to deternime if they want to create a new username and password or exit the application
	else
	{
		cout << "You have entered the wrong username or password please retry or register for a new account :(" << endl;
		cout << "Please enter 1 to regeister for a new account or press 2 to exit out of application "; cin >> resp;
		if (resp == 1)
		{
			rprocess();
		}
		else if (resp != 1)
			cout << "Logging you out now... Press the X button at the top right of the application window." << endl;
	}
}

//register process
void rprocess()
{
	//initalizing username and password
	string username, password;
	
	//num responce
	int numr;

	//Creating account process
	cout << "Enter your prefered username: "; cin >> username;
	cout << "Enter your prefered pasword: "; cin >> password;

	//creating new file to save new username and password
	/*creating the file by appending it to make sure that if its not there it will append the dataand create a new file once checked
	also std::io_base is a class that is the bassis for all input and output streams, ::app is an append that checks for files status and makes new ones if not */
	fstream file;
	file.open(username + ".txt", std::ios_base::app);

	//writing to the file
	file << username << endl;
	file << password << endl;

	//(ALWAYS COSE THE FILE WHEN FINISHED)closing the file
	file.close();

	//Coninutation to login/ and or exit out of application
	cout << "Your account has been created. Would you like to login now? 1 = YES 2 = NO : ";
	cin >> numr;

	if (numr == 1)
	{
		loginp();
	}
	else if (numr == 2)
	{
		cout << "Thankyou have a good day! Press the X button at the top right of the applicaiton screen." << endl;
	}
}