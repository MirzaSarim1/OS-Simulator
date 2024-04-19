#include<iostream>
#include<string.h>
#include "bits/stdc++.h"
#include <unistd.h>
using namespace std;
int main()
{
cout << "\e[1;32m\n";
system("clear");
	int i, t = 5, j, d = 0, f = 0, p;
	char ch, ch2, letter;
	string str1, str2, str3, let;
	cout << "	" << "	" << "	" << "WELCOME TO HANGMAN!!!\n\n";
	cout << "Enter word(Player 1)";
	cin >> str1;
	for (int i = 0; i < str1.length(); ++i)
	{
		str1[i] = toupper(str1[i]);
	}
	system("clear");

	cout << "		";

	cout << "Player 2 have 5 chances to guess the word" << endl;
	do
	{
		cout << "1.Do you want to guess word\n ";
		cout << "Enter choice\n";
		cin >> ch;
		if (ch == '1')
		{
			cout << "Enter word\n";
			cin >> str2;
			for (int i = 0; i < str2.length(); ++i)
			{
				str2[i] = toupper(str2[i]);
			}
			if (str1 == str2)
			{
				cout << "The answer is correct.You won\n";
				break;
			}
			else
			{
				t--;
				cout << "The answer is not correct.Try again.\n";
				cout << "Chances left\n" << t << endl;
			}
			if (t == 0)
			{
				cout << "You have lost\n";
			}

		}
		cout << "Thanks for playing!!!";
	} while (t > 0);
}
void* mainHang(void *hang)
{
system("clear");

	cout << "  __                                           " << endl;
	cout << " |  |--.---.-.-----.-----.--------.---.-.-----." << endl;
	cout << " |     |  _  |     |  _  |        |  _  |     |" << endl;
	cout << " |__|__|___._|__|__|___  |__|__|__|___._|__|__|" << endl;
	cout << "                   |_____|                     " << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << endl;
//sleep(3);
main();
	return NULL;
}

