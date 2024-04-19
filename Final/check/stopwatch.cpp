#include <iostream>
#include <unistd.h>
#include <sys/ioctl.h>
#include "bits/stdc++.h"
#include <termios.h>
using namespace std;
bool kbhit()
{
    termios term;
    tcgetattr(0, &term);
    termios term2 = term;
    term2.c_lflag &= ~ICANON;
    tcsetattr(0, TCSANOW, &term2);
    int byteswaiting;
    ioctl(0, FIONREAD, &byteswaiting);
    tcsetattr(0, TCSANOW, &term);
    return byteswaiting > 0;
}

void displayTime(int hours, int minutes, int seconds) {
   // for linux
   system("clear");
        cout << "\n\t\t stopwatch";
        cout << "\n\t\t HH: MM: SS";
        cout << "\n\t\t " << hours<< " : " << minutes << " : " << seconds;
        cout << "\n\t\t press any key to stop";

}
void startWatch()
{
  int hour = 0;
  int min = 0;
  int sec = 0;
  displayTime(hour, min, sec);
  while(!kbhit()) 
  {
    sleep(1);
    sec++;
    if(sec > 59) {
      min++;
      sec = 0;
    } 
    if(min > 59) {
      hour++;
      sec = 0;
      min = 0;
    }
    displayTime(hour, min, sec);
  }
      displayTime(hour, min, sec);
}
void* mainWatch(void *watch)
 {
 	cout << "        __                              __        __    " << endl;
	cout << " .-----|  |_.-----.-----.--.--.--.---.-|  |_.----|  |--." << endl;
	cout << " |__ --|   _|  _  |  _  |  |  |  |  _  |   _|  __|     |" << endl;
	cout << " |_____|____|_____|   __|________|___._|____|____|__|__|" << endl;
	cout << "                  |__|                                  " << endl;
	sleep(3);
startWatch();
return NULL;
}
int main()
{
cout << "\e[1;32m\n";
startWatch();
}







