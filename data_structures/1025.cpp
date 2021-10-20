#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    int leftCount;
    Node *left;
    Node *right;

    Node(int value)
    {
        this->value = value;
        leftCount = 0;
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
            this->leftCount += 1;

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

    int position(int value)
    {
        int count = 0;
        Node *n = find(this, value, &count);

        if (n == nullptr)
            return 0;
        return count + n->leftCount + 1;
    }

    Node *find(Node *n, int value, int *count)
    {
        if (n == nullptr)
            return nullptr;

        if (n->value == value)
            return n;
        if (value < n->value)
            return find(n->left, value, count);

        *count += n->leftCount + 1;
        return find(n->right, value, count);
    }
};

int main(int argc, char const *argv[])
{
    int n, q, value, caseCont = 1, r;
    Node *root;

    cin >> n >> q;
    while (n != 0 || q != 0)
    {
        cin >> value;
        root = new Node(value);

        for (int i = 1; i < n; i++)
        {
            cin >> value;
            root->insert(value);
        }

        cout << "CASE# " << caseCont << ":" << endl;
        for (int i = 0; i < q; i++)
        {
            cin >> value;
            r = root->position(value);
            cout << value << " ";

            if (r == 0)
                cout << "not found";
            else
                cout << "found at " << r;
            cout << endl;
        }

        // delete root;
        caseCont++;
        cin >> n >> q;
    }

    return 0;
}