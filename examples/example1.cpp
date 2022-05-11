#include <iostream>
// include the library
#include "Menu.hpp"

#define Print(str) std::cout << str << std::endl;

// define some functions
void primerItem();
void segundoItem();

/*    MOST BASIC USAGE    */
int main(int argc, char *argv[])
{
    // create an item object per function defined
    SItem<void> fistItem = {"primer item", primerItem};
    SItem<void> secondItem = {"segundo item", segundoItem};

    // create the menu class instance
    Menu menu({&fistItem, &secondItem}, {0, 4});

    // call the loop menu and save his result in a variable
    // in this case the menu loop returns a iterator
    auto it = *menu.Loop();
    // clear the screen (bad practice)
    system("cls");
    // execute the funtion returned, whatever it was.
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