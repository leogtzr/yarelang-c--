#pragma once

#ifndef _YAREPARSER_H_INCLUDED
#define _YAREPARSER_H_INCLUDED

namespace YL {
	class Parser {
		public:
			Parser() : parser(scanner) {
			}
		
			int parse(void) {
				return parser.parse();
			}

		private:
			YL::FlexScanner scanner;
			YL::BisonParser parser;
	};
}

#endif
