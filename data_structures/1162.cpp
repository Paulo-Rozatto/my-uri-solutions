#include <iostream>

using namespace std;

int bubbleSort(int v[], int length)
{
    bool hadSwap;
    int cont = 0, aux;

    for (int i = 0; i < length; i++)
    {
        hadSwap = false;
        for (int j = 0; j < length - i - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
                cont++;
                hadSwap = true;
            }
        }
        if (!hadSwap)
            break;
    }

    return cont;
}

int main(int argc, char const *argv[])
{
    int n, size, swaps;
    int *v;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> size;

        v = new int[size];
        for (int j = 0; j < size; j++)
        {
            cin >> v[j];
        }
        swaps = bubbleSort(v, size);

        cout << "Optimal train swapping takes " << swaps << " swaps." << endl;

        delete[] v;
    }
    return 0;
}