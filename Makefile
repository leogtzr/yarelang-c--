all:
	bison -d yare.y
	flex yare.l
	g++ lex.yy.cc yare.tab.c Main.cpp -o yare -lm -O3
	@echo 
	@echo ---------------------------------------------
	@echo "| Ok ...... ...				    |"
	@echo ---------------------------------------------
	@echo
	
clean:
	@echo
	@echo Limpiando archivos temporales de yare 0.01
	@echo
	rm -rf yare.tab.c yare.tab.h y.tab.c y.tab.h location.hh position.hh stack.hh
	rm -rf lex.yy.cc
	@echo

help:
	@echo "yare file.yar"
