#include <iostream>
#include "MenuView.h"
#include "MenuController.h"
#include "GameGenerator.h"
using namespace std;

int main(){
    MenuView MainMenu;
      
    GameGenerator Game;
    
    MenuController MControl(MainMenu);
  
    MControl.go();
    
   
    
    Game.getGame(MControl.gameChoice);
     
    cout<<"Thanks for playing!"<< endl;
}
