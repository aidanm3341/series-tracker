#ifndef WINDOW_H
#define WINDOW_H

class Window
{
    int width, height, y, x;
    public:
        Window(int height, int width, int y, int x);
        ~Window();
};

#endif
