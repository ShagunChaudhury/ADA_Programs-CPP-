#include<iostream.h>
#include<conio.h>
void Huffman(int A[],int freq[],int n)
{
 struct node
 {
  int data;
  node *left;
  node *right;
  node *bincode;
  node *f;
  node *symbolindex;
 };
 node *root;
//node *parent=NULL;
//node *ptr=NULL;
 for(i=0;i<n;i++)
 {
  node *P,tree[15];
  P=new node;
  P->bincode="";
  P->f=freq[i];
  P->left=NULL;
  P->right=NULL;
  P->symbolindex=i;
  tree[i]=P;
 }
