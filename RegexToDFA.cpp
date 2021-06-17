// Given regex : a(a*ba*ba*)*
// Program to convert given regex to DFA.

#include <iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

int DFA(string str)
{
	int state = 0;
	int n = str.length();
	for(int i=0;i<n;i++)
	{
		if(state == 0)
		{
			if(str[i]=='a')
			{
				state = 1;
			}
			else
			{
				state = -1;
			}
		}
		else if(state == 1)
		{
			if(str[i]=='a')
			{
				state = 2;
			}
			else if(str[i]=='b')
			{
				state = 3;
			}
			else
			{
				state = -1;
			}
		}
		else if(state == 2)
		{
			if(str[i]=='a')
			{
				state = 2;
			}
			else if(str[i]=='b')
			{
				state = 3;
			}
			else
			{
				state = -1;
			}
		}
		else if(state == 3)
		{
			if(str[i]=='a')
			{
				state = 3;
			}
			else if(str[i]=='b')
			{
				state = 4;
			}
			else 
			{
				state = -1;
			}
		}
		else if(state == 4)
		{
			if(str[i]=='a')
			{
				state = 4;
			}
			else if(str[i]=='b')
			{
				state = 3;
			}
			else 
			{
				state = -1;
			}
		}}
	return state;
 } 

int main()
{
	string str;
	cout<<"Enter the expression: ";
	cin>>str;
	int final = DFA(str);
	if(final == 1 || final == 4)
	{
		cout<<"String accepted ";
	}
	else
	{
		cout<<"String not accepted ";
	}
	return 0;
}

//Transition Table formed:
// states | a   | b   |
//   q0   | q1  | qd  |
//   q1   | q2  | q3  |
//   q2   | q2  | q3  |
//   q3   | q3  | q4  |
//   q4   | q4  | q3  |
