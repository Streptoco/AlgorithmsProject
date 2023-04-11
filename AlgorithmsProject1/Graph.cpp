#include "Graph.h"

DirectedGraph::DirectedGraph(int i_NumberOfVertex, int i_NumberOfEdges)
{
	m_NumberOfVertex = i_NumberOfVertex;
	m_NumberOfEdges = i_NumberOfEdges;
	FREE GraphNode* nodeArr = new GraphNode[m_NumberOfVertex];
	for (int i = 0; i < i_NumberOfVertex; i++)
	{
		nodeArr[i].setVertexNumber(i + 1);
		m_mainVector.push_back(&nodeArr[i]);
	}	
}

void DirectedGraph::addEdgeToGraph(short i_currentHoldingNumber, short i_vertexToConnect)
{
	insertEdgeToGraph(i_currentHoldingNumber, i_vertexToConnect);
}



void DirectedGraph::printGraph()
{
	vector<GraphNode*>::iterator listItr;
	for (listItr = m_mainVector.begin(); listItr != m_mainVector.end(); ++listItr)
	{
		cout << "Main list node: " << (*listItr)->getVertexNumber() << "\n";
		(*listItr)->printSecondaryNodes();
	}
}

list<GraphNode*> DirectedGraph::findCircuit(GraphNode* i_startingVertex)
{
	GraphNode* currentVertex = i_startingVertex;
	list<GraphNode*> resultList;
	list<GraphNode*>::iterator secondaryListItr;
	resultList.push_back(currentVertex);
	while (currentVertex->getNumberOfAvailableEdges() > 0)
	{
		secondaryListItr = currentVertex->getHeadOfSecondaryList();
		if ((*secondaryListItr)->isVisited() == false)
		{
			(*secondaryListItr)->visitVertex();
			currentVertex->substractNumberOfAvailableEdges();
			resultList.push_back((*secondaryListItr));
			currentVertex = (*secondaryListItr)->getMutualPointerForMainVertex();
		}
	}
	if (resultList.back()->getVertexNumber() == resultList.front()->getVertexNumber())
	{
		return resultList;
	}
	else
	{
		cout << "No circuits exist!\n";
		resultList.clear();
		return resultList;
	}
}

void DirectedGraph::insertEdgeToGraph(short i_currentHoldingNumber, short i_vertexToConnect)
{
	GraphNode* getMutualPointerForVertex = m_mainVector[i_vertexToConnect - 1];
	m_mainVector[i_currentHoldingNumber - 1]->addVertexToSecondaryList(i_vertexToConnect, getMutualPointerForVertex);
	m_mainVector[i_currentHoldingNumber - 1]->setNumberOfAvailableEdges();
	
}

DirectedGraph::~DirectedGraph()
{
	for(auto v : m_mainVector)
	{
		delete v;
	}
	m_mainVector.clear();
}
