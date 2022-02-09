/*

Shortest Subsequence
Send Feedback
Gary has two string S and V. Now, Gary wants to know the length shortest subsequence in S, which is not a subsequence in V.
Note: The input data will be such that there will always be a solution.
Input Format :
The first line of input contains a string, that denotes the value of S. The following line contains a string, that denotes the value of V.
Output Format :
Length of shortest subsequence in S such that it is not a subsequence in V
Constraints:
1 <= |S| <= 1000 (|x| implies the length of the string x)
1 <= |V| <= 1000 
Time Limit: 1 second
Sample Input 1:
babab
babba
Sample Output 1:
3
Explanation:
"aab" is the shortest subsequence which is present in S and absent in V.

*/


#include <iostream>
#include <string>
using namespace std;

#include <vector>


// #define m 1000


// int solve_memo(string s, string v, int **output)
// {
//     if(s.size() == 0)
//     {
//         return m;
//     }
    
//     if(v.size() == 0)
//     {
//         return 1;
//     }
    
//     if(output[s.size()][v.size()] != -1)
//     {
//         return output[s.size()][v.size()];
//     }
    
//     int i=0;
//     while(i<v.length())
//     {
//         if(v[i] == s[0])
//         {
//             break;
//         }
        
//         i++;
//     }
    
//     if(i==v.size())
//     {
//         return 1;
//     }
    
//     int a = solve_memo(s.substr(1), v, output);
//     int b = solve_memo(s.substr(1), v.substr(i+1), output) + 1;
    
//     int ans =  min(a, b);
//     output[s.size()][v.size()] = ans;
//     return ans;
// }


int solve(string s, string v) {
    
    // Write your code here
    
    
    // Brute Force
    
//     if(s.size() == 0) 
//     {
//         return m;
//     }
    
//     if(v.size() == 0)
//     {
//         return 1;
//     }
    
//     int i = 0;
//     while(i < v.length())
//     {
//         if(v[i] == s[0])
//         {
//             break;
//         }
        
//         i++;
//     }
    
//     if(i == v.size())
//     {
//         return 1;
//     }
    
//     int a = solve(s.substr(1), v);
//     int b = solve(s.substr(1), v.substr(i+1)) + 1;
    
//     return min(a, b);
    
    
    // Memoication
    
//     int **output = new int*[s.size() + 1];
//     for(int i=0;i<s.size()+1;i++)
//     {
//         output[i] = new int[v.size() + 1];
//         for(int j=0;j<v.size()+1;j++)
//         {
//             output[i][j] = -1;
//         }
//     }
    
//     return solve_memo(s, v, output);
    
    
    // Dynamic Programming
    
    int n = s.length();
    int m = v.length();
    
    vector<vector<int>> output(n+1, vector<int>(m+1));
    vector<vector<int>> next(n+1, vector<int>(m+1));
    
    for(int i=0;i<n;i++)
    {
        int prev = -1;
        for(int j=0;j<m;j++)
        {
            if(s[i] == v[j])
            {
                prev = j;
            }
            
            next[i+1][j+1] = prev;
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        output[i][0] = 1;
    }
    
    for(int i=0;i<=m;i++)
    {
        output[0][i] = 1e9;
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(next[i][j] == -1)
            {
                output[i][j] = 1;
            }
            
            else
            {
                output[i][j] = min(output[i-1][j], 1 + output[i-1][next[i][j]]);
            }
        }
    }
    
    return output[n][m];
}

int main() {
    string s, v;
    cin >> s >> v;
    cout << solve(s, v);
}
