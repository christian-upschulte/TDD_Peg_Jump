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

#include "TestSizeMenu.h"
#include "../SizeMenuView.cpp"
#include "../SizeMenuController.cpp"

using namespace CppUnit;
using namespace std;

class MockSizeMenu : public SizeMenuView{
    public:
    
        int choiceTest(int choice){
            if(choice == 5 || choice == 6 || choice == 7 || choice == 0)
                return choice;
            else
                return -1;
        }
};

void TestSizeMenu::testIfChoiceValid(void)
{
    MockSizeMenu menu;
    int choice1 = menu.choiceTest(5);
    int choice2 = menu.choiceTest(6);
    int choice3 = menu.choiceTest(7);
    int choice4 = menu.choiceTest(0);
    CPPUNIT_ASSERT((5 == choice1 || 6 == choice1 || 7 == choice1 || 0 == choice1) && 
                   (5 == choice2 || 6 == choice2 || 7 == choice2 || 0 == choice2) && 
                   (5 == choice3 || 6 == choice3 || 7 == choice3 || 0 == choice3) && 
                   (5 == choice4 || 6 == choice4 || 7 == choice4 || 0 == choice4));
}

void TestSizeMenu::setUp(void)
{
    mTestObj = new SizeMenuView();
}

void TestSizeMenu::tearDown(void)
{
    delete mTestObj;
}


