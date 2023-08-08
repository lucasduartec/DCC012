#include "siga.h"
#include "sort.h"
#include "tools.h"
#include "perf.h"
#include "estudante.h"
#include <algorithm>

struct
{
     bool operator()(int &a, int &b) const
     {
          return a < b;
     }
} cmp;

struct
{
     bool operator()(Siga::Estudante &a, Siga::Estudante &b) const
     {
          return a.ObterMatricula() < b.ObterMatricula();
     }
} cmpEstudante;

// Ordem descendente de matrícula
struct
{
     bool operator()(Siga::Estudante &a, Siga::Estudante &b) const
     {
          return a.ObterMatricula() > b.ObterMatricula();
     }
} cmpMatricula;

int main(int argc, const char *argv[])
{
     // TODO: Implementar teste de performance considerando aleatórios
     // Chame as rotinas de ordenação:
     //  BasicSort, MergeSort, QuickSort, HeapSort, MySort
     // e meça tempo de execução, número de comparações e trocas.
     // Use diferentes tamanhos de vetores para testar.
     // Verifique o desempenho usando
     //    (1) vetores de inteiros de diferentes tamanhos
     //    (2) vetores de estudantes de diferentes tamanhos
     // Observe que a base de dados tem tamanho máximo de 5000 estudantes.
     // Analise o desempenho considerando as seguintes configurações de entrada:
     //    (1) dados com distribuição aleatória. (caso médio)
     //    (2) dados com ordenação descendente (pior caso)

     Perf::Performance perf;
     Perf::PerformanceTimer &timer = perf.get_timer();
     Perf::PerformanceCounter &counter = perf.get_counter();

     int sizes[4] = {100, 500, 1000, 5000};

     int option;
     cout << "Programa para ordenação de vetores\n Escolha o tipo de dado: \n (1) Inteiros\n (2) Estudantes\n";
     cin >> option;

     int dist;
     cout << "\nSelecione a configuração de entrada:\n (1) Distribuição aleatória (caso médio)\n (2) Ordenação descendente (pior caso)\n";
     cin >> dist;

     std::vector<int> v;

     std::vector<Siga::Estudante> estudantes;

     switch (option)
     {
     case 1:
          // Inteiros
          for (int i = 0; i < 4; i++)
          {
               v = Siga::Tools::get_random_int_vector(sizes[i], 10000);

               if (dist == 2)
               {
                    // Ordena em ordem descendente
                    std::sort(v.begin(), v.end(), std::greater<int>());
               }

               timer.start();
               Sort::BasicSort(v, cmp, counter);
               timer.stop();

               cout << "Tempo de execução para vetor com " << sizes[i] << " elementos:\n\n";
               cout << "BasicSort: " << timer.elapsed_time() << " segundos\n";
               cout << "Comparações: " << counter.get_comparisons() << endl;
               cout << "Trocas: " << counter.get_swaps() << endl
                    << endl;

               counter.resetCounter();

               timer.start();
               Sort::MergeSort(v, cmp, counter);
               timer.stop();
               cout << "MergeSort: " << timer.elapsed_time() << " segundos\n";
               cout << "Comparações: " << counter.get_comparisons() << endl;
               cout << "Trocas: " << counter.get_swaps() << endl
                    << endl;

               counter.resetCounter();

               timer.start();
               Sort::QuickSort(v, cmp, counter);
               timer.stop();
               cout << "QuickSort: " << timer.elapsed_time() << " segundos\n";
               cout << "Comparações: " << counter.get_comparisons() << endl;
               cout << "Trocas: " << counter.get_swaps() << endl
                    << endl;

               counter.resetCounter();

               timer.start();
               Sort::HeapSort(v, cmp, counter);
               timer.stop();
               cout << "HeapSort: " << timer.elapsed_time() << " segundos\n";
               cout << "Comparações: " << counter.get_comparisons() << endl;
               cout << "Trocas: " << counter.get_swaps() << endl
                    << endl;

               counter.resetCounter();

               timer.start();
               Sort::MySort(v, cmp, counter);
               timer.stop();
               cout << "CombSort: " << timer.elapsed_time() << " segundos\n";
               cout << "Comparações: " << counter.get_comparisons() << endl;
               cout << "Trocas: " << counter.get_swaps() << endl
                    << endl;

               counter.resetCounter();
          }

          break;
     case 2:
          // Estudantes
          for (int i = 0; i < 4; i++)
          {
               estudantes = Siga::Tools::get_random_est_vector(sizes[i]);

               if (dist == 2)
               {
                    // Ordena em ordem descendente
                    std::sort(estudantes.begin(), estudantes.end(), cmpMatricula);
               }

               timer.start();
               Sort::BasicSort(estudantes, cmpEstudante, counter);
               timer.stop();

               cout << "Tempo de execução para vetor com " << sizes[i] << " estudantes:\n\n";
               cout << "BasicSort: " << timer.elapsed_time() << " segundos\n";
               cout << "Comparações: " << counter.get_comparisons() << endl;
               cout << "Trocas: " << counter.get_swaps() << endl
                    << endl;

               counter.resetCounter();

               timer.start();
               Sort::MergeSort(estudantes, cmpEstudante, counter);
               timer.stop();
               cout << "MergeSort: " << timer.elapsed_time() << " segundos\n";
               cout << "Comparações: " << counter.get_comparisons() << endl;
               cout << "Trocas: " << counter.get_swaps() << endl
                    << endl;

               counter.resetCounter();

               timer.start();
               Sort::QuickSort(estudantes, cmpEstudante, counter);
               timer.stop();
               cout << "QuickSort: " << timer.elapsed_time() << " segundos\n";
               cout << "Comparações: " << counter.get_comparisons() << endl;
               cout << "Trocas: " << counter.get_swaps() << endl
                    << endl;

               counter.resetCounter();

               timer.start();
               Sort::HeapSort(estudantes, cmpEstudante, counter);
               timer.stop();
               cout << "HeapSort: " << timer.elapsed_time() << " segundos\n";
               cout << "Comparações: " << counter.get_comparisons() << endl;
               cout << "Trocas: " << counter.get_swaps() << endl
                    << endl;

               counter.resetCounter();

               timer.start();
               Sort::MySort(estudantes, cmpEstudante, counter);
               timer.stop();
               cout << "CombSort: " << timer.elapsed_time() << " segundos\n";
               cout << "Comparações: " << counter.get_comparisons() << endl;
               cout << "Trocas: " << counter.get_swaps() << endl
                    << endl;

               counter.resetCounter();
          }

          break;
     default:
          return 0;
     }

     // OBS.: Na implementação dos métodos de ordenação, busque por implementações eficientes.
     //       Indique os resultados obtidos no arquivo REPORT.m

     return 0;
}
