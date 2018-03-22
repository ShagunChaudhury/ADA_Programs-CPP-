#include<iostream>
#include<algorithm>
using namespace std;
struct kruskal
{
	int i;
	int j;
	int weight;
};
int P[20],rank[20],n,m;
void MakeSet(int x)
{
	P[x]=x;
	rank[x]=0;
}
int FindSet(int x)
{
	if(x!=P[x])
	{
		P[x]=FindSet(P[x]);
	}
	return P[x];
}
void setunion(int x,int y)
{
	int rep1=FindSet(x);
	int rep2=FindSet(y);
	if(rank[rep1]>rank[rep2])
	{
		P[rep2]=rep1;
	}
	else if(rank[rep1]<rank[rep2])
	{
		P[rep1]=rep2;
	}
	else
	{
		P[rep2]=rep1;
		rank[rep1]=rank[rep1]+1;
	}
}
bool comp(kruskal a,kruskal b)
{
	return(a.weight<b.weight);
}
int MST_Kruskal(kruskal a[])
{
	int A=0;
	sort(a,a+m,comp);
	for(int e=0;e<m;e++)
	{
		int u=a[e].i;
		int v=a[e].j;
		if(FindSet(u)!=FindSet(v))
		{
			A=A+a[e].weight;
			setunion(u,v);
		 } 
	}
	return A;
}
int main()
{
	cout<<"Enter the number of vertices and edges you want to enter\n";
	cin>>n>>m;
	kruskal a[m];
	for(int v=0;v<n;v++)
	{
		MakeSet(v);
	}
	cout<<"Enter the edges and their corresponding weight\n";
	for(int k=0;k<m;k++)
	{
	    cin>>a[k].i>>a[k].i>>a[k].weight;
	}
    cout<<"Min spanning weight is: "<<MST_Kruskal(a);
}
