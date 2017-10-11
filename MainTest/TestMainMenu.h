#ifndef TEST_MAIN_MENU_H
#define TEST_MAIN_MENU_H
#include "../MenuView.h"
#include <cppunit/extensions/HelperMacros.h>

using namespace CppUnit;
using namespace std;

class TestMainMenu : public CppUnit::TestFixture
{
     CPPUNIT_TEST_SUITE(TestMainMenu);
     CPPUNIT_TEST(testIfChoice0);
     CPPUNIT_TEST_SUITE_END();
    
    public:
        void setUp(void);
        void tearDown(void);
    protected:
        void testIfChoice0(void);
        void testIfChoiceValid(void);
    private:
        MenuView *mTestObj;      
};

#endif