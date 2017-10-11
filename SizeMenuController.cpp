#include "SizeMenuController.h"

SizeMenuController::SizeMenuController(SizeMenuView &inSMView): sizeMenuView(inSMView){
    sizeMenuView.observer = this;
}

void SizeMenuController::go(){
   sizeMenuView.DisplayMenu();
}

// View Observer
void SizeMenuController::sizeRequested(int choice){
    sizeChoice = choice;
}