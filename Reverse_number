/*
Reverse the number
PrepBuddy gave you a number 
X
 and asks you to reverse that number and print it.

Input format
One integer is provided denoting the value of 
X
.
Note - The given number doesn't have leading or ending zero's.

Output format
Print the reverse of 
X
.

Constraints
1
<=
X
<=
10
6

Time Limit
1 second

Example
Input
102345

Output
543201

Note - Do not use any inbuilt function for solving this question.

*/


#include <bits/stdc++.h>
using namespace std;
int reverse(int);

int main()
{
  int X, rev=0;
  cin>>X;
  rev = reverse(X);
  cout<<endl<<rev;
  return 0;
}

int reverse(int n)
{
  int res=0, rem;
  while(n!=0)
  {
   rem = n%10;
   res = rem + (res*10);
   n=n/10;
  }
  return res;
}
