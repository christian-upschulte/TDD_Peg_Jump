#ifndef GAME_GENERATOR_H
#define GAME_GENERATOR_H

#include "GameGenerator.h"


class GameGenerator{
    public:
        int TotalWins;
        int TotalLosses;
        
        GameGenerator();
        void getGame(int choice);
};

#endif