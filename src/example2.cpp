#include <iostream>

#include "Menu.hpp"

#define Print(str) std::cout << str << std::endl;

void primerItem();
void segundoItem();
void salir();

int main(int argc, char *argv[])
{
    SItem<void> fistItem = {"primer item", primerItem};
    SItem<void> secondItem = {"segundo item", segundoItem};
    SItem<void> quit = {"salir", salir};

    Menu menu({&fistItem, &quit}, {2, 8}, {true});
// you can add a new item after defining the menu
    menu.AppendItem(&secondItem);

    auto it = *menu.Loop();

    system("cls");
    (it->toDo)();

    return EXIT_SUCCESS;
}

void primerItem()
{
    Print("primer item");
}

void segundoItem()
{
    Print("segundo item");
}

void salir()
{
    Print("salir");
}