/*
Input :  n = 4

![Cycle 1](cycle1.png?raw=true "Optional Title 1")
Output : Total cycles = 3
Explanation : Following 3 unique cycles 
   0 -> 1 -> 2 -> 3 -> 0
   0 -> 1 -> 4 -> 3 -> 0
   1 -> 2 -> 3 -> 4 -> 1
Note* : There are more cycles but
these 3 are unique as 0 -> 3 -> 2 -> 1
-> 0 and 0 -> 1 -> 2 -> 3 -> 0 are 
same cycles and hence will be counted as 1.
*/


#include <bits/stdc++.h>
using namespace std;
 
// Number of vertices
const int V = 5;
 
void DFS(bool graph[][V], bool marked[], int n,
               int vert, int start, int &count)
{
    // mark the vertex vert as visited
    marked[vert] = true;
 
    // if the path of length (n-1) is found
    if (n == 0) {
 
        // mark vert as un-visited to make
        // it usable again.
        marked[vert] = false;
 
        // Check if vertex vert can end with
        // vertex start
        if (graph[vert][start])
        {
            count++;
            return;
        } else
            return;
    }
 
    // For searching every possible path of
    // length (n-1)
    for (int i = 0; i < V; i++)
        if (!marked[i] && graph[vert][i])
 
            // DFS for searching path by decreasing
            // length by 1
            DFS(graph, marked, n-1, i, start, count);
 
    // marking vert as unvisited to make it
    // usable again.
    marked[vert] = false;
}
 
// Counts cycles of length N in an undirected
// and connected graph.
int countCycles(bool graph[][V], int n)
{
    // all vertex are marked un-visited intially.
    bool marked[V];
    memset(marked, 0, sizeof(marked));
 
    // Searching for cycle by using v-n+1 vertices
    int count = 0;
    for (int i = 0; i < V - (n - 1); i++) {
        DFS(graph, marked, n-1, i, i, count);
 
        // ith vertex is marked as visited and
        // will not be visited again.
        marked[i] = true;
    }
 
    return count/2;
}
 
int main()
{
    bool graph[][V] = {{0, 1, 0, 1, 0},
                      {1, 0, 1, 0, 1},
                      {0, 1, 0, 1, 0},
                      {1, 0, 1, 0, 1},
                      {0, 1, 0, 1, 0}};
    int n = 4;
    cout << "Total cycles of length " << n << " are "
         << countCycles(graph, n);
    return 0;
}
