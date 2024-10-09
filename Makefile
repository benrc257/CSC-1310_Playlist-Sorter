# TO COMPILE WITH MAKEFILE ON WINDOWS, DO "mingw32-make"
# IF ON MAC OR LINUX, USE "make"

# settings
CXX := g++
CXXFLAGS := -c

# file names
functions := functions.cpp
driver := driver.cpp
playlist := Classes/playlist.cpp
metadata := Classes/metadata.cpp
sorter := Classes/sorter.cpp
smart := Classes/smartpointer.cpp
output := PlaylistSorter.exe
files := driver.o functions.o sorter.o playlist.o metadata.o smart.o

# os detection
ifeq ($(OS),Windows_NT)
	OSCLEAN = del
else
	OSCLEAN = rm
endif

# compile PlaylistSorter.exe (all)
all: driver.o functions.o sorter.o playlist.o metadata.o smart.o
	g++ ${files} -o ${output}
	del -force ${files}

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

smart.o: ${smart}
	${CXX} ${CXXFLAGS} ${smart} -o smart.o

# clean
clean:
	$(OSCLEAN) -force ${files} ${output}
