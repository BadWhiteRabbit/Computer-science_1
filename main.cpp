/*  
    * Данная контрольная работа по информатике предназначена для студентов первого
    курса по направлению "Информатики и вычислительной техники"
    большая просьба к студентам не копипастить все задания, а в случае
    если что то не понятно разбирать код и делать самостоятельно.
    Я знаю, что мой код получился ... но я специально не исправлял свои ошибки
    чтобы в будующем увидеть свой прогресс.

    * В объекте меню присутствует метод для автоматического переноса слов со строки,
    здесь организован ручной перенос т.к. не решил проблему с русским текстом
    (с английским работает нормально)

    *По всем вопросам оброщайтесь (Telegram https://t.me/Tomboy9_4)

*/
#include "menu.h"
int main() 
{
    
Menu MainMenu("Главное меню", 15);
Menu Task_Menu("Задание №", 2);
Menu Choose_Menu_Task4("Вы хотите использовать случайный набор чисел?",2);

MainMenu.ListName[0] = "1.Ввести 2-значное число (типа ab), вывести 4-значное число (типа aabb)\n";
MainMenu.ListName[1] = "2.Ввести коэффициенты квадратного уравнения и выдать либо сообщение,\nчто уравнение не квадратное, либо сообщение о количестве и значении корней\n";
MainMenu.ListName[2] = "3.Ввести целое число не более чем из 10 разрядов и цифру. Проверить, что цифра входит в число.\n";
MainMenu.ListName[3] = "4.Ввести массив из чисел (из 30 элементов) и найти среднее арифметическое значение его элементов.\n";
MainMenu.ListName[4] = "5.Создать массив из цифр (из 20 элементов) и инвертировать его (т.е. вывернуть задом наперед).\n";
MainMenu.ListName[5] = "6.Создать массив из целых 2-значных чисел  (из 20 элементов) и выполнить циклический\nсдвиг на 3 элемента вправо.\n";
MainMenu.ListName[6] = "7.Ввести массив из целых чисел  (из 10 элементов) и проверить, что он упорядочен\nпо невозрастанию (убыванию).\n";
MainMenu.ListName[7] = "8.Создать массив из целых чисел  (из 10 элементов) и отсортировать методом пузырька\nпо невозрастанию (убыванию).\n";
MainMenu.ListName[8] = "9.Создать массив из целых чисел  (из 10 элементов) и отсортировать методом выбора\nпо невозрастанию (убыванию).\n";
MainMenu.ListName[9] = "10.Создать 2-мерный массив из цифр  5х10 элементов и найти максимальный\nэлемент с указанием его номера строки и номера столбца.\n";
MainMenu.ListName[10] = "11.Ввести 2-мерный массив из целых чисел  5х5 элементов и заменить\nчетные на 0, нечетные на 1, на двух диагоналях поставить 2.\n";
MainMenu.ListName[11] = "12.Ввести координаты трех точек на плоскости и проверить возможность\nсуществования треугольника с вершинами в этих точках(программа из двух функций).\n";
MainMenu.ListName[12] = "13.По длине стороны квадрата определить радиусы вписанной и описанной\nокружностей (две функции, указатели).\n";
MainMenu.ListName[13] = "14.Ввести предложение и определить, сколько в нем слов.\n";
MainMenu.ListName[14] = "15.Выход.";

Task_Menu.ListName[0] = " Проверить задание.\n";
Task_Menu.ListName[1] = " Назад в главное меню.\n";

Choose_Menu_Task4.ListName[0] = "Да\n";
Choose_Menu_Task4.ListName[1] = "Нет\n";


int A;
int B;
int C;
    
        
go_menu:      
system("clear");
A = MainMenu.menu_();
                    
switch (A) 
{
    case 0:
    {
        task_0:                    
        B = Task_Menu.menu_(A + 1);
        if(B == 1) goto go_menu;
    
        task_one();
                
        B = mygetch();
        goto task_0;
                                               
    }
                    
    case 1:
    {
        task_1:                    
        B = Task_Menu.menu_(A + 1);
        if(B == 1) goto go_menu;
        
        task_two();

        B = mygetch();
        goto task_1;
    }
                    
    case 2:
    {
        task_2:                    
        B = Task_Menu.menu_(A + 1);
        if(B == 1) goto go_menu;

        task_tree();

        B = mygetch();
        goto task_2;
    }

    case 3:
    {
        task_3:                    
        B = Task_Menu.menu_(A + 1);
        if(B == 1) goto go_menu;
        C = Choose_Menu_Task4.menu_();

        task_four(C);

        B = mygetch();
        goto task_3;
    }

    case 4:
    {
        task_4:                    
        B = Task_Menu.menu_(A + 1);
        if(B == 1) goto go_menu;

        task_five();

        B = mygetch();
        goto task_4;
    }
                   
    case 5:
    {
        task_5:                    
        B = Task_Menu.menu_(A + 1);
        if(B == 1) goto go_menu;

        task_six();

        B = mygetch();
        goto task_5;
    }

    case 6:
    {
        task_6:                    
        B = Task_Menu.menu_(A + 1);
        if(B == 1) goto go_menu;

        task_seven();

        B = mygetch();
        goto task_6;
    }

    case 7:
    {
        task_7:                    
        B = Task_Menu.menu_(A + 1);
        if(B == 1) goto go_menu;

        task_eight();

        B = mygetch();
        goto task_7;
    }

    case 8:
    {
        task_8:                    
        B = Task_Menu.menu_(A + 1);
        if(B == 1) goto go_menu;

        task_nine();

        B = mygetch();
        goto task_8;
    }

    case 9:
    {
        task_9:                    
        B = Task_Menu.menu_(A + 1);
        if(B == 1) goto go_menu;

        task_ten();

        B = mygetch();
        goto task_9;
    }

    case 10:
    {
        task_10:                    
        B = Task_Menu.menu_(A + 1);
        if(B == 1) goto go_menu;

        task_eleven();

        B = mygetch();
        goto task_10;
    }
    case 11:
    {
        task_11:                    
        B = Task_Menu.menu_(A + 1);
        if(B == 1) goto go_menu;

        task_twelve();

        B = mygetch();
        goto task_11;
    }
    case 12:
    {
        task_12:                    
        B = Task_Menu.menu_(A + 1);
        if(B == 1) goto go_menu;

        task_thirteen();

        B = mygetch();
        goto task_12;
    }

    case 13:
    {
        task_13:                    
        B = Task_Menu.menu_(A + 1);
        if(B == 1) goto go_menu;

        task_fourteen();

        B = mygetch();
        goto task_13;
    }

    case 14:
    {
        system("clear");
        return 0;
    }

}//SWICH
     
    return 0;
}
