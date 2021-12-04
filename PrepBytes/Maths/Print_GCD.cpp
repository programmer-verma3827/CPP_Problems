/*  

Print GCD
Let's begin with a very simple question.
You are given two integers represented by 
N
 and 
M
, your task is to print GCD(Greatest Common Divisor) of 
N
 and 
M
.

Input format
The first line contains an integer 
T
 denoting the number of test cases.
For the next 
T
 lines, each line contains two integers represented by 
N
 and 
M
.

Output format
For each test case on a new line, print GCD of 
N
 and 
M
.

Constaints
1
<=
T
<=
10

1
<=
N
<=
10
5

1
<=
M
<=
10
5

Time Limit
1
 second

Example
Input
2
4 10
6 9

Output
2
3

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
    int n1, n2, gcd;
    cin>>n1>>n2;
    if(n2>n1)
    {
      int temp = n2;
      n2 = n1;
      n1 = temp;
    }
    
    for(int i=1;i<=n2;i++)
    {
      if(n1%i==0 && n2%i==0)
      {
        gcd = i;
      }
    }
    
    cout<<gcd<<endl;
    
    t--;
  }
  
  return 0;
}
