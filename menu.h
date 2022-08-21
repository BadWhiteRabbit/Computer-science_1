//#ifndef INC_1_MAIN_MENU_MENU_H
//#define INC_1_MAIN_MENU_MENU_H
//#endif //INC_1_MAIN_MENU_MENU_H
#include "function.h"



using std::string;



class Menu {
public:
string HudName;             // Название текущего меню
int SizeMenu;               // Колличество  пунктов меню
string *ListName;           // Названия пунктов меню
char * FoundationMenu;      // Массив символов состоящий из пробелов
int Border;                 // Граница массива меню
int Buttom;                 // Управление меню
int PosStar;                // Координата '*'
int WeightConWin;           // Ширина консоли
public:


Menu(string hudname, int sizemenu) //конструктор
{
HudName = hudname;
SizeMenu = sizemenu;
FoundationMenu = new char[sizemenu];
ListName = new string[sizemenu];
Border = 0;
Buttom = 0;
PosStar = 0;
WeightConWin = 120;
}
 
    
    void weight_text(string *ListName) //метод для выравнивания текста
    {
        for (int i = 0; i < SizeMenu; ++i)
        {
            int S = ListName[i].length();
            int count = S / (WeightConWin - 4); // -4 это колличество неучитываемых элементов, от WeightConWin еще зависит 2 метода
            int pos = (WeightConWin + 1) - 4;

            if(count > 0)
            {
                for(; count != 0 ; --count) //количество переносов строки
                {
                    bool word = true;
                    while(word) // тут нужно будет поменять на случай если одно слово будет превышать размер поля
                    {
                        if(ListName[i][pos] == ' ')
                        {
                            ListName[i].replace(pos, 1, "\n");
                            pos = pos + (WeightConWin + 1) - 4; 
                            word = false;
                        }
                        else pos--;
                    }
                }//for count
            }//if count

        }

    }


    void stars_hud(string HudName) //отображение названия меню типа *********[название]********
    {
        
        int A = WeightConWin - HudName.length() - 2;
        int B = A / 2 + 2; // (+ 2) - костыль (выравнивание для [Задание №]), строка ниже тоже самое
        for (int i = 0; i < A + 2; ++i) 
        {
            std::cout << "*";
            if(i == B) std::cout <<"["<<HudName<<"]";
        }
        std::cout << "\n\n";
    }

   void stars_hud(string HudName, int NumberTask) //отображение названия меню типа *********[Задание №x]********
    {

        std::string s = std::to_string(NumberTask);

        int A = WeightConWin - HudName.length() - s.length() - 2;
        int B = A / 2;
        for (int i = 0; i < A; ++i) 
        {
            std::cout << "*";
            if(i == B) std::cout <<"["<< HudName << NumberTask << "]";
        }
        std::cout << "\n\n";
    }


    void init_menu(char* FoundationMenu, int SizeMenu) //инициализация меню пустым значением
    {
        for (int i = 0; i < SizeMenu; ++i) FoundationMenu[i] = ' ';
    }

    void print_menu(char* FoundationMenu, string *ListName, int SizeMenu) // отображение меню [*] название
    {
        for (int i = 0; i < SizeMenu; ++i) std::cout <<"["<< FoundationMenu[i] <<"] " << ListName[i] << "\n";
    }


    int menu_() 
    {
        weight_text(ListName);
        do
        {
            system("clear"); 
            stars_hud(HudName);
            init_menu(FoundationMenu, SizeMenu);
            FoundationMenu[PosStar] = '*';
            Border = PosStar;
            print_menu(FoundationMenu, ListName, SizeMenu);
            Buttom = mygetch();
            if (Buttom == 65) PosStar--;
            if (Buttom == 66) PosStar++;
            if (PosStar > SizeMenu - 1 || PosStar < 0) PosStar = Border;
        } while (Buttom != 10);

        return PosStar;
    }//menu_

int menu_(int NumberTask) //Меню для заданий
    {
       PosStar = 0;
        do
        {
            system("clear"); 

            stars_hud(HudName,NumberTask);
            init_menu(FoundationMenu, SizeMenu);
            FoundationMenu[PosStar] = '*';
            Border = PosStar;
            print_menu(FoundationMenu, ListName, SizeMenu);
            Buttom = mygetch();
            if (Buttom == 65) PosStar--;
            if (Buttom == 66) PosStar++;
            if (PosStar > SizeMenu - 1 || PosStar < 0) PosStar = Border;
        } while (Buttom != 10);
        return PosStar;
    }//menu_


};



