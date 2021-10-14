#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node *left;
    Node *right;

    Node(int value)
    {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
    ~Node()
    {
        if (left != nullptr)
            delete left;
        if (right != nullptr)
            delete right;
    }

    void insert(int value)
    {
        if (value < this->value)
        {
            if (left == nullptr)
            {
                this->left = new Node(value);
            }
            else
            {
                this->left->insert(value);
            }
        }
        else
        {
            if (right == nullptr)
            {
                this->right = new Node(value);
            }
            else
            {
                this->right->insert(value);
            }
        }
    }

    void breadth(int size)
    {
        Node* queue[size];
        int next = 1;

        queue[0] = this;

        for(int i = 0; i < next && i < size; i++) {
            if(i != 0) cout << " ";
            cout << queue[i]->value;

            if(queue[i]->left != nullptr) {
                queue[next] = queue[i]->left;
                next++;
            }

            if(queue[i]->right != nullptr) {
                queue[next] = queue[i]->right;
                next++;
            }

        }
        cout << endl << endl;
    }
};

int main(int argc, char const *argv[])
{
    int cases, size, value;
    Node *root;

    cin >> cases;

    for(int i = 0; i < cases; i++) {
        cin >> size;

        cin >> value;

        root = new Node(value);

        for(int j = 1; j < size; j++) {
            cin >> value;
            root->insert(value);
        }

        cout << "Case " << (i + 1) << ":" << endl;
        root->breadth(size);
        delete root;
    }

    return 0;
}