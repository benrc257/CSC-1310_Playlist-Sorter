# TO COMPILE WITH MAKEFILE ON WINDOWS, DO "mingw32-make"
# IF ON MAC OR LINUX, USE "make"

# settings
CXX = @g++
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

# Detect OS for clean
ifdef OS
   RM = @del -force
else
   ifeq ($(shell uname), Linux)
      RM = @rm -f
   endif
endif

# Compile output (All)
${all}: ${objects}
	${CXX} ${objects} -o ${output}
	${RM} ${objects}
	@echo "Output built successfully"

# Compile main
${driverout}: ${driver}
	${CXX} ${CXXFLAGS} ${driver} -o driver.o

${functionsout}: ${functions}
	${CXX} ${CXXFLAGS} ${functions} -o functions.o

# Compile classes
${sorterout}: ${sorter}
	${CXX} ${CXXFLAGS} ${sorter} -o sorter.o

${playlistout}: ${playlist}
	${CXX} ${CXXFLAGS} ${playlist} -o playlist.o

${metadataout}: ${metadata}
	${CXX} ${CXXFLAGS} ${sorter} -o metadata.o

${smartout}: ${smart}
	${CXX} ${CXXFLAGS} ${smart} -o smart.o

# Make clean (Removes files)
clean:
	${RM} ${objects} ${output}
	@echo "Removed build files"