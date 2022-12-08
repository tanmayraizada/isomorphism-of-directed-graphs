/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
#include<iostream>

using namespace std;

bool checkisomorphism(vector<int> adj1[],vector<int> adj2[],int n,int a,int m,int b){
    if(n != a)
    {
        return false;
    }
    if(m!=b)
    {
        return false;
    }
	vector<int> inorder1(n,0);
	vector<int> inorder2(a,0);

	for(int i=0;i<n;i++){
		for(auto it: adj1[i])
		{
			inorder1[it]++;
		}}
	
   for(int i=0;i<a;i++){
		for(auto it: adj2[i]){
			inorder2[it]++;
		}}
	sort(inorder1.begin(), inorder1.end());
	sort(inorder2.begin(), inorder2.end());
	for(int i=0;i<a;i++){
		if(inorder1[i]!=inorder2[i]){
			return false;
		}
	}
	return true;
} 

int main(){
    int n,m;
    cout<<"Enter number of vertices:";
    cin>>n;
    cout<<"Enter number of edges:";
    cin>>m;
    vector<int> adj1[n + 1];
    for(int i=0;i<m;i++){
        int u,v;
        cout<<"enter the connection:"<<endl;
        cin>>u>>v;
        adj1[u].push_back(v);
    }
    for(int i=0;i<=n;i++){
    
    
    for(auto it: adj1[i]){
               cout<<i<<"->"<<it<<endl; 
    }}
    int a,b;
    
    cout<<"Enter the number of vertices in 2nd graph:";
    cin>>a;
    cout<<"Enter number of edges in 2nd graph:";
    cin>>b;
    vector<int>adj2[a + 1];
    for(int i=0;i<b;i++){
        int x,y;
        cout<<"enter the connection for 2nd graph";
        cin >> x >> y;
        
        adj2[x].push_back(y);
    }
     for(int i=0;i<=a;i++){
    
    
    for(auto it: adj2[i]){
               cout<<i<<"->"<<it<<endl; 
    }}
    if(checkisomorphism(adj1,adj2,n,a,m,b)){
     cout<<"true";
    }
    else{
        cout<<"false";
    }
}


   

