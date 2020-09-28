//
// Created by He Elvina on 27.09.2020.
//

#ifndef HOMEWORKOPENMP_TASK6_H
#define HOMEWORKOPENMP_TASK6_H

#include <cstdio>
#include <omp.h>
#include <iostream>

using namespace std;

// Написать программу, в которой объявить и присвоить начальные значения целочисленному
// массиву a[100]. Используя конструкцию parallel for и reduction вычислить
// средние арифметические значения элементов массива a.
// Одно при помощи reduction, другое без. Сравнить полученные значения.
// Объяснить возможную разность результатов. (2 балла)

#define N 100

class Task6 {
    private:void result(float aver_red, float aver)
    {
        printf("Average of massive a with reduction: %f\nAverage of massive a without reduction: %f\n", aver_red, aver);
    }

    public:void task6() {
        cout << "*************Task6*************" << endl;

        int a[N];
        for (int i = 0; i < N; i++)
        {
            a[i] = i;
        }

        int sum = 0;
        #pragma omp parallel for reduction(+: sum)
        for (int i = 0; i < N; i++)
        {
            sum += a[i];
        }
        float aver_red = sum/N;

        sum = 0;
        #pragma omp parallel for
        for (int i = 0; i < N; i++)
        {
            sum += a[i];
        }
        float aver = sum/N;

        result(aver_red, aver);
    }
};
#endif //HOMEWORKOPENMP_TASK6_H
