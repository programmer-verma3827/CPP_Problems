/*

Longest Increasing Subsequence
Send Feedback
Given an array with N elements, you need to find the length of the longest subsequence in the given array such that all elements of the subsequence are sorted in strictly increasing order.
Input Format
The first line of input contains an integer N. The following line contains N space separated integers, that denote the value of elements of array.
Output Format
The first and only line of output contains the length of longest subsequence.
Constraints
1 <= N <= 10^3
Time Limit: 1 second
Sample Input 1 :
6
5 4 11 1 16 8
Sample Output 1 :
3
Sample Output Explanation
Length of longest subsequence is 3 i.e. (5,11,16) or (4,11,16).
Sample Input 2 :
3
1 2 2
Sample Output 2 :
2

*/


#include <iostream>
using namespace std;

int longestIncreasingSubsequence_brute(int *arr, int index, int prev, int n)
{
    if(index == n)
    {
        return 0;
    }
    
    int x=0, y=0;
    if(arr[index] > prev)
    {
        x = 1 + longestIncreasingSubsequence_brute(arr, index+1, arr[index], n);
    }
    
    y = longestIncreasingSubsequence_brute(arr, index+1, prev, n);
    
    return max(x, y);
}


// int longestIncreasingSubsequence_memo(int *arr, int index, int prev, int n, int *output)
// {
//     if(index == n)
//     {
//         return 0;
//     }
    
//     if(output[n] != -1)
//     {
//         return output[n];
//     }
    
//     int x = 0, y = 0;
//     if(arr[index] > prev)
//     {
//         x = 1 + longestIncreasingSubsequence_memo(arr, index+1, arr[index], n, output);
//     }
    
//     y = longestIncreasingSubsequence_memo(arr, index+1, prev, n, output);
    
//     int answer = max(x, y);
    
//     output[n] = answer;
//     return output[n];
// }


int longestIncreasingSubsequence(int* arr, int n) {
    
	// Write your code here
    
    // Dynamic Programming (1st Method)
    
    
//     if(n == 0) return 0;
//     if(n == 1) return 1;
//     if(n == 2)
//     {
//         if(arr[0] > arr[1])
//         {
//             return 1;
//         }
        
//         else
//         {
//             return 2;
//         }
//     }
    
//     int *output = new int[n];
//     output[0] = 1;
    
//     int ans = 1;
//     for(int i=1;i<n;i++)
//     {
//         int max = 1;
//         for(int j=i-1;j>=0;j--)
//         {
//             if(arr[j] < arr[i])
//             {
//                 int result = output[j] + 1;
//                 if(result > max)
//                 {
//                     max = result;
//                 }
//             }
//         }
        
//         output[i] = max;
//         if(max > ans)
//         {
//             ans = max;
//         }
//     }
    
//     return ans;
    
    
    // Dynamic Programming (2nd Method)
    
//     int *output = new int[n];
//     output[0] = 1;
//     for(int i=0;i<n;i++)
//     {
//         output[i] = 1;
//         for(int j=i-1;j>=0;j--)
//         {
//             if(arr[j] > arr[i])
//             {
//                 continue;
//             }
            
//             if(arr[j] < arr[i])
//             {
//                 output[i] = max(output[j] + 1, output[i]);
//             }
//         }
//     }
    
//     int best = 0;
//     for(int i=0;i<n;i++)
//     {
//         if(best < output[i])
//         {
//             best = output[i];
//         }
//     }
    
//     delete [] output;
//     return best;
    
    
    // Brute Force 
    
    return longestIncreasingSubsequence_brute(arr, 0, -1, n);
    
    
    // Memoization
    
//     int *output = new int[n+1];
//     for(int i=0;i<n;i++)
//     {
//         output[i] = -1;
//     }
    
//     return longestIncreasingSubsequence_memo(arr, 0, -1, n, output);
    
}

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << longestIncreasingSubsequence(arr, n);
}
