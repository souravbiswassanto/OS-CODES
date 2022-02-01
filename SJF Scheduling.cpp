 /*
	Shortest Job First Process Scheduling
	Non-Preemptive
*/
#include "stdio.h"
#include "stdlib.h"
struct process
{
	int pid;
	int AT;
	int BT;
	int WT;
	int TAT;
	int CT;
};
int main()
{
	int n,i,j;
	int bt=0,k=1,tat=0,sum=0,min;
	printf("Enter number of processes: ");
	scanf("%d",&n);
	struct process proc[n],temp;
	for(i=0;i<n;i++)
	{
		printf("\n");
		printf("Enter arrival time for process%d: ",i+1);
		scanf("%d",&proc[i].AT);
		printf("Enter burst time for process%d: ",i+1);
		scanf("%d",&proc[i].BT);
		proc[i].pid = i+1;
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
		    if(proc[i].AT == proc[j].AT && proc[i].BT < proc[j].BT){
                temp = proc[j];
				proc[j] = proc[i];
				proc[i] = temp;
		    }
			if(proc[i].AT < proc[j].AT)
			{
				temp = proc[j];
				proc[j] = proc[i];
				proc[i] = temp;
			}
		}
	}
    bt = proc[0].AT + proc[0].BT;
	for(i=0;i<n;i++)
	{
		bt+=proc[i].BT;
		min = proc[k].BT;
		for(j=k;j<n;j++)
		{
			if(bt>=proc[j].AT && proc[j].BT<min)
			{
				temp=proc[k];
				proc[k]=proc[j];
				proc[j]=temp;
			}
		}
		k++;
	}
	proc[0].WT = 0;
	proc[0].CT = proc[0].BT + proc[0].AT;
	int wait_time_total = 0;
	proc[0].TAT = proc[0].CT - proc[0].AT;
	int TAT_total=0;
	for(i=1;i<n;i++)
	{
		proc[i].CT = proc[i - 1].CT + proc[i].BT;
		proc[i].TAT = proc[i].CT - proc[i].AT;
		proc[i].WT = proc[i].TAT - proc[i].BT;

		if(proc[i].WT < 0)proc[i].WT = 0;
	}
	for(i=0;i<n;i++)
	{
		wait_time_total += proc[i].WT;
		TAT_total += proc[i].TAT;
	}
	printf("Process\tBurst Time\tArrival Time\tWaiting Time\tTurn-Around Time\n");

	for(i=0;i<n;i++)
	{

		printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",proc[i].pid,proc[i].BT, proc[i].AT, proc[i].WT,proc[i].TAT);
	}
	printf("Average waiting time: %f\n", (float)wait_time_total/n);
	printf("Average turn around time: %f\n",(float)TAT_total/n);

}
