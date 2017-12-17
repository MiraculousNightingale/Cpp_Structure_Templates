// Cpp_Structure_Templates.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "List.h"

using namespace std;

void main()
{
	List<int> test;
	test.Add(1);
	test.Add(2);
	test.Add(3);
	test.Output();
    
	system("pause");
}

