//
// Created by He Elvina on 16.09.2020.
//

#ifndef UNTITLED1_TASK3_H
#define UNTITLED1_TASK3_H

#include <cstdio>
#include <omp.h>
#include <iostream>

using namespace std;

// Написать программу, в которой объявить и присвоить начальные значения целочисленным переменным: a и b,
// определить две параллельные области, первая – с числом нитей 2,вторая – с числом нитей 4.
// Для первой области переменные a и b объявить защищенными,
// с режимом доступа private и firstprivate соответственно,
// внутри области определить номер нити и выполнить увеличение значения переменных на эту величину.
// Выдать на экран значения переменных до входа в параллельную область,
// внутри параллельной области и после выхода из параллельной области.
// Для второй области переменную a объявить общей, переменную b объявить защищенной,
// с режимом доступа private, определить номер нити и выполнить уменьшение значения
// переменных на эту величину. Выдать на экран значения переменных до входа в параллельную область,
// внутри параллельной области и после выхода из параллельной области. (2 балла)

class Task3 {
    private:void print_a_b_number(int a, int b)
    {
        printf("a: %d, b: %d\n", a, b);
    }

    public:void task3(){
        cout << "*************Task3*************" << endl;

        int a = 13;
        int b = 29;

        print_a_b_number(a,b);

        #pragma omp parallel num_threads(2) private(a), firstprivate(b)
        {
            int thread = omp_get_thread_num();
            a += thread;
            b += thread;
            print_a_b_number(a,b);
        }
        print_a_b_number(a,b);

        #pragma omp parallel num_threads(4) shared(a), private(b)
        {
            int thread = omp_get_thread_num();
            a -= thread;
            b -= thread;
            print_a_b_number(a,b);
        }
        print_a_b_number(a,b);
    }
};
#endif //UNTITLED1_TASK3_H
