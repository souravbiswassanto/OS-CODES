#include "stdio.h"
#include "stdlib.h"
struct process
{
	int pid, AT, BT, WT, TAT, CT;
};
int main()
{
	int n,i;
	printf("Enter number of processes: ");
	scanf("%d",&n);
	struct process proc[n];
	for(i=0;i<n;i++)
	{
		printf("\n");
		printf("Enter arrival time for process%d: ",i+1);
		scanf("%d",&proc[i].AT);
		printf("Enter burst time for process%d: ",i+1);
		scanf("%d",&proc[i].BT);
		proc[i].pid = i+1;
	}
	
	proc[0].CT = proc[0].BT + proc[0].AT;
	proc[0].WT = 0;	
	proc[0].TAT = proc[0].CT - proc[0].AT;

	for(i=1;i<n;i++)
	{
		proc[i].CT = proc[i - 1].CT + proc[i].BT;
		proc[i].TAT = proc[i].CT - proc[i].AT;
		proc[i].WT = proc[i].TAT - proc[i].BT;
        
		if(proc[i].WT < 0)proc[i].WT = 0;
	}

	printf("\n\n");
	printf("Process\tBurst Time\tArrival Time\tWaiting Time\tTurn-Around Time\tCompletion Time\n");
	int total_WT=0,total_TAT=0;
	for(i=0;i<n;i++)
	{
		total_WT += proc[i].WT;
		total_TAT += proc[i].TAT;

		printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",proc[i].pid,proc[i].BT, proc[i].AT, proc[i].WT,proc[i].TAT,proc[i].CT);
	}
	printf("Average waiting time: %f\n", (float)total_WT/n);
	printf("Average turn around time: %f\n",(float)total_TAT/n);
}