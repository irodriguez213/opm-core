#include <stdlib.h>
#include <math.h>
#include <string.h>

/**
   Ahhh - the joys of comparing floating point numbers ....

   http://www.cygnus-software.com/papers/comparingfloats/comparingfloats.htm
*/

int opm_memcmp_double(const double * p1 , const double *p2 , size_t num_elements) {
    if (memcmp(p1 , p2 , num_elements * sizeof * p1) == 0)
        return 0;
    else {
        const double abs_epsilon = 1e-8;
        const double rel_epsilon = 1e-5;
        size_t index;
        for (index = 0; index < num_elements; index++) {
            double diff = fabs(p1[index] - p2[index]);
            if (diff > abs_epsilon) {
                double sum = fabs(p1[index]) + fabs(p2[index]);

                if (diff > sum * rel_epsilon)
                    return 1;
            }
        }

        return 0;
    }
}
