///////////////////// Yare /////////////////////////////
// Autor: Leo Gutiérrez Ramírez <leorocko13@hotmail.com>
///////////////////// Yare /////////////////////////////

#pragma once

#ifndef _YARESCANNER_H_INCLUDED
#define _YARESCANNER_H_INCLUDED

#if ! defined(yyFlexLexerOnce)
	#include <FlexLexer.h>
#endif

#undef YY_DECL
#define YY_DECL int YL::FlexScanner::yylex()

#include "yare.tab.h"

namespace YL {
	
	class FlexScanner : public yyFlexLexer {
		public:

			int yylex(YL::YareParser::semantic_type *lval) { 
				lexema = lval; 
				return yylex(); 
			}

			FlexScanner(std::istream * in = 0, std::ostream * out = 0) : yyFlexLexer(in, out) {}

		private:
			int yylex();
			YL::YareParser::semantic_type *lexema;
	};
}

#endif
