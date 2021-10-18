/*
Number Pattern 2

Print the following pattern
Pattern for N = 4


The dots represent spaces.



Input Format :
N (Total no. of rows)
Output Format :
Pattern in N lines
Sample Input :
5
Sample Output :


The dots represent spaces.

*/


#include<iostream>
using namespace std;


int main(){

       /*  Read input as specified in the question.
	* Print output as specified in the question.
	*/
  int n;
    cin>>n;
    int i=1;
    while(i<=n)
    {
        int k=1;
        while(k<=n-i)
        {
            cout<<" ";
            k = k+1;
        }
        int val=i;
        int j=1;
        while(j<=i)
        {
          cout<<val++;
            j++;
        }
        cout<<endl;
        i = i+1;
    }
    return 0;
    
}
