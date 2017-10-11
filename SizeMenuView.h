#ifndef SIZE_MENU_VIEW_H
#define SIZE_MENU_VIEW_H

#include <iostream>
#include "SizeMenuView.h"

using namespace std;

class SizeMenuViewObserver{
    public:
        virtual void sizeRequested(int choice) = 0;
};

class SizeMenuView{
    public:
        SizeMenuView();
        SizeMenuViewObserver *observer;
        void DisplayMenu();

};

#endif