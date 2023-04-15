#include "DriverProgram.h"

void DriverProgram::printMenu()
{
	char userResponse;
	bool successfulInput; // double-check that the input is indeed valid
	cout << "Is the graph directed: y/n\n";
	cin >> userResponse;
	switch (userResponse)
	{
	case 'y':
		successfulInput = handleDirectedGraph();
		break;
	case 'n':
		successfulInput = handleUndirectedGraph();
		break;
	default:
		cout << "invalid input";
		exit(1);
	}
	if (successfulInput == true)
	{
		successfulInput = getInputForEdgesFromUser(); // gets the stream of {vertex A, vertex B} input from the user
	}

	if (successfulInput == true)
	{
		printList(graph->euler()); // prints the euler circuit, if it exists
	}
}

bool DriverProgram::handleDirectedGraph()
{
	bool result = unifiedHandlerForFirstCase();
	if (result == true)
	{
		FREE graph = new DirectedGraph(VAL m_NumberOfVertexes, VAL m_NumberOfEdges); // the 'FREE' prefix exists to let us know the object is dynamically allocated
		return true;
	}
	else
	{
		return false;
	}
}

bool DriverProgram::handleUndirectedGraph()
{
	bool result = unifiedHandlerForFirstCase();
	if (result == true)
	{
		FREE graph = new UndirectedGraph(VAL m_NumberOfVertexes, VAL m_NumberOfEdges);
		return true;
	}
	else
	{
		return false;
	}
}

bool DriverProgram::unifiedHandlerForFirstCase()
{
	cin >> m_NumberOfVertexes >> m_NumberOfEdges;
	if (m_NumberOfEdges <= 0 || m_NumberOfVertexes <= 0)
	{
		cout << "invalid input" << endl;
		return false;
	}
	return true;

}

bool DriverProgram::getInputForEdgesFromUser()
{
	short currentHoldingNumber, vertexToConnect; // currentHoldingNumber corresponds to the main vertex, the latter to the vertex in the residency list
	for (int i = 0; i < graph->getNumberOfEdges(); i++)
	{
		cin >> currentHoldingNumber >> vertexToConnect;
		if (currentHoldingNumber > graph->getNumberOfVertex() || vertexToConnect > graph->getNumberOfVertex())
		{
			cout << "invalid input" << endl;
			return false;
		}
		graph->addEdgeToGraph(currentHoldingNumber, vertexToConnect);
	}
	return true;
}

void DriverProgram::printGraph()
{
	graph->printGraph();
}

void DriverProgram::printList(list<GraphNode*> resultList)
{
	if (resultList.empty() == true)
	{
		return;
	}

	list<GraphNode*>::iterator listItr = resultList.begin();
	cout << "(";
	for (int i = 0; i < resultList.size(); i++, ++listItr)
	{
		if (i == resultList.size() - 1)
		{
			cout << (*listItr)->getVertexNumber();
		}
		else
		{
			cout << (*listItr)->getVertexNumber() << ",";
		}
	}
	cout << ")";
}