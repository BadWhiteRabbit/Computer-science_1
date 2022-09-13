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

void random_array(int *A, int size, int Msing) 
{
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

void print_array(int A[], int size) 
{
	for (int i = 0; i < size; i++)
		printf("%3d", A[i]);
}


void task_one()
{
	my_clear();
    printf("Задание № 1\n\n");
	printf("Введите двузначное число ");
	int a;
	scanf("%d", &a);
	printf("Ответ: %d%d%d%d\n\n", a / 10, a / 10, a % 10, a % 10);
	printf("Для продолжения нажмите любую клавишу");
	mygetch();
}

void task_two()
{
	my_clear();
	printf("Задание № 2\n\n");
	printf("Введите коэффициенты квадратного уравнения\n");
	int coef_A, coef_B, coef_C;
	printf("A = ");
	scanf("%d", &coef_A);
	printf("B = ");
	scanf("%d", &coef_B);
	printf("C = ");
	scanf("%d", &coef_C);
	int x1, x2;
	if (coef_C == 0) 
	{
		printf("%dx^2 + %dx = 0\n", coef_A, coef_B);
		x2 = (coef_B / coef_A) * -1;
		printf("Первый корень = 0, Второй корень = %d.\n\n", x2);
		printf("Для продолжения нажмите любую клавишу");
		mygetch();
		return;
	}

	else if (coef_B == 0) 
	{
		printf("%dx^2 + %d = 0\n", coef_A, coef_C);
		x1 = sqrt(coef_C / coef_A);
		x2 = sqrt(coef_C / coef_A) * -1;
		printf("Первый корень = %d, Второй корень = %d.\n\n", x1, x2);
		printf("Для продолжения нажмите любую клавишу");
		mygetch();
		return;
	}
	else if (coef_A == 0) 
	{
		printf("Это не квадратное уравнение!\n\n");
		printf("Для продолжения нажмите любую клавишу");
		mygetch();
		return;
	}
	else 
	{
		int dis;
		printf("%dx^2 + %dx + %d = 0\n", coef_A, coef_B, coef_C);
		dis = pow(coef_B, 2) - ((4 * coef_A) * coef_C);
		if (dis < 0) 
		{
			printf("Дискриминант = %d < 0.\n", dis);
			printf("У этого уравнения нет корней!\n\n");
			printf("Для продолжения нажмите любую клавишу");
			mygetch();
			return;
		}
		else if (dis == 0) 
		{
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
	 my_clear();
	 printf("Задание № 3\n\n");
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
    }
}

void task_four(int a)
{
	my_clear();
	printf("Задание № 4\n\n");
	int N_task4 = 30;
	switch (a) 
	{
		case 0: 
		{ 
			int A[N_task4] = { 0 };
			double arith = 0;
			for (int i = 0; i < N_task4; i++) 
			{
				A[i] = rand() % 100;
				arith = arith + A[i];
				printf("%3d", A[i]);
			} 
		printf("\n");
		printf("Среднее арифметическое = %.2f\n\n", arith / N_task4);
		printf("Для продолжения нажмите любую клавишу");
       // mygetch();
		return;
		}
		case 1: 
		{ 
			double arith = 0;
			int number_30;
			printf("Сколько чисел? ");
			scanf("%d", &N_task4);
			int A[N_task4] = { 0 };
			printf("Введите числа:\n");
			for (int i = 0; i < N_task4; i++) 
			{
				scanf("%d", &number_30);
				A[i] = number_30;
				arith = arith + A[i];
				printf("[%d] - %d\n", i + 1, number_30);
			}
			printf("Среднее арифметическое = %.2f\n\n", arith / N_task4);
			printf("Для продолжения нажмите любую клавишу");
       		mygetch();
			return;
		}
	}
}

void task_five()
{
	my_clear();
	printf("Задание № 5\n\n");
	int N_task5 = 20;
	int A[N_task5] = { 0 };
	for (int i = 0; i < N_task5; ++i) 
	{
		A[i] = i;
		printf("%3d", A[i]);
	}
	printf("\n");
	for (int i = 0; i < N_task5 / 2; ++i) 
	{
		int tmp = A[i];
		A[i] = A[N_task5 - i - 1];
		A[N_task5 - i - 1] = tmp;
	}
	printf("\n");
	for (int i = 0; i < N_task5; ++i) printf("%3d", A[i]);
	printf("\n\n");
	printf("Для продолжения нажмите любую клавишу");
	return;
}

void task_six()
{
	my_clear();
	printf("Задание № 6\n\n");
	int const N_task6 = 20;
	int A[N_task6] = { 0 };
	int SX = 0;
	int shift = 2;
	printf("На сколько вы хотите выполнить цикличческий сдвиг вправо?\n(по заданию - 3) ");
	scanf("%d", &shift);

	if (shift >= N_task6) shift %= N_task6;
	
	for (int i = 0; i < N_task6; i++) 
	{ 
		A[i] = i + 10;
		printf("%3d", A[i]);
	}
	printf("\n\n");
	while (SX != shift) 
	{
		int tmp_t6 = A[N_task6 - 1];
		for (int i = N_task6 - 1; i > 0; --i) A[i] = A[i - 1];
		A[0] = tmp_t6;
		SX++;
	}

	for (int i = 0; i < N_task6; i++) printf("%3d", A[i]);
	printf("\n\n");
	printf("Для продолжения нажмите любую клавишу");
	mygetch();
	return;
}

void task_seven()
{
	my_clear();
	printf("Задание № 7\n\n");
	int const N_task7 = 10;
	int A[N_task7] = { 0 };
	int number_10;
	printf("Введите массив из 10 чисел: ");
	for (int i = 0; i < N_task7; ++i) 
		{
			scanf("%d", &number_10);
			A[i] = number_10;
		}

	for(int i = 0; i < N_task7; ++i) printf("%3d", A[i]);
	printf("\n\n");
	for (int i = 0; i < N_task7; i++) 
	{
		if (A[i] < A[i + 1]) 
		{ 
			printf("Нет! Этот массив не упорядочен в порядке невозрастания(убывания).\n\n");
			printf("Для продолжения нажмите любую клавишу");
			mygetch();
			return;
		}
		else if (i == N_task7 - 1)
			printf("Да! Этот массив упорядочен в порядке невозрастания(убывания).\n\n");
	}
			printf("Для продолжения нажмите любую клавишу");
			mygetch();
}

void task_eight()
{
	my_clear();	
	printf("Задание № 8\n\n");
	int const N_task8 = 10;
	int A[N_task8];
	random_array(A, N_task8, 100);
	int tmp8;
	int i = 1;
	while (N_task8 > i) 
	{
		for (int j = 1; j < N_task8; ++j)
			if (A[j] >= A[j - 1]) 
			{
				tmp8 = A[j];
				A[j] = A[j - 1];
				A[j - 1] = tmp8;
			}

		++i;
	}
	printf("\n");
	print_array(A, N_task8);
	printf("\n\n");
	printf("Для продолжения нажмите любую клавишу");
}

void task_nine()
{
	my_clear();
	printf("Задание № 9\n\n");
	int const N_task9 = 10;
	int A[N_task9];
	int max, tmp;
	random_array(A, N_task9, 100);
	printf("\n");
	for (int i = 0; i < N_task9; ++i) 
	{
		max = i;
		for (int j = i + 1; j < N_task9; j++) 
		{
			if (A[j] > A[max]) 
			{
				max = j;
			}
		}
		if (max != i) 
		{
			tmp = A[i];
			A[i] = A[max];
			A[max] = tmp;
		}
	}
	print_array(A, N_task9);
	printf("\n\n");
	printf("Для продолжения нажмите любую клавишу");
}

void task_ten()
{
	my_clear();
	printf("Задание № 10\n\n");
	int const NH_task10 = 5;
	int const NW_task10 = 10;
	int A[NH_task10][NW_task10];
	int stime;
	long ltime;
	ltime = time(NULL);
	stime = (unsigned)ltime / 2;
	srand(stime);

	for (int i = 0; i < NH_task10; i++) 
	{
		for (int j = 0; j < NW_task10; j++) 
		{
			A[i][j] = rand() % 100;
			printf(" [%d][%d]=%2d ", i, j, A[i][j]);
		}

		printf("\n");
	}
	printf("\n");
	int maxI;
	int maxJ;
	int i, j;
	maxI = 0;
	maxJ = 0;
	for (i = 1; i < NH_task10; i++) 
	{
		for (j = 1; j < NW_task10; j++) 
		{

			if (A[i][j] > A[maxI][maxJ]) 
			{
				maxI = i;
				maxJ = j;
			}
		}

	}

	printf("Максимальное значение массива [%d][%d] = %d", maxI, maxJ, A[maxI][maxJ]);
	printf("\n\n");
	printf("Для продолжения нажмите любую клавишу");
}



void task_eleven()
{
	my_clear();
	printf("Задание № 11\n\n");
	int const N_task11 = 5;
	int A[N_task11][N_task11];
	for (int i = 0; i < N_task11; i++) 
	{
		for (int j = 0; j < N_task11; j++) 
		{
			A[i][j] = rand() % 100;
			printf(" [%d][%d]=%2d ", i, j, A[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (int i = 0; i < N_task11; i++) 
	{
			for (int j = 0; j < N_task11; j++) 
			{
				if (A[i][j] % 2 == 0) 
					A[i][j] = 0;
				else
					A[i][j] = 1;
				if (i == j || i + j == 4)
					A[i][j] = 2;
				printf(" %d ",  A[i][j]); //[%d][%d]= i, j,
			}
				printf("\n");
	}

	printf("\n\n");
	printf("Для продолжения нажмите любую клавишу");
}

void task_twelve()
{
	my_clear();
	printf("Дополнительное задание № 12\n");
	int x1, x2, x3, y1, y2, y3;
	printf("Введите координаты трех точек:\n");
	printf("X(1) = ");
	scanf("%d", &x1);
	printf("Y(1) = ");
	scanf("%d", &y1);
	printf("X(2) = ");
	scanf("%d", &x2);
	printf("Y(2) = ");
	scanf("%d", &y2);
	printf("X(3) = ");
	scanf("%d", &x3);
	printf("Y(3) = ");
	scanf("%d", &y3);

	if ((x1 - x3) * (y2 - y3) - (x2 - x3) * (y1 - y3) == 0)
		printf("Невозможно построить треугольник!(точки лежат на одной прямой)\n\n");
	else
		printf("По этим координатам можно построить треугольник\n\n");

	printf("Для продолжения нажмите любую клавишу");
	mygetch();

}

void task_thirteen()
{
	my_clear();
	int size_x, in_circle, c_circle;// вписанная in_circle, описанная c_ccircle
	printf("Дополнительное задание № 13\n\n");
	printf("Введите длину стороны квадрата ");
	scanf("%d", &size_x);
	in_circle = size_x / 2;
	c_circle = size_x / sqrt(2);
	printf("\n");
	printf("Радиус вписанной окружности = %d\nРадиус описанной окружности = %d\n\n", in_circle, c_circle);
	printf("Для продолжения нажмите любую клавишу");
	mygetch();
}

void task_fourteen()
{
	my_clear();
	printf("Дополнительное задание № 14\n\n");//Ввести предложение и определить, сколько в нем слов
	printf("Введите текст:\n");
	int c, nw, state;
	int IN = 1;
	int OUT = 0;
	c = nw = 0;
	state = OUT;
	while ((c = getchar()) != 10) 
	{
		if (c == ' ' or c == '\t' or c == '\n')
			state = OUT;
		else if (state == OUT) 
		{
			state = IN;
			++nw;
		}

	}
	printf("Всего слов = %d\n\n", nw);
	printf("Для продолжения нажмите любую клавишу");
}