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
	printList(graph->findCircuit(graph->returnFirstVector()));
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
	cin >> m_NumberOfVertexes >> m_NumberOfEdges;
}

void DriverProgram::getInputForEdgesFromUser()
{
	short currentHoldingNumber, vertexToConnect;
	for (int i = 0; i < graph->getNumberOfEdges(); i++)
	{
		cin >> currentHoldingNumber >> vertexToConnect;
		graph->addEdgeToGraph(currentHoldingNumber, vertexToConnect);
	}
}

void DriverProgram::printGraph()
{
	graph->printGraph();
}

void DriverProgram::printList(list<GraphNode*> resultList)
{
	list<GraphNode*>::iterator listItr = resultList.begin();
	for (; listItr != resultList.end(); ++listItr)
	{
		cout << (*listItr)->getVertexNumber() << ", ";
	}
}