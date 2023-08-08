#include <iostream>
#include <vector>

namespace Sort
{
    void bubblesort(int *array, int size)
    {
        // BubbleSort
        for (int i = size - 1; i > 0; i--)
        {
            for (int j = 0; j < i; j++)
            {

                if (array[j] > array[j + 1])
                {

                    int aux = array[j + 1];
                    array[j + 1] = array[j];
                    array[j] = aux;
                }
            }
        }
    }
}