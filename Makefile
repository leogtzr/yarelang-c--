all:
	bison -d yare.y
	flex yare.l
	g++ lex.yy.cc yare.tab.c Main.cpp -o yare -lm 
	@echo 
	@echo ---------------------------------------------
	@echo "| Ok ...... ...				    |"
	@echo ---------------------------------------------
	@echo
	@echo "\a"
	
clean:
	@echo
	@echo Limpiando archivos temporales de yare 0.01
	@echo
	rm -rf yare.tab.c yare.tab.h y.tab.c y.tab.h location.hh position.hh stack.hh
	rm -rf lex.yy.cc
	rm -rf waffleshop
	@echo

help:
	@echo "yare < file.yar"
