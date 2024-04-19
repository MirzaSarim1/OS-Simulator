#include<iostream>
using namespace std;

void fcfs(int processes[], int n, int burstTime[])
{
     int waitingTime[n];
     waitingTime[0] = 0;
 
    // calculating waiting time
    for (int  i = 1; i < n ; i++ )
        waitingTime[i] =  burstTime[i-1] + waitingTime[i-1] ;
        
    //calculating turn around time    
     int tat[n];
     
      for (int  i = 0; i < n ; i++)
        tat[i] = burstTime[i] + waitingTime[i];
        
     int totalWT = 0;
    int totalTAT = 0;
    
    //total waiting time and total turn around time
    for (int  i=0; i<n; i++)
    {
        totalWT += waitingTime[i];
        totalTAT += tat[i];
    }
    
 float avgWT = (float)totalWT / (float)n; 
 float avgTAT = (float)totalTAT / (float)n;
 
 cout << "Average Waiting Time: " << avgWT << endl;
 cout << "Average Turn Around Time: " << avgTAT << endl;
 cout << endl;
 for(int i = 0; i < n ; i++)
 {
     cout << "Process " << i + 1 << endl;
     cout << "Burst Time: " << burstTime[i] << endl;
     cout << "Waiting Time: " << waitingTime[i] << endl;
     cout << "Turn Around Time: " << tat[i] << endl;
     cout << endl;
 }
     
}
 
// Driver code
int main()
{
    cout << "\e[1;32m\n";
	cout << "\t\tTASK # 3" << endl << endl;
    //process id's
    int processes[] = { 1, 2, 3};
    int n = 3;
    //Burst time of all processes
    int  burstTime[] = {6, 3, 1};
 
    fcfs(processes, n,  burstTime);
    return 0;
}
