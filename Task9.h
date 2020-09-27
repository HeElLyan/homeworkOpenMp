//
// Created by He Elvina on 27.09.2020.
//

#ifndef HOMEWORKOPENMP_TASK9_H
#define HOMEWORKOPENMP_TASK9_H

#include <cstdio>
#include <omp.h>
#include <iostream>

using namespace std;

// Используя возможности OpenMP написать программу умножения матрицы на вектор.
// Сравнить время выполнения последовательной и параллельных программ
// (выбрать наилучший schedule). Определить размеры матрицы при которых
// параллельная программа начинает работать быстрей последовательной(ответ - начиная от 100) (3 балла)

#define N 600

class Task9 {

    public:void task9() {
        cout << "*************Task9*************" << endl;

        static int a[N][N];
        static int b[N];
        static int c[N];

        for(int i = 0; i < N; i++)
        {
            b[i] = i;
            for(int j = 0; j < N; j++)
            {
                a[i][j] = i;
            }
        }


        double start = omp_get_wtime();
        for(int i = 0; i < N; i++)
        {
            c[i] = 0;
            for(int j = 0; j < N; j++)
            {
                c[i] += a[i][j] * b[j];
            }
        }
        double end = omp_get_wtime( );
        printf("Not parallel time in seconds = %f\n", end-start);

        start = omp_get_wtime();
        #pragma omp parallel for schedule(auto) num_threads(4)
        for(int i = 0; i < N; i++)
        {
            c[i] = 0;
            for(int j = 0; j < N; j++)
            {
                c[i] += a[i][j] * b[j];
            }
        }
        end = omp_get_wtime( );
        printf("Parallel time in seconds = %f\n", end-start);
    }
};

#endif //HOMEWORKOPENMP_TASK9_H
