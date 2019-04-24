/*Sudesh Sharma is a Linux expert who wants to have an online system where he can handle student queries.
Since there can be multiple requests at any time he wishes to dedicate a fixed amount of time 
to every request so that everyone gets a fair share of his time.
He will log into the system from 10am to 12am only. He wants to have separate requests queues for students and faculty. 
Implement a strategy for the same.The summary at the end of the session should include 
the total time he spent on handling queries and average query time. */


#include<conio.h>
#include<unistd.h>
#include<stdio.h>
int main()
{
 int a;      //a number of process
 int b;      //b number of resources
 int i,j,k,cnt,cunt;
 int avail[10],q[10];
 int need[10][10], allc[10][10], maxi[10][10];

 printf("\nWelcome\n");
 printf("\nEnter number of process :  ");
 scanf("%d",&a);
 printf("\nEnter  resources available :  ");
 scanf("%d",&b);
 printf("\nEnter insatnces for resources :  \n");
 for(i=0;i<b;i++)
 {  printf("R%d  ",i+1);
  scanf("  %d",&avail[i]);
  }
 printf("\n Enter allocation matrix   \n");
 for(i=0;i<a;i++)
 {
 printf("p%d  ",i+1);          q[i]=0;
 for(j=0;j<b;j++)
 {
  scanf("   %d",&allc[i][j]);
 }
}
  printf("\n Enter MAX matrix    \n");

 for(i=0;i<a;i++)
 {
 printf("p%d  ",i+1);
 for(j=0;j<b;j++)
 {
  scanf("   %d",&maxi[i][j]);
 }
 }

 for(i=0;i<a;i++)
 {
 printf(" \np%d\t  ",i+1) ;
 for(j=0;j<b;j++)
 {
  need[i][j]=maxi[i][j]-allc[i][j];
  printf("    \t%d  ",need[i][j]);
  }
 }
 k=0;     cunt=0;
 printf("\n\n");
 while(k<15)
 {
 for(i=0;i<a;i++)
 {  cnt=0;
 for(j=0;j<b;j++)
 {
  if(q[i]==1) break;
  if(need[i][j]<=avail[j])
  {
  cnt++;
  }
  if(cnt==b)
  {
  for(j=0;j<b;j++)
  {
  avail[j]+=allc[i][j];
  }
  printf("p%d\t  ",i+1);  q[i]=1;     cunt++;
  }
 }
 } k++;
 }
 if(cunt<a-1)
 {
 printf("\n deadlock ");
 }
      getch();
 }
