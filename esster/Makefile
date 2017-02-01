//g++ main.cpp ./source/additional.cpp ./source/analyze.cpp ./source/bins.cpp ./source/generator.cpp ./source/list.cpp ./source/toymodel.cpp ./source/eigenvalues.cpp -llapack -lblas  ./source/my_root.cpp `root-config --libs --cflags` -lEG  -o execute

CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		esster.o

LIBS =

TARGET =	esster

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
