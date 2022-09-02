#ifndef TEST_EXAMPLE_H
#define TEST_EXAMPLE_H

#include <iostream>
#include "TestCase.h"
#include "TestSuite.h"
#include "TestCaller.h"
#include "TestRunner.h"

class TestExampleTestCase : public TestCase 
{
	ExampleTestCase() : TestCase() {}

	// method to test the constructor
	void testConstructor();

	// method to test the assigning and retrieval of grades
	void testAssignAndRetrieveGrades();

	// method to create a suite of tests
	static Test *suite ();	
};

#endif