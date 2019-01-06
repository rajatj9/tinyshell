#Pranav Talwar - 3035435462
# Rajat Jain - 3035453684
tinyshell: tinyshell.o command.o
	g++ -o tinyshell tinyshell.o command.o
tinyshell.o: tinyshell.cpp command.h
	g++ -c tinyshell.cpp
command.o: command.cpp command.h
	g++ -c command.cpp
clean:
	rm tinyshell tinyshell.o command.o
tar:
	tar -czvf tinyshell.tgz *.cpp *.h
run:
	./tinyshell
.PHONY: clean tar
