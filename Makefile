# TO COMPILE WITH MAKEFILE ON WINDOWS, DO "mingw32-make"
# IF ON MAC OR LINUX, USE "make"

# settings
CXX = g++
CXXFLAGS = -c

# file names
functions := functions.cpp
driver := driver.cpp
sorter := Classes/sorter.cpp
playlist := Classes/playlist.cpp
metadata := Classes/metadata.cpp
smart := Classes/smartpointer.cpp
files := ${functions} ${driver} ${playlist} ${metadata} ${sorter} ${smart}

# object names
output := PlaylistSorter.exe
all := all
driverout := driver.o
functionsout := functions.o
sorterout := sorter.o
playlistout := playlist.o
metadataout := metadata.o
smartout := smart.o
objects := ${driverout} ${functionsout} ${sorterout} ${playlistout} ${metadataout} ${smartout}

# compile output (All)
${all}: ${objects}
	${CXX} ${objects} -o ${output}

# compile main
${driverout}: ${driver}
	${CXX} ${CXXFLAGS} ${driver} -o driver.o

${functionsout}: ${functions}
	${CXX} ${CXXFLAGS} ${functions} -o functions.o

# compile classes
${sorterout}: ${sorter}
	${CXX} ${CXXFLAGS} ${sorter} -o sorter.o

${playlistout}: ${playlist}
	${CXX} ${CXXFLAGS} ${playlist} -o playlist.o

${metadataout}: ${metadata}
	${CXX} ${CXXFLAGS} ${sorter} -o metadata.o

${smartout}: ${smart}
	${CXX} ${CXXFLAGS} ${smart} -o smart.o

# clean for windows

clean: ${objects} ${output}
	del -force ${objects} ${output}
	echo "Removed build files"

# clean for all other platforms

clean: ${objects} ${output}
	rm -f ${objects} ${output}
	echo "Removed build files"