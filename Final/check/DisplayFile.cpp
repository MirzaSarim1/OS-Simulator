#include<iostream>
#include<sys/types.h>
#include<unistd.h>
#include<string>
#include<fstream>
using namespace std;
void DisplayFile()
{
int choice;
while(choice != 2)
{
cout << "Enter 1 for Display File:" << endl;
cout << "Enter 2 for Back to List:" << endl;
cin >> choice;
if (choice == 1)
{
string display = "cat ";
string FileName;
cin.ignore();
cout << "Enter File Name:     ";
getline(cin, FileName);
ifstream file;
file.open(FileName);
if(!file.is_open())
{
cout << "File Not Exist.\n" << endl;
}
else
{
cout << "File Data:" << endl;
display = display + FileName;
const char* displayfile = display.c_str();
system(displayfile);
cout << endl;
}
}
else if (choice == 2)
{
break;
}
else
{
cout << "Invalid Input. Enter Agian.\n" << endl;
}
}
}
int main()
{
 cout << "\e[1;32m\n";
DisplayFile();
return 0;
}
