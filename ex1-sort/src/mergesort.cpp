#include <iostream>
#include <vector>

namespace Sort
{
    void merge(int *array, int p, int q, int r)
    {
        int i = p;
        int j = q;
        int k = 0;

        std::vector<int> aux(r - p);

        while ((i < q) && (j < r))
        {

            if (array[i] < array[j])
            {
                aux[k] = array[i];
                i++;
            }
            else
            {
                aux[k] = array[j];
                j++;
            }
            k++;
        }

        while (i < q)
        {
            aux[k] = array[i];
            i++;
            k++;
        }
        while (j < r)
        {
            aux[k] = array[j];
            j++;
            k++;
        }

        for (i = p; i < r; i++)
        {

            array[i] = aux[i - p];
        }
    }

    void auxMergeSort(int *array, int p, int r)
    {
        if (p < r - 1)
        {
            int q = (p + r) / 2;
            auxMergeSort(array, p, q);
            auxMergeSort(array, q, r);
            merge(array, p, q, r);
        }
    }

    void mergesort(int *array, int size)
    {
        auxMergeSort(array, 0, size);
    }
}