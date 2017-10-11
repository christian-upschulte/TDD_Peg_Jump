//MenuController
#include "MenuController.h"

MenuController::MenuController(MenuView &inMenuView): menuView(inMenuView){
  menuView.observer = this;
}
void MenuController::go(){
    menuView.DisplayMenu();
}

// View Observer
void MenuController::gameRequested(int choice){
    gameChoice = choice;
}