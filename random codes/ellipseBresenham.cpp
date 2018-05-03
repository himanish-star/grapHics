#include <iostream>
#include <graphics.h>

using namespace std;

void drawEllipse(int cx, int cy,int x, int y)
{
    putpixel(cx + x, cy - y, WHITE);
    putpixel(cx + x, cy + y, WHITE);
    putpixel(cx - x, cy - y, WHITE);
    putpixel(cx - x, cy + y, WHITE);
}

void myellipse(int cx, int cy, int a, int b)
{
    int x = 0, y = b;
    int d = 2 * b * b + a * a - 2 * a * a * b;
    drawEllipse(cx, cy, x, y);

    while (a * a * y > x * b * b) {
        if (d > 0) {
            d += (2 * b * b * (2 * x + 3) - 4 * a * a * (y - 1));
            y--;
        }
        else {
            d += (2 * b * b * (2 * x + 3));
        }
        x++;
        drawEllipse(cx, cy, x, y);

    }

    d = 2 * b * b * x * x + b * b + 2 * b * b * x + 2 * a * a * y * y + 2 * a * a - 4 * a * a * y - 2 * a * a * b * b;

    while (y >= 0) {
        if (d < 0) {
            d += (4 * b * b * (x + 1) - 2 * a * a * (2 * y - 3));
            x++;
        }
        else {
            d += 2 * a * a * (3 - 2 * y);
        }
        y--;
        drawEllipse(cx, cy, x, y);
    }
}

int main()
{
    initwindow(800, 500);

    int a, b, cx, cy;
    cout << "Enter the center of ellipse: ";
    cin >> cx >> cy;
    cout << "Enter the values of a and b for ellipse: ";
    cin >> a >> b;

    myellipse(cx, cy, a, b);

    getch();
    return 0;
}

