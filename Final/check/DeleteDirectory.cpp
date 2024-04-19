#include<iostream>
#include<sys/types.h>
#include<unistd.h>
#include<string>
#include<fstream>
using namespace std;
void DeleteDirectory()
{
int choice;
while (choice != 2)
{
cout << "Enter 1 for Delete a Directory:" << endl;
cout << "Enter 2 for Back to List:" << endl;
cin >> choice;
if (choice == 1)
{
string remove = "rmdir ";
string dirName;
cin.ignore();
cout << "Enter Directory Name:     ";
getline(cin, dirName);
ifstream Directory;
Directory.open(dirName);
if(!Directory.is_open())
{
cout << "Directory Not Exist.\n" << endl;
}
else
{
remove = remove + dirName;
const char* rmDirectory = remove.c_str();
system(rmDirectory);
cout << "Directory Deleted Successfully.\n" << endl;
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
DeleteDirectory();
return 0;
}
