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

		std::string okStr(argv[1]);
		if(okStr.compare("-v") == 0 || okStr.compare("-version") == 0) {
			cout << "yare v1.0\n\nautor: Leonardo Gutiérrez R <leorocko13@hotmail.com>\n\n";
			exit(EXIT_SUCCESS);
		}

		srand((unsigned)time(NULL));		

		std::string fn(argv[1]);
  		if(fn.substr(fn.find_last_of(".") + 1) == "yar") {
    		Parser parser(argv[1]);
			return parser.parse();
  		} else {
    		std::cout << "El archivo de código fuente debe poseer la extensión '.yar'" << std::endl;
    		exit(EXIT_FAILURE);
  		}	

	}

}

