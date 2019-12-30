#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli m=3;
	lli processors=m;
	lli n=8;
	lli tasks=n;
	double wd[n];        //amount of computation to be performed by the subtask T i
	double cd[n][n]=INT_MAX;     // edge weight represents the amount of communication between subtask T i and subtask T j
	for(lli i=0;i<n;i++)
	{
		cd[i][i]=0;
	}
	double s[n][m]; //The execution speeds of the processors in a heterogeneous computing system are represented by matrix S, in which an element S(Ti,pk) represents the speed at which processor Pk executes subtask Ti. 
	double Wp[n][m]; //computation cost of subtask ti, running on preocessor pk, denoted as W(t,pk);
	s[0][0]=1; s[0][1]=0.85; s[0][2]=1.22;
	s[1][0]=1.20; s[1][1]=.80; s[1][2]=1.09;
	s[2][0]=1.33; s[2][1]=1; s[2][2]=0.86;
	s[3][0]=1.18; s[3][1]=0.81; s[3][2]=1.30;
	s[4][0]=1; s[4][1]=1.37; s[4][2]=0.79;
	s[5][0]=0.75; s[5][1]= 1.00; s[5][2]=1.79;
	s[6][0]=1.30; s[6][1]=0.93; s[6][2]=1;
	s[7][0]=1.09; s[7][1]=0.80; s[7][2]=1.20;


	double wbd[n]; // average computaion cost of subtask ti;
	wbd[0]=11.00;
	wbd[1]=12.00;
	wbd[2]=11.67;
	wbd[3]=12.33;
	wbd[4]=15.00;
	wbd[5]=8.67;
	wbd[6]=12.33;
	wbd[7]=12.00;


	double B[m][m]; //The communication bandwidths between any two heterogeneous processors are represented by a two-dimensional matrix B of size m*m, where B(Pk,Pl) represents the communication cost of sending a unit of data from Pk  to Pl . 