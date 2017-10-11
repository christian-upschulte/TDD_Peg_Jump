#include "GameGenerator.h"
#include "PegJumpGenerator.h"
#include <iostream>
using namespace std;

GameGenerator::GameGenerator(){
    TotalWins = 0;
    TotalLosses = 0;
}


void GameGenerator::getGame(int choice){
    char again;
    switch (choice){
        case 1:
            do{
                PegJumpGenerator PegGame(TotalWins, TotalLosses);
                PegGame.playGame();
                
                if(PegGame.didWin == true)
                    TotalWins++;
                else
                    TotalLosses++;
                
                cout<<"Would you like to play again?"<< endl;
                cout<<" Y/y for yes, any other key to exit"<< endl;
                cin>> again;
            }while(again == 'Y' || again == 'y');
            break;
    }
}