#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int people_free_time[5];  //store the time from which particular person is available

struct Time
{
	int hr;
	int min;
};

int mapping(string s)   //for indexing
{
		if(s=="MicerMousy")
			return 0;
		if(s=="DadsAngel")
			return 1;
		if(s== "SnoringScientist")
			return 2;
		if(s== "HungryHarry")
			return 3;
		if(s== "LazyLee")
			return 4;
		else
			return -1;
}

int Start_time(vector<int> v)    //returns the time at which all the participants of the meeting are free
{
	int ans=0;
	for(int i=0;i<v.size();i++)
	{
		if(people_free_time[v[i]]>ans)
		{
			ans=people_free_time[v[i]];  //free time of ith person
		}
	}
	return ans;
}

bool companyClose(int start_time,int time)   //tells if meeting can be scheduled within given time duration
{
	if(start_time+time>180)
		return true;
	return false;
}

int End_time(int start_time, int time)   //time at which meeting will end
{
	return start_time+time;
}

void update(int end_time, vector<int> v)
{
	for(int i=0;i<v.size();i++)
	{
		people_free_time[v[i]]=end_time;  //time by which they will finish their ongoing meeting
	}
}

Time get_time(int time)    //return time
{
	Time ans;
	ans.hr=9+time/60;
	ans.min=time%60;
	return ans;
}

void print_time(Time t)
{
	if(t.min/10==0)
	{
		cout<<t.hr<<":"<<t.min<<"0"<<endl;
	}
	else
	{
		cout<<t.hr<<":"<<t.min<<endl;
	}
}

int main() {

	memset(people_free_time,0,sizeof(people_free_time));
	cout<<"COMPANY CALENDAR"<<endl;
	while(1)
	{
		int meeting_time; 
		cout<<"enter duration of meeting and name of persons who will attend the meeting: "<<endl;
		vector<int> people;     //people who all have to be included in the meeting

		string s;
		std::string line ;
		std::stack<std::string> stk ;
	    std::getline( std::cin, line ) ;

	    {
	        std::istringstream stm(line) ;
	        std::string word ;
	        while( stm >> word ) stk.push(word) ;
	    }
	    if(stk.size()==1)
	    {
	    	cout<<"Enter People"<<endl;	 
	    	break;
	    }
	    while(stk.size()!=1)
	    {
	    	s=stk.top();
	    	stk.pop();
	    	int x=mapping(s);
			if(x==-1)
			{
				cout<<"Person not present"<<endl;
			}
			people.push_back(x);
	    }

	    meeting_time=stoi(stk.top());
	    if(meeting_time==0)       //no further meetings.
			return 0;

		int start_time=Start_time(people);    //time at which current meeting will start

		if(companyClose(start_time,meeting_time))
		{
			cout<<"-------------"<<endl;
			cout<<"No slots available"<<endl;
			cout<<"-------------"<<endl;
		}
		else
		{
			int end_time=End_time(start_time,meeting_time);    //time at which current meeting will end
			update(end_time,people);  //update the free time of all the participating people

			Time start = get_time(start_time);
			Time end = get_time(end_time);
			cout<<"-------------"<<endl;
			cout<<"Meeting will start at ";
			print_time(start);
			cout<<"Meeting will end at ";
			print_time(end);
			cout<<"-------------"<<endl;
			cout<<endl;
		}

	}
}