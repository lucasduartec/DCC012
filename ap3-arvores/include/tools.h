#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>
#include <chrono>
#include <vector>

#include "estudante.h"

// Gerar valores aletórios de inteiros entre 0 e n-1.

namespace Siga
{

    namespace Tools
    {

        std::vector<int> get_sorted_int_vector(int n, int max_values);
        std::vector<int> get_random_int_vector(int n, int max_values);
        int get_random_int_number(int floor, int ceiling);

        template <typename T, class Compare>
        bool is_sorted(std::vector<T> &data, Compare cmp)
        {
            for (int i = 0; i < data.size() - 1; i++)
            {
                // Se o elemento é menor que o anterior, então o vetor não está ordenado
                if (cmp(data[i + 1], data[i]))
                {
                    return false;
                }
            }
            return true;
        }

        template <typename T>
        void print_vector(std::vector<T> &data)
        {
            for (int i = 0; i < data.size(); i++)
            {
                std::cout << data[i] << endl;
            }
        }

        template <typename T, class Compare>
        bool compare_vector(std::vector<T> &data1, std::vector<Estudante> &data2, Compare cmp_equal)
        {
            if (data1.size() != data2.size())
            {
                return false;
            }
            for (int i = 0; i < data1.size(); i++)
            {
                if (cmp_equal(data1[i], data2[i]))
                {
                    return false;
                }
            }
            return true;
        }

    } // end namespace tools

}

#endif /* TOOLS_H */
