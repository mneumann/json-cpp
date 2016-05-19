src/json_parser.cc: src/json_parser.rl
	ragel src/json_parser.rl | rlgen-cd -o $@
