#include <iostream>
#include <string>
#include <conio.h>

#include "Menu.hpp"

using namespace std;

void NewGame();

void LoadGame();

void QuitGame();

void Loading();

int main()
{
    SItem<void> ng = {"new game", NewGame};
    SItem<void> lg = {"load game", LoadGame};
    SItem<void> qg = {"quit game", QuitGame};

    Menu menu({&ng, &lg, &qg}, {0, 3});

    auto it = *menu.Loop();
    system("cls");
    (it->toDo)();

    _getch();

    main();
}

void NewGame()
{
    cout << "starting a new game" << endl;
}

void LoadGame()
{
    SItem<void> slot1 = {"slot 1", Loading};
    SItem<void> slot2 = {"slot 2", Loading};

    Menu loadMenu({&slot1, &slot2}, {1, 4});

    ((*loadMenu.Loop())->toDo)();
}

void QuitGame()
{
    cout << "game over! thanks for playing" << endl;
}

void Loading()
{
    cout << "loading ..." << endl;
}