src/json_parser.cc: src/json_parser.rl
	ragel -o $@ src/json_parser.rl
