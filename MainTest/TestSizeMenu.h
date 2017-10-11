#ifndef TEST_SIZE_MENU_H
#define TEST_SIZE_MENU_H
#include "../SizeMenuView.h"
#include <cppunit/extensions/HelperMacros.h>

using namespace CppUnit;
using namespace std;

class TestSizeMenu : public CppUnit::TestFixture
{
     CPPUNIT_TEST_SUITE(TestSizeMenu);
     CPPUNIT_TEST(testIfChoiceValid);
     CPPUNIT_TEST_SUITE_END();
    
    public:
        void setUp(void);
        void tearDown(void);
    protected:
        void testIfChoiceValid(void);
    private:
        SizeMenuView *mTestObj;      
};

#endif