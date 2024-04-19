#include<iostream>
#include<sys/types.h>
#include<unistd.h>
#include<string>
#include<fstream>
using namespace std;
void FindString()
{
int choice;
while(choice != 2)
{
cout << "Enter 1 for Find String In File:" << endl;
cout << "Enter 2 for Back to List:" << endl;
cin >> choice;
if (choice == 1)
{
string find = "grep ";
string fileName, word;
cin.ignore();
cout << "Enter the Word:          ";
getline(cin, word);
cout << "Enter the File Name:     ";
getline(cin, fileName);
ifstream file;
file.open(fileName);
if(!file.is_open())
{
cout << "File Not Exist.\n" << endl;
}
else
{
find = find + word + " " + fileName;
const char* findstr = find.c_str();
system(findstr);
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
FindString();
return 0;
}
