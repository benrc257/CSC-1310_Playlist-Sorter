# TO COMPILE WITH MAKEFILE ON WINDOWS, DO "mingw32-make"
# IF ON MAC OR LINUX, USE "make"

# settings
CXX = g++
CXXFLAGS = -c

# file names
functions := functions.cpp
driver:= driver.cpp
playlist:= Classes/playlist.cpp
metadata:= Classes/metadata.cpp
sorter:= Classes/sorter.cpp
smart:= Classes/smartpointer.cpp

# compile SushiBar (All)
all: driver.o functions.o sorter.o playlist.o metadata.o smart.o
	g++ driver.o functions.o sorter.o playlist.o metadata.o smart.o -o PlaylistSorter

# compile main
main.o: ${driver}
	${CXX} ${CXXFLAGS} ${driver} -o driver.o

functions.o: ${functions}
	${CXX} ${CXXFLAGS} ${functions} -o functions.o

#compile classes
sorter.o: ${sorter}
	${CXX} ${CXXFLAGS} ${sorter} -o sorter.o

playlist.o: ${playlist}
	${CXX} ${CXXFLAGS} ${playlist} -o playlist.o

metadata.o: ${metadata}
	${CXX} ${CXXFLAGS} ${sorter} -o metadata.o

sushi.o: ${smart}
	${CXX} ${CXXFLAGS} ${smart} -o smart.o