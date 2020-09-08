# Vorbital makefile.  Requires wxWidgets.
# by default, wx-config from the PATH is used
WX_CONFIG := wx-config

# Main executable file
PROGRAM = CheckBeat

# Directory containing library portions of code.
INCLUDEDIR = ../AudioFile/

# Object files
OBJECTS = CheckBeat.o DirectNoise.o

CXX = $(shell $(WX_CONFIG) --cxx -ggdb)

.SUFFIXES:	.o .cpp

.cpp.o :
	$(CXX) -ggdb -c -I$(INCLUDEDIR) `$(WX_CONFIG) --cxxflags` -o $@ $<

all:    $(PROGRAM)

$(PROGRAM):	$(OBJECTS)
	$(CXX) -o $(PROGRAM) -I$(INCLUDEDIR) $(OBJECTS) `$(WX_CONFIG) --libs` `pkg-config --cflags --libs jack`

clean: 
	rm -f *.o $(PROGRAM)
