#include "MenuView.h"

MenuView::MenuView(){}

void MenuView::DisplayMenu(){
    int choice;
        cout <<"Choose which game you'd like to play!" <<endl
         <<"-------------------------------------" <<endl
         <<"1: Peg Jump" <<endl 
         <<"0: Exit" <<endl <<endl
         <<"Choice: ";
         cin>> choice;
    getChoice(choice);
     observer->gameRequested(choice);
}
int MenuView::getChoice(int choice){
    return choice;
}