#include <iostream>
#include <json.h>
#include <json_parser.h>
#include <string.h>

int main(int argc, char **argv) {
  using namespace std;

  const char *json = "{\"test\": 123.123, \"ary\": [\"abc\", true]}";
  jsonValue *val = jsonParser::parse(json, strlen(json));

  val->output(cout);
  cout << endl;

  return 0;
}
