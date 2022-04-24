#include <iostream>

#include "Menu.hpp"

#define Print(str) std::cout << str << std::endl;

void primerItem();
void segundoItem();

int main(int argc, char *argv[])
{
    SItem<void> fistItem = {"primer item", primerItem};
    SItem<void> secondItem = {"segundo item", segundoItem};

    Menu menu({&fistItem, &secondItem}, {0, 4});

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