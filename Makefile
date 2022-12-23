# set compiler
CC = gcc
# include files
INCLUDE = -I ./include  
#compilers flags for compiling object files
CFLAGSO = -lstdc++  -c ${INCLUDE}  
# libraries
LIBS =  -lstdc++ -lmingw32 -lSDL2main -lSDL2 -lSDL2_image 
#compilers flags for compiling binary file
CFLAGSB = -s ${LIBS}   

default: objCompile
	mkdir -p ./make/bin
	${CC} ./make/build/*.o -o ./make/bin/main ${CFLAGSB}
	cp -r ./assets ./make/bin/

objCompile: 
	mkdir -p ./make/build
	${CC} ./src/*.cpp ${CFLAGSO}
	# laymans way to move object files to make/build folder 
	mv *.o ./make/build

win: winObjCompile
	mkdir  -p ./make/bin/
	${CC} ./make/build/*.o -o ./make/bin/main  ${CFLAGSB} 
	cp -r ./assets/ ./make/bin/


winObjCompile: 
	mkdir -p ./make/build/
	${CC} ./src/*.cpp  ${CFLAGSO} 
	# laymans way to move object files to make/build folder 
	mv *.o ./make/build

run:
	./make/bin/main.exe