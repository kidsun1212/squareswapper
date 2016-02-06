CXX = g++
CXXFLAGS = -Wall -MMD
EXEC = ss5k
OBJECTS = main.o Square.o Basic.o Lateral.o Upright.o Unstable.o Psychedelic.o Game.o Level0.o Level1.o Level2.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
