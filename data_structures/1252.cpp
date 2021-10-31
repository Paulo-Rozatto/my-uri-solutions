#include <iostream>

using namespace std;

bool isOdd(int v)
{
    return v % 2 != 0;
}

bool isEven(int v)
{
    return v % 2 == 0;
}

class Number
{
public:
    int value;
    int mod;

    Number();
    ~Number(){};

    void copy(Number &n);
};

Number::Number()
{
    value = 0;
    mod = 0;
};

void Number::copy(Number &n)
{
    this->value = n.value;
    this->mod = n.mod;
}

void merge(Number *v, int p, int q, int r)
{
    int i = p, j = q, k = 0;
    Number aux[r - p];

    while (i < q && j < r)
    {
        if (v[i].mod < v[j].mod)
        {
            aux[k] = v[i];
            i++;
        }
        else if (v[i].mod > v[j].mod)
        {
            aux[k] = v[j];
            j++;
        }
        else if (isOdd(v[i].value))
        {
            if (isEven(v[j].value) || v[i].value >= v[j].value)
            {
                aux[k] = v[i];
                i++;
            }
            else
            {
                aux[k] = v[j];
                j++;
            }
        }
        else
        {
            if (isOdd(v[j].value) || v[i].value >= v[j].value)
            {
                aux[k] = v[j];
                j++;
            }
            else
            {
                aux[k] = v[i];
                i++;
            }
        }
        k++;
    }
    while (i < q)
    {
        aux[k] = v[i];
        i++;
        k++;
    }
    while (j < r)
    {
        aux[k] = v[j];
        j++;
        k++;
    }
    for (i = p; i < r; i++)
        v[i] = aux[i - p];
}

void mergeSort(Number *v, int p, int r)
{
    if (p < r - 1)
    {
        int q = (p + r) / 2;
        mergeSort(v, p, q);
        mergeSort(v, q, r);
        merge(v, p, q, r);
    }
}

int main(int argc, char const *argv[])
{
    Number *v;
    int n, m, value;

    do
    {
        cin >> n >> m;
        cout << n << " " << m << endl;

        v = new Number[n];
        for(int i = 0; i < n; i++)
        {
            cin >> v[i].value;
            v[i].mod = v[i].value % m;
        }
        mergeSort(v, 0, n);

        for(int i = 0; i < n; i++)
        {
            cout << v[i].value << endl;
        }

        delete[] v;
    } while (n != 0 || m != 0);
    

    return 0;
}