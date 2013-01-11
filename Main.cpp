#include "YareScanner.h"
#include "YareParser.h"
#include <cstring>
#include <ctime>
#include <cstdlib>

using std::cout;
using std::cerr;
using std::endl;
using YL::Parser;

// Entry Point
int main(void) {
	srand((unsigned)time(0));	
	Parser parser;
	return parser.parse();
}

