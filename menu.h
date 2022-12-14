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

Menu(string hudname, int sizemenu) 
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
 
bool is_word(std::string B, int i) // для метода LineBreak
{
    if(B[i] == ' ') return true;
    else return false;
}

void LineBreak(std::string B, int weightwindow) // Метод для выравнивания текста (Только английский язык)
{
    
    int size = B.length() / weightwindow;
    std::cout << "size = " << size << "\n";
    int pos = weightwindow;
    for(int i = 0; i != size; ++i)
    {
        
        while(is_word(B,pos) != true) --pos;
        B.replace(pos, 1, "\n");
        pos = pos + weightwindow;
    
    }

    std::cout << B << std::endl; 
}
void stars_hud() //отображение названия меню типа *********[название]******** string HudName
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

void stars_hud( int NumberTask) //отображение названия меню типа *********[Задание №x]********
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

    void init_menu() //инициализация меню пустым значением
    {
        for (int i = 0; i < SizeMenu; ++i) FoundationMenu[i] = ' ';
    }

    void print_menu() // отображение меню [*] название //char* FoundationMenu, string *ListName, int SizeMenu
    {
        for (int i = 0; i < SizeMenu; ++i) std::cout <<"["<< FoundationMenu[i] <<"] " << ListName[i] << "\n";
    }


int menu_() 
{
    do
    {
        system("clear");
        stars_hud();
        init_menu();
        FoundationMenu[PosStar] = '*';
        Border = PosStar;
        print_menu();
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
        system("clear");  //cls
        stars_hud(NumberTask); //HudName
        init_menu(); //FoundationMenu, SizeMenu
        FoundationMenu[PosStar] = '*';
        Border = PosStar;
        print_menu(); //FoundationMenu, ListName, SizeMenu
        Buttom = mygetch();
        if (Buttom == 65) PosStar--;
        if (Buttom == 66) PosStar++;
        if (PosStar > SizeMenu - 1 || PosStar < 0) PosStar = Border;
    } while (Buttom != 10);
    return PosStar;
    }//menu_
};



