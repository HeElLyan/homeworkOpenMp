//
// Created by He Elvina on 27.09.2020.
//

#ifndef HOMEWORKOPENMP_TASK12_H
#define HOMEWORKOPENMP_TASK12_H

#include <cstdio>
#include <omp.h>
#include <iostream>

using namespace std;

// Написать программу, в которой, объявить и заполнить случайными
// значениями массив целых чисел. Используя возможности OpenMP
// найти максимальное значение элементов массива кратных 7.
// Длину массива и количество потоков определить самостоятельно.
// Результат выдать на экран. Для синхронизации числовых значений
// максимума используется механизм критических секций. (2 балла)

#define N 500

class Task12 {

    private:void result(int num)
    {
        printf("Max divisible to 7: %d\n", num);
    }

    public:void task12() {
        cout << "*************Task12*************" << endl;

        int a[N];
        int max = INT_MIN;

        for (int i = 0; i < N; i++)
        {
            a[i] = rand() % 100;
        }

        #pragma omp parallel for firstprivate(a) shared(max) num_threads(4)
        for (int i = 0; i < N; i++)
        {
            if (a[i] % 7 == 0)
            {
                #pragma omp critical
                if (a[i] > max)
                {
                    max = a[i];
                }
            }
        }

        result(max);
    }
};

#endif //HOMEWORKOPENMP_TASK12_H
