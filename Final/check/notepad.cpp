#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
int main()
{
cout << "\e[1;32m\n";
ofstream f;
string text,s;
cout << "Enter the name of file?" << endl;
cin>>s;
s=s+".txt";
f.open(s);
cout << "Enter your text?" << endl;
cin.ignore();
getline(cin,text);
f << text<<" ";
f.close();
}
