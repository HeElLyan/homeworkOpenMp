//
// Created by He Elvina on 27.09.2020.
//

#ifndef HOMEWORKOPENMP_TASK11_H
#define HOMEWORKOPENMP_TASK11_H

#include <cstdio>
#include <omp.h>
#include <iostream>

using namespace std;

// Написать программу, в которой объявить и присвоить начальные
// значения массиву целых чисел a[30], для инициализации значений
// использовать генератор случайных чисел. Используя конструкцию
// omp parallel for и omp atomic вычислить количество элементов массива,
// числовые значения которых кратны 9. Количество нитей задать
// самостоятельно. Результат выдать на экран. (2 балла)

#define N 30

class Task11 {

private:void result(int count)
    {
        printf("Count: %d\n", count);
    }

public:void task11() {
        cout << "*************Task11*************" << endl;

        int a[N];

        for (int i = 0; i < N; i++)
        {
            a[i] = rand() % 100;
            printf("%d\n", a[i]);
        }

        int count = 0;

        #pragma omp parallel for shared(a, count)
        for (int i = 0; i < N; i++)
        {
            if (a[i] % 9 == 0)
            {
            #pragma omp atomic
                count += 1;
            }
        }

        result(count);
    }
};

#endif //HOMEWORKOPENMP_TASK11_H
