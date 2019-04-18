OBJS = main.o menu.o display.o
CXX = g++
CXXFLAGS = -std=c++11
LDLIBS = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

game: $(OBJS)
	$(CXX) -o game $(OBJS) $(LDLIBS) $(LDFLAGS)

main.o: menu.hpp 
menu.o: menu.hpp 
clean:
	$(RM) game $(OBJS)
