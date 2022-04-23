::g++ -I ./headers  ./sources/main.cpp ./sources/Menu.cpp ./sources/__utils.cpp -o menu_test
::cls
::menu_test


cd build

cmake .. -G "MinGW Makefiles"

mingw32-make