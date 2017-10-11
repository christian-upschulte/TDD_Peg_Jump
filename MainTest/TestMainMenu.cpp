#include <iostream>
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

#include "TestMainMenu.h"
#include "../MenuView.cpp"

using namespace CppUnit;
using namespace std;

class MockMainMenu : public MenuView{
    public:
        int choiceTest(){
            int choice, choice2;
            do{
                choice = 1;
                choice2 = 0;
            }while((choice != 1 && choice != 0) && (choice2 != 1 && choice2 != 0));
            return choice;
        }
};

void TestMainMenu::testIfChoice0(void)
{
    CPPUNIT_ASSERT(0  == mTestObj->getChoice(0));
}

void TestMainMenu::testIfChoiceValid(void)
{
    MockMainMenu menu;
    CPPUNIT_ASSERT(0 == menu.choiceTest() || 1 == menu.choiceTest());  
}

void TestMainMenu::setUp(void)
{
    mTestObj = new MenuView();
}

void TestMainMenu::tearDown(void)
{
    delete mTestObj;
}


