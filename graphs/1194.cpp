#include <iostream>
#include <string>

using namespace std;

string posfix(string pre, string in)
{
    if (pre.length() == 0)
        return "";

    char root = pre[0];
    string pos = "", nextPre, nextIn;

    // left
    nextIn = in.substr(0, in.find(root));
    nextPre = pre.substr(1);

    if (nextIn.length() > 1)
    {
        pos += posfix(nextPre, nextIn);
    }
    else
    {
        pos += nextIn;
    }

    // right
    nextPre = pre.substr(pre.find(root) + nextIn.length() + 1);
    nextIn = in.substr(in.find(root) + 1);

    if (nextIn.length() > 1)
    {
        pos += posfix(nextPre, nextIn);
    }
    else
    {
        pos += nextIn;
    }

    pos += root;

    return pos;
}

int main(int argc, char const *argv[])
{
    int entrys, treeSize;
    string pre, in, pos;
    char root;

    cin >> entrys;

    for (int i = 0; i < entrys; i++)
    {
        cin >> treeSize >> pre >> in;

        cout << posfix(pre, in) << endl;
    }
    return 0;
}