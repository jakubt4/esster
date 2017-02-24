CXXFLAGS =	-O2 -g -Wall -fmessage-length=0 -std=c++11

#PATHS
EVENT = src/event/shape/sort/events/impl/Event.o
EVENT_PART = src/event/shape/sort/events/impl/EventPart.o
PIU = src/event/shape/sort/sorter/impl/Piu.o
PNIU = src/event/shape/sort/sorter/impl/Pniu.o
PUNI = src/event/shape/sort/sorter/impl/Puni.o
BIN = src/event/shape/sort/events/impl/Bin.o
EVENTS = esster.o src/event/shape/sort/events/impl/Events.o
EVENTS_GENERATOR = src/event/shape/sort/events/generator/impl/EventsGenerator.o
READER = src/event/shape/sort/events/reader/Reader.o
SORTER = src/event/shape/sort/sorter/Sorter.o

#OBJECTS
OBJS = $(EVENTS) $(EVENT) $(EVENT_PART) $(EVENTS_GENERATOR) $(READER) $(BIN) $(SORTER)
TEST_EVENT_OBJS =  $(EVENT) $(EVENT_PART) test/event/shape/sort/events/EventTest.o
TEST_PIU_OBJS =  $(EVENT) $(EVENT_PART) $(PIU) $(BIN) test/event/shape/sort/sorter/PiuTest.o
TEST_PNIU_OBJS =  $(EVENT) $(EVENT_PART) $(PIU) $(PNIU) $(BIN) test/event/shape/sort/sorter/PniuTest.o
TEST_PUNI_OBJS =  $(EVENT) $(EVENT_PART) $(PIU) $(PNIU) $(PUNI) $(BIN) test/event/shape/sort/sorter/PuniTest.o

#LIBS
LIBS =

#TARGETS
TARGET =	esster
TEST_EVENT_TARGET = test_event
TEST_PIU_TARGET = test_piu
TEST_PNIU_TARGET = test_pniu
TEST_PUNI_TARGET = test_puni

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)
$(TEST_EVENT_TARGET): $(TEST_EVENT_OBJS)
	$(CXX) -o $(TEST_EVENT_TARGET) $(TEST_EVENT_OBJS) $(LIBS)
$(TEST_PIU_TARGET): $(TEST_PIU_OBJS)
	$(CXX) -o $(TEST_PIU_TARGET) $(TEST_PIU_OBJS) $(LIBS)
$(TEST_PNIU_TARGET): $(TEST_PNIU_OBJS)
	$(CXX) -o $(TEST_PNIU_TARGET) $(TEST_PNIU_OBJS) $(LIBS)
$(TEST_PUNI_TARGET): $(TEST_PUNI_OBJS)
	$(CXX) -o $(TEST_PUNI_TARGET) $(TEST_PUNI_OBJS) $(LIBS)

all: $(TARGET) $(TEST_EVENT_TARGET) $(TEST_PIU_TARGET) $(TEST_PNIU_TARGET) $(TEST_PUNI_TARGET)

tests: $(TEST_EVENT_TARGET) $(TEST_PIU_TARGET) $(TEST_PNIU_TARGET) $(TEST_PUNI_TARGET)

clean:
	rm -f $(OBJS) $(TARGET) $(TEST_EVENT_OBJS) $(TEST_EVENT_TARGET) $(TEST_PIU_OBJS) $(TEST_PIU_TARGET) $(TEST_PNIU_OBJS) $(TEST_PNIU_TARGET) $(TEST_PUNI_OBJS) $(TEST_PUNI_TARGET)
