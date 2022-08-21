#include <time.h>
#include <math.h>
#include <cstdlib>
#include "getch.h"
#include <string>
#include <iostream>

void my_clear()
    {
        system("clear"); // для OS Windows, нужно изменить clear -> cls
    }


void random_array(int *A, int size, int Msing) {

	int i, stime;
	long ltime;
	ltime = time(NULL);
	stime = (unsigned)ltime / 2;
	srand(stime);
	for (i = 0; i < size; ++i) {
		A[i] = rand() % Msing;
		printf("%3d", A[i]);
	}

}

void print_array(int A[], int size) {
	for (int i = 0; i < size; i++)
		printf("%3d", A[i]);
}


void task_one()
{
	system("clear");
    printf("Задание № 1\n");
	printf("Введите двузначное число ");
	int a;
	scanf("%d", &a);
	printf("Ответ: %d%d%d%d\n\n", a / 10, a / 10, a % 10, a % 10);
	printf("Для продолжения нажмите любую клавишу");
	mygetch();
}


void task_two()
{
	printf("Задание № 3\n");
     int bigN_3, digit_3;
     printf("Введите целое число, состоящее не более чем из 10 цифр: ");
     scanf("%d", &bigN_3);
     printf("Введите цифру: ");
     scanf("%d", &digit_3);
     printf("Проверка...\n ");
     
     while (bigN_3 > 0) 
     {
     	if (bigN_3 % 10 == digit_3) 
     	{
	    	printf("Да! Эта цифра присутствует в этом числе.\n\n ");
    	 	break;
    	 }
    
        else if (bigN_3 <= 9) 
        {
        	printf("Нет! Этой цифры в этом числе нет.\n\n ");
			break;
        }

        bigN_3 /= 10;
    }//while

}