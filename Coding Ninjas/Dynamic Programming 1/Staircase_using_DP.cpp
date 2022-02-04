/*

Code : Staircase using Dp
Send Feedback
A child runs up a staircase with 'n' steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count and return all possible ways in which the child can run-up to the stairs.
Input format :
The first and the only line of input contains an integer value, 'n', denoting the total number of steps.
Output format :
Print the total possible number of ways.
 Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec
Sample Input 1:
4
Sample Output 1:
7
Sample Input 2:
10
Sample Output 2:
274

*/


#include <iostream>
using namespace std;

// long stairCase_helper(int n, long *arr)
// {
//     if(n < 0)
//     {
//         return 0;
//     }
    
//     if(n == 0 || n == 1)
//     {
//         return 1;
//     }
    
//     if(arr[n] != -1)
//     {
//         return arr[n];
//     }
    
//     long x = stairCase_helper(n-1, arr);
//     long y = stairCase_helper(n-2, arr);
//     long z = stairCase_helper(n-3, arr);
    
//     arr[n] = x + y + z;
//     return arr[n];
// }


long staircase(int n)
{
	//Write your code here
    
    
    // Brute Force
    
//     if(n < 0)
//     {
//         return 0;
//     }
    
//     if(n == 0 || n == 1)
//     {
//         return 1;
//     }
    
//     long x = staircase(n-1);
//     long y = staircase(n-2);
//     long z = staircase(n-3);
    
//     return x + y + z;
    
    
    // Dynamic Programming
    
    long *stair = new long[n+1]
    
    stair[0] = 1;
    stair[1] = 1;
    stair[2] = 2;
    
    for(int i=3;i<=n;i++)
    {
        stair[i] = stair[i-1] + stair[i-2] + stair[i-3];
    }
    
    long result = stair[n];
    delete [] stair;
    
    return result;
    
    
    // Memoization
    
//     long *arr = new long[n+1];
//     for(int i=0;i<n+1;i++)
//     {
//         arr[i] = -1;
//     }
    
//     return stairCase_helper(n, arr);
}

int main()
{
	int n;
	cin >> n;
	cout << staircase(n);
}
