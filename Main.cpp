#include "YareScanner.h"
#include "YareParser.h"
#include <cstring>
#include <ctime>
#include <cstdlib>

using std::cout;
using std::cerr;
using std::endl;
using YL::Parser;

int main(int argc, char **argv) {
	
	if(argc <= 1) {
		
		srand((unsigned)time(NULL));		
		Parser parser;
		return parser.parse_interact();

	} else {

		srand((unsigned)time(NULL));		
		Parser parser(argv[1]);
		return parser.parse();

	}

}

