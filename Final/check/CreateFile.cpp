#include<iostream>
#include<sys/types.h>
#include<unistd.h>
#include<string>
#include<fstream>
using namespace std;
void MakeFile()
{
int choice;
while(choice != 2)
{
cout << "Enter 1 for Create File:" << endl;
cout << "Enter 2 for Back to List:" << endl;
cin >> choice;
if (choice == 1)
{
string create = "touch ";
string fileName;
cin.ignore();
cout << "Enter the File Name:     ";
getline(cin, fileName);
ifstream file;
file.open(fileName);
if(!file.is_open())
{
create = create + fileName;
const char* createfile = create.c_str();
system(createfile);
cout << "File Created Successfully.\n" << endl;
}
else
{
cout << "File Already Exist.\n" << endl;
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
MakeFile();
return 0;
}
