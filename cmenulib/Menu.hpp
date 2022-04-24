#include <iostream>
#include <string>
#include <vector>
#include <conio.h>

#include "__cutils.hpp"

using namespace std;

#ifndef Menu_h
#define Menu_h

template <class Tf>
struct SItem
{
    string text;
    Tf (*toDo)();
};

class Menu
{
    vector<SItem<void> *> szpItems;
    __cutils::SPoint ptTopLeft = {};
    __cutils::Cursor cursor;
    vector<SItem<void> *>::iterator itTarget;
    unsigned int width, height;

    inline void ShowItems()
    {
        for (size_t i = 0; i < szpItems.size(); i++)
        {
            __cutils::GoToXY(ptTopLeft.x + 3, ptTopLeft.y + i);
            cout << szpItems[i]->text;
        }
    }

    inline int LongestTextItem()
    {
        SItem<void> *anterior = *szpItems.begin();
        for (SItem<void> *it : szpItems)
        {
            if (anterior->text.length() < it->text.length())
            {
                anterior = it;
            }
        }
        return anterior->text.length();
    }

public:
    Menu(vector<SItem<void> *>, __cutils::SPoint);

    ~Menu(){};

    void AppendItem(SItem<void> *);

    bool MoveCursor();

    vector<SItem<void> *>::iterator Loop();
};

#endif