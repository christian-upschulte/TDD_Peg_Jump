#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>
#include <netinet/in.h>

#include "TestBoard.h"
#include "../BoardGenerator.cpp"

class MockBoard : public BoardGenerator{
    public:
        string getTextFileName()
        {
            return "FiveWide.txt";
        }
        
        string testTextFileName(string textFile)
        {
            if (textFile == "FiveWide.txt" || textFile == "SixWide.txt" || textFile == "SevenWide.txt")
                return textFile;
            else
                return "gobbledygook";
        }
        
        int getDirection()
        {
            return 1;
        }
        
        int testDirection(int dir)
        {
            if (dir == 1 || dir == 2 || dir == 3 || dir == 4 || dir == 5 || dir == 6)
                return dir;
            else
                return -1;
        }
        bool getDirectionExist()
        {
            char test[5][5];
            ifstream fin;
            fin.open("testPegs.txt");
            for(int i=0; i<5; i++){
                for(int j =0; j<5; j++){
                    fin >> test[i][j];
                }
            }
            fin.close();
             for(int i=0; i<5; i++){
                for(int j =0; j<5; j++){
                   if (test[i+1][j+1] !='*' && test[i+2][j+2]=='*'){//SE
                        return true;
                    }
                }
             }
            return false;
        }
        
        bool testDirectionExist()
        {
            bool test1, test2, test3, test4, test5, test6;
            test1 = false;
            test2=false;
            test3=false;
            test4=false;
            test5=false;
            test6=false;
            char board[5][5];
            ifstream fin;
            fin.open("testPegs.txt");
            for(int i=0; i<5; i++){
                for(int j =0; j<5; j++){
                    fin >> board[i][j];
                }
            }
            fin.close();
             for(int i=0; i<5; i++){
                for(int j =0; j<5; j++){
                    if (board[i+1][j+1] !='*' && board[i+2][j+2]=='*'){//SE
                        test1 = true;
                    }
                    if (board[i-1][j+1] != '*' && board[i-2][j+2]=='*'){//NE
                        test2 = true;
                    }
                    if (board[i][j-1] != '*' && board[i][j-2]=='*'){//W
                        test3 = true;
                    }
                    if (board[i-1][j-1] != '*' && board[i-2][j-2]=='*'){//NW
                        test4 = true;
                    }
                    if(board[i+1][j-1] !='*' && board[i+2][j-2] == '*'){//SW
                        test5 = true;
                    }
                    if (board[i][j+1] != '*' && board[i][j+2]=='*'){//E
                        test6 = true;  
                    }
                }
             }
             return (test1 && test2 && test3 && test4 && test5 && test6);
        }
};

void TestBoard::TestBoardCorrectness5(void)
{
    MockBoard board;
    string test = "FiveWide.txt";
    CPPUNIT_ASSERT(test == board.getTextFileName());
}

void TestBoard::TestBoardCorrectnessAll(void)
{
    MockBoard board;
    string test1 = board.testTextFileName("FiveWide.txt");
    string test2 = board.testTextFileName("SixWide.txt");
    string test3 = board.testTextFileName("SevenWide.txt");
    CPPUNIT_ASSERT((test1 == "FiveWide.txt" || test1 == "SixWide.txt" || test1 == "SevenWide.txt") && 
                   (test2 == "FiveWide.txt" || test2 == "SixWide.txt" || test2 == "SevenWide.txt") && 
                   (test3 == "FiveWide.txt" || test3 == "SixWide.txt" || test3 == "SevenWide.txt"));
}

void TestBoard::TestMove1(void)
{
    MockBoard board;
    CPPUNIT_ASSERT(1 == board.getDirection());
}

void TestBoard::TestMoveAny(void)
{
    MockBoard board;
    int test1 = board.testDirection(1);
    int test2 = board.testDirection(2);
    int test3 = board.testDirection(3);
    int test4 = board.testDirection(4);
    int test5 = board.testDirection(5);
    int test6 = board.testDirection(6);
    CPPUNIT_ASSERT((test1 == 1 || test1 == 2 || test1 == 3 || test1 == 4 || test1 == 5 || test1 == 6) &&
                   (test2 == 1 || test2 == 2 || test2 == 3 || test2 == 4 || test2 == 5 || test2 == 6) &&
                   (test3 == 1 || test3 == 2 || test3 == 3 || test3 == 4 || test3 == 5 || test3 == 6) &&
                   (test4 == 1 || test4 == 2 || test4 == 3 || test4 == 4 || test4 == 5 || test4 == 6) &&
                   (test5 == 1 || test5 == 2 || test5 == 3 || test5 == 4 || test5 == 5 || test5 == 6) &&
                   (test6 == 1 || test6 == 2 || test6 == 3 || test6 == 4 || test6 == 5 || test6 == 6));
}

void TestBoard::TestMoveExist(void)
{
    MockBoard board;
    CPPUNIT_ASSERT(true == board.getDirectionExist());
}

void TestBoard::TestAllExist(void)
{
    MockBoard board;
    CPPUNIT_ASSERT(true == board.testDirectionExist());
}

void TestBoard::TestUpdateWins(void){
    MockBoard board;
    int wins = board.TotalWins;
    board.UpdateWins();
    CPPUNIT_ASSERT(wins+1 == board.TotalWins);
}

void TestBoard::TestUpdateLosses(void){
    MockBoard board;
    int losses = board.TotalLosses;
    board.UpdateLosses();
    CPPUNIT_ASSERT(losses+1 == board.TotalLosses);
}

void TestBoard::setUp(void)
{
    mTestObj = new BoardGenerator();
}

void TestBoard::tearDown(void)
{
    delete mTestObj;
}
