//
// Created by He Elvina on 27.09.2020.
//

#ifndef HOMEWORKOPENMP_TASK8_H
#define HOMEWORKOPENMP_TASK8_H

#include <cstdio>
#include <omp.h>
#include <iostream>

using namespace std;

// Написать программу, в которой объявлен массив из 16000
// элементов и инициализирован так, что значение элемента
// массива равно его порядковому номеру. Затем создайте
// результирующий массив, в котором (за исключением крайних элементов)
// будут средние значения исходного массива: b[i] = (a[i-1] + a[i] + a[i+1])/3.0
// Запустите программу с 8-ю процессами при различных типах распределения
// работ (static, dynamic, guided, auto(runtime, если auto не работает))
// и посмотреть время на разных размерах порций. (4 балла)

#define N 16000

class Task8 {

    public:void task8() {
        cout << "*************Task8*************" << endl;

        int a[N];
        for (int i = 0; i < N; i++)
        {
            a[i] = i;
        }

        int b[N];
        double start = omp_get_wtime();
        #pragma omp parallel for schedule(static, 8) num_threads(8)
        for (int i = 1; i < N - 1; i++)
        {
            b[i] = (a[i-1] + a[i] + a[i+1])/3.0;
        }
        double end = omp_get_wtime( );
        printf("Parallel static time in seconds = %f\n", end-start);

        start = omp_get_wtime();
        #pragma omp parallel for schedule(dynamic, 600) num_threads(8)
        for (int i = 1; i < N - 1; i++)
        {
            b[i] = (a[i-1] + a[i] + a[i+1])/3.0;
        }
        end = omp_get_wtime( );
        printf("Parallel dynamic time in seconds = %f\n", end-start);

        start = omp_get_wtime();
        #pragma omp parallel for schedule(guided, 450) num_threads(8)
        for (int i = 1; i < N - 1; i++)
        {
            b[i] = (a[i-1] + a[i] + a[i+1])/3.0;
        }
        end = omp_get_wtime( );
        printf("Parallel guided time in seconds = %f\n", end-start);

        start = omp_get_wtime();
        #pragma omp parallel for schedule(auto) num_threads(8)
        for (int i = 1; i < N - 1; i++)
        {
            b[i] = (a[i-1] + a[i] + a[i+1])/3.0;
        }
        end = omp_get_wtime( );
        printf("Parallel auto time in seconds = %f\n", end-start);
    }
};

#endif //HOMEWORKOPENMP_TASK8_H
