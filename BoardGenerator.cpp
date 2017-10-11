#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "BoardGenerator.h"
using namespace std;

BoardGenerator::BoardGenerator(int Wins, int Losses){
    TotalWins = Wins;
    TotalLosses = Losses;
}

void BoardGenerator::getBoard(int choice){
    ifstream fin; 
  
    switch (choice){
        case 0:
            exit(0);
            break;
        case 1:
            cout<<"   SCORE" <<endl
                <<"-----------" <<endl
                <<"  Wins: " <<TotalWins <<endl
                <<"Losses: " <<TotalLosses <<endl;
            break;
        case 5:
        {
            char board[7][13];
            fin.open("FiveWide.txt");
            for(int i=0; i<7; i++){
                for(int j=0; j<13; j++){
                    fin >> board[i][j];
                }
            }
            board[1][6] = '.';
            playPegJump(board);
            break;
        }
        case 6:
        {
            char board[8][15];
            fin.open("SixWide.txt");
            for(int i=0; i<8; i++){
                for(int j=0; j<15; j++){
                    fin >> board[i][j];
                }
            }
            board[1][7] = '.';
            playPegJump(board);
            break;
        }
        case 7:
        {
            char board[9][17];
            fin.open("SevenWide.txt");
            for(int i=0; i<9; i++){
                for(int j=0; j<17; j++){
                    fin >> board[i][j];
                }
            }
              board[1][8] = '.';
            playPegJump(board);
            break;
        }
        case 8:
            exit(0);
            break;

    }
   
    fin.close();
}

template <int x, int y>
void BoardGenerator::displayBoard(char (&board)[x][y]){
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            cout << board[i][j];
        }
        cout << endl;
    }
}

template <int x, int y>
void BoardGenerator::playPegJump(char (&board)[x][y]){    
    displayBoard(board);
    Move(board);
}

template <int x, int y>
void BoardGenerator::Move(char (&board)[x][y]){
    char pegChoice;
    int jumpChoice;
    int zeroCount = 1;
    bool solved = false;
    
    do{
        if(MoveExists(board)){
            cout<<"Which peg do you wish to move? (Enter '1' to Exit, '2' to see Score)"<< endl;
            do{
                cin>>pegChoice;
                if(validPeg(pegChoice, board))
                    cout<<"Try Again"<< endl;
            }while(validPeg(pegChoice, board));
            if (pegChoice == '1'){exit(0);}
            else if (pegChoice == '2'){
                cout<<"   SCORE" <<endl
                <<"-----------" <<endl
                <<"  Wins: " <<TotalWins <<endl
                <<"Losses: " <<TotalLosses <<endl;
            }
            
            cout<<"Which direction do you want to jump?"<< endl;
            cout<<"1. NW" << endl
                <<"2. NE" << endl
                <<"3. E" << endl
                <<"4. SE" << endl
                <<"5. SW" << endl
                <<"6. W" << endl
                <<"7. See Current Score" <<endl
                <<"8. Exit the Program" <<endl
                <<"Please input the number" <<endl;
                do{
                    cin>> jumpChoice;
                    if (!validJump(jumpChoice))
                        cout<<"Try Again"<< endl;
                }while(!validJump(jumpChoice));
            for(int i=0; i<x; i++){
                for(int j=0; j<y; j++){
                    if (board[i][j] == pegChoice){
                        MakeMove(i, j, pegChoice, jumpChoice, zeroCount, board);
                        break;
                    }
                }      
            }

            for(int i=0; i<x; i++){
                for(int j=0; j<y; j++){
                    cout << board[i][j];
                }
                cout << endl;
            }
        }
        else{
            solved = true;
            
            switch(zeroCount){
                case 14:
                    if (y == 13){
                        cout<<"You win!!" <<endl;
                        UpdateWins();
                    }
                    else{
                        cout<<"You lose." <<endl;
                        UpdateLosses();
                    }
                    break;
                case 20:
                    if (y == 15){
                        cout<<"You win!!" <<endl;
                        UpdateWins();
                    }
                    else{
                        cout<<"You lose." <<endl;
                        UpdateLosses();
                    }
                    break;
                case 27:
                    if (y == 17){
                        cout<<"You win!!" <<endl;
                        UpdateWins();
                    }
                    else{
                        cout<<"You lose." <<endl;
                        UpdateLosses();
                    }
                    break;
                default:
                    cout<<"You lose." <<endl;
                    UpdateLosses();
                    break;
            }
        }
    }while(!solved);
}

template< int x, int y> 
bool BoardGenerator::MoveExists(char(&board)[x][y]){
    bool moveExists = false;
        for(int i=0; i<x; i++){
            for(int j=0; j<y; j++){
                if (isalpha(board[i][j])|| board[i][j]=='&' || board[i][j] == '@'){
                    if (board[i+1][j+1] !='.' && board[i+2][j+2]=='.'){//SE
                        moveExists = true;
                    }
                    else if (board[i-1][j+1] != '.' && board[i-2][j+2]=='.'){//NE
                        moveExists = true;
                    }
                    else if (board[i][j-2] != '.' && board[i][j-4]=='.'){//W
                        moveExists = true;
                    }
                     else if (board[i-1][j-1] != '.' && board[i-2][j-2]=='.'){//NW
                        moveExists = true;
                    }
                    else if(board[i+1][j-1] !='.' && board[i+2][j-2] == '.'){//SW
                        moveExists = true;
                    }
                    else if (board[i][j+2] != '.' && board[i][j+4]=='.'){//E
                        moveExists = true;  
                    }
                }
            }
        }
    return moveExists;
}

template< int x, int y >
void BoardGenerator::MakeMove(int i, int j, char pegChoice, int jumpChoice, int &zeroCount, char(&board)[x][y]){
  
    switch(jumpChoice){
        case 1://NW
            if (board[i-1][j-1] !='.' && board[i-2][j-2]=='.'){
                board[i-2][j-2] = pegChoice;
                board[i][j]='.';
                board[i-1][j-1] = '.';
                zeroCount++;
            }
            else{
                cout<<"Invalid Move, Try again!"<< endl;
            }
            break;
        case 2://NE
            if (board[i-1][j+1] != '.' && board[i-2][j+2]=='.'){
                board[i-2][j+2] = pegChoice;
                board[i][j]='.';
                board[i-1][j+1] = '.';
                zeroCount++;
            }
            else{
                cout<<"Invalid Move, Try again!"<< endl;
            }
            break;
        case 3://E
            if (board[i][j+2] != '.' && board[i][j+4]=='.'){
                board[i][j+4] = pegChoice;
                board[i][j]='.';
                board[i][j+2] = '.';
                zeroCount++;
            }
            else{
                cout<<"Invalid Move, Try again!"<< endl;
            }
            break;
        case 4://SE
            if (board[i+1][j+1] != '.' && board[i+2][j+2]=='.'){
                board[i+2][j+2] = pegChoice;
                board[i][j]='.';
                board[i+1][j+1] = '.';
                zeroCount++;
            }
            else{
                cout<<"Invalid Move, Try again!"<< endl;
            }
            break;
        case 5://SW
            if (board[i+1][j-1] != '.' && board[i+2][j-2] == '.'){
                board[i+2][j-2] = pegChoice;
                board[i][j]='.';
                board[i+1][j-1] = '.';     
                zeroCount++;
            }
            else{
                cout<<"Invalid Move, Try again!"<< endl;
            }
            break;
        case 6://W
            if (board[i][j-2] != '.' && board[i][j-4]=='.'){
                board[i][j-4] = pegChoice;
                board[i][j]='.';
                board[i][j-2] = '.';
                zeroCount++;
            }
            else{
                cout<<"Invalid Move, Try again!"<< endl;
            }
            break;
        case 7:
            cout<<"   SCORE" <<endl
                <<"-----------" <<endl
                <<"  Wins: " <<TotalWins <<endl
                <<"Losses: " <<TotalLosses <<endl;
            break;
        case 8:
            exit(0);

    
         
    }
}
template <int i, int j>
bool BoardGenerator::validPeg(char choice, char(&board)[i][j])
{ 
    if(j == 17)
    {
        if(isalpha(board[i][j]) || board[i][j]=='&' || board[i][j] == '@'){
            return true;  
        }
    }
    else if (j==15){
        if(isalpha(board[i][j]) &&  board[i][j]!='v' &&  board[i][j]!='w'&&  board[i][j]!='x'&&  board[i][j]!='y'&&  board[i][j]!='z')
        {
            return true;
        }
    }
    else if (j==13){
        if(isalpha(board[i][j]) && board[i][j]!='u' && board[i][j]!='t' && board[i][j]!='s' && board[i][j]!='r' && board[i][j]!='q' && board[i][j]!='p' && board[i][j]!='v' &&  board[i][j]!='w'&&  board[i][j]!='x'&&  board[i][j]!='y'&&  board[i][j]!='z')
        {
            return true;
        }
    }
    return false;
}
bool BoardGenerator::validJump(int  choice){
    if(choice>0 && choice<9)
    {
        return true;
    }
    return false;
}


void BoardGenerator::UpdateWins(){
    didWin = true;
}

void BoardGenerator::UpdateLosses(){
    didWin = false;
}