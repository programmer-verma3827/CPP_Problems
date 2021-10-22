/*
Code : Diamond of stars

Print the following pattern for the given number of rows.
Note: N is always odd.


Pattern for N = 5



The dots represent spaces.



Input format :
N (Total no. of rows and can only be odd)
Output format :
Pattern in N lines
Constraints :
1 <= N <= 49
Sample Input 1:
5
Sample Output 1:
  *
 ***
*****
 ***
  *
Sample Input 2:
3
Sample Output 2:
  *
 ***
  *


*/

#include<iostream>
using namespace std;


int main() {
    
   int n;
    cin>>n;
    int n1, n2;
    n1= (n+1)/2;
    n2= n1-1;
    for(int i=1; i<=n1; i++)
    {
for(int z=1; z<=(n1-i); z++){
    
    cout<<" ";
}
        for(int j=1; j<=((2*i)-1); j++)
        {
            cout<<"*";
        }
        
        cout<<endl;
    }
    
    for(int q=n2; q>=1; q--)
    {
        for(int w=1; w<=(n2-q)+1; w++)
        {
            cout<<" ";
        }
        for(int e=1; e<=(2*q)-1;e++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    
}
