#include "Graph.h"
#include "Node.h"
#include "Edge.h"
#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
#include <list>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <float.h>
#include <iomanip>
#include <algorithm>
#include <string.h>
#include <vector>
#include <iomanip>
#include <climits>
using namespace std;

/**************************************************************************************************
 * Defining the Graph's methods
**************************************************************************************************/

// Constructor
Graph::Graph(int order, bool directed, bool weighted_edge, bool weighted_node)
{

    this->order = order;
    this->directed = directed;
    this->weighted_edge = weighted_edge;
    this->weighted_node = weighted_node;
    this->firstNode = this->lastNode = nullptr;
    this->has_clusters = false;
    this->number_edges = 0;
    this->node_cont = 0;
    adjacencia = new list<int>[order + 1];
}

Graph::Graph(int order, bool directed, bool weighted_edge, bool weighted_node, bool has_clusters)
{

    this->order = order;
    this->directed = directed;
    this->weighted_edge = weighted_edge;
    this->weighted_node = weighted_node;
    this->firstNode = this->lastNode = nullptr;
    this->has_clusters = has_clusters;
    this->number_edges = 0;
    this->node_cont = 0;
    adjacencia = new list<int>;
}
vector<Edge> edges; //vetor das arestas

// Destructor
Graph::~Graph()
{

    Node *next_node = this->firstNode;

    while (next_node != nullptr)
    {

        next_node->removeAllEdges();
        Node *aux_node = next_node->getNextNode();
        delete next_node;
        next_node = aux_node;
    }
}

// Getters
int Graph::getOrder()
{
    return this->order;
}
int Graph::getNumberEdges()
{
    return this->number_edges;
}
//Function that verifies if the graph is directed
bool Graph::getDirected()
{

    return this->directed;
}
//Function that verifies if the graph is weighted at the edges
bool Graph::getWeightedEdge()
{

    return this->weighted_edge;
}

//Function that verifies if the graph is weighted at the nodes
bool Graph::getWeightedNode()
{

    return this->weighted_node;
}

Node *Graph::getFirstNode()
{

    return this->firstNode;
}

Node *Graph::getLastNode()
{

    return this->lastNode;
}

// Other methods
/*
    The outdegree attribute of nodes is used as a counter for the number of edges in the graph.
    This allows the correct updating of the numbers of edges in the graph being directed or not.
*/
void Graph::insertNode(int id)
{
    Node *node = new Node(id);

    if (firstNode == nullptr)
    {
        firstNode = lastNode = node;
    }
    else
    {
        lastNode->setNextNode(node);
        lastNode = node;
    }

    node_cont++;

    if (node_cont > order)
    {
        order++;
    }
}

void Graph::insertNode(int id, int clusterId)
{
    Node *node = new Node(id, clusterId);

    if (firstNode == nullptr)
    {
        firstNode = lastNode = node;
    }
    else
    {
        lastNode->setNextNode(node);
        lastNode = node;
    }

    node_cont++;

    if (node_cont > order)
    {
        order++;
    }
}

void Graph::insertEdge(int id, int target_id, float weight)
{
    Edge edge(id, target_id, weight); //cria aresta com as configura��es dadas
    edges.push_back(edge);            // preenche o vetor de arestas

    if (!has_clusters)
    {
        // a lista de adjacencia e montada adicionando o vertice alvo no array referente ao vertice origem
        adjacencia[id].push_back(target_id);
    }

    Node *node, *target_node;
    node = getNode(id);

    // try to get target_node only if node exists
    if (node != nullptr)
    {
        target_node = getNode(target_id);

        // inserts edge only if target_node also exists
        if (target_node != nullptr)
        {
            node->insertEdge(target_id, weight);

            if (directed)
            {
                node->incrementOutDegree();
                target_node->incrementInDegree();
            }
            else
            {
                node->incrementInDegree();
                target_node->insertEdge(id, weight);
                target_node->incrementOutDegree();
            }
        }
    }
}

Cluster *Graph::insertCluster(int id)
{
    Cluster *c = new Cluster(id);
    if (first_cluster == nullptr)
    {
        first_cluster = c;
    }
    else
    {
        c->setNextCluster(first_cluster);
        first_cluster = c;
    }
    number_clusters++;

    return c;
}

void Graph::removeNode(int id)
{
}

bool Graph::searchNode(int id)
{
    Node *node = firstNode;

    while (node != nullptr)
    {
        if (node->getId() == id)
        {
            return true;
        }

        node = node->getNextNode();
    }

    return false;
}

Node *Graph::getNode(int id)
{
    Node *node = firstNode;

    while (node != nullptr && node->getId() != id)
    {
        node = node->getNextNode();
    }

    return node;
}