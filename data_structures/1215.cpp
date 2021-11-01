#include <iostream>

using namespace std;

// smaller
bool sm(string &s1, string &s2)
{
    int i = 0, j = 0;
    int l1 = s1.length(), l2 = s2.length();

    while (i < l1 && i < l2)
    {
        if (s1[i] < s2[i])
            return true;
        if (s1[i] > s2[i])
            return false;
        i++;
    }
    return i == l1 && i != l2;
}

// greater
bool gt(string &s1, string &s2)
{
    int i = 0, j = 0;
    int l1 = s1.length(), l2 = s2.length();

    while (i < l1 && i < l2)
    {
        if (s1[i] > s2[i])
            return true;
        if (s1[i] < s2[i])
            return false;
        i++;
    }
    return i == l2 && i != l1;
}

int partition(string *v, int p, int q)
{
    string pivot = v[(p + q) / 2];
    int i = p, j = q;
    string aux;

    do
    {
        // while (v[i] < pivot)
        while (sm(v[i], pivot))
            i++;
        while (gt(v[j], pivot))
            j--;

        if (i <= j)
        {
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;

            if (i < q)
                i++;
            if (j > p)
                j--;
        }

    } while (i <= j);
    return j;
}

void quickSort(string *v, int p, int r)
{
    int q;
    if (p < r)
    {
        q = partition(v, p, r);
        quickSort(v, p, q);
        quickSort(v, q + 1, r);
    }
}

class Node
{
public:
    string value;
    Node *left;
    Node *right;

    Node()
    {
        this->value = "";
        left = nullptr;
        right = nullptr;
    }

    Node(string &value)
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

    void insert(string &value)
    {
        if (this->value == "")
        {
            this->value = value;
        }
        else if (sm(value, this->value))
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
        else if (gt(value, this->value))
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

    void infix()
    {
        helper(this);
    }

    void helper(Node *node)
    {
        if (node == nullptr)
            return;

        helper(node->left);
        cout << node->value << endl;
        helper(node->right);
    }
};

bool toLowercase(string &s, Node *t)
{
    string aux;
    int init = 0, i;
    bool findInit = false;

    for (i = 0; i < s.length(); i++)
    {
        aux = s[i];
        if (s[i] >= 65 && s[i] <= 90)
        {
            s[i] += 32;
            if (findInit)
            {
                init = i;
                findInit = false;
            }
        }
        else if ((s[i] < 97 || s[i] > 122))
        {
            if (!findInit)
            {
                if (i > 0)
                {
                    string str = s.substr(init, i - init);
                    t->insert(str);
                }
                findInit = true;
            }
        }
        else
        {
            if (findInit)
            {
                init = i;
                findInit = false;
            }
        }
    }
    if (!findInit)
    {
        string str = s.substr(init);
        t->insert(str);
    }

    return true;
}

int main(int argc, char const *argv[])
{
    // cout << 'a' << " " << 'z' << endl
    //      << 'A' << " " << 'Z' << endl;
    Node *tree;
    string s;

    tree = new Node();

    // cout << toLowercase(s, tree) << " " << s << endl;
    while (cin >> s)
    {
        toLowercase(s, tree);
    }

    tree->infix();

    return 0;
}