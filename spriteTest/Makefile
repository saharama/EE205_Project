OBJS = main.o 
CXX = g++
CXXFLAGS = -WCL4 -std=c++11
LDLIBS = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

game: $(OBJS)
	$(CXX) -o game $(OBJS) $(LDLIBS) $(LDFLAGS)
 
main.o:

clean:
	$(RM) game $(OBJS)