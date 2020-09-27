//
// Created by He Elvina on 16.09.2020.
//

#ifndef UNTITLED1_TASK5_H
#define UNTITLED1_TASK5_H

#include <cstdio>
#include <omp.h>
#include <iostream>

using namespace std;

// Написать программу, в которой объявить и присвоить начальные значения
// элементам двумерного массива d[6][8], для инициализации значений
// использовать генератор случайных чисел.
// Используя конструкцию директивы sections, section определить три секции для выполнения следующих операций:
// первая секция выполняет вычисление среднего арифметического значения элементов двумерного массива,
// вторая секция выполняет вычисление минимального и максимального значений элементов двумерного массива,
// третья секция выполняет вычисление количества элементов массива, числовые значения которых кратны 3.
// В каждой секции определить и выдать на экран номер исполняющей нити
// и результат выполнения вычислений. (3 балла)

#define N 6
#define M 8

class Task5 {
    private:void result(int min, int max)
    {
        int thread = omp_get_thread_num();
        printf("Thread number: %d", thread);
    }

    public:void task5() {
        cout << "*************Task5*************" << endl;

        int d[N][M];

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                d[i][j] = (rand() % 10) * (rand() % 10);
                printf("d[%d][%d] = %d ", i, j, d[i][j]);
            }
        }

        #pragma omp parallel sections shared(d)
        {
            #pragma omp section
            {
                int sum = 0;

                for (int i = 0; i < N; i++)
                {
                    for (int j = 0; j < M; j++)
                    {
                        sum += d[i][j];
                    }
                }
                printf("Sum: %d\n", sum);

                int average = sum / (N * M);
                printf("Average: %d\n", average);
            }

            #pragma omp section
            {
                int min = INT_MAX;
                int max = INT_MIN;

                for (int i = 0; i < N; i++)
                {
                    for (int j = 0; j < M; j++)
                    {
                        if (d[i][j] > max)
                        {
                            max = d[i][j];
                        }
                        if (d[i][j] < min)
                        {
                            min = d[i][j];
                        }
                    }
                }
                printf("Min in thread %d: %d\nMax in thread %d: %d\n", omp_get_thread_num(), min, omp_get_thread_num(),
                       max);
            }

            #pragma omp section
            {
                int count = 0;
                for (int i = 0; i < N; i++)
                {
                    for (int j = 0; j < M; j++)
                    {
                        if (d[i][j] % 3 == 0)
                        {
                            count++;
                        }
                    }
                }
                printf("Count from thread %d: %d\n", omp_get_thread_num(), count);
            }
        }
    }
};

#endif //UNTITLED1_TASK5_H
