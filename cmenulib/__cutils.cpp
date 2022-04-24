#include "__cutils.hpp"

namespace __cutils
{
    void GoToXY(int _x, int _y)
    {
        HANDLE H_CONSOLE = GetStdHandle(STD_OUTPUT_HANDLE);

        COORD dwPosition;

        dwPosition.X = _x;
        dwPosition.Y = _y;

        SetConsoleCursorPosition(H_CONSOLE, dwPosition);
    }

    void DrawVerticalLine(int _x, int _y_0, int _y_1)
    {
        for (int y = _y_0; y < _y_1; y++)
        {
            GoToXY(_x, y);
            _putch('|');
        }
    }

    void DrawHorizontalLine(int _y, int _x_0, int _x_1)
    {
        for (int x = _x_0; x < _x_1; x++)
        {
            GoToXY(x, _y);
            _putch('-');
        }
    }

    void Cursor::MoveDown(int _max)
    {
        ptCurrentPosition.y++;
        if (ptCurrentPosition.y > (ptStartPosition.y + _max))
        {
            ptCurrentPosition.y = ptStartPosition.y + _max;
        }
    }

    void Cursor::MoveUp()
    {
        ptCurrentPosition.y--;
        if (ptCurrentPosition.y < ptStartPosition.y)
        {
            ptCurrentPosition.y = ptStartPosition.y;
        }
    }

}
