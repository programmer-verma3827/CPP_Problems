/*

Code : Dijkstra's Algorithm
Send Feedback
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all other vertices (including source vertex also) using Dijkstra's Algorithm.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
For each vertex, print its vertex number and its distance from source, in a separate line. The vertex number and its distance needs to be separated by a single space.
Note : Order of vertices in output doesn't matter.
Constraints :
2 <= V, E <= 10^5
Time Limit: 1 sec
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
0 0
1 3
2 4
3 5

*/


#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int findMinDistance(int *distance, bool *visited, int n)
{
    int minDistance = -1;
    for(int i=0;i<n;i++)
    {
        if(!visited[i] && (minDistance == -1 || distance[minDistance] > distance[i]))
        {
            minDistance = i;
        }
    }
    
    return minDistance;
}


void dijkstraAlgo(int **edges, int n)
{
    int *distance = new int[n];
    bool *visited = new bool[n];
    
    for(int i=0;i<n;i++)
    {
        visited[i] = false;
        distance[i] = INT_MAX;
    }
    
    distance[0] = 0;
    
    for(int i=0;i<n;i++)
    {
        int minDistance = findMinDistance(distance, visited, n);
        visited[minDistance] = true;
        
        for(int j=0;j<n;j++)
        {
            if(edges[minDistance][j] != 0 && !visited[j])
            {
                int dist = distance[minDistance] + edges[minDistance][j];
                if(dist < distance[j])
                {
                    distance[j] = dist;
                }
            }
        }
    }
    
    for(int i=0;i<n;i++)
    {
        cout<<i<<" "<<distance[i]<<endl;
    }
    
}


int main() {
    
    // Write your code here
    
    int n, e;
    cin>>n>>e;
    
    int **edges = new int*[n];
    for(int i=0;i<n;i++)
    {
        edges[i] = new int[n];
        for(int j=0;j<n;j++)
        {
            edges[i][j] = 0;
        }
    }
    
    for(int i=0;i<e;i++)
    {
        int f, s, weight;
        cin>>f>>s>>weight;
        edges[f][s] = weight;
        edges[s][f] = weight;
    }
    
    cout<<endl;
    dijkstraAlgo(edges, n);
    
    for(int i=0;i<n;i++)
    {
        delete[] edges[i];
    }
    
    delete [] edges;
    
}
