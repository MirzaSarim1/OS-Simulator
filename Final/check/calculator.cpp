#include <iostream>
#include <unistd.h>
using namespace std;

//calculator
void calculator()
{
int option;
float n=0.5;
int a,b;
while(true)
{
cout<<"1. Addition"<<endl;
cout<<"2. Subtraction"<<endl;
cout<<"3. Multiplication"<<endl;
cout<<"4. Division"<<endl;
cout<<"5. Quit"<<endl;
cin>>option;
if(option==1)
{
int sum=0;
cout<<"Enter first number"<<endl;
cin>>a;
cout<<"Enter second number"<<endl;
cin>>b;
sum=a+b;
cout<<"Sum of a and b is "<<sum<<endl;
}
else if(option==2)
{
int sub=0;
cout<<"Enter first number"<<endl;
cin>>a;
cout<<"Enter second number"<<endl;
cin>>b;
sub=a-b;
cout<<"difference of a and b is "<<sub<<endl;
}
else if(option==3)
{
int pro=0;
cout<<"Enter first number"<<endl;
cin>>a;
cout<<"Enter second number"<<endl;
cin>>b;
pro=a*b;
cout<<"Product of a and b is "<<pro<<endl;
}
else if(option==4)
{
int div=0;
cout<<"Enter first number"<<endl;
cin>>a;
cout<<"Enter second number"<<endl;
cin>>b;
div=a/b;
cout<<"Product of a and b is "<<div<<endl;
}

else if(option== 5)
{
break;
}
else
{
cout<<"Wrong option"<<endl;
}
}
}

int main()
{
cout << "\e[1;32m\n";
calculator();
};
