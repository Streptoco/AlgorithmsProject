#include "Graph.h"

DirectedGraph::DirectedGraph(int i_NumberOfVertex, int i_NumberOfEdges)
{
	m_NumberOfVertex = i_NumberOfVertex;
	m_NumberOfEdges = i_NumberOfEdges;
	FREE GraphNode* nodeArr = new GraphNode[m_NumberOfVertex]; // in order to have control over the allocated nodes, we save them in a dynamic array, later to be deleted
	for (int i = 0; i < i_NumberOfVertex; i++)
	{
		nodeArr[i].setVertexNumber(i + 1);
		m_mainVector.push_back(&nodeArr[i]); // the nodes are then added to the main vertex list, each to have a residency list
	}
	_nodesArr = nodeArr;
}

void DirectedGraph::addEdgeToGraph(short i_currentHoldingNumber, short i_vertexToConnect)
{
	insertEdgeToGraph(i_currentHoldingNumber, i_vertexToConnect); // call the method to insert the edge into the graph
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
	resultList.push_back(currentVertex); // start with the first vertex passed to the method
	while (currentVertex->getNumberOfAvailableEdges() > 0) // condition: while the current vertex still has "unused" edges
	{
		secondaryListItr = currentVertex->getNextAvailableVertexInList();
		if (*secondaryListItr == nullptr)
		{
			break;
		}
		if ((*secondaryListItr)->isVisited() == false)
		{

			(*secondaryListItr)->visitVertex(); // mark vertex as visited
			UndirectedGraph* unDirectedGraph = dynamic_cast<UndirectedGraph*>(this); // check during run-time if the graph is un-directed
			if (unDirectedGraph != nullptr)
			{
				unDirectedGraph->markTheOppositeEdge(currentVertex, (*secondaryListItr)->getMutualPointerForMainVertex()); // if so, mark both ends
			}

			currentVertex->substractNumberOfAvailableEdges(); // substract by 1 the number of available edges
			resultList.push_back((*secondaryListItr)->getMutualPointerForMainVertex());
			currentVertex = (*secondaryListItr)->getMutualPointerForMainVertex();
		}
		if (i_startingVertex == currentVertex)
		{
			return resultList;
		}
	}
	if (resultList.back()->getVertexNumber() == resultList.front()->getVertexNumber()) // if we're in a circle
	{
		return resultList;
	}
	else
	{
		resultList.clear(); // delete the list to return an empty one
		return resultList;
	}
}

void DirectedGraph::insertEdgeToGraph(short i_currentHoldingNumber, short i_vertexToConnect)
{
	GraphNode* getMutualPointerForVertex = m_mainVector[i_vertexToConnect - 1]; // create a vertex for the main vertex vector
	m_mainVector[i_currentHoldingNumber - 1]->addVertexToSecondaryList(i_vertexToConnect, getMutualPointerForVertex); // add the second parameter to the first one's residency list
	m_mainVector[i_currentHoldingNumber - 1]->setNumberOfAvailableEdges(); // increment by 1 the number of available edges

}

DirectedGraph::~DirectedGraph()
{
#ifdef DEBUG
	cout << endl << "Directed graph d'tor" << endl;
	vector< GraphNode* > ::iterator itr, itrEnd = m_mainVector.end();
#endif
	delete[] _nodesArr;
	m_mainVector.clear();
}

list<GraphNode*> DirectedGraph::euler()
{
	GraphNode* currentVertex;
	list<GraphNode*> eulerResultList;
	list<GraphNode*> temporaryListToPaste;
	eulerResultList = findCircuit(m_mainVector[0]);
	if (eulerResultList.empty()) // this case happens when we haven't found a circle in the passed vertex
	{
		cout << "The graph is not aulerian\n";
		eulerResultList.clear();
		return eulerResultList;
	}

	list<GraphNode*>::iterator eulerIterator = eulerResultList.begin();
	++eulerIterator; // advance, so we could get the next vertex in the list

	for (; eulerIterator != eulerResultList.end(); ++eulerIterator)
	{
		if ((*eulerIterator)->getNumberOfAvailableEdges() > 0)
		{
			currentVertex = (*eulerIterator);
			temporaryListToPaste = findCircuit(currentVertex); // find the circle from the next vertex
			if (temporaryListToPaste.empty())
			{
				cout << "The graph is not aulerian\n";
				eulerResultList.clear();
				return eulerResultList;
			}

			eulerIterator = eulerResultList.insert(eulerIterator, temporaryListToPaste.begin(), --temporaryListToPaste.end()); // paste the temporary list into the main one
		}
	}
	if (eulerResultList.back()->getVertexNumber() == eulerResultList.front()->getVertexNumber()) // if the outcome of the list is a circle
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
