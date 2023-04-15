#include "DriverProgram.h"

void DriverProgram::printMenu()
{
	char userResponse;
	bool successfulInput;
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
		successfulInput = getInputForEdgesFromUser();
	}

	if (successfulInput == true)
	{
		printList(graph->euler());
	}
}

bool DriverProgram::handleDirectedGraph()
{
	bool result = unifiedHandlerForFirstCase();
	if (result == true)
	{
		FREE graph = new DirectedGraph(VAL m_NumberOfVertexes, VAL m_NumberOfEdges);
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
	short currentHoldingNumber, vertexToConnect;
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