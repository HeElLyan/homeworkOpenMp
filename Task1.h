//
// Created by He Elvina on 16.09.2020.
//

#ifndef UNTITLED1_TASK1_H
#define UNTITLED1_TASK1_H

#include <cstdio>
#include <omp.h>
#include <iostream>

using namespace std;

// Написать программу, где каждый поток печатает свой идентификатор,
// количество потоков всего и строчку «Hello World». Запустить программу с 8 потоками.
// Всегда ли вывод идентичен? Почему?(1 балл)

class Task1{
    public:void task1(){
        cout << "*************Task1*************" << endl;

        #pragma omp parallel num_threads(8)
        {
    //        omp_set_num_threads(8);
            int id = omp_get_thread_num();
            int threads_count = omp_get_num_threads();
            printf("Program called: Hello world, the thread number is %d, number of threads: %d\n", id, threads_count);
        }
    }
};

#endif //UNTITLED1_TASK1_H
