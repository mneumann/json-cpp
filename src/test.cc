#include <json.h>
#include <json_parser.h>
#include <iostream>

int main(int argc, char **argv) {
    using namespace std;

    jsonValue *val = jsonParser::parse("{}", 2);

    val->output(cout);
    cout << endl;

    return 0;
}
