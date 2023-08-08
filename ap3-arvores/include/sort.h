#ifndef SORT_H
#define SORT_H

#include "config.h"
#include "perf.h"
#include <vector>
using namespace Perf;

namespace Sort 
{

    template<typename T, class Compare >
    void InsertionSort(std::vector<T> &v, Compare cmp, Performance& perf)
    {   
#ifdef ENABLE_PERF
        perf.get_timer().start();
#endif
        int i, j;
        T key;
        for (i = 1; i < v.size(); i++) {
            key = v[i];
            j = i - 1;
#ifdef ENABLE_PERF
            perf.get_counter().increment_comparisons();
#endif
            while (j >= 0 && cmp(key, v[j])) {
                v[j + 1] = v[j];
                j--;
#ifdef ENABLE_PERF
                perf.get_counter().increment_comparisons();
                perf.get_counter().increment_swaps();
#endif
            }
            v[j + 1] = key;
#ifdef ENABLE_PERF
            perf.get_counter().increment_swaps();
#endif
        }
        perf.get_timer().stop();
    }

    // Implementação do algoritmos de ordenação basicos O(n^2)
    // Escolha uns dos métodos abaixo para implementar
    //  - BubbleSort
    //  - SelectionSort
    //  - InsertionSort
    template<typename T, class Compare >
    void BasicSort(std::vector<T> &v, Compare cmp)
    {
        Perf::Performance perf;
        InsertionSort(v, cmp, perf);
#ifdef ENABLE_PERF
        std::cout << "BasicSort (InsertionSort): " << std::endl;
        std::cout << "   Tamanho    : " << v.size() << std::endl;
        std::cout << "   Comparacoes: " << perf.get_counter().get_comparisons() << std::endl;
        std::cout << "   Trocas     : " << perf.get_counter().get_swaps() << std::endl;
        std::cout << "   Tempo de execução : " << perf.get_timer().elapsed_time() << " segundos" << std::endl;    
#endif 
    }

    template<typename T, class Compare >
    void Merge(std::vector<T> &v, int low, int mid, int hight, Compare cmp, Performance &perf)
    {
        int i, j, k;
        int n1 = mid - low + 1;
        int n2 = hight - mid;

        std::vector<T> L(n1), R(n2);

        for (i = 0; i < n1; i++) {
            L[i] = v[low + i];
        }
        for (j = 0; j < n2; j++) {
            R[j] = v[mid + 1 + j];
        }

        i = 0;
        j = 0;
        k = low;

        while (i < n1 && j < n2) {
#ifdef ENABLE_PERF
            perf.get_counter().increment_comparisons();
#endif
            if (cmp(L[i], R[j])) {
                v[k] = L[i];
                i++;
            } else {
                v[k] = R[j];
                j++;
            }
#ifdef ENABLE_PERF
            perf.get_counter().increment_swaps();   
#endif  
            k++;
        }

        while (i < n1) {
            v[k] = L[i];
            i++;
            k++;
#ifdef ENABLE_PERF
            perf.get_counter().increment_swaps();   
#endif  
        }

        while (j < n2) {
            v[k] = R[j];
            j++;
            k++;
#ifdef ENABLE_PERF
            perf.get_counter().increment_swaps();
#endif
        }
    }

    template<typename T, class Compare >
    void MergeSort(std::vector<T> &v, int low, int hight, Compare cmp, Performance &perf)
    {
        if (low < hight) {
            int mid = (low + hight) / 2;
            MergeSort(v, low, mid, cmp, perf);
            MergeSort(v, mid + 1, hight, cmp, perf);
            Merge(v, low, mid, hight, cmp, perf);
        }
    }


    // Implementação algoritmo de ordenação MergeSort
    template<typename T, class Compare >
    void MergeSort(std::vector<T> &v, Compare cmp)
    {
        Perf::Performance perf;
        MergeSort(v, 0, v.size() - 1, cmp, perf);
#ifdef ENABLE_PERF
        std::cout << "MergeSort: " << std::endl;
        std::cout << "   Tamanho    : " << v.size() << std::endl;
        std::cout << "   Comparacoes: " << perf.get_counter().get_comparisons() << std::endl;
        std::cout << "   Trocas     : " << perf.get_counter().get_swaps() << std::endl;
        std::cout << "   Tempo de execução : " << perf.get_timer().elapsed_time() << " segundos" << std::endl;
#endif

    }

    template<typename T, class Compare >
    int Partition(std::vector<T> &v, Compare cmp, Performance &perf)
    {

        return 0;
    }

    template<typename T, class Compare >
    void QuickSort(std::vector<T> &v, int low, int hight, Compare cmp, Performance &perf)
    {

    }

    // TODO: Implementação algoritmo de ordenação QuickSort
    template<typename T, class Compare >
    void QuickSort(std::vector<T> &v, Compare cmp)
    {



    }

    
    //  TODO: Implemente algoritmo de ordenação HeapSort
    template<typename T, class Compare >
    void HeapSort(std::vector<T> &v, Compare cmp)
    {
      
    }

    // TODO: Pesquise por algoritmos de ordenação eficientes não vistos em sala de aula.
    //       Implemente um deles.
    template<typename T, class Compare >
    void MySort(std::vector<T> &v, Compare cmp)
    {
   
    }

    //Observaçã0:
     // Compare cmp é uma função que recebe dois elementos do tipo T e retorna um bool.
     // Exemplo de como declarar uma função do tipo Compare:
     /*
       struct {
         bool operator() (T &a, T &b) const
            {
                return a < b;
            }
        } cmp;
    */
     // Se cmp(a, b) retorna true, então a é menor que b. 
     // veja nos arquivos de teste como usar essa função.

     // Funçoes auxiliares deve ser implementadas neste arquivo.
}

#endif /* SORT_H */
