/*

Determine Prime
Given a number 
N
, your task is to print "Yes" if 
N
 is prime number else print "No".

Input format
First line contains an integer 
T
, representing the number of test cases.
For each of the next 
T
 lines, each line contains an integer 
N
.

Output format
For each test case on a new line, print "Yes"(without quotes) or "No"(without quotes) depending on 
N
.

Constraints
1
<=
T
<=
50

1
<=
N
<=
10
6

Time Limit
1
 second

Example
Input
2
53
8

Output
Yes
No

*/


#include <bits/stdc++.h>
using namespace std;

int main()
{
  //write your code here
  int t;
  cin>>t;
  while(t>0)
  {
  int n, i;
  bool isPrime = true;
  cin>>n;
  if(n==0 || n==1)
  {
    isPrime = false;
  }
  
  else {
    for(i=2;i<=n/2;i++)
    {
      if(n%i==0)
      {
        isPrime = false;
        break;
      }
    }
  }
  
  if(isPrime)
  cout<<"Yes"<<endl;
  else
  cout<<"No"<<endl;
  
  t--;
  }
  
  return 0;
}
