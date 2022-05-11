#include <iostream>

#include "Menu.hpp"

#define Print(str) std::cout << str << std::endl;

void primerItem();
void segundoItem();
void salir();
// declare some extra functions
void subPrimerItem();
void subSegundoItem();

int main(int argc, char *argv[])
{
    // create some extra items, basics items
    SItem<void> subFistItem = { "primer item", subPrimerItem };
    SItem<void> subSecondItem = { "segundo item", subSegundoItem };

    // create new menu, this will be the submenu
    Menu* submenu = new Menu({ &subFistItem, &subSecondItem }, { 10, 8 });

    // pass the submenu as argument to any of these items
    SItem<void> fistItem = {"primer item", primerItem};
    SItem<void> secondItem = {"segundo item", static_cast<void*>(submenu)};
    SItem<void> quit = {"salir", salir};

    Menu menu({&fistItem, &quit}, {2, 8});
    // you can add a new item after defining the menu
    // menu.AppendItem(&secondItem); // add the item to the end
    menu.InsertItemAt(&secondItem, 1); // add the item in an especific place
    
    // call the loop
    auto it = *menu.Loop();

    // and then control if the toDo pointer or the submenu pointer are nullpointers
   if (it->toDo == nullptr)
    {
        // cast the submenu pointer in compiling time to a Menu type and call his loop
        auto subIt = *(static_cast<Menu*>(it->submenu))->Loop();
        system("cls");
        (subIt->toDo)();
    }
    else
    {
        system("cls");
        (it->toDo)();
    }

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

void subPrimerItem()
{
    Print("sub primer item");
}

void subSegundoItem()
{
    Print("sub segundo item");
}