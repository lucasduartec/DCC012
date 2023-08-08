#include <iostream>
#include <chrono>
#include <fstream>

using namespace std;

#include "string_matching.h"

int main()
{
    std::cout << "===============================" << endl;
    std::cout << "||   Medição de desempenho   ||" << endl;
    std::cout << "===============================" << endl;

    std::cout << endl
              << "Escolha o método para análise:" << endl;

    std::cout << "[1] Força Bruta" << endl;
    std::cout << "[2] Knuth-Morris-Pratt" << endl;
    std::cout << "[3] Boyer-Moore" << endl;
    std::cout << "[4] Rabin-Karp" << endl;

    int metodo = validateInput(4);

    std::cout << endl;

    auto start = std::chrono::high_resolution_clock::now();

    StringMatching(metodo);

    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

    auto time = duration * 1e6;

    std::cout << "Tempo de execução: " << time << " milissegundos" << endl;

    return 0;
}