//
// Created by He Elvina on 27.09.2020.
//

#ifndef HOMEWORKOPENMP_TASK10_H
#define HOMEWORKOPENMP_TASK10_H

#include <cstdio>
#include <omp.h>
#include <iostream>

using namespace std;

// Написать программу, в которой объявить и присвоить начальные
// значения элементам двумерного массива d[6][8], для инициализации
// значений использовать генератор случайных чисел. Используя
// конструкцию директивы omp parallel for и omp critical определить
// минимальное и максимальное значения элементов двумерного массива.
// Реализовать аналог reduction для max и min. Количество нитей задать
// самостоятельно. Результат выдать на экран. (2 балла)

#define N 6
#define M 8

class Task10 {

    private:void result(int min, int max)
    {
        printf("Min in massive a: %d\nMax in massive a: %d\n", min, max);
    }

    public:void task10() {
        cout << "*************Task10*************" << endl;

        int a[N][M];
        int min = INT_MAX;
        int max = INT_MIN;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                a[i][j] = rand() % 10;
            }
        }

        #pragma omp parallel for shared(a, min, max)
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                #pragma omp critical
                if (a[i][j] > max)
                {
                    max = a[i][j];
                }

                #pragma omp critical
                if (a[i][j] < min)
                {
                    min = a[i][j];
                }
            }
        }
        result(min, max);
    }
};

#endif //HOMEWORKOPENMP_TASK10_H
