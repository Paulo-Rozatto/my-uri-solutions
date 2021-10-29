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