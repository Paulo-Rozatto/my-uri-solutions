#include <iostream>

using namespace std;

// Arvore binaria de busca

class Node
{
public:
    char value;
    Node *left;
    Node *right;

    Node(char value);
    ~Node();
    void insert(char value);
};

Node::Node(char value)
{
    this->value = value;
    this->left = nullptr;
    this->right = nullptr;
}

Node::~Node()
{
    if (this->left != nullptr)
        delete this->left;
    if (this->right != nullptr)
        delete this->left;
}

void Node::insert(char value)
{
    if (value < this->value)
    {
        if (left == nullptr)
            this->left = new Node(value);
        else
            this->left->insert(value);
    }
    else
    {
        if (right == nullptr)
            this->right = new Node(value);
        else
            this->right->insert(value);
    }
}

class Tree
{
public:
    Node *root;

    Tree();
    ~Tree();
    void insert(char value);
    void search(char value);
    void prefix();
    void infix();
    void posfix();

    void preHelper(Node *node, int i);
    void inHelper(Node *node, string *v);
    void posHelper(Node *node, string *v);
};

Tree::Tree()
{
    this->root = nullptr;
}
Tree::~Tree()
{
    delete root;
}

void Tree::insert(char value)
{
    if (root != nullptr)
        root->insert(value);
    else
        this->root = new Node(value);
}

void Tree::prefix()
{
    preHelper(root, 0);
    cout << endl;
}

void Tree::preHelper(Node *node, int i)
{
    if (node == nullptr)
        return;

    if (i > 0)
        cout << " ";

    cout << node->value;

    preHelper(node->left, i + 1);
    preHelper(node->right, i + 1);
}

void Tree::infix()
{
    string v;
    inHelper(root, &v);
    cout << v.substr(0, v.length() - 1) << endl;
}

void Tree::inHelper(Node *node, string *v)
{
    if (node == nullptr)
        return;

    inHelper(node->left, v);
    *v += node->value;
    *v += " ";
    inHelper(node->right, v);
}

void Tree::posfix()
{
    string v;
    posHelper(root, &v);
    cout << v.substr(0, v.length() - 1) << endl;
}

void Tree::posHelper(Node *node, string *v)
{
    if (node == nullptr)
        return;

    posHelper(node->left, v);
    posHelper(node->right, v);
    *v += node->value;
    *v += " ";
}

void Tree::search(char value)
{
    bool isValue = false;
    Node *n = root;

    while (n != nullptr)
    {
        if (n->value == value)
        {
            isValue = true;
            break;
        }

        if (value < n->value)
            n = n->left;
        else
            n = n->right;
    }

    if(isValue)
        cout << value << " existe" << endl;
    else 
        cout << value << " nao existe" << endl;
    
}

int main(int argc, char const *argv[])
{
    string command;
    char value;
    Tree *tree = new Tree();

    while (cin >> command)
    {
        if (command.length() == 1)
        {
            cin >> value;

            if (command[0] == 'I')
                tree->insert(value);
            else if(command[0] == 'P')
                tree->search(value);
        }
        else
        {
            if (command == "PREFIXA")
                tree->prefix();
            else if (command == "INFIXA")
                tree->infix();
            else
                tree->posfix();
        }
    }

    return 0;
}