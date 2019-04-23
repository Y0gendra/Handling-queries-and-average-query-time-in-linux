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
 int n;      //n number of process
 int r;      // number of resources
 int i,j,k,cnt,cntt;
 int avail[10],p[10];
 int need[10][10], alloc[10][10], max[10][10];

 printf("\nEnter number of process :  ");
 scanf("%d",&n);
 printf("\nEnter  resources available :  ");
 scanf("%d",&r);
 printf("\nEnter insatnces for resources :  \n");
 for(i=0;i<r;i++)
 {  printf("R%d  ",i+1);
  scanf("  %d",&avail[i]);
  }
 printf("\n Enter allocation matrix   \n");
 for(i=0;i<n;i++)
 {
 printf("p%d  ",i+1);          p[i]=0;
 for(j=0;j<r;j++)
 {
  scanf("   %d",&alloc[i][j]);
 }
}
  printf("\n Enter MAX matrix    \n");

 for(i=0;i<n;i++)
 {
 printf("p%d  ",i+1);
 for(j=0;j<r;j++)
 {
  scanf("   %d",&max[i][j]);
 }
 }

 for(i=0;i<n;i++)
 {
 printf(" \np%d\t  ",i+1) ;
 for(j=0;j<r;j++)
 {
  need[i][j]=max[i][j]-alloc[i][j];
  printf("    \t%d  ",need[i][j]);
  }
 }
 k=0;     cntt=0;
 printf("\n\n");
 while(k<15)
 {
 for(i=0;i<n;i++)
 {  cnt=0;
 for(j=0;j<r;j++)
 {
  if(p[i]==1) break;
  if(need[i][j]<=avail[j])
  {
  cnt++;
  }
  if(cnt==r)
  {
  for(j=0;j<r;j++)
  {
  avail[j]+=alloc[i][j];
  }
  printf("p%d\t  ",i+1);  p[i]=1;     cntt++;
  }
 }
 } k++;
 }
 if(cntt<n-1)
 {
 printf("\n deadlock ");
 }
      getch();
 }

