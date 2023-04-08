#include "DriverProgram.h"

void DriverProgram::printMenu()
{
    char userResponse;
    cout << "Is the graph directed: y/n\n";
    cin >> userResponse;
    while(userResponse != 'y' && userResponse != 'n')
    {
        if (userResponse == 'y')
        {
            handleDirectedGraph();
        }
        else if (userResponse == 'n')
        {
            handleUndirectedGraph();
        }
        cout << "Please enter a valid input. '" << userResponse << "' isn't a valid input.";
    }
    getInputForEdgesFromUser();
}

void DriverProgram::handleDirectedGraph()
{
    unifiedHandlerForFirstCase();
    graph = new DirectedGraph(VAL m_NumberOfVertexes,VAL m_NumberOfEdges);
}

void DriverProgram::handleUndirectedGraph()
{
    unifiedHandlerForFirstCase();
    graph = new UndirectedGraph(VAL m_NumberOfVertexes, VAL m_NumberOfEdges);
}

void DriverProgram::unifiedHandlerForFirstCase()
{
    cin >> m_NumberOfVertexes >> m_NumberOfEdges;
    while (m_NumberOfEdges > m_NumberOfVertexes)
    {
        cout << "The number of the edges cannot be great than the number of the vertices!";
        cin >> m_NumberOfVertexes >> m_NumberOfEdges;
    }
}

void DriverProgram::getInputForEdgesFromUser()
{
    short currentHoldingNumber, vertexToConnect;
    for (int i = 0; i < graph->getNumberOfEdges(); i++)
    {
        cin >> currentHoldingNumber >> vertexToConnect;
        GraphNode* mainListNode = new GraphNode(currentHoldingNumber);
        GraphNode* secondaryListNode = new GraphNode(vertexToConnect);
        if (i == 0)
        {
            
        }
        else 
        
            graph->addEdgeToGraph(tempNode);
        }
    }
}