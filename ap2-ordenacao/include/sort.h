#ifndef SORT_H
#define SORT_H

#include <vector>
#include "perf.h"

namespace Sort
{

    // TODO: Implemente do algoritmos de ordenação basicos O(n^2)
    // Escolha uns dos métodos abaixo para implementar
    //   - BubbleSort
    //  - SelectionSort
    //  - InsertionSort
    template <typename T, class Compare>
    void BasicSort(std::vector<T> &v, Compare cmp, Perf::PerformanceCounter &counter)
    {
        // BubbleSort
        for (int i = v.size() - 1; i > 0; i--)
        {
            for (int j = 0; j < i; j++)
            {
                counter.increment_comparisons();

                if (cmp(v[j + 1], v[j]))
                {
                    counter.increment_swaps();

                    T aux = v[j + 1];
                    v[j + 1] = v[j];
                    v[j] = aux;
                }
            }
        }
    }

    // TODO: Implemente algoritmo de ordenação MergeSort
    template <typename T, class Compare>
    void merge(std::vector<T> &v, Compare cmp, int p, int q, int r, Perf::PerformanceCounter &counter)
    {
        int i = p;
        int j = q;
        int k = 0;

        std::vector<T> aux(r - p);

        while ((i < q) && (j < r))
        {

            counter.increment_comparisons();

            if (cmp(v[i], v[j]))
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
        {

            counter.increment_comparisons();

            counter.increment_swaps();

            v[i] = aux[i - p];
        }
    }

    template <typename T, class Compare>
    void auxMergeSort(std::vector<T> &v, Compare cmp, int p, int r, Perf::PerformanceCounter &counter)
    {
        if (p < r - 1)
        {
            int q = (p + r) / 2;
            auxMergeSort(v, cmp, p, q, counter);
            auxMergeSort(v, cmp, q, r, counter);
            merge(v, cmp, p, q, r, counter);
        }
    }

    template <typename T, class Compare>
    void MergeSort(std::vector<T> &v, Compare cmp, Perf::PerformanceCounter &counter)
    {
        auxMergeSort(v, cmp, 0, v.size(), counter);
    }

    // TODO: Implemente algoritmo de ordenação QuickSort

    template <typename T, class Compare>
    int partition(std::vector<T> &v, Compare cmp, int low, int high, Perf::PerformanceCounter &counter)
    {
        T pivot = v[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++)
        {
            counter.increment_comparisons();

            if (cmp(v[j], pivot))
            {
                i++;
                std::swap(v[i], v[j]);
                counter.increment_swaps();
            }
        }
        std::swap(v[i + 1], v[high]);
        counter.increment_swaps();
        return i + 1;
    }

    template <typename T, class Compare>
    void auxQuickSort(std::vector<T> &v, Compare cmp, int low, int high, Perf::PerformanceCounter &counter)
    {
        if (low >= 0 && high >= 0 && low < high)
        {
            int p = partition(v, cmp, low, high, counter);
            auxQuickSort(v, cmp, low, p - 1, counter);
            auxQuickSort(v, cmp, p + 1, high, counter);
        }
    }

    template <typename T, class Compare>
    void QuickSort(std::vector<T> &v, Compare cmp, Perf::PerformanceCounter &counter)
    {
        auxQuickSort(v, cmp, 0, v.size() - 1, counter);
    }

    //  TODO: Implemente algoritmo de ordenação HeapSort
    template <typename T, class Compare>
    void MaxHeapify(std::vector<T> &v, Compare cmp, int i, int n, Perf::PerformanceCounter &counter)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        int m = i;

        if (left <= n && cmp(v[left], v[i]))
        {
            counter.increment_comparisons();
            m = left;
        }

        else
        {
            m = i;
        }

        if (right <= n && cmp(v[right], v[m]))
        {
            counter.increment_comparisons();
            m = right;
        }

        if (m != i)
        {
            std::swap(v[i], v[m]);
            counter.increment_swaps();
            MaxHeapify(v, cmp, m, n, counter);
        }
    }

    template <typename T, class Compare>
    void BuildMaxHeap(std::vector<T> &v, Compare cmp, Perf::PerformanceCounter &counter)
    {
        int n = v.size();

        for (int i = n / 2; i >= 0; i--)
        {
            MaxHeapify(v, cmp, i, n - 1, counter);
        }
    }

    template <typename T, class Compare>
    void HeapSort(std::vector<T> &v, Compare cmp, Perf::PerformanceCounter &counter)
    {
        BuildMaxHeap(v, cmp, counter);
        for (int i = v.size() - 1; i >= 1; i--)
        {
            std::swap(v[0], v[i]);
            counter.increment_swaps();
            MaxHeapify(v, cmp, 0, i - 1, counter);
        }
    }

    // TODO: Pesquise por algoritmos de ordenação eficientes não vistos em sala de aula.
    //       Implemente um deles.

    // Comb Sort

    template <typename T, class Compare>
    void combSort(std::vector<T> &v, Compare cmp, Perf::PerformanceCounter &counter)
    {

        int n = v.size();

        int gap = n;
        bool swapped = true;

        while (gap != 1 || swapped)
        {
            gap = (gap * 10) / 13;
            if (gap < 1)
                gap = 1;

            swapped = false;

            for (int i = 0; i < n - gap; i++)
            {

                counter.increment_comparisons();

                if (cmp(v[i + gap], v[i]))
                {
                    swap(v[i], v[i + gap]);
                    counter.increment_swaps();
                    swapped = true;
                }
            }
        }
    }

    template <typename T, class Compare>
    void MySort(std::vector<T> &v, Compare cmp, Perf::PerformanceCounter &counter)
    {
        combSort(v, cmp, counter);
    }

    // Observaçã0:
    //  Compare cmp é uma função que recebe dois elementos do tipo T e retorna um bool.
    //  Exemplo de como declarar uma função do tipo Compare:

    // struct
    // {
    //     bool operator()(T &a, T &b) const
    //     {
    //         return a < b;
    //     }
    // } cmp;

    // Se cmp(a, b) retorna true, então a é menor que b.
    // veja nos arquivos de teste como usar essa função.

    // Funçoes auxiliares deve ser implementadas neste arquivo.
}

#endif /* SORT_H */
