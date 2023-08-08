#include <iostream>
#include "sort.h"
#include <random>

int main()
{

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 15000);

    int sizes[5] = {100, 500, 1000, 5000, 10000};

    for (int i = 0; i < 5; i++)
    {
        int array[sizes[i]];

        for (int n = 0; n < sizes[i]; n++)
        {
            array[n] = dist(gen);
        }

        Sort::bubblesort(array, sizes[i]);
    }
}