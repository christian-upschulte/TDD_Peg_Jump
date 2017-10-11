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

#include "TestGenerator.h"
#include "TestMainMenu.h"
#include "TestSizeMenu.h"
#include "TestBoard.h"
using namespace CppUnit;
using namespace std;

CPPUNIT_TEST_SUITE_REGISTRATION( TestMainMenu );
CPPUNIT_TEST_SUITE_REGISTRATION( TestGenerator );
CPPUNIT_TEST_SUITE_REGISTRATION( TestSizeMenu );
CPPUNIT_TEST_SUITE_REGISTRATION( TestBoard );

int main(int argc, char* argv[])
{
    CPPUNIT_NS::TestResult testresult;
    CPPUNIT_NS::TestResultCollector collectedresults;
    testresult.addListener (&collectedresults);
    CPPUNIT_NS::BriefTestProgressListener progress;
    testresult.addListener (&progress);
    CPPUNIT_NS::TestRunner testrunner;
    testrunner.addTest (CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest ());
    testrunner.run(testresult);
    CPPUNIT_NS::CompilerOutputter compileroutputter(&collectedresults, std::cerr);
    compileroutputter.write ();

    return collectedresults.wasSuccessful() ? 0 : 1;
}
