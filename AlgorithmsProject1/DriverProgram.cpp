#include "DriverProgram.h"

void DriverProgram::printMenu()
{
	char userResponse;
	cout << "Is the graph directed: y/n\n";
	do
	{
		cin >> userResponse;
		if (userResponse == 'y')
		{
			cout << "IN BEFORE HANDLE\n";
			handleDirectedGraph();
		}
		else if (userResponse == 'n')
		{
			handleUndirectedGraph();
		}
		else
		{
			cout << "Please enter a valid input. '" << userResponse << "' isn't a valid input.\n";
		}
	} while (userResponse != 'y' && userResponse != 'n');
	getInputForEdgesFromUser();
	printGraph();
}

void DriverProgram::handleDirectedGraph()
{
	unifiedHandlerForFirstCase();
	FREE graph = new DirectedGraph(VAL m_NumberOfVertexes, VAL m_NumberOfEdges);
}

void DriverProgram::handleUndirectedGraph()
{
	unifiedHandlerForFirstCase();
	FREE graph = new UndirectedGraph(VAL m_NumberOfVertexes, VAL m_NumberOfEdges);
}

void DriverProgram::unifiedHandlerForFirstCase()
{
	cout << "IN DRIVER::UNIFIED_HANDLER\n";
	cin >> m_NumberOfVertexes >> m_NumberOfEdges;
}

void DriverProgram::getInputForEdgesFromUser()
{
	short currentHoldingNumber, vertexToConnect;
	for (int i = 1; i <= graph->getNumberOfEdges(); i++)
	{
		cin >> currentHoldingNumber >> vertexToConnect;
		graph->addEdgeToGraph(currentHoldingNumber, vertexToConnect);
	}
}

void DriverProgram::printGraph()
{
	graph->printGraph();
}