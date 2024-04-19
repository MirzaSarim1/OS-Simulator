#include<iostream>
#include<sys/types.h>
#include<unistd.h>
#include<string>
#include<fstream>
using namespace std;
void MakeDirectory()
{
int choice;
while(choice != 2)
{
cout << "Enter 1 for Create Directory:" << endl;
cout << "Enter 2 for Back to List:" << endl;
cin >> choice;
if (choice == 1)
{
string create = "mkdir ";
string dirName;
cin.ignore();
cout << "Enter Directory Name:     ";
getline(cin, dirName);
ifstream Directory;
Directory.open(dirName);
if(!Directory.is_open())
{
create = create + dirName;
const char* createdir = create.c_str();
system(createdir);
cout << "Directory Created Successfully.\n" << endl;
}
else
{
cout << "Directory Already Exist.\n" << endl;
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
MakeDirectory();
return 0;
}
