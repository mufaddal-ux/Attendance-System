#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
// #include<algorithm>
using namespace std;
class Login{
public:
int delay()
{
	for(int i = 0; i<3; i ++)
{
	cout<<"\n Saving Records ...";
    for(int ii = 0; ii<20000; ii ++)
    {
    	for(int iii = 0; iii<20000; iii ++)
       	{ }
    }
}
cout<<"\n Exiting Now ...";
for(int i = 0; i<3; i ++){
   for(int ii = 0; ii<20000; ii ++) {
     for(int iii = 0; iii<20000; iii ++){
	 }
    }
}
return 0;
}
int studentLogin()
{
system("cls");
cout<<"\n -------- Student Login ---------";
studentView();
delay();
return 0;
}
int checkStudentCredentials(string username, string password)
{
ifstream read;
read.open("db.txt");
if (read) {
int recordFound = 0;
string line;
string temp = username +".txt";
getchar();

while(getline(read, line)) {
	if(line == temp)
	{

		getchar();
    cout<<"Found";
		getchar();
		getchar();
		recordFound = 1;
		break;
	}
}

if(recordFound == 0)
    return 0;
else
   return 1;
}
else
{
   return 0;
}

}
int adminLogin()
{
system("cls");
cout<<"\n --------- Admin Login --------";

string username;
string password;

cout<<"\n Enter username : ";
cin>>username;
cout<<"\n Enter password : ";
cin>>password;
// transform(username.begin(), username.end(), username.begin(), ::tolower);
// transform(password.begin(), password.end(), password.begin(), ::tolower);

if(username=="mit" && password=="mit@wpu")
{
	  adminView();
    delay();
    getchar();
}
else
{
cout<<"\n Error ! Invalid Credintials..";
cout<<"\n Press ENTER key for main menu ";
getchar();
getchar();
}
return 0;
}
int studentView()
{
string username, password;

cout<<"\n Enter name : ";
cin>>username;

cout<<"\n Enter password : ";
cin>>password;

int res = checkStudentCredentials(username, password);

if(res  == 0)
{
   cout<<"\n Invalid Credentials !!";
   cout<<"\n Press Enter key for Main Menu..";
   getchar();
   return 0;
}

int goBack = 0;
while(1)
{
system("cls");
cout<<"\n 1 Count my Attendance";
cout<<"\n 0. Go Back <- \n";
int choice;
cout<<"\n Enter your choice: ";
cin>>choice;
switch(choice)
{

	case 1: countMyAttendance(username); break;
	case 0: goBack = 1;break;
    default: cout<<"\n Invalid choice. Enter again ";

}

if(goBack == 1)
{
break;
}

}
return 0;
}

int countMyAttendance(string username)
{
cout<<"\n Count my attendance for today !!";

string wif;
ifstream fin("attend.txt");
int count=0;
while(getline(fin,wif))
 {

	 if(wif==username){
		 count++;
	 }
 }
getchar();
cout<<count;
cout<<"\nPress ENTER key for continue";
getchar();
getchar();
return 0;
}
int adminView()
{
int goBack = 0;
while(1)
{
system("cls");
cout<<"\n --------- Welcome --------";
cout<<"\n 1 Register a Student";
cout<<"\n 2 Delete All students name registered";
cout<<"\n 3 Get List of student with their attendance count";
cout<<"\n 4 Mark Attendance of Student";
cout<<"\n 5 Check Presense Count by PRN";
cout<<"\n 6 Check Presence count by Name";
cout<<"\n 0 Go Back <- \n";
int choice;

cout<<"\n Enter you choice: ";
cin>>choice;

switch(choice)
{
  case 1: registerStudent();break;
  case 2: deleteAllStudents(); break;
	case 3: getListOfStudentsWithTheirPresenseCount(); break;
  case 4: markStudentAttendance();break;
	case 5: checkPresenseCountbyRollno();break;
	case 6: checkpresencecountbyName();break;
  case 0: goBack = 1;break;
    default: cout<<"\n Invalid choice. Enter again ";
		goBack=1;
    getchar();
}

if(goBack == 1)
{
break;
}

}
return 0;
}
int registerStudent()
{
    cout<<"\n ----- Form to Register Student ---- \n";

    string name, username, password, PRN, DOB,cor;
	ifstream read;
    cout<<"\n Enter Name : ";
	 cin>>name;
    cout<<"\n Enter Username : ";
		cin>>username;
    cout<<"\n Enter password : ";
		cin>>password;
    cout<<"\n Enter PRN : ";
		cin>>PRN;
		cout<<"\n Enter DOB : ";
		cin>>DOB;
		cout<<"\n Enter Course : ";
		cin>>cor;
		string s=name+".txt";
		read.open(s);
		if(read)
    {
			int recordFound =0;
	   	string line;
	    while(getline(read, line)) {
    	if(line == name)
    	{
    		recordFound=1;
    	    break;

		}
		}
			if(recordFound == 1)
        {
			getchar();
    	cout<<"\n Student already Register. Please choose another username ";
    	getchar();
    	read.close();
    	return 0;
		}
	}
    read.close();

    ofstream out;
	out.open("db.txt", ios::app);
	out<<name+".txt"<<"\n";
	out.close();
	ofstream out1;
	string temp = name+".txt";
	out1.open(temp.c_str());
	out1<<"The name is:"<<name<<"\n";
	out1<<"The username is:"<<username<<"\n";
	out1<<"The password is:"<<password<<"\n";
	out1<<"The PRN is:"<<PRN<<"\n";
	out1<<"The DOB is:"<<DOB<<"\n";
	out1<<"The Course is:"<<cor<<"\n";
	out1.close();
	getchar();
	cout<<"\n Student Registered Successfully !!";
	delay();
	cout<<"\n Please ENTER key to continue..";
	getchar();
	return 0;
}


int markStudentAttendance()
{
char se[100];
			string name;

			ifstream read;
			read.open("db.txt");

			cout<<"Write Name of Student:";
			cin>>name;
			fstream file;
			string s=name+".txt";
			file.open(s);
			if(read)
			{
				int recordFound=0;
				string line;
				while(getline(read,line)){
					if(line==name+".txt"){
						recordFound=1;
						break;
				}
			}

					if(recordFound==1){
						ofstream file;
						file.open("attend.txt",ios::app);
						strcpy(se,name.c_str());
						file<<se<<"\n";
						cout<<"Write PRN of Student:";
						cin>>se;
						cin.ignore();

						cout<<"Attendance Marked";
						getchar();
						getchar();
						file<<se<<"\n";
						file.close();
					}
					if(recordFound==0){
						getchar();
						cout<<"User not Register";
						getchar();
						getchar();
					}
				}
return 0;
}
int deleteAllStudents()
{
cout<<"\n Delete all students !!";
cout<<"\n Please ENTER key to continue..";
fstream File;
string filepath = "db.txt";
File.open(filepath.c_str(), std::ifstream::out | std::ifstream::trunc );
if (!File.is_open() || File.fail())
{
   File.close();
   printf("\nError : failed to erase file content !");
	 return 0;
}
File.close();
getchar(); getchar();
return 0;
}
int checkPresenseCountbyRollno()
{
string a,b;
int count=0;
cout<<"\n Check presense count of any Student PRN \n";
cout<<"Enter PRN:";
cin>>a;
fstream file;
file.open("attend.txt");
while(getline(file,b))
 {

	 if(b==a){
		 count++;
	 }

 }
 getchar();
cout<<count;
if(count==0){
	cout<<"\n User Not Exist";
}
getchar();
cout<<"\nPress ENTER key for continue";
return 0;
}
int getListOfStudentsWithTheirPresenseCount()
{
cout<<"\n Student with their Presense count !!";
ifstream file;
string s;
file.open("attend.txt");
while(getline(file,s))
	{

        cout<<s;
				cout<<"\n";
				getchar();
				getchar();
	}

	file.close();
return 0;
}
int checkpresencecountbyName()
{
	string a,b;
	int count=0;
cout<<"\n Check presence count of any Student Name \n";
cout<<"Enter Name:";
cin>>a;
fstream file;
file.open("attend.txt");
while(getline(file,b))
 {

	 if(b==a){
		 count++;
	 }
}
 getchar();
cout<<count;
if(count==0){
cout<<"\n User Not Exist";
}
getchar();
cout<<"\nPress ENTER key for continue";
return 0;
}
};

int main() {
Login l;
while(1)
{
	system("cls");
	cout<<"\n Attendance Management System \n";
	cout<<"-------------------------------------\n\n";

	cout<<"1. Student Login\n";
	cout<<"2. Admin Login\n";

	cout<<"0. Exit\n";
	int choice;

	cout<<"\n Enter you choice: ";
	cin>>choice;

	switch(choice)
	{
	case 1: l.studentLogin(); break;
	case 2: l.adminLogin(); break;
	case 0:
	        while(1)
	        {
		    system("cls");
        	cout<<"\n Are you sure, you want to exit? y | n \n";
        	char ex;
        	cin>>ex;
        	if(ex == 'y' || ex == 'Y')
        	   exit(0);
        	else if(ex == 'n' || ex == 'N')
             {
             	 break;
             }
             else{
             	cout<<"\n Invalid choice !!!";
             	getchar();
							getchar();
             }
					 }
            break;
  getchar();
	}
}
}
