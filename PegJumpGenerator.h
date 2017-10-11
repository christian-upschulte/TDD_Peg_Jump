#ifndef PEG_JUMP_GENERATOR_H
#define PEG_JUMP_GENERATOR_H

#include "PegJumpGenerator.h"


class PegJumpGenerator{
    public:
        int TotalWins;
        int TotalLosses;
        bool didWin;
    
        PegJumpGenerator(int Wins, int Losses);
        void playGame();
};

#endif
