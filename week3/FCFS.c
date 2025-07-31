#include <stdio.h>
#include <unistd.h>
#include<stdlib.h>
typedef struct process
{
    int pid;
    int arrivalTime;
    int burstTime;
    int ct;
    int tat;
    int wt;
    int rt;
    int st;
} process;
int cmp(process p1[],process p2[])
{
    
}
int main()
{
    int n;
    printf("Enter number of process:");
    scanf("%d", &n);
    process p[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter details of %d process", i + 1);
        int arrTime, burstTime, ct;
        p[i].pid=i;
        printf("Enter arrival time:");
        scanf("%d", &p[i].arrivalTime);
        printf("Enter burst Time:");
        scanf("%d", &p[i].burstTime);
        qsort ((void *)p, n, sizeof(process), cmp); 

    }
     printf("process\tAT\tBT\tCT\tTAT\tWT\tRT\tST");
    for(int i=0;i<n;i++)
    {
       printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d",i,p[i].arrivalTime,p[i].burstTime,p[i].ct,p[i].tat,p[i].wt,p[i].rt,p[i].st);
    }
}
