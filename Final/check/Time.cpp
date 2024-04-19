#include<iostream>
using namespace std;
int main()
{
cout << "\e[1;32m\n";
int temp;
const char* message = "echo Your Current Time is: ";
system(message);
const char* Time = "date";
system(Time);
cout << "Press Any Key to Continue." << endl;
cin >> temp;
return 0;
}
