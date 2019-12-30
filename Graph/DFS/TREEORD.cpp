#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
lli temp[8005];
bool flag=true;
// A utility function to search x in arr[] of size n 
lli search(lli arr[], lli x, lli n) 
{ 
    for (lli i = 0; i < n; i++) 
        if (arr[i] == x) 
            return i; 
    return -1; 
} 
lli k=0;
// Prints postorder traversal from given inorder and preorder traversals 
void printPostOrder(lli in[], lli pre[], lli n) 
{ 
    // The first element in pre[] is always root, search it 
    // in in[] to find left and right subtrees 
    lli root = search(in, pre[0], n); 
  	if(root==-1)
  	{
  		flag=false;
  		return;
  	}
    // If left subtree is not empty, print left subtree 
    if (root != 0) 
        printPostOrder(in, pre + 1, root); 
  
    // If right subtree is not empty, print right subtree 
    if (root != n - 1) 
        printPostOrder(in + root + 1, pre + root + 1, n - root - 1); 
  
    // Print root 
    temp[k]=pre[0];
//    cout<<pre[0]<<" ";
    k++;

} 



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli N;
	cin>>N;
	lli pre[N],pos[N],in[N];
	for(lli i=0;i<N;i++)
	{
		cin>>pre[i];
	}
	for(lli i=0;i<N;i++)
	{
		cin>>pos[i];
	}
	for(lli i=0;i<N;i++)
	{
		cin>>in[i];
	}
	printPostOrder(in, pre, N);
//	cout<<endl;
	if(!flag)
		cout<<"no"<<endl;
	else
	{
		for(lli i=0;i<N;i++)
		{
			if(temp[i]!=pos[i])
			{
				cout<<"no"<<endl;
				return 0;
			}
		}
		cout<<"yes"<<endl;
	}
}

