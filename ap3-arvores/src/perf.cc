
#include "perf.h"

namespace Perf
{

    PerformanceTimer::PerformanceTimer()
    {
        running = false;
    }

    void PerformanceTimer::start()
    {
        start_time = std::chrono::high_resolution_clock::now();
        running = true;
    }

    void PerformanceTimer::stop()
    {
        end_time = std::chrono::high_resolution_clock::now();
        running = false;
    }

    double PerformanceTimer::elapsed_time()
    {
        std::chrono::duration<double> elapsed_seconds;
        if(running)
        {
            elapsed_seconds = std::chrono::high_resolution_clock::now() - start_time;
        }
        else
        {
            elapsed_seconds = end_time - start_time;
        }
        return elapsed_seconds.count();
    }

    PerformanceCounter::PerformanceCounter():
        n_comparisons(0),
        n_swaps(0)
    {
    }

    void PerformanceCounter::increment_comparisons()
    {
        n_comparisons++;
    }

    void PerformanceCounter::increment_swaps()
    {
        n_swaps++;
    }

    unsigned int PerformanceCounter::get_comparisons()
    {
        return n_comparisons;
    }

    unsigned int PerformanceCounter::get_swaps()
    {
        return n_swaps;
    }

    void PerformanceCounter::reset()
    {
        n_comparisons = 0;
        n_swaps = 0;
    }

    Performance::Performance():
        timer(),
        counter()
    {
    }

    PerformanceCounter& Performance::get_counter()
    {
        return counter;
    }

    PerformanceTimer& Performance::get_timer()
    {
        return timer;
    }

}
