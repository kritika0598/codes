#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli T;
	cin>>T;
	double WX,WY,WZ,XY,XZ,YZ;
	while(T--)
	{
		cin>>WX>>WY>>WZ>>XY>>XZ>>YZ;
		if(WX==0 || WY==0 || WZ==0 || XY==0|| XZ==0 || YZ==0)
			cout<<"0.0000"<<endl;
		else
		{
			double s1=0.5*(WX+WY+XY);
			double a1=s1*(s1-WX)*(s1-WY)*(s1-XY);
			a1=pow(a1,0.5);
			double s2=0.5*(WX+WZ+XZ);
			double a2=s2*(s2-WX)*(s2-WZ)*(s2-XZ);
			a2=pow(a2,0.5);
			double s3=0.5*(WY+WZ+YZ);
			double a3=s3*(s3-WY)*(s3-WZ)*(s3-YZ);
			a3=pow(a3,0.5);
			double s4=0.5*(XY+XZ+YZ);
			double a4=s4*(s4-XY)*(s4-XZ)*(s4-YZ);
			a4=pow(a4,0.5);

			double vol;
			double u,v,w,W,V,U;
			u=WX;
			v=WY;
			w=WZ;
			W=XY;
			V=XZ;
			U=YZ;
			vol=sqrt(4*u*u*v*v*w*w- u*u*(v*v+w*w - U*U)*(v*v+w*w-U*U) - v*v*(w*w+u*u - V*V)*(w*w+u*u-V*V) - w*w*(u*u + v*v - W*W)*(u*u+v*v-W*W) + (v*v +w*w - U*U)*(w*w+u*u- V*V)*(u*u+v*v - W*W))/12;
			double r=vol*3/(a1+a2+a3+a4);
			if(r!=r)
				cout<<"0.0000"<<endl;
			else
				cout<<fixed<<setprecision(4)<<r<<endl;
		}
		



	}
		
}