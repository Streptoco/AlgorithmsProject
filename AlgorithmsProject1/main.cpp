#include "Graph.h"

int main()
{
    // TODO: handle errors with input, check for validity of undirected graph.
    char userResponse;
    unsigned short vertexA, vertexB;
    unsigned short n, m;
    cout << "Is the graph directed: y/n\n";
    cin >> userResponse >> n >> m;
    if (userResponse == 'y') // Directed Graph 
    {
        DirectedGraph graph;
        // Start getting user input for the list
        for (int i = 0; i < m; i++)
        {
            cin >> vertexA >> vertexB;

        }
    }
}