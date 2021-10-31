void merge(int *v, int p, int q, int r)
{
    int i = p, j = q, k = 0;
    int aux[r - p];

    while (i < q && j < r)
    {
        if (v[i] < v[j])
        {
            aux[k] = v[i];
            i++;
        }
        else
        {
            aux[k] = v[j];
            j++;
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


void mergeSort(int *v, int p, int r)
{
    if (p < r - 1)
    {
        int q = (p + r) / 2;
        mergeSort(v, p, q);
        mergeSort(v, q, r);
        merge(v, p, q, r);
    }
}