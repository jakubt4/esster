CXXFLAGS =	-O2 -g -Wall -fmessage-length=0 -std=c++11

OBJS =		esster.o src/event/shape/sort/events/impl/Events.o src/event/shape/sort/events/impl/Event.o src/event/shape/sort/events/impl/EventPart.o src/event/shape/sort/events/generator/impl/EventsGenerator.o src/event/shape/sort/events/reader/Reader.o

LIBS =

TARGET =	esster

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
