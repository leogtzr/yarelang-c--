#include "YareScanner.h"
#include "YareParser.h"
#include <cstring>
#include <ctime>
#include <cstdlib>

using std::cout;
using std::cerr;
using std::endl;
using YL::Parser;

int main(void) {
	srand((unsigned)time(NULL));	
	Parser parser;
	return parser.parse();
}

