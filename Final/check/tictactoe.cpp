#include <iostream>
#include <cstdlib>
#include <time.h>
#include <unistd.h>
using namespace std;
char  a = '1', b = '2', c = '3', d = '4', e = '5', f = '6', g = '7', h = '8', i = '9'; //These variables have been declared globally so they are accessible everywhere
int p1Wins = 0, p2Wins = 0, draws; //To keep track of the score
//Prototypes of all the functions used in program

//Credits of the game function
void credits();
//Function for game rules
void rules();
//Function for main menu
void mainMenu();
//Function for displaying gameplay options
void playGame();
//Player vs Player game module function
void pvsp();
//Player vs Machine game module function
void pvsm();
//Function for keeping track of the score 
void score();
//Function for defining all winning conditions
int winning_condition();
//Function for defining draw conditions
void draw_condition();
//Function for toss or first turn of the game;
bool toss();
//Toggling player turn
bool player_turn(bool);
//Displaying matrix
void matrix();
//Marking characters
int mark(int, char);

//Main function 
int main() {
        cout << "\e[1;32m\n";
	srand(time(0));
	mainMenu();
	return 0;
}

void mainMenu() {
	int n; //For selection of menu;
	a = '1', b = '2', c = '3', d = '4', e = '5', f = '6', g = '7', h = '8', i = '9'; //Initialization so if user plays game again variables value are reinitialized
	cout << "\t\t\t\t\t\t\tMain Menu\n";
	cout << "1) Play Game\n2) Rules\n3) Score\n4) Credits\n(1-4)\n";
	cin >> n;
	switch (n)
	{
	case 1:
		playGame();
		break;
	case 2:
		rules();
		break;
	case 3:
		score();
		break;
	case 4:
		credits();
	default:
		cout << "Invalid Input Quitting Program!\n";
		sleep(2);
		break;
	}

}
void playGame() {
	int selection;
	cout << "Select Module you want to play!\n";
	cout << "1) Player vs Player\n2) Player vs Computer\n";
	cin >> selection;
	switch (selection)
	{
	case 1:
		//Player vs Player
		pvsp();
		break;
	case 2:
		//Player vs Computer
		pvsm();
		break;
	default:
		cout << "Invalid Input! Quitting Program!\n";
		break;
	}
}
void pvsp() {
	//Toss function to decide who will play first turn
	char m;
	int play;
	bool pt = toss();
	if (pt == 1)
		cout << "Player 1 turn!";
	else
		cout << "PLayer 2 turn!";
	
	pt = (pt == 1) ? 1 : 0;
	
		 matrix();
		 m = (pt == 1)?'X':'O'; //For marking X or O
		 cin >> play;
		 if(play > 0 && play < 10){
		 mark(play, m);
		 }
		 else {
			 while (1) {
				 cout << "Input between 1 & 9\n";
				 cin >> play;
				 if (play > 0 && play < 10) {
					 mark(play, m);
					 break;
				 }
			 }
		 }
		 matrix();
		 while (1) {			 //Infinite loop will only be break on certain conditions

			pt = player_turn(pt); //Toggling player turn
			 m = (pt == 0) ? 'O' : 'X';
			 if (m == 'O')
				 cout << "Player 2 Turn!\n";
			 else
				 cout << "Player 1 Turn!\n";
			 
			 cin >> play;
			 if (play > 0 && play < 10) { //To ensure that user does'nt enter invalid input.
				 while (mark(play, m) == -1) { //To check user doesnt rewrite on filled slots

					 cin >> play;
				 }
			 }
			 else {
				 while (1) {
					 cout << "Input between 1 & 9\n";
					 cin >> play;
					 if (play > 0 && play < 10) {
						 mark(play, m);
						 break;
					 }
				 }
			 }
			 
			 matrix();
			 if (winning_condition() == 1) //Winning Condition and loop break
				 break;		

			 if (a != '1' && b !='2' && c !='3' && d !='4' && e != '5' && f != '6' && g != '7' && h != '8' && i != '9') { //If every slot is filled call the draw function and break the loop
				 draw_condition();
				 break;
			 }
		 }
		 int any;
		 cout << "Enter any key to Go back to main menu!\n";
		 cin >> any;
		 system("clear");
		 mainMenu(); //Going back again to main menu
}
void pvsm() { //Player vs Machine function
	char m;
	int play;
	bool pt = toss();
	if (pt == 1)
		cout << "Player 1 turn!";
	else
		cout << "Player 2 turn!";
	
	pt = (pt == 1) ? 1 : 0;

	matrix();
	m = (pt == 1) ? 'X' : 'O';
	if (m == 'O') {
		play = rand() % 9 + 1; // Machine will randomly input in slot with random function
	}
	else
	{
		cin >> play; //If its user's turn he will input the slot in which he want to mark.
		
	}
	mark(play, m);
	matrix();
	while (1) {
		pt = player_turn(pt);                  //toggling player turn
		m = (pt == 0) ? 'O' : 'X';             // For mark change
		if (m == 'O')
			cout << "Player 2 Turn!\n"; 
		else
			cout << "Player 1 Turn!\n";
		if (m == 'O') {
			play = rand() % 9 + 1; //If its machine's turn input will be given through random.
		}
		else
		{
			cin >> play;     //User will give input manually
		}
		while (mark(play, m) == -1) {
			if (m == 'O') {
				play = rand() % 9 + 1;
			}
			else {
				cin >> play;
			}
			
		}
		matrix();
		if (winning_condition() == 1) //Winning condition check
			break;

		if (a != '1' && b != '2' && c != '3' && d != '4' && e != '5' && f != '6' && g != '7' && h != '8' && i != '9') {
			draw_condition(); //draw condition check
			break;
		}
	}
	int any;
	cout << "Enter any key to Go back to main menu!\n";
	cin >> any;
	system("clear");
	mainMenu();
}
void score() {
	cout << "\t\t\t\t\t\t\tScore\n\n";
	cout << "Player 1 Wins : " << p1Wins << endl; //Keeping track of the score
	cout << "Player 2 Wins : " << p2Wins << endl;
	cout << "Total Draws : " << draws << endl;
	int any;
	cout << "Enter any key to Go back to main menu!\n";
	cin >> any;
	system("clear");
	mainMenu();
}
int winning_condition()
{
	//Player 1 winning conditions
	if (a =='X' && b=='X' &&c=='X')
	{
		cout << "Player 1 wins!\n";
		p1Wins++;
		return 1;
	}
	else if (a == 'X' && d == 'X' && g == 'X')
	{
		cout << "Player 1 wins!\n";
		p1Wins++;
		return 1;
	}
	else if (a == 'X' && e== 'X' && i == 'X')
	{
		cout << "Player 1 wins!\n";
		p1Wins++;
		return 1;
	}
	else if (b == 'X' && e == 'X' && h == 'X')
	{
		cout << "Player 1 wins!\n";
		p1Wins++;
		return 1;
	}
	else if (c == 'X' && f == 'X' && i == 'X')
	{
		cout << "Player 1 wins!\n";
		p1Wins++;
		return 1;
	}
	else if (c == 'X' && e == 'X' && g == 'X')
	{
		cout << "Player 1 wins!\n";
		p1Wins++;
		return 1;
	}
	else if (d == 'X' && e == 'X' && f == 'X')
	{
		cout << "Player 1 wins!\n";
		p1Wins++;
		return 1;
	}
	else if (g == 'X' && h == 'X' && i == 'X')
	{
		cout << "Player 1 wins!\n";
		p1Wins++;
		return 1;
	}

	//Player 2 winning conditions
	else if (a == 'O' && b == 'O' && c == 'O')
	{
		cout << "Player 2 wins!\n";
		p2Wins++;
		return 1;
	}
	else if (a == 'O' && d == 'O' && g == 'O')
	{
		cout << "Player 2 wins!\n";
		p2Wins++;
		return 1;
	}
	else if (a == 'O' && e == 'O' && i == 'O')
	{
		cout << "Player 2 wins!\n";
		p2Wins++;
		return 1;
	}
	else if (b == 'O' && e == 'O' && h == 'O')
	{
		cout << "Player 2 wins!\n";
		p2Wins++;
		return 1;
	}
	else if (c == 'O' && f == 'O' && i == 'O')
	{
		cout << "Player 2 wins!\n";
		p2Wins++;
		return 1;
	}
	else if (c == 'O' && e == 'O' && g == 'O')
	{
		cout << "Player 2 wins!\n";
		p2Wins++;
		return 1;
	}
	else if (d == 'O' && e == 'O' && f == 'O')
	{
		cout << "Player 2 wins!\n";
		p2Wins++;
		return 1;
	}
	else if (g == 'O' && h == 'O' && i == 'O')
	{
		cout << "Player 2 wins!\n";
		p2Wins++;
		return 1;
	}

	return 0;
}
//Draw condition output
void draw_condition()
{
	cout << "This game is draw!\n";
	draws++;
}
//Toggling player turn
bool player_turn(bool pt)
{
	if (pt == true){
		pt = false;
	return pt;
	}
	else {
		pt = true;
		return pt;
	}
	cout << "Player " << pt << "Turn!\n";
	

}
//Matrix of the game
void matrix()
{
	system("clear");
	cout << "Player 1 : X \nPLayer 2 : O\n\n";
	cout << "     |     |     " << endl;
	cout << "  " << a << "  |  " << b << "  |  " << c << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << d << "  |  " << e << "  |  " << f << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << g << "  |  " << h << "  |  " << i << endl;

	cout << "     |     |     " << endl << endl;
}
//Toss for determining first turn
bool toss()
{
	int rNum = rand() % 2 + 1;
	if (rNum == 1) {
		return true;
	}
	else {
		return false;
	}
}
//Function for marking characters in Matrix
int mark(int play, char m)
{
	if (play == 1) {
		if (a == '1') {
			a = m;
		}
		else {
			if (m == 'O') {
				cout << "Already Filled!\n";
				return -1;
			}
			else {
				cout << "Already FIlled!\n";
				return -1;
			}
		}
	}
	else if (play == 2) {
		if (b == '2') {
			b = m;
		}
		else {
			if (m == 'O') {
				cout << "Already Filled!\n";
				return -1;
			}
			else {
				cout << "Already FIlled!\n";
				return -1;
			}
		}
		
	}

	else if (play == 3) {
		if (c == '3') {
			c = m;
		}
		else {
			if (m == 'O') {
				cout << "Already Filled!\n";
				return -1;
			}
			else {
				cout << "Already FIlled!\n";
				return -1;
			}
		}
	}
	else if (play == 4) {
	
		if (d == '4') {
			d = m;
		}
		else {
			if (m == 'O') {
				cout << "Already Filled!\n";
				return -1;
			}
			else {
				cout << "Already FIlled!\n";
				return -1;
			}
		}
	}
	else if (play == 5) {
		if (e == '5') {
			e = m;
		}
		else {
			if (m == 'O') {
				cout << "Already Filled!\n";
				return -1;
			}
			else {
				cout << "Already FIlled!\n";
				return -1;
			}
		}
	}
	else if (play == 6) {
		
		if (f == '6') {
			f = m;
		}
		else {
			if (m == 'O') {
				cout << "Already Filled!\n";
				return -1;
			}
			else {
				cout << "Already FIlled!\n";
				return -1;
			}
		}
	}
	else if (play == 7) {
		if (g == '7') {
			g = m;
		}
		else {
			if (m == 'O') {
				cout << "Already Filled!\n";
				return -1;
			}
			else {
				cout << "Already FIlled!\n";
				return -1;
			}
		}
	}
	else if (play == 8) {
		if (h == '8') {
			h = m;
		}
		else {
			if (m == 'O') {
				cout << "Already Filled!\n";
				return -1;
			}
			else {
				cout << "Already FIlled!\n";
				return -1;
			}
		}
	}
	else if (play == 9) {

		if (i == '9') {
			i = m;
		}
		else {
			if (m == 'O') {
				cout << "Already Filled!\n";
				return -1;
			}
			else {
				cout << "Already FIlled!\n";
				return -1;
			}
		}
	}
	return 0;
}
//Rules of playing game
void rules() {
	
	int any;
	matrix();
	cout << "\t\t\t\t\t\t\tRules\n\n";
	cout << "1) Enter the number(1-9) to mark at your specified position in matrix\n2) The game is played on a 3 x 3 matrix as shown above\n3) Player 1(You) is X while Player 2(Your Freind or Machine) is O\n4) The first player to get his marks three in a row will win the game whether the marks put are up down or diagonal\n5) When all 9 slots are filled and no player gets 3 marks in a row the game is tied\n6) You can not mark again on a slot where the other player has already marked\n";
	cout << "\nEnter any key to go back to main menu!\n";
	cin >> any;
	system("clear");
	mainMenu();
}
//Game Credits
void credits() {
	int any;
	cout << "\t\t\t\t\t\t\tCredits\n\n";
	cout << "This game is developed, designed and managed by Talha Noman\n";
	cout << "\nEnter any key to go back to main menu!\n";
	cin >> any;
	system("clear");
	mainMenu();
}

