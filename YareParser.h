#pragma once

#ifndef _YAREPARSER_H_INCLUDED
#define _YAREPARSER_H_INCLUDED

#include <iostream>
#include <fstream>

namespace YL {
class Parser {
                public:
                        Parser(char *file) : parser(scanner) {
                                fileName = file;
                        }

                        Parser() : parser(scanner) {}

                        int parse(void) {

                                std::ifstream inFile(fileName);
                                YL::FlexScanner sc(&inFile);       
                                YL::YareParser ps(sc);

                                return ps.parse();
                        }

                        int parse_interact(void) {
                                return parser.parse();
                        }

                private:
                        YL::FlexScanner scanner;
                        YL::YareParser parser;
                        char *fileName;
        };
}

#endif
