//MenuController.h
#ifndef MENU_CONTROLLER_H
#define MENU_CONTROLLER_H

#include "MenuController.h"
#include "MenuView.h"


class MenuController :public MenuViewObserver
{
    public:
        int gameChoice;
    
        MenuController(MenuView &inMenuView);
        void go();
        
         virtual void gameRequested(int choice);
         
    private:
        MenuView &menuView;
};

#endif