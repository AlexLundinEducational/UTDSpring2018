#Alex Lundin
#AML140830@utdallas.edi
#SE 3377.501 CC+ in UNIX
#makefile
#rule for hw4 target
hw4: hw4.o file1.cc
	g++ file1.cc -o hw4
	flex Scanner.l
	gcc lex.yy.c -o Scanner -lfl
	flex ScannerTest.l
	gcc lex.yy.c -o ScannerTest -lfl
#rule for hw4 object file
hw4.o: file1.cc
	g++ -c file1.cc
# Project name.  This is used in building the file name for the backup target
PROJECTNAME = Program4
test:
	./ScannerTest.o input.txt
run:
	./hw4.o
clean:
	rm -f $(OBJS) $(EXECFILE) *.P *~ \#* *.o

# Backup Target
backup:	clean
	@mkdir -p ./tball; chmod 700 ./tball
	@$(eval CURDIRNAME := $(shell basename `pwd`))
	@$(eval MKBKUPNAME := ./tball/$(PROJECTNAME).tar.gz)
	@echo
	@echo Writing Backup file to: $(MKBKUPNAME)
	@echo
	@-tar zcfv $(MKBKUPNAME)  ../$(CURDIRNAME) 
	@chmod 600 $(MKBKUPNAME)
	@echo
	@echo Done!