#include<iostream>
#include<fstream>
using namespace std;
int main()
{
cout << "\e[1;32m\n";
cout<<"Enter the Name of File: ";
string text;
cin>>text;
remove(text.c_str());
return 0;
}
