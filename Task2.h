//
// Created by He Elvina on 16.09.2020.
//

#ifndef UNTITLED1_TASK2_H
#define UNTITLED1_TASK2_H

#include <cstdio>
#include <omp.h>
#include <iostream>

using namespace std;

// Написать программу, определить две параллельные области,
// выполнение которых зависит от условного оператора #pragma omp parallel if(…),
// если заданное значение числа нитей больше 2,
// область выполняется параллельно, иначе не параллельно.
// Число нитей перед первой областью задать равным 3, перед второй – равным 2.
// Внутри параллельных областей определить количество нитей и номер каждой нити,
// результат выдать на экран. Убедиться в правильности работы программы. (2 балла)

class Task2 {
    private:void print_thread_number()
    {
        int thread_id = omp_get_thread_num();
        int threads_count = omp_get_num_threads();
        printf("Thread number: %d, number of threads: %d\n", thread_id, threads_count);
    }

    public:void task2(){
        cout << "*************Task2*************" << endl;

        int thread = 3;
        #pragma omp parallel num_threads(thread) if(thread > 2)
        {
            print_thread_number();
        }

        thread = 2;
        #pragma omp parallel num_threads(thread) if(thread > 2)
        {
            print_thread_number();
        }
    }
};


#endif //UNTITLED1_TASK2_H
