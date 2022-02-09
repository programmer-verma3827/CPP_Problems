/*

Matrix Chain Multiplication
Send Feedback
Given a chain of matrices A1, A2, A3,.....An, you have to figure out the most efficient way to multiply these matrices. In other words, determine where to place parentheses to minimize the number of multiplications.
You will be given an array p[] of size n + 1. Dimension of matrix Ai is p[i - 1]*p[i]. You need to find minimum number of multiplications needed to multiply the chain.
Input Format:
The first line of input contains an integer, that denotes the value of n. The following line contains n+1 integers, that denote the value of elements of array p[].
Output Format:
The first and only line of output prints the minimum number of multiplication needed.
Constraints :
1 <= n <= 100
Time limit: 1 second
Sample Input 1:
3
10 15 20 25
Sample Output 1:
8000
Sample Output Explanation:
There are two ways to multiply the chain - A1*(A2*A3) or (A1*A2)*A3.
If we multiply in order- A1*(A2*A3), then number of multiplications required are 11250.
If we multiply in order- (A1*A2)*A3, then number of multiplications required are 8000.
Thus minimum number of multiplications required are 8000. 

*/


#include <iostream>
using namespace std;

#include <bits/stdc++.h>


// Brute Force

// int matrixChainMultiplication_helper(int *arr, int startIndex, int endIndex)
// {
//     if(startIndex == endIndex)
//     {
//         return 0;
//     }
    
//     int x = INT_MAX;
//     for(int k=startIndex; k<endIndex; k++)
//     {
//         x = min(x, matrixChainMultiplication_helper(arr, startIndex, k) + matrixChainMultiplication_helper(arr, k+1, endIndex) + 
//         (arr[startIndex-1] * arr[k] * arr[endIndex]));
//     }
    
//     return x;
// }


// Memoization

// int matrixChainMultiplication_memo(int *arr, int startIndex, int endIndex, int *output)
// {
//     if(startIndex == endIndex)
//     {
//         return 0;
//     }
    
//     if(output[endIndex] != -1)
//     {
//         return output[endIndex];
//     }
    
//     int x = INT_MAX;
//     for(int k = startIndex; k < endIndex; k++)
//     {
//         x = min(x, matrixChainMultiplication_memo(arr, startIndex, k, output) + matrixChainMultiplication_memo(arr, k+1, 
//         endIndex, output) + arr[startIndex-1] * arr[k] * arr[endIndex]);
//     }
    
//     // output[endIndex] = x;
//     return x;
// }


int matrixChainMultiplication(int* arr, int n) {
    
    // Write your code here
    
    // return matrixChainMultiplication_helper(arr, 1, n);
    
    
//     int *output = new int[n+1];
//     for(int i=0;i<n+1;i++)
//     {
//         output[i] = -1;
//     }
    
//     return matrixChainMultiplication_memo(arr, 1, n, output);
    
    
    // Dynamic Programming
    
    n += 1;
    vector<vector<int>> output(n, vector<int>(n));
    for(int i=1;i<n;i++)
    {
        output[i][i] = 0;
    }
    
    for(int l=2;l<n;l++)
    {
        for(int i=1;i<n-l+1;i++)
        {
            int j = i+l-1;
            output[i][j] = INT_MAX;
            
            for(int k=i;k<=j-1;k++)
            {
                int q = output[i][k] + output[k+1][j] + (arr[i-1] * arr[k] * arr[j]);
                
                if(q<output[i][j])
                {
                    output[i][j] = q;
                }
            }
        }
    }
    
    return output[1][n-1];
}

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i <= n; i++) {
        cin >> arr[i];
    }

    cout << matrixChainMultiplication(arr, n);

    delete[] arr;
}
