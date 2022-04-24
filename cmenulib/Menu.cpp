#include "Menu.hpp"

Menu::Menu(list<SItem<void> *> _items, __cutils::SPoint _ptTopLeft)
    : szpItems(_items),
      ptTopLeft(_ptTopLeft),
      cursor({_ptTopLeft}),
      itTarget(szpItems.begin())
{
    height = szpItems.size();
    width = LongestTextItem();
};

void Menu::AppendItem(SItem<void> *_item)
{
    szpItems.push_back(_item);
}

void Menu::InsertItemAt(SItem<void> *_item, unsigned int _at)
{
    if (szpItems.size() < _at)
        throw std::runtime_error("Has indicado un indice mayor a la cantidad de elementos en la lista.");
    else
        szpItems.insert(next(szpItems.begin(), _at), _item);
}

bool Menu::MoveCursor()
{
    cursor.PutCursorInConsole();

    switch (_getch())
    {
    case KEY_ARROW_UP:
        cursor.ClearCursorCurrentPosition();
        cursor.MoveUp();

        if (itTarget != szpItems.begin())
            itTarget--;
        // itTarget = szpItems.begin();

        break;
    case KEY_ARROW_DOWN:
        cursor.ClearCursorCurrentPosition();
        cursor.MoveDown(szpItems.size() - 1);

        if (itTarget != szpItems.end())
            itTarget++;
        else
            itTarget = szpItems.end()--;

        break;
    case KEY_ENTER:
        return false;
    default:
        return true;
    }

    return true;
}

list<SItem<void> *>::iterator Menu::Loop()
{
    bool inLoop;
    system("cls");

    ShowItems();

    do
    {
        inLoop = MoveCursor();
    } while (inLoop);

    return itTarget;
}