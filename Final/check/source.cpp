#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>
#include <string.h>
#include <fstream>
#include <chrono>
#include <thread>

using namespace std;
int harddisk, ram, cores;
pthread_mutex_t lock[15];
int memory[100];
string tasks[100];
int ind = -1;
int counter = 0;
bool checkIfKernel = false;

void *taskManager(void *arg) // taskmanager
{
    cout << endl << "		Active Tasks			MB " << endl;
    for (int i = 0; i < counter; i++)
    {
        if (memory[i] == 0)
        {
            continue;
        }
        else
        {
            cout << "		Task" << i + 1 << " : " << tasks[i] << "		" << memory[i] << endl;
        }
    }
    pthread_exit(NULL);
}

void freeMemory(int &sum , int &size , string &var)
{
    for (int i = 0; i < counter; i++)
    {
        memory[i] = 0;
        tasks[i] = " ";
    }
    ind = -1;
    counter = 0;
    sum = 0;
    size = 0;
    var;
}

// functions
// 1
void *calender(void *arg)
{
    pthread_mutex_lock(&lock[1]);
    system("g++ calendar.cpp -o calendar ");
    system("gnome-terminal -- \"./calendar\"");
    pthread_mutex_unlock(&lock[1]);
    pthread_exit(NULL);
}
// 2
void *calculator(void *arg)
{
    pthread_mutex_lock(&lock[2]);
    system("g++ calculator.cpp -o calculator ");
    system("gnome-terminal -- \"./calculator\"");
    pthread_mutex_unlock(&lock[2]);
    pthread_exit(NULL);
}
// 3

void *tictactoe(void *arg)
{
    pthread_mutex_lock(&lock[3]);
    system("g++ tictactoe.cpp -o tictactoe ");
    system("gnome-terminal -- \"./tictactoe\"");
    pthread_mutex_unlock(&lock[3]);
    pthread_exit(NULL);
}
// 4

void *createfile(void *arg)
{
    pthread_mutex_lock(&lock[4]);
    system("g++ CreateFile.cpp -o CreateFile ");
    system("gnome-terminal -- \"./CreateFile\"");
    pthread_mutex_unlock(&lock[4]);
    pthread_exit(NULL);
}
// 5

void *movefile(void *arg)
{
    pthread_mutex_lock(&lock[5]);
    system("g++ moveFile.cpp -o moveFile ");
    system("gnome-terminal -- \"./moveFile\"");
    pthread_mutex_unlock(&lock[5]);
    pthread_exit(NULL);
}
// 6
void *deletefile(void *arg)
{
    pthread_mutex_lock(&lock[6]);
    system("g++ delete.cpp -o delete ");
    system("gnome-terminal -- \"./delete\"");
    pthread_mutex_unlock(&lock[6]);
    pthread_exit(NULL);
}
// 7
void *notepad(void *arg)
{
    pthread_mutex_lock(&lock[7]);
    system("g++ notepad.cpp -o notepad ");
    system("gnome-terminal -- \"./notepad\"");
    pthread_mutex_unlock(&lock[7]);
    pthread_exit(NULL);
}
// 8
void *createdirectory(void *arg)
{
    pthread_mutex_lock(&lock[8]);
    system("g++ CreateDirectory.cpp -o CreateDirectory ");
    system("gnome-terminal -- \"./CreateDirectory\"");
    pthread_mutex_unlock(&lock[8]);
    pthread_exit(NULL);
}
// 9
void *stopwatch(void *arg)
{
    pthread_mutex_lock(&lock[9]);
    system("g++ stopwatch.cpp -o stopwatch ");
    system("gnome-terminal -- \"./stopwatch\"");
    pthread_mutex_unlock(&lock[9]);
    pthread_exit(NULL);
}
// 10
void *hangman(void *arg)
{
    pthread_mutex_lock(&lock[10]);
    system("g++ hangman.cpp -o hangman ");
    system("gnome-terminal -- \"./hangman\"");
    pthread_mutex_unlock(&lock[10]);
    pthread_exit(NULL);
}
// 11
void *deletedirectory(void *arg)
{
    pthread_mutex_lock(&lock[11]);
    system("g++ DeleteDirectory.cpp -o DeleteDirectory ");
    system("gnome-terminal -- \"./DeleteDirectory\"");
    pthread_mutex_unlock(&lock[11]);
    pthread_exit(NULL);
}
// 12
void *displayfile(void *arg)
{
    system("g++ DisplayFile.cpp -o DisplayFile ");
    system("gnome-terminal -- \"./DisplayFile\"");
    pthread_mutex_unlock(&lock[12]);
    pthread_exit(NULL);
}
// 13
void *findstring(void *arg)
{
    pthread_mutex_lock(&lock[13]);
    system("g++ FindString.cpp -o FindString ");
    system("gnome-terminal -- \"./FindString\"");
    pthread_mutex_unlock(&lock[13]);
    pthread_exit(NULL);
}
// 14
void *time(void *arg)
{
    pthread_mutex_lock(&lock[14]);
    system("g++ Time.cpp -o Time ");
    system("gnome-terminal -- \"./Time\"");
    pthread_mutex_unlock(&lock[14]);
    pthread_exit(NULL);
}
// End
void startup()
{
    system("clear");
    cout << R"(
 
					_____  _    _  ____  ______ _   _ _______   __
					|  __ \| |  | |/ __ \|  ____| \ | |_   _\ \ / /
					| |__) | |__| | |  | | |__  |  \| | | |  \ V / 
					|  ___/|  __  | |  | |  __| | . ` | | |   > <  
					| |    | |  | | |__| | |____| |\  |_| |_ / . \ 
					|_|    |_|  |_|\____/|______|_| \_|_____/_/ \_\
                                                                                        
  				Operating System by (F21-9148 , F21-9149 , F21-9164 , F21-9073)
  )" << endl;
    cout << endl;
    // Set the loading bar width
    const int barWidth = 20;

    cout << "Loading...\n";

    // Loop through the loading sequence
    for (int i = 0; i <= barWidth; i++)
    {
        cout << "[";
        // Print the progress bar
        for (int j = 0; j < barWidth; j++)
        {
            if (j < i)
            {
                cout << "#";
            }
            else
            {
                cout << ".";
            }
        }
        cout << "] " << int(i / (float)barWidth * 100.0) << " %\r";
        cout.flush();

        // Delay for a short amount of time to simulate the loading
        this_thread::sleep_for(chrono::milliseconds(100));
    }

    cout << endl
         << "Loading complete!\n";
    sleep(5);
    system("clear");
}
void userMode()
{
    ram = 2 * 1024;
    harddisk = 250 * 1024;
    checkIfKernel = false;
}
void kernelMode()
{
    cout << "Enter the amount of Ram(GB) : ";
    cin >> ram;
    cout << "Enter the amount of Hardisk(GB) : ";
    cin >> harddisk;
    cout << "Enter the amount of cores : ";
    cin >> cores;
    ram = ram * 1024;
    harddisk = harddisk * 1024;
    checkIfKernel = true;
}
void resources()
{
    cout << endl;
    cout << "		Ram Available: " << ram << " MB" << endl;
    cout << "		Hardisk Available: " << harddisk << " MB" << endl;
    cout << endl;
}
void menu()
{
    int mode = 0;
    cout << "Select the booting mode " << endl;
    cout << "1. User Mode " << endl;
    cout << "2. Kernel Mode " << endl
         << endl;
    cout << "Choice : ";
    cin >> mode;
    while (mode != 1 && mode != 2)
    {
        cout << "Enter correct mode : ";
        cin >> mode;
    }
    if (mode == 1)
        userMode();
    else if (mode == 2)
        kernelMode();
    else
        cout << "Invalid Input " << endl;
}

void Main_Menu()
{
    bool check = false;
    pthread_t thread[15];
    for (int i = 0; i < 15; ++i)
    {
        pthread_mutex_init(&lock[i], NULL);
    }
    int sum = 0;
    int size = 0;
    string var;
    int choice;
    while (true)
    {
        system("clear");
        cout << endl;
        cout << "0.  Task Manager" << endl;
        cout << "1.  Calendar" << endl;
        cout << "2.  Calculator" << endl;
        cout << "3.  Tic Tac Toe" << endl;
        cout << "4.  Make a new File" << endl;
        cout << "5.  Move a File " << endl;
        cout << "6.  Delete a File " << endl;
        cout << "7.  Notepad " << endl;
        cout << "8.  Create Directory " << endl;
        cout << "9.  Stopwatch " << endl;
        cout << "10. Hangman" << endl;
        cout << "11. Delete Directory" << endl;
        cout << "12. Open A file" << endl;
        cout << "13. Find String in File" << endl;
        cout << "14. System Time " << endl;
        cout << "15. Shut Down" << endl
             << endl;
        cout << "Choice : ";
        cin >> choice;
        if (choice == 0)
        {
            pthread_create(&thread[choice], NULL, &taskManager, NULL);
            pthread_join(thread[choice], NULL);
        }
        else if (choice == 1)
        {
            for (int i = 0; i < counter; i++)
            {
                sum = sum + memory[i];
            }
            if (sum > ram)
            {
                cout << endl << "  ... Can't Allocate Memory ..." << endl;
                check = true;
            }
            if (check != true)
            {
                var = "Calendar";
                size = 150;
                ind++;
                tasks[ind] = var;
                memory[ind] = size;
                counter++;

                int f = fork();
                if (f > 0)
                {
                    wait(NULL);
                }
                else
                {
                    pthread_create(&thread[choice], NULL, &calender, NULL);
                    pthread_join(thread[choice], NULL);
                    exit(0);
                }
            }
        }

        else if (choice == 2)
        {
            for (int i = 0; i < counter; i++)
            {
                sum = sum + memory[i];
            }
            if (sum > ram)
            {
                cout << "  ... Can't Allocate Memory ..." << endl;
                check = true;
            }
            if (check != true)
            {
                var = "Calculator";
                size = 80;
                ind++;
                tasks[ind] = var;
                memory[ind] = size;
                counter++;

                int f = fork();
                if (f > 0)
                {
                    wait(NULL);
                }
                else
                {
                    pthread_create(&thread[choice], NULL, &calculator, NULL);
                    pthread_join(thread[choice], NULL);
                    exit(0);
                }
            }
        }

        else if (choice == 3)
        {
            for (int i = 0; i < counter; i++)
            {
                sum = sum + memory[i];
            }
            if (sum > ram)
            {
                cout << "  ... Can't Allocate Memory ..." << endl;
                check = true;
            }
            if (check != true)
            {
                var = "TicTacToe";
                size = 150;
                ind++;
                tasks[ind] = var;
                memory[ind] = size;
                counter++;

                int f = fork();
                if (f > 0)
                {
                    wait(NULL);
                }
                else
                {
                    pthread_create(&thread[choice], NULL, &tictactoe, NULL);
                    pthread_join(thread[choice], NULL);
                    exit(0);
                }
            }
        }

        else if (choice == 4)
        {
            for (int i = 0; i < counter; i++)
            {
                sum = sum + memory[i];
            }
            if (sum > ram)
            {
                cout << "  ... Can't Allocate Memory ..." << endl;
                check = true;
            }
            if (check != true)
            {
                var = "MakeFile";
                size = 10;
                ind++;
                tasks[ind] = var;
                memory[ind] = size;
                counter++;

                int f = fork();
                if (f > 0)
                {
                    wait(NULL);
                }
                else
                {
                    pthread_create(&thread[choice], NULL, &createfile, NULL);
                    pthread_join(thread[choice], NULL);
                    exit(0);
                }
            }
        }

        else if (choice == 5)
        {
            for (int i = 0; i < counter; i++)
            {
                sum = sum + memory[i];
            }
            if (sum > ram)
            {
                cout << "  ... Can't Allocate Memory ..." << endl;
                check = true;
            }
            if (check != true)
            {
                var = "MoveFile";
                size = 20;
                ind++;
                tasks[ind] = var;
                memory[ind] = size;
                counter++;

                int f = fork();
                if (f > 0)
                {
                    wait(NULL);
                }
                else
                {
                    pthread_create(&thread[choice], NULL, &movefile, NULL);
                    pthread_join(thread[choice], NULL);
                    exit(0);
                }
            }
        }

        else if (choice == 6)
        {
            for (int i = 0; i < counter; i++)
            {
                sum = sum + memory[i];
            }
            if (sum > ram)
            {
                cout << "  ... Can't Allocate Memory ..." << endl;
                check = true;
            }
            if (check != true)
            {
                var = "DeleteFile";
                size = 100;
                ind++;
                tasks[ind] = var;
                memory[ind] = size;
                counter++;

                int f = fork();
                if (f > 0)
                {
                    wait(NULL);
                }
                else
                {
                    pthread_create(&thread[choice], NULL, &deletefile, NULL);
                    pthread_join(thread[choice], NULL);
                    exit(0);
                }
            }
        }

        else if (choice == 7)
        {
            for (int i = 0; i < counter; i++)
            {
                sum = sum + memory[i];
            }
            if (sum > ram)
            {
                cout << "  ... Can't Allocate Memory ..." << endl;
                check = true;
            }
            if (check != true)
            {
                var = "Notepad";
                size = 100;
                ind++;
                tasks[ind] = var;
                memory[ind] = size;
                counter++;

                int f = fork();
                if (f > 0)
                {
                    wait(NULL);
                }
                else
                {
                    pthread_create(&thread[choice], NULL, &notepad, NULL);
                    pthread_join(thread[choice], NULL);
                    exit(0);
                }
            }
        }

        else if (choice == 8)
        {
            for (int i = 0; i < counter; i++)
            {
                sum = sum + memory[i];
            }
            if (sum > ram)
            {
                cout << "  ... Can't Allocate Memory ..." << endl;
                check = true;
            }
            if (check != true)
            {
                var = "CreateDirectory";
                size = 50;
                ind++;
                tasks[ind] = var;
                memory[ind] = size;
                counter++;

                int f = fork();
                if (f > 0)
                {
                    wait(NULL);
                }
                else
                {
                    pthread_create(&thread[choice], NULL, &createdirectory, NULL);
                    pthread_join(thread[choice], NULL);
                    exit(0);
                }
            }
        }

        else if (choice == 9)
        {
            for (int i = 0; i < counter; i++)
            {
                sum = sum + memory[i];
            }
            if (sum > ram)
            {
                cout << "  ... Can't Allocate Memory ..." << endl;
                check = true;
            }
            if (check != true)
            {
                var = "Stopwatch";
                size = 50;
                ind++;
                tasks[ind] = var;
                memory[ind] = size;
                counter++;

                int f = fork();
                if (f > 0)
                {
                    wait(NULL);
                }
                else
                {
                    pthread_create(&thread[choice], NULL, &stopwatch, NULL);
                    pthread_join(thread[choice], NULL);
                    exit(0);
                }
            }
        }

        else if (choice == 10)
        {
            for (int i = 0; i < counter; i++)
            {
                sum = sum + memory[i];
            }
            if (sum > ram)
            {
                cout << "  ... Can't Allocate Memory ..." << endl;
                check = true;
            }
            if (check != true)
            {
                var = "hangman";
                size = 150;
                ind++;
                tasks[ind] = var;
                memory[ind] = size;
                counter++;

                int f = fork();
                if (f > 0)
                {
                    wait(NULL);
                }
                else
                {
                    pthread_create(&thread[choice], NULL, &hangman, NULL);
                    pthread_join(thread[choice], NULL);
                    exit(0);
                }
            }
        }

        else if (choice == 11)
        {
            for (int i = 0; i < counter; i++)
            {
                sum = sum + memory[i];
            }
            if (sum > ram)
            {
                cout << "  ... Can't Allocate Memory ..." << endl;
                check = true;
            }
            if (check != true)
            {
                var = "DeleteDirectory";
                size = 150;
                ind++;
                tasks[ind] = var;
                memory[ind] = size;
                counter++;

                int f = fork();
                if (f > 0)
                {
                    wait(NULL);
                }
                else
                {
                    pthread_create(&thread[choice], NULL, &deletedirectory, NULL);
                    pthread_join(thread[choice], NULL);
                    exit(0);
                }
            }
        }

        else if (choice == 12)
        {
            for (int i = 0; i < counter; i++)
            {
                sum = sum + memory[i];
            }
            if (sum > ram)
            {
                cout << "  ... Can't Allocate Memory ..." << endl;
                check = true;
            }
            if (check != true)
            {
                var = "Display a File";
                size = 150;
                ind++;
                tasks[ind] = var;
                memory[ind] = size;
                counter++;

                int f = fork();
                if (f > 0)
                {
                    wait(NULL);
                }
                else
                {
                    pthread_create(&thread[choice], NULL, &displayfile, NULL);
                    pthread_join(thread[choice], NULL);
                    exit(0);
                }
            }
        }

        else if (choice == 13)
        {
            for (int i = 0; i < counter; i++)
            {
                sum = sum + memory[i];
            }
            if (sum > ram)
            {
                cout << "  ... Can't Allocate Memory ..." << endl;
                check = true;
            }
            if (check != true)
            {
                var = "FindString";
                size = 100;
                ind++;
                tasks[ind] = var;
                memory[ind] = size;
                counter++;

                int f = fork();
                if (f > 0)
                {
                    wait(NULL);
                }
                else
                {
                    pthread_create(&thread[choice], NULL, &findstring, NULL);
                    pthread_join(thread[choice], NULL);
                    exit(0);
                }
            }
        }

        else if (choice == 14)
        {
            for (int i = 0; i < counter; i++)
            {
                sum = sum + memory[i];
            }
            if (sum > ram)
            {
                cout << "  ... Can't Allocate Memory ..." << endl;
                check = true;
            }
            if (check != true)
            {
                var = "Time";
                size = 100;
                ind++;
                tasks[ind] = var;
                memory[ind] = size;
                counter++;

                int f = fork();
                if (f > 0)
                {
                    wait(NULL);
                }
                else
                {
                    pthread_create(&thread[choice], NULL, &time, NULL);
                    pthread_join(thread[choice], NULL);
                    exit(0);
                }
            }
        }

        else if (choice == 15)
        {
            cout << "\e[1;32m\n";
            system("clear");
            cout << "\n\n\n\t    --- Shutting Down --- " << endl;
            sleep(3);
            system("xdotool getactivewindow windowkill");
            break;
        }
        else
        {
            cout << "Invalid Input" << endl;
            sleep(2);
            continue;
        }
	
	// checking if the memory is full (start)
	int Memory = 0;
	if ( checkIfKernel == true )
	{
		if ( check == true )
		{
		    Memory = 0;
		    cout << endl << "1. Free memory" << endl;
		    cout << "2. ShutDown";
		    cout << endl << "Choice : ";
		    cin >> Memory;
		    cout << endl;
		    if ( Memory == 1 )
		    {
		    	system("clear");
		    	cout << "		Freeing up memory from the task manager ...." << endl << endl ;
		    	sleep(3);
		    	freeMemory(sum,size,var);
		    	cout << "Memory freed successfully " << endl ;
		    	cout << "Press 1 to continue to main page" << endl ;
		    	cin >> Memory;
		    	if (Memory == 1)
		    	{
		    	    check = false;
		    	    continue;
		    	}
		    	else
		    	{
		    	    check = false;
		    	    continue;
		    	}
		    	 
		    }
		    else
		    {
		    	check = false;
		        cout << "\e[1;32m\n";
            		system("clear");
            		cout << "\n\n\n\t    --- Shutting Down --- " << endl;
            		sleep(3);
            		system("xdotool getactivewindow windowkill");
            		break;
		    }
		    
		    
		}
	}
	else
	{
	    if ( check == true )
	    {
	        cout << "Not enough rights to free up memory " << endl ;
	        sleep(3);
	        int key = 0 ;
	    	cout << "\e[1;32m\n";
            	cout << "Press any key to shutdown " << endl << endl ;
            	cin >> key;
            	system("clear");
            	cout << "\n\n\n\t   	 --- Shutting Down --- " << endl;
            	sleep(3);
            	system("xdotool getactivewindow windowkill");
            	break;
	    }
            
	}
	// (end)
        cout << endl
             << endl;
        cout << "		0 to Close  || 1 to Minimize || 2 to multitask" << endl;
        int choice1;
        cout << "Choice : ";
        cin >> choice1;
        if (choice1 == 0)
        {
            int check = -1;
            cout << "        -- You have Closed -- " << endl
                 << endl;
            if (choice == 0)
            {
                continue;
            }
            else
            {
                for (int i = 0; i < counter; i++)
                {
                    if (tasks[i] == var)
                    {
                        check = i;
                    }
                }
                memory[check] = 0;
                tasks[check] = " ";
                system("pause");
            }
        }
        else if (choice1 == 1)
        {
            cout << "        -- You have Minimized -- " << endl
                 << endl;
            system("pause");
        }
        else if (choice1 == 2)
        {
            continue;
        }
        else
        {
            cout << "Invalid Input" << endl;
        }
    }
}

int main()
{

    startup();
    cout << "\e[1;32m\n";
    menu();
    resources();
    Main_Menu();
    return 0;
}
