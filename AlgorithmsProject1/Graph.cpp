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
	_nodesArr = nodeArr;
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
	currentVertex->visitVertex();
	list<GraphNode*> resultList;
	list<GraphNode*>::iterator secondaryListItr;
	resultList.push_back(currentVertex);
	while (currentVertex->getNumberOfAvailableEdges() > 0)
	{
		secondaryListItr = currentVertex->getNextAvailableVertexInList();
		if (*secondaryListItr == nullptr)
		{
			break;
		}
		if ((*secondaryListItr)->isVisited() == false)
		{

			(*secondaryListItr)->visitVertex();
			UndirectedGraph* unDirectedGraph = dynamic_cast<UndirectedGraph*>(this);
			if (unDirectedGraph != nullptr)
			{
				unDirectedGraph->markTheOppositeEdge(currentVertex, (*secondaryListItr)->getMutualPointerForMainVertex());
			}

			currentVertex->substractNumberOfAvailableEdges();
			resultList.push_back((*secondaryListItr)->getMutualPointerForMainVertex());
			currentVertex = (*secondaryListItr)->getMutualPointerForMainVertex();
		}
		if (i_startingVertex == currentVertex)
		{
			return resultList;
		}
	}
	if (resultList.back()->getVertexNumber() == resultList.front()->getVertexNumber())
	{
		return resultList;
	}
	else
	{
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
#ifdef DEBUG
	cout << endl << "Directed graph d'tor" << endl;
	vector< GraphNode* > ::iterator itr, itrEnd = m_mainVector.end();
#endif

	/*for (itr = m_mainVector.begin(); itr != itrEnd; ++itr)
	{
		delete (*itr);
	}*/
	/*for(auto v : _nodesArr)
	{
		delete v;
	}*/

	delete[] _nodesArr;
	m_mainVector.clear();
}

list<GraphNode*> DirectedGraph::euler()
{
	GraphNode* currentVertex;
	list<GraphNode*> eulerResultList;
	list<GraphNode*> temporaryListToPaste;
	eulerResultList = findCircuit(m_mainVector[0]);
	if (eulerResultList.empty())
	{
		cout << "The graph is not aulerian\n";
		eulerResultList.clear();
		return eulerResultList;
	}

	list<GraphNode*>::iterator eulerIterator = eulerResultList.begin();
	++eulerIterator;

	for (; eulerIterator != eulerResultList.end(); ++eulerIterator)
	{
		if ((*eulerIterator)->getNumberOfAvailableEdges() > 0)
		{
			currentVertex = (*eulerIterator);
			temporaryListToPaste = findCircuit(currentVertex);
			if (temporaryListToPaste.empty())
			{
				cout << "The graph is not aulerian\n";
				eulerResultList.clear();
				return eulerResultList;
			}

			eulerIterator = eulerResultList.insert(eulerIterator, temporaryListToPaste.begin(), --temporaryListToPaste.end());
		}
	}
	if (eulerResultList.back()->getVertexNumber() == eulerResultList.front()->getVertexNumber())
	{
		cout << "The graph is aulerian\n";
		return eulerResultList;
	}
	else
	{
		cout << "The graph is not aulerian\n";
		eulerResultList.clear();
		return eulerResultList;
	}
}
