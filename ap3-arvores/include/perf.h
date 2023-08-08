#ifndef PERF_H
#define PERF_H

#include <chrono>

namespace Perf
{
    // Classe para medir o tempo de execução de um algoritmo
    class PerformanceTimer
    {   
        public:
            PerformanceTimer();
            void start();
            void stop();
            double elapsed_time();
        private:
            std::chrono::time_point<std::chrono::high_resolution_clock> start_time;
            std::chrono::time_point<std::chrono::high_resolution_clock> end_time;
            bool running;
    };

    class PerformanceCounter
    {
        public:
            PerformanceCounter();
            void increment_comparisons();
            void increment_swaps();
            unsigned int get_comparisons();
            unsigned int get_swaps();
            void reset();
        private:
            unsigned int n_comparisons;
            unsigned int n_swaps;
    };

    class Performance
    {
        public:
            Performance();
            PerformanceCounter& get_counter();
            PerformanceTimer&    get_timer();
        private:
            PerformanceTimer timer;
            PerformanceCounter counter;
    };

} // namespace Perf


#endif /* PERF_H */
