# TO COMPILE WITH MAKEFILE ON WINDOWS, DO "mingw32-make"
# IF ON MAC OR LINUX, USE "make"

# settings
CXX = @g++ -std=c++2a
CXXFLAGS = -c

# file names
functions := functions.cpp
driver := driver.cpp
sorter := Classes/sorter.cpp
playlist := Classes/playlist.cpp
metadata := Classes/metadata.cpp
files := ${functions} ${driver} ${playlist} ${metadata} ${sorter}

# object names
output := PlaylistSorter
all := all
driverout := driver.o
functionsout := functions.o
sorterout := sorter.o
playlistout := playlist.o
metadataout := metadata.o
objects := ${driverout} ${functionsout} ${sorterout} ${playlistout} ${metadataout}

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
	${CXX} ${CXXFLAGS} ${driver} -o {driverout}

${functionsout}: ${functions}
	${CXX} ${CXXFLAGS} ${functions} -o {functionsout}

# Compile classes
${sorterout}: ${sorter}
	${CXX} ${CXXFLAGS} ${sorter} -o {sorterout}

${playlistout}: ${playlist}
	${CXX} ${CXXFLAGS} ${playlist} -o {playlistout}

${metadataout}: ${metadata}
	${CXX} ${CXXFLAGS} ${sorter} -o {metadataout}

# Make clean (Removes files)
clean:
	${RM} ${objects} ${output}
	@echo "Removed build files"