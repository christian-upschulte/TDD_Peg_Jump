#ifndef BOARD_GENERATOR_H
#define BOARD_GENERATOR_H

#include <iostream>

#include "BoardGenerator.h"


class BoardGenerator{
    public:
        int TotalWins;
        int TotalLosses;
        bool didWin;
    
        BoardGenerator(int Wins, int Losses);
        
        void getBoard(int choice);
        
        template <int x, int y>
        void displayBoard(char (&board)[x][y]);
        
        template <int x, int y>
        void playPegJump(char (&board)[x][y]);
        
        template <int x, int y>
         void Move(char(&board)[x][y]);
        
        template< int x, int y>
        bool MoveExists(char(&board)[x][y]);
        
        template< int x, int y >
        void MakeMove(int i, int j, char pegChoice, int jumpChoice, int &zeroCount, char(&board)[x][y]);
        
        void UpdateWins();
        void UpdateLosses();
        
        template <int x, int y>
        bool validPeg(char choice, char(&board)[x][y]);
        bool validJump(int  choice);
};

#endif