#include "GameGenerator.h"
#include "SizeMenuView.h"
#include "SizeMenuController.h"
#include "PegJumpGenerator.h"
#include "BoardGenerator.h"
PegJumpGenerator::PegJumpGenerator(int Wins, int Losses){
    TotalWins = Wins;
    TotalLosses = Losses;
}

void PegJumpGenerator::playGame(){
    SizeMenuView SizeChoice;
    BoardGenerator board(TotalWins, TotalLosses);
    didWin = board.didWin;
    SizeMenuController SControl(SizeChoice);
    SControl.go();
    board.getBoard(SControl.sizeChoice);
}