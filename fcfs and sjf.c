#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	char pid[10];
	int arr;
	int burst;
	int rem;
	int wait;
	int turn;
	int flag;
}job;

void fcfs(job ar[],int n)
{
	int time=0;
	float avgturn=0,avgwait=0;
	int min=9999;
	int index;
	job temp;
	
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(ar[j].arr<ar[i].arr)
			{
				temp=ar[j];
				ar[j]=ar[i];
				ar[i]=temp;
			}
		
		}
	
	}
	
	for(int i=0;i<n;i++)
	{
		time+=ar[i].burst;
	}
	
	printf("\n");
	int i=0;
	for(int t=0;t<time;)
	{
		if(i<n)
		{
			ar[i].wait=t;
		
			t+=ar[i].burst;
		
			ar[i].turn=t;
		
			i++;
		}
		else
			break;
	}
	printf("\nProcess ID\tArrival Time\tBurst Time\tTurnaround\tWaiting Time\n");
	for(int i=0;i<n;i++)
	{
		printf("\n%s\t\t%d\t\t%d\t\t%d\t\t%d",ar[i].pid,ar[i].arr,ar[i].burst,ar[i].turn,ar[i].wait);
		avgturn+=ar[i].turn;
		avgwait+=ar[i].wait;
	}
	printf("\n Average \t\t\t\t\t%.2f\t\t%.2f",avgturn/n,avgwait/n);
	printf("\n");
}

void sfnp(job ar[],int n)
{
	int time=0;
	float avgturn=0,avgwait=0;
	int min;
	int index;
	
	printf("\n\n\t\tSHORTEST JOB FIRST (non pre emptive)\n");
	time=0;
	for(int i=0;i<n;i++)
	{
		time+=ar[i].burst;
	}
	
	printf("\nProcess ID\tArrival Time\tBurst Time\tTurnaround\tWaiting Time\n");
	for(int t=0;t<time;)
	{
		min=9999;
		for(int i=0;i<n;i++)
		{
			if(ar[i].burst<min && ar[i].flag==0)
			{
				min=ar[i].burst;
				index=i;
			}
		}
		ar[index].flag=1;
		ar[index].wait=t;
		t+=ar[index].burst;
		ar[index].turn=t;
		printf("\n%s\t\t%d\t\t%d\t\t%d\t\t%d",ar[index].pid,ar[index].arr,ar[index].burst,ar[index].turn,ar[index].wait);
		avgturn+=ar[index].turn;
		avgwait+=ar[index].wait;
	}
	
	printf("\n Average \t\t\t\t\t%.2f\t\t%.2f",avgturn/n,avgwait/n);
	printf("\n");
}

void sfp(job ar[],int n)
{
	int time=0;
	float avgturn=0,avgwait=0;
	int min;
	int index;
	int prev=-1;
	printf("\n\n\t\tSHORT REMAINING TIME FIRST (Pre Emptive)\n");
	time=0;
	int remain=0,endtime;
	
	for(int i=0;i<n;i++)
	{
		time+=ar[i].burst;
	}
	
	printf("\nProcess ID\tArrival Time\tBurst Time\tTurnaround\tWaiting Time\n");
	for(int t=0;remain!=n;t++)
	{
		min=9999;
		for(int i=0;i<n;i++)
		{
			if( ar[i].arr<=t && ar[i].rem<min && ar[i].rem>0)
			{
				min=ar[i].rem;
				index=i;
			}
		}
		
		ar[index].rem-=1;
		
		if(ar[index].rem==0)
		{
			remain++;
			endtime=t+1;
			ar[index].turn=endtime-ar[index].arr;
			ar[index].wait=endtime-ar[index].burst-ar[index].arr;
		}	
	}
	for(int i=0;i<n;i++)
	{
		printf("\n%s\t\t%d\t\t%d\t\t%d\t\t%d",ar[i].pid,ar[i].arr,ar[i].burst,ar[i].turn,ar[i].wait);
		avgturn+=ar[i].turn;
		avgwait+=ar[i].wait;
	}
	printf("\n Average \t\t\t\t\t%.2f\t\t%.2f",avgturn/n,avgwait/n);
	printf("\n");
}

void input(job ar[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("\nEnter PID : ");
		scanf("%s",ar[i].pid);
		printf("Enter Arrival Time : ");
		scanf("%d",&ar[i].arr);
		printf("Enter Burst Time : ");
		scanf("%d",&ar[i].burst);
		ar[i].rem=ar[i].burst;
		ar[i].flag=0;
	}
	printf("\n");
}

int main()
{
	job ar[10];
	int n;
	int time=0;
	float avgturn=0,avgwait=0;
	int min;
	int index;
	int choice=3;
	while(choice!=0)
	{
		printf("\n\n\t\tCPU SCHEDULING ALGORITHMS\n");
		printf("1.FCFS\n2.SJF\n0.EXIT\nEnter Choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:			
				printf("\t\tFCFS CPU SCHEDULER\n");
				printf("Enter Number of Processes : ");
				scanf("%d",&n);
				input(ar,n);
				fcfs(ar,n);
				break;
			case 2:
				printf("\t\tSFJ CPU SCHEDULER\n");
				printf("1. Non Preemptive SJF\n2. Pre emptive SJF\nEnter your option : ");
				scanf("%d",&choice);
				printf("Enter Number of Processes : ");
				scanf("%d",&n);
				input(ar,n);
				if(choice==1)
					sfnp(ar,n);
				else if(choice==2)
					sfp(ar,n);
				else
					printf("Invalid Choice !!!\n");
				break;
		}
	}
	return 0;
}
