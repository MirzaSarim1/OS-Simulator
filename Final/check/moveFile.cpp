#include<iostream>
#include<sys/types.h>
#include<unistd.h>
#include<string>
#include<fstream>
using namespace std;
void MoveFile()
{
int choice;
while(choice != 2 )
{
cout << "Enter 1 for Move File to Another Location:" << endl;
cout << "Enter 2 for Back to List:" << endl;
cin >> choice;
if (choice == 1)
{
string move = "mv ";
string Source, Destination;
cin.ignore();
cout << "Enter Source:     ";
getline(cin, Source);
cout << "Enter Destination:     ";
getline(cin, Destination);
ifstream file;
file.open(Source);
if(!file.is_open())
{
cout << "File Not Exist.\n" << endl;
}
else
{
move = move + Source + " " + Destination;
const char* mvfile = move.c_str();
system(mvfile);
cout << "File Move Successfully.\n" << endl;
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
MoveFile();
return 0;
}
