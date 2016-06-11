src/test: src/test.o src/json.o src/json_parser.o
	${CXX} -o $@ src/test.o src/json.o src/json_parser.o

src/json_parser.cc: src/json_parser.rl
	ragel -o $@ src/json_parser.rl

src/json_parser.o: src/json.h src/json_parser.h src/json_parser.cc
	${CXX} -c src/json_parser.cc -o $@ -I./src

src/json.o: src/json.h src/json_parser.h src/json.cc
	${CXX} -c src/json.cc -o $@ -I./src

src/test.o: src/json.h src/json_parser.h src/test.cc
	${CXX} -c src/test.cc -o $@ -I./src

format:
	sh format.sh src/json.cc
	sh format.sh src/json.h
	sh format.sh src/json_parser.cc
	sh format.sh src/json_parser.h
	sh format.sh src/test.cc

clean:
	rm -f src/test src/*.o
