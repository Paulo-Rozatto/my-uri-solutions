#include <iostream>

using namespace std;

// --- Edge -- //
class Edge
{
private:
    int originId;
    int targetId;
    Edge *nextEdge;

public:
    Edge(int originId, int targetId);
    ~Edge();

    int getTargetId();
    int getOriginId();
    Edge *getNextEdge();

    void setNextEdge(Edge *edge);
};

Edge::Edge(int originId, int targetId)
{
    this->originId = originId;
    this->targetId = targetId;
    nextEdge = nullptr;
}

Edge::~Edge()
{

    if (this->nextEdge != nullptr)
    {
        delete this->nextEdge;
        this->nextEdge = nullptr;
    }
}

int Edge::getTargetId()
{
    return this->targetId;
}

Edge *Edge::getNextEdge()
{
    return this->nextEdge;
}

void Edge::setNextEdge(Edge *edge)
{
    this->nextEdge = edge;
}

// --- Node --- //
class Node
{
private:
    int id;
    int value;
    Edge *firstEdge;
    Edge *lastEdge;
    unsigned int inDegree;
    unsigned int outDegree;
    Node *nextNode;

public:
    // Constructor
    Node(int id);
    // Destructor
    ~Node();
    // Getters
    Edge *getFirstEdge();
    Edge *getLastEdge();
    int getId();
    int getInDegree();
    int getOutDegree();
    Node *getNextNode();
    // Setters
    void setNextNode(Node *node);
    void setWeight(float weight);
    // Other methods
    void insertEdge(int target_id);
    void incrementOutDegree();
    void decrementOutDegree();
    void incrementInDegree();
    void decrementInDegree();
    bool hasEdge(int targetId);
};

Node::Node(int id)
{
    this->id = id;
    this->firstEdge = nullptr;
    this->lastEdge = nullptr;
    this->nextNode = nullptr;
}

void Node::setNextNode(Node *node)
{
    this->nextNode = node;
}

int Node::getId()
{
    return this->id;
}

Edge *Node::getFirstEdge()
{
    return this->firstEdge;
}

Node *Node::getNextNode()
{
    return this->nextNode;
}

void Node::insertEdge(int targetId)
{
    Edge *e = new Edge(this->id, targetId);

    if (this->firstEdge == nullptr)
    {
        this->firstEdge = this->lastEdge = e;
    }
    else
    {
        this->lastEdge->setNextEdge(e);
        this->lastEdge = e;
    }
}

bool Node::hasEdge(int targetId)
{
    Edge *e = this->firstEdge;

    while (e != nullptr)
    {
        if (e->getTargetId() == targetId)
            return true;

        e = e->getNextEdge();
    }

    return false;
}

// --- Graph --- //
class Graph
{

    //Atributes
private:
    int order;
    int number_edges;
    Node *firstNode;
    Node *lastNode;

public:
    //Constructor
    Graph();
    //Destructor
    ~Graph();
    //Getters
    int getOrder();
    int getNumberEdges();
    bool getDirected();
    bool getWeightedEdge();
    bool getWeightedNode();
    Node *getFirstNode();
    Node *getLastNode();
    //Other methods
    void insertNode(int id);
    void insertEdge(int id, int target_id);
    void removeNode(int id);
    bool searchNode(int id);
    Node *getNode(int id);
    int numberOfMovements();
};

Graph::Graph()
{
    this->order = 0;
    this->number_edges = 0;
    this->firstNode = nullptr;
    this->lastNode = nullptr;
}

void Graph::insertNode(int id)
{
    Node *n = new Node(id);

    if (firstNode == nullptr)
    {
        this->firstNode = this->lastNode = n;
    }
    else
    {
        this->lastNode->setNextNode(n);
        this->lastNode = n;
    }
    this->order += 1;
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

void Graph::insertEdge(int originId, int targetId)
{
    Node *origin = getNode(originId);

    if (!origin->hasEdge(targetId))
    {
        Node *target = getNode(targetId);

        this->number_edges++;
        origin->insertEdge(targetId);
        target->insertEdge(originId);
    }
}

int aux(Graph *g, Node *n, bool visited[])
{
    if (n == nullptr)
    {
        return 0;
    }

    if (visited[n->getId()])
    {
        return 0;
    }

    int cont = 1, nextId;
    Edge *e = n->getFirstEdge();

    visited[n->getId()] = true;

    while (e != nullptr)
    {
        int nextId = e->getTargetId();
        cont = cont + aux(g, g->getNode(nextId), visited);
        e = e->getNextEdge();
    }

    return cont;
}

int Graph::numberOfMovements()
{
    // bool *visited = new bool[order];
    // Node *n = firstNode;
    // int cont = aux(this, this->firstNode, visited);

    // return 2 * cont - 2;
    return 2 * this->number_edges;
}

int main(int argc, char const *argv[])
{
    int entrys, firstNode, numberNodes, numberEdges, nodeId1, nodeId2;
    Graph *g;

    cin >> entrys;

    for (int i = 0; i < entrys; i++)
    {
        cin >> firstNode >> numberNodes >> numberEdges;

        g = new Graph();
        g->insertNode(firstNode);

        for (int j = 0; j < numberEdges; j++)
        {
            cin >> nodeId1 >> nodeId2;

            if (g->getNode(nodeId1) == nullptr)
            {
                g->insertNode(nodeId1);
            }

            if (g->getNode(nodeId2) == nullptr)
            {
                g->insertNode(nodeId2);
            }

            g->insertEdge(nodeId1, nodeId2);
        }

        cout << g->numberOfMovements();
        cout << endl;
    }

    return 0;
}