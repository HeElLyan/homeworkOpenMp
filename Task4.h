//
// Created by He Elvina on 16.09.2020.
//

#ifndef UNTITLED1_TASK4_H
#define UNTITLED1_TASK4_H

#include <cstdio>
#include <omp.h>
#include <iostream>

using namespace std;

// Написать программу, в которой объявить и присвоить начальные значения целочисленным массивам a[10] и b[10],
// определить параллельную область, количество нитей задать равным 2,
// выделить код для основной (номер 0) и нити с номером 1.
// Основная нить (master) должна выполнять поиск min значения элементов массива a,
// нить с номером 1 - поиск max значения элементов массива b. Результат выдать на экран. (2 балла)

#define N 10

class Task4 {
    private:void result(int min, int max)
    {
        printf("Min in massive a: %d\nMax in massive b: %d\n", min, max);
    }

    public:void task4() {
        cout << "*************Task4*************" << endl;

        int a[N];
        int b[N];

        for (int i = 0; i < N; i++)
        {
            a[i] = i;
            b[i] = i;
        }

        int max = INT_MIN;
        int min = INT_MAX;

        #pragma omp parallel num_threads(2)
        {
            if (omp_get_thread_num() == 0)
            {
                #pragma omp master
                for (int j = 0; j < N; j++)
                {
                    if (min > a[j])
                    {
                        min = a[j];
                    }
                }
            }
            else
                {
//                #pragma omp parallel for
                for (int j = 0; j < N; j++)
                {
                    if (max < b[j])
                    {
                        max = b[j];
                    }
                }
            }
        }
        result(min, max);
    }
};

#endif //UNTITLED1_TASK4_H
