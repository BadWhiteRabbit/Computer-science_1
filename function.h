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
	//Ввести коэффициенты квадратного уравнения и выдать либо сообщение, что уравнение не квадратное, либо сообщение о количестве и значении корней
			printf("Задание № 2\n");
			printf("Введите коэффициенты квадратного уравнения\n");
			int coef_A, coef_B, coef_C;
			printf("A = ");
			scanf("%d", &coef_A);
			printf("B = ");
			scanf("%d", &coef_B);
			printf("C = ");
			scanf("%d", &coef_C);

			int x1, x2;
			if (coef_C == 0) {
				printf("%dx^2 + %dx = 0\n", coef_A, coef_B);
				x2 = (coef_B / coef_A) * -1;
				printf("Первый корень = 0, Второй корень = %d.\n\n", x2);
				printf("Для продолжения нажмите любую клавишу");
				mygetch();
				return;
				
			}

			else if (coef_B == 0) {
				printf("%dx^2 + %d = 0\n", coef_A, coef_C);
				x1 = sqrt(coef_C / coef_A);
				x2 = sqrt(coef_C / coef_A) * -1;
				printf("Первый корень = %d, Второй корень = %d.\n", x1, x2);
				printf("Для продолжения нажмите любую клавишу");
				mygetch();
				return;
			}
			else if (coef_A == 0) {
				printf("Это не квадратное уравнение!\n");
				printf("Для продолжения нажмите любую клавишу");
				mygetch();
				return;
			}
			else {
				int dis;
				printf("%dx^2 + %dx + %d = 0\n", coef_A, coef_B, coef_C);
				dis = pow(coef_B, 2) - ((4 * coef_A) * coef_C);
				if (dis < 0) {
					printf("Дискриминант = %d < 0.\n", dis);
					printf("У этого уравнения нет корней!\n");
					printf("Для продолжения нажмите любую клавишу");
					mygetch();
					return;
				}
				else if (dis == 0) {
					x1 = -1 * coef_B / (2 * coef_A);
					printf("Дискриминант = %d\n", dis);
					printf("Корень уравнения = %d.\n\n", x1);
					printf("Для продолжения нажмите любую клавишу");
					mygetch();
					return;
				}
				x1 = (-1 * coef_B - sqrt(dis)) / (2 * coef_A);
				x2 = (-1 * coef_B + sqrt(dis)) / (2 * coef_A);

				printf("Дискриминант = %d\n", dis);
				printf("Первый корень = %d, Второй корень = %d.\n\n", x1, x2);
				printf("Для продолжения нажмите любую клавишу");
				mygetch();
			}
}


void task_tree()
{
	printf("Задание № 3\n");
     int bigN_3, digit_3;
     printf("Введите целое число, состоящее не более чем из 10 цифр: ");
     scanf("%d", &bigN_3);
     printf("Введите цифру: ");
     scanf("%d", &digit_3);
     printf("\n");
     
     while (bigN_3 > 0) 
     {
     	if (bigN_3 % 10 == digit_3) 
     	{
	    	printf("Да! Эта цифра присутствует в этом числе.\n\n ");
	    	printf("Для продолжения нажмите любую клавишу");
	    	mygetch();
    	 	break;
    	 }
    
        else if (bigN_3 <= 9) 
        {
        	printf("Нет! Этой цифры в этом числе нет.\n\n ");
        	printf("Для продолжения нажмите любую клавишу");
        	mygetch();
			break;
        }

        bigN_3 /= 10;
    }//while

}


/*void task_four()
{
	//Ввести массив из чисел (из 30 элементов) и найти среднее арифметическое значение его элементов
			printf("Задание № 4\n");
			int input_task4;
			printf("Вы хотите использовать случайные значения? (в случае отказа введите тридцатизначное чило)\n");
			printf("1.Да\n2.Нет\n");
			scanf_s("%d", &input_task4);
			switch (input_task4) {
			case 1: { //random case
				int A[N_task4] = { 0 };
				double arith = 0;
				for (int i = 0; i < N_task4; i++) {
					A[i] = rand() % 100;
					arith = arith + A[i];
					printf("%3d", A[i]);
				}
				printf("\n");
				printf("Среднее арифметическое = %.2f\n", arith / N_task4);
				fWait();
				break;
			}
			case 2: { //enter a thirty-digit number
				int A[N_task4] = { 0 };
				double arith = 0;
				int number_30;
				printf("Заполните массив (тридцатизначное чило)\n");
				for (int i = 0; i < N_task4; i++) {
					scanf_s("%d", &number_30);
					A[i] = number_30;
					arith = arith + A[i];
					printf("%d ", number_30);
				}
				printf("Среднее арифметическое = %.2f\n", arith / N_task4);
				fWait();
				break;
			}
			default: {
				printf("Неправильный ввод!\n");
				break;

			}

			}
			fWait();
			break;
}*/