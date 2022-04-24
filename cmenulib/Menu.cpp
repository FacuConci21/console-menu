#include "Menu.hpp"

Menu::Menu(list<SItem<void> *> _items, __cutils::SPoint _ptTopLeft = {0, 0})
    : szpItems(_items),
      ptTopLeft(_ptTopLeft),
      cursor({_ptTopLeft}),
      itTarget(szpItems.begin())
{
    height = szpItems.size();
    width = LongestTextItem();
};
Menu::Menu(list<SItem<void> *> _items, __cutils::SPoint _ptTopLeft = {0, 0}, SAppearance _appearance = {false})
    : szpItems(_items),
      ptTopLeft(_ptTopLeft),
      cursor({_ptTopLeft}),
      itTarget(szpItems.begin()),
      sbAppearance(_appearance)
{
    height = szpItems.size();
    width = LongestTextItem();
};

void Menu::AppendItem(SItem<void> *_item)
{
    szpItems.push_back(_item);
}

bool Menu::MoveCursor()
{
    cursor.PutCursorInConsole();

    switch (_getch())
    {
    case 72:
        cursor.ClearCursorCurrentPosition();
        cursor.MoveUp();

        if (itTarget != szpItems.begin())
            itTarget--;
        // itTarget = szpItems.begin();

        break;
    case 80:
        cursor.ClearCursorCurrentPosition();
        cursor.MoveDown(szpItems.size() - 1);

        if (itTarget != szpItems.end())
            itTarget++;
        else
            itTarget = szpItems.end()--;

        break;
    case 13:
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