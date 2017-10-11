#include "TestGenerator.h"
#include "../GameGenerator.cpp"

using namespace CppUnit;
using namespace std;

class MockYes: public GameGenerator {

    public:
        char againTest(){
         char again;
         do{
            again='N';
         }while(again == 'Y' && again == 'y');
      return again;
    }
};
void TestGenerator::testIfChoiceY(void)
{
    MockYes Mock;
    CPPUNIT_ASSERT('N' == Mock.againTest());
}

void TestGenerator::setUp(void)
{
    mTestObj = new GameGenerator();
}

void TestGenerator::tearDown(void)
{
    delete mTestObj;
}
