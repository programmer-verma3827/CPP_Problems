/*

Code : No. of balanced BTs
Send Feedback
Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so, return output modulus 10^9 + 7.
Write a simple recursive solution.
Input Format :
The first and only line of input contains an integer, that denotes the value of h. Here, h is the height of the tree.
Output Format :
The first and only line of output contains the count of balanced binary trees modulus 10^9 + 7.
Constraints :
1 <= h <= 24
Time Limit: 1 sec
Sample Input 1:
3
Sample Output 1:
15
Sample Input 2:
4
Sample Output 2:
315

*/

#include <iostream>
using namespace std;

#include <cmath>

int balancedBTsHelper(int n, int *arr)
{
    if(n <= 1)
    {
        return 1;
    }
    
    int modulus = (int)(pow(10, 9)) + 7;
    
    if(arr[n] != -1)
    {
        return arr[n];
    }
    
    int x = balancedBTsHelper(n-1, arr);
    int y = balancedBTsHelper(n-2, arr);
    
    int temp1 = ((long) (x) * x) % modulus;
    int temp2 = (2* (long)(x) * y) % modulus;
    
    arr[n] = (temp1 + temp2) % modulus;
    return arr[n];
}


int balancedBTs(int n) {
    
    // Write your code here
    
    // Brute Force

//     if(n <= 1)
//     {
//         return 1;
//     }
    
//     int modulus = (int)(pow(10, 9)) + 7;
    
//     int x = balancedBTs(n-1);
//     int y = balancedBTs(n-2);
    
//     int temp1 = ((long)(x) * x) % modulus;
//     int temp2 = (2 *(long)(x) * y) % modulus;
    
//     return (temp1 + temp2) % modulus;
    
    
    // Memoization
    
    int *arr = new int[n+1];
    for(int i=0;i<n+1;i++)
    {
        arr[i] = -1;
    }
    
    return balancedBTsHelper(n, arr);
}

int main() {
    int n;
    cin >> n;
    cout << balancedBTs(n);
}
