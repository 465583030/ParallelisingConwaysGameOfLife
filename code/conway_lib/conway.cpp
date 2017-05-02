#include "conway.h"

void cgl::print_test_string() {
    int threadnum = 0;
    int numthreads = 0;

    #pragma omp parallel shared(numthreads), private(threadnum)
    {
        #ifdef _OPENMP
        threadnum = omp_get_thread_num();
            #pragma omp single
            {
                numthreads = omp_get_num_threads();
            }

        #endif
        #pragma omp critical
        {
            std::cout << "Hello World I am, "
                      << threadnum << " of " << numthreads << std::endl;
        }
    }

}