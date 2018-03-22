#include<iostream.h>
#include<conio.h>
int n;
int Frac_knapsack(int V[],int W[],double c)
{
 int temp,i,j;
 double R[15];
 for(i=0;i<n;i++)
 {
  R[i]=(double)V[i]/W[i];
 }
 for(i=0;i<n-1;i++)  //selection sort
 {
  for(j=i+1;j<n;j++)
  {
   if(R[i]<R[j])
   {
    temp=R[i];
    R[i]=R[j];
    R[j]=temp;
    temp=W[i];
    W[i]=W[j];
    W[j]=temp;
    temp=V[i];
    V[i]=V[j];
    V[j]=temp;
   }
  }
 }
 i=0;
 double x;
 double v=0;
 while(c>0)
 {
  if(c>=W[i])
  {
   c=c-W[i];
   v=v+V[i];
  }
  else
  {
   x=W[i]/c;
   c=0;
   v=v+V[i]/x;
  }
  i++;
 }
 return v;
}

void main()
{
 clrscr();
 int i,V[15],W[15];
 double c;
 cout<<"Enter the number of items\n";
 cin>>n;
 cout<<"Enter the value and weight of the items\n";
 for(i=0;i<n;i++)
 {
  cin>>V[i]>>W[i];
 }
 cout<<"Enter the capacity of the knapsack: ";
 cin>>c;
 cout<<"The total value of the items according to the capacity in the kapsack is: ";
 cout<<Frac_knapsack(V,W,c);
 getch();
}