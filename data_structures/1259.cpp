#include <iostream>

using namespace std;

int partition(int *v, int p, int q)
{
    int pivot = v[(p + q) / 2];
    int i = p, j = q;
    int aux;

    do
    {
        while (v[i] < pivot)
            i++;
        while (v[j] > pivot)
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

void quickSort(int *v, int p, int r)
{
    int q;
    if (p < r)
    {
        q = partition(v, p, r);
        quickSort(v, p, q);
        quickSort(v, q + 1, r);
    }
}

int main(int argc, char const *argv[])
{
    int n, *odd, *even, oidx = 0, eidx = 0, value;

    cin >> n;

    odd = new int[n];
    even = new int[n];

    for(int i = 0; i < n; i++)
    {
        cin >> value;

        if(value % 2 == 0)
        {
            even[eidx] = value;
            eidx++;
        }
        else
        {
            odd[oidx] = value;
            oidx++;
        }
    }
    quickSort(even, 0, eidx - 1);
    quickSort(odd, 0, oidx - 1);

    for(int i = 0; i < eidx; i++)
        cout << even[i] << endl;

    for(int i = oidx - 1; i >= 0; i--)
        cout << odd[i] << endl;

    return 0;
}