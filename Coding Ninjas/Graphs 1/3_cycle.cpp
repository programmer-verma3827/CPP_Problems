/*

3 Cycle
Send Feedback
Given a graph with N vertices (numbered from 0 to N-1) and M undirected edges, then count the distinct 3-cycles in the graph. A 3-cycle PQR is a cycle in which (P,Q), (Q,R) and (R,P) are connected by an edge.
Input Format :
The first line of input contains two space separated integers, that denotes the value of N and M.
Each of the following M lines contain two integers, that denote the vertices which have an undirected edge between them. Let us denote the two vertices with the symbol u and v. 
Output Format :
Print the count the number of 3-cycles in the given graph
Constraints :
0 <= N <= 100
0 <= M <= (N*(N-1))/2
0 <= u <= N - 1
0 <= v <= N - 1
Time Limit: 1 sec
Sample Input 1:
3 3
0 1
1 2
2 0
Sample Output 1:
1

*/


#include <iostream>
using namespace std;


// 1st Method


// int threeCycleHelper(int **edges, int n, int i, bool *visited, int &count)
// {
//     for(int j=0;j<n+1;j++)
//     {
//         if(visited[j] == false && edges[i][j] == 1)
//         {
//             for(int k=0;k<n+1;k++)
//             {
//                 if(visited[k] == false && edges[j][k] == 1 && edges[k][i] == 1)
//                 {
//                     count++;
//                 }
//             }
//         }
//     }
    
//     return count/2;
// }



// int threeCycle(int **edges, int n)
// {   
//     bool *visited = new bool[n];
//     for(int i=0;i<n;i++)
//     {
//         visited[i] = false;
//     }
    
//     int sum = 0;
//     for(int i=1;i<n;i++)
//     {
//         visited[i] = true;
//         int count = 0;
        
//         sum = sum + threeCycleHelper(edges, n, i, visited, count);
//     }

//     delete [] visited;
//     return sum;
// }



// 2nd Method

int getCycles(bool **edges, int n)
{
    int countCycle = 0;
    for(int i=0;i<n-2;i++)
    {
        for(int j=i+1;j<n-1;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                if(edges[i][j] && edges[j][k] && edges[k][i])
                {
                    countCycle++;
                }
            }
        }
    }
    
    return countCycle;
}


int main() {
    
    // Write your code here
    
    
    // 1st Method
    
//     int n, e;
//     cin>>n>>e;
    
//     int **edges = new int*[n+1];
//     for(int i=0;i<n;i++)
//     {
//         edges[i] = new int[n+1];
//         for(int j=0;j<n;j++)
//         {
//             edges[i][j] = 0;
//         }
//     }
    
//     for(int i=0;i<e;i++)
//     {
//         int f, s;
//         cin>>f>>s;
//         edges[f][s] = 1;
//         edges[s][f] = 1;
//     }
    
//     cout<<threeCycle(edges, n);
    
//     for(int i=0;i<n;i++)
//     {
//         delete[] edges[i];
//     }
    
//     delete [] edges;
    
    
    // 2nd Method
    
    int n, e;
    cin>>n>>e;
    
    bool **edges = new bool*[n];
    for(int i=0;i<n;i++)
    {
        edges[i] = new bool[n]();
    }
    
    for(int i=0;i<e;i++)
    {
        int a, b;
        cin>>a>>b;
        edges[a][b] = true;
        edges[b][a] = true;
    }
    
    cout<<getCycles(edges, n);
    
    for(int i=0;i<n;i++)
    {
        delete[] edges[i];
    }
    
    delete [] edges;
    
}
