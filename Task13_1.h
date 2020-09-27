//
// Created by He Elvina on 28.09.2020.
//

#ifndef HOMEWORKOPENMP_TASK13_1_H
#define HOMEWORKOPENMP_TASK13_1_H

#include <cstdio>
#include <omp.h>
#include <iostream>

using namespace std;

// Модифицируйте задачу 1 так, чтобы потоки распечатывали
// свои идентификаторы в обратном (убывающем) порядке.
// Существует как минимум 5 способов решения.
// Постарайтесь найти как можно больше.
// (каждый вариант 1 балл – max 5 баллов)

class Task13_1{
public:void task13_1(){
        cout << "*************Task13_1*************" << endl;

        int a[8];

        #pragma omp parallel shared(a) num_threads(8)
        {
            int threads = omp_get_num_threads();
            #pragma omp for
            for (int i = 0; i < threads; i++)
            {
                a[i] = omp_get_thread_num();
            }

            #pragma omp for ordered
            for (int i = threads - 1; i >= 0; i--)
            {
            #pragma omp ordered
                {
                    printf("Hello World, I'm thread number %d and total number of threads is %d\n", a[i], omp_get_num_threads());
                }
            }
        }
    }
};
#endif //HOMEWORKOPENMP_TASK13_1_H
