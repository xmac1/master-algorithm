OPT = -I src/list -I src/queue -I src/stack

recursive:
	g++ -g3 ${OPT} exercise/recursive.cc

infix:
	g++ -g3 ${OPT} exercise/main.cc

clean:
	rm *a.out

queue:
	g++ -g3 ${OPT} exercise/queue.cc

application:
	g++ -g3 ${OPT} exercise/application.cc