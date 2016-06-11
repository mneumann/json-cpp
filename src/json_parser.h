#pragma once

#include "json.h"

class jsonParser {
public:
  static jsonValue *parse(const char *content, int size);
  static jsonValue *parse_file(const char *filename);
  static jsonValue *parse_file_mmap(const char *filename);
};
