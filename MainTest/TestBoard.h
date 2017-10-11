#ifndef TEST_BOARD_H
#define TEST_BOARD_H
#include <cppunit/extensions/HelperMacros.h>
#include "../BoardGenerator.h"

using namespace CppUnit;
using namespace std;

class TestBoard : public CppUnit::TestFixture
{
     CPPUNIT_TEST_SUITE(TestBoard);
     CPPUNIT_TEST(TestBoardCorrectness5);
     CPPUNIT_TEST(TestBoardCorrectnessAll);
     CPPUNIT_TEST(TestMove1);
     CPPUNIT_TEST(TestMoveAny);
     CPPUNIT_TEST(TestMoveExist);
     CPPUNIT_TEST(TestAllExist);
     CPPUNIT_TEST(TestUpdateWins);
     CPPUNIT_TEST(TestUpdateLosses);
     CPPUNIT_TEST_SUITE_END();
    
    public:
        void setUp(void);
        void tearDown(void);
    protected:
        void TestBoardCorrectness5(void);
        void TestBoardCorrectnessAll(void);
        void TestMove1(void);
        void TestMoveAny(void);
        void TestMoveExist(void);
        void TestAllExist(void);
        void TestUpdateWins(void);
        void TestUpdateLosses(void);
    private:
        BoardGenerator *mTestObj;      
};

#endif
