#include <iostream>
#include <string>
#include <vector>
#include <list>
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
    void *submenu;

    SItem(string _text, Tf (*_toDo)()): text(_text), toDo(_toDo), submenu(nullptr) {}
    SItem(string _text, void *_submenu): text(_text), toDo(nullptr), submenu(_submenu) {}

    ~SItem() { ::operator delete(submenu); }
};

struct SAppearance
{
    bool rectangle = false;
};

class Menu
{
    list<SItem<void> *> szpItems;
    __cutils::SPoint ptTopLeft = {};
    __cutils::Cursor cursor;
    list<SItem<void> *>::iterator itTarget;
    unsigned int width, height;
    SAppearance sbAppearance = {};

    inline void ShowItems()
    {
        int i = 0;
        for (list<SItem<void> *>::iterator it = szpItems.begin(); it != szpItems.end(); it++)
        {
            __cutils::GoToXY(ptTopLeft.x + 3, ptTopLeft.y + i);
            cout << (*it)->text;
            i++;
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
    Menu(list<SItem<void> *> _items, __cutils::SPoint _ptTopLeft = {0, 0});

    ~Menu(){};

    void AppendItem(SItem<void> *_item);

    void InsertItemAt(SItem<void> *_item, unsigned int _at);

    bool MoveCursor();

    list<SItem<void> *>::iterator Loop();
};

#endif