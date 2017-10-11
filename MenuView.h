
#ifndef MENU_VIEW_H
#define MENU_VIEW_H

#include <iostream>
#include "MenuView.h"

using namespace std;
class MenuViewObserver{
    public:
        virtual void gameRequested(int choice) = 0;
};

class MenuView{
    public:
        MenuView();
         MenuViewObserver *observer;
         void DisplayMenu();
        int getChoice(int choice);
};

#endif