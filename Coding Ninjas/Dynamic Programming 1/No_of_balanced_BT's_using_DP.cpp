/*

Code : No. of balanced BTs using DP
Send Feedback
Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so, return output modulus 10^9 + 7.
Time complexity should be O(h).
Input Format :
The first and only line of input contains an integer, that denotes the value of h. Here, h is the height of the tree.
Output Format :
The first and only line of output contains the count of balanced binary trees modulus 10^9 + 7.
Constraints :
1 <= h <= 10^6
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

#include <climits>
#include <cmath>

int balancedBTs(int n) {
    
    // Write your code here
    
    int *arr = new int[n+1];
    arr[0] = 1;
    arr[1] = 1;
    
    int modulus = (int)(pow(10, 9)) + 7;
    
    for(int i=2;i<=n;i++)
    {
        int result1 = ((long)(arr[i-1]) * arr[i-1]) % modulus;
        int result2 = (2 * (long)(arr[i-1]) * arr[i-2]) % modulus;
        
        arr[i] = (result1 + result2) % modulus;
    }
    
    return arr[n];
}

int main() {
    int n;
    cin >> n;
    cout << balancedBTs(n);
}
