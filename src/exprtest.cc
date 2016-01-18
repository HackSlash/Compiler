// $Id$

#include <iostream>
#include <fstream>

#include "driver.h"
#include "expression.h"
#include "tree.h"


void Delete(std::vector<classdeclNode*>&classes){
	for(std::vector<classdeclNode*>::iterator itt = classes.begin; itt != classes.end; ++itt){
			delete *itt;
		}
		classes.clear();
}

int main(int argc, char *argv[])
{
	std::vector<classdeclNode*>classes;


    CalcContext calc;
    example::Driver driver(calc);
    bool readfile = false;

    for(int ai = 1; ai < argc; ++ai)
    {
	if (argv[ai] == std::string ("-p")) {
	    driver.trace_parsing = true;
	}
	else if (argv[ai] == std::string ("-s")) {
	    driver.trace_scanning = true;
	}
	else
	{
	    // read a file with expressions

	    std::fstream infile(argv[ai]);
	    if (!infile.good())
	    {
		std::cerr << "Could not open file: " << argv[ai] << std::endl;
		return 0;
	    }

	    calc.clearExpressions();
	    bool result = driver.parse_stream(infile, argv[ai],classes);
	    if (result)
	    {
		std::cout << "Expressions:" << std::endl;
		for (unsigned int ei = 0; ei < calc.expressions.size(); ++ei)
		{
		    std::cout << "[" << ei << "]:" << std::endl;
		    std::cout << "tree:" << std::endl;
		    calc.expressions[ei]->print(std::cout);
		    std::cout << "evaluated: "
			      << calc.expressions[ei]->evaluate()
			      << std::endl;
		}
	    }

	    readfile = true;
	}
    }

    if (readfile) {


    		Delete(classes);
    	return 0;}
    
    std::cout << "Reading expressions from stdin" << std::endl;

    std::string line;
    while( std::cout << "input: " &&
	   std::getline(std::cin, line) &&
	   !line.empty() )
    {
	bool result = driver.parse_string(line, classes, "input");
	if(result){
		for(std::vector<classdeclNode*>::iterator itt = classes.begin; itt != classes.end; ++itt){

			classdeclNode*node = *itt;
			std::cout<<std::to_string(node->typeNode->id) << std::endl;
			Delete(classes);

		}
	}

    }
}
