CXXFLAGS =	-O2 -g -Wall -fmessage-length=0 -std=c++11

OBJS =		esster.o src/Event.o src/EventPart.o src/EventsGenerator.o #/src/generator/generator.o src/utils/folder_creator_util.o

LIBS =

TARGET =	esster

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
