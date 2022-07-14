#include <stdio.h>
void findWaitingTime(int processes[], int n, int bt[],
								int wt[], int at[])
{
	int service_time[n];
	service_time[0] = at[0];
	wt[0] = 0;
	for (int i = 1; i < n ; i++)
	{
		service_time[i] = service_time[i-1] + bt[i-1];
		wt[i] = service_time[i] - at[i];
		if (wt[i] < 0)
			wt[i] = 0;
	}
}

void findTurnAroundTime(int processes[], int n, int bt[],
									int wt[], int tat[])
{
	for (int i = 0; i < n ; i++)
		tat[i] = bt[i] + wt[i];
}

void findavgTime(int processes[], int n, int bt[], int at[])
{
	int wt[n], tat[n];

	findWaitingTime(processes, n, bt, wt, at);
	findTurnAroundTime(processes, n, bt, wt, tat);
    printf("Processes  Burst Time  Arrival Time  Waiting Time  Turn-Around Time  Completion Time \n");

	int total_wt = 0, total_tat = 0;
	for (int i = 0 ; i < n ; i++)
	{
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		int compl_time = tat[i] + at[i];
        printf(" %d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i+1, bt[i], at[i], wt[i], tat[i], compl_time);
	}

        printf("Average waiting time = %.2f", (float)total_wt / (float)n);
        printf("\nAverage turn-around time = %.2f\n",(float)total_tat / (float)n);
}

int main()
{
	int processes[] = {1, 2, 3, 4};
	int n = sizeof processes / sizeof processes[0];
	int burst_time[] = {6, 8, 7, 3};
	int arrival_time[] = {1, 1, 2, 3};
	findavgTime(processes, n, burst_time, arrival_time);
	return 0;
}
