//
// Created by He Elvina on 27.09.2020.
//

#ifndef HOMEWORKOPENMP_TASK7_H
#define HOMEWORKOPENMP_TASK7_H

#include <cstdio>
#include <omp.h>
#include <iostream>

using namespace std;

// Написать программу, в которой определить две параллельные области,
// каждая из которых содержит итерационную конструкцию for выполняющую
// инициализацию элементов одномерных массивов целых чисел a[12], b[12] и c[12].
// Число нитей перед первой областью задать равным 3, перед второй – равным 4.
// Первая параллельная область выполняет инициализацию элементов массивов a и b
// с использованием статического распределения итераций, размер порции итераций
// выбрать самостоятельно, вторая параллельная область
// выполняет инициализацию элементов массива c
// по следующему правилу c[i] = a[i] + b[i],
// с использованием динамического распределения итераций,
// размер порции итераций выбрать самостоятельно. В каждой области
// определить и выдать на экран количество нитей, номер нити и результат
// выполнения цикла. Убедиться в правильности работы программы.  (2 баллов)

#define N 12

class Task7 {
    private:void result(float aver_red, float aver)
    {
        printf("Average of massive a with reduction: %f\nAverage of massive a without reduction: %f\n", aver_red, aver);
    }

    public:void task7() {
        cout << "*************Task7*************" << endl;

        int a[N];
        int b[N];
        int c[N];

        #pragma omp parallel for schedule(static, 2) num_threads(3)
        for (int i = 0; i < N; i++)
        {
            a[i] = i;
            b[i] = i * 10;
            printf("Initialization a[%d]:%d, b[%d]:%d, thread = %d, total number of threads = %d\n", i, a[i], i, b[i], omp_get_thread_num(), omp_get_num_threads());
        }

        #pragma omp parallel for schedule(dynamic, 2) num_threads(4)
        for (int i = 0; i < N; i++)
        {
            c[i] = a[i] + b[i];
            printf("Initialization c[%d]:%d, thread = %d, total number of threads = %d\n", i, c[i], omp_get_thread_num(), omp_get_num_threads());
        }
    }
};

#endif //HOMEWORKOPENMP_TASK7_H
