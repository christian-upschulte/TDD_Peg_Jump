#include "SizeMenuView.h"

SizeMenuView::SizeMenuView(){}

void SizeMenuView::DisplayMenu(){
    int choice = 0;
    
    cout <<"Choose the size of peg board!" <<endl
         <<"-------------------------------------" <<endl
         <<"5: 5 Peg Length" <<endl
         <<"6: 6 Peg Length "<< endl
         <<"7: 7 Peg Length"<< endl << endl
         <<"1: View Score" << endl
         <<"0: Exit" <<endl <<endl
         <<"Choice: ";
         
    cin >>choice;
    observer->sizeRequested(choice);
}