#ifndef TEST_GENERATOR_H
#define TEST_GENERATOR_H

#include "../GameGenerator.h"
#include <cppunit/extensions/HelperMacros.h>

using namespace CppUnit;
using namespace std;

class TestGenerator : public CppUnit::TestFixture
{
     CPPUNIT_TEST_SUITE(TestGenerator);
     CPPUNIT_TEST(testIfChoiceY);
     CPPUNIT_TEST_SUITE_END();
    
    public:
        void setUp(void);
        void tearDown(void);
    protected:
        void testIfChoiceY(void);
    private:
        GameGenerator *mTestObj;      
};

#endif