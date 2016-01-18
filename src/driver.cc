// $Id$
/** \file driver.cc Implementation of the example::Driver class. */

#include <fstream>
#include <sstream>

#include "driver.h"
#include "scanner.h"
#include "tree.h"
namespace example {

Driver::Driver(class CalcContext& _calc)
    : trace_scanning(false),
      trace_parsing(false),
      calc(_calc)
{
}

bool Driver::parse_stream(std::istream& in, std::vector<classdeclNode*> &classes, const std::string& sname)
{
    streamname = sname;

    Scanner scanner(&in);
    scanner.set_debug(trace_scanning);
    this->lexer = &scanner;

    Parser parser(*this,classes);
    parser.set_debug_level(trace_parsing);
    return (parser.parse() == 0);
}

bool Driver::parse_file(const std::string &filename, std::vector<classdeclNode*> &classes) 
{
    std::ifstream in(filename.c_str());
    if (!in.good()) return false;
    return parse_stream(in, classes, filename);
}

bool Driver::parse_string(const std::string &input, std::vector<classdeclNode*> &classes, const std::string& sname)
{
    std::istringstream iss(input);
    return parse_stream(iss, classes, sname);
}

void Driver::error(const class location& l,
		   const std::string& m)
{
    std::cerr << l << ": " << m << std::endl;
}

void Driver::error(const std::string& m)
{
    std::cerr << m << std::endl;
}

} // namespace example
