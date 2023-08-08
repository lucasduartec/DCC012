
#include <iostream>
#include <random>
#include <set>
#include "tools.h"
#include <algorithm>

namespace Siga
{
    namespace Tools
    {

        std::vector<int> get_sorted_int_vector(int n, int max_values)
        {
            const int range_from = 0;
            const int range_to = max_values - 1;
            std::random_device rand_dev;
            std::mt19937 generator(rand_dev());
            std::uniform_int_distribution<int> distr(range_from, range_to);

            std::set<int> s;
            while (s.size() < n)
            {
                s.insert(distr(generator));
            }
            std::vector<int> vec(n);
            std::copy(s.begin(), s.end(), vec.begin());
            // for (int i = 0; i < vec.size(); i++)
            // {
            //     cout << vec[i] << endl;
            // }
            return vec;
        }

        std::vector<int> get_random_int_vector(int n, int max_values)
        {
            std::random_device rand_dev;
            std::mt19937 generator(rand_dev());
            std::vector<int> vec(max_values - 1);

            for (int i = 0; i < max_values; i++)
            {
                vec[i] = i + 1;
            }

            std::shuffle(vec.begin(), vec.end(), generator);

            vec.resize(n);

            // for (int i = 0; i < vec.size(); i++)
            // {
            //     cout << vec[i] << endl;
            // }

            return vec;
        }

        int get_random_int_number(int floor, int ceiling)
        {
            // Cria um gerador de números pseudoaleatórios
            std::random_device rd;
            std::mt19937 generator(rd());

            // Define a faixa do sorteio
            std::uniform_int_distribution<int> distribution(floor, ceiling);

            // Gera um número inteiro aleatório entre 1 e 10000
            int randomNumber = distribution(generator);

            return randomNumber;
        }
    }

}
