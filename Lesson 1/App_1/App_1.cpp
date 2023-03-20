
#include <iostream>
#include <stdio.h>
#include "App_1.h"
#include <windows.h>
#include <iostream>

using namespace std;

int main()
{
   /* int j = 1; ТЕОРИЯ + часть первого задания
    int q = 0;
    for (int i = 1; i < 10; i++) {
        cout << i << endl;
        j *= i;
    }
    cout << j << endl;

    printf_s("%d - %d\n", j,q);

    printf_s("Hello\n");
    char s[50];
    scanf_s("%s",s, 10);
    printf_s("%s", s);*/


    setlocale(LC_ALL, "Russian");
    int num = 0;
    printf_s("Введите число - ");
    scanf_s("%i", &num);
    printf_s("Ваше число - %d\n", num);
    for (int i = 1; i < 10; i++) {
        printf_s("Умножение на %d = %d\n", i, i*num);
    }
    



}
