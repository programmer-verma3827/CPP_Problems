/*

Code : Min Steps to 1 using DP
Send Feedback
Given a positive integer 'n', find and return the minimum number of steps that 'n' has to take to get reduced to 1. You can perform any one of the following 3 steps:
1.) Subtract 1 from it. (n = n - ­1) ,
2.) If n is divisible by 2, divide by 2.( if n % 2 == 0, then n = n / 2 ) ,
3.) If n is divisible by 3, divide by 3. (if n % 3 == 0, then n = n / 3 ).  
Input format :
The first and the only line of input contains an integer value, 'n'.
Output format :
Print the minimum number of steps.
Constraints :
1 <= n <= 10 ^ 6
Time Limit: 1 sec
Sample Input 1 :
4
Sample Output 1 :
2 
Explanation of Sample Output 1 :
For n = 4
Step 1 :  n = 4 / 2  = 2
Step 2 : n = 2 / 2  =  1 
Sample Input 2 :
7
Sample Output 2 :
3
Explanation of Sample Output 2 :
For n = 7
Step 1 :  n = 7 - 1 = 6
Step 2 : n = 6  / 3 = 2 
Step 3 : n = 2 / 2 = 1  

*/


#include <bits/stdc++.h>
using namespace std;

#include <climits>

int countStepsToOne(int n)
{
	//Write your code here
    
    // 1st Method
    
//     int *arr = new int[n+1];
//     arr[1] = 0;
//     arr[2] = 1;
//     arr[3] = 1;
    
//     int x, y, z;
    
//     for(int i=4;i<n+1;i++)
//     {
//         x = y = z = INT_MAX;
//         if(i % 2 == 0)
//         {
//             x = arr[i/2];
//         }
        
//         if(i % 3 == 0)
//         {
//             y = arr[i/3];
//         }
        
//         else
//         {
//             z = arr[i-1];
//         }
        
//         arr[i] = 1 + min(x, min(y, z));
//     }
    
//     return arr[n];
    
    
    // 2nd Method
    
    int *arr = new int[n+1];
    arr[1] = 0;
    
    for(int i=2;i<=n;i++)
    {
        int x = arr[i-1];
        int y = INT_MAX;
        int z = INT_MAX;
        
        if(i % 2 == 0)
        {
            y = arr[i/2];
        }
        
        if(i % 3 == 0)
        {
            z = arr[i/3];
        }
        
        arr[i] = min(x, min(y, z)) + 1;
    }
    
    return arr[n];
    
}

int main()
{
	int n;
	cin >> n;
	cout << countStepsToOne(n);
}
