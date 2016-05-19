#ifndef __YINSPIRE__JSON_PARSER__
#define __YINSPIRE__JSON_PARSER__

#include "json.h"

class jsonParser
{
  public:

    static jsonValue* parse(char* content, int size);
    static jsonValue* parse_file(const char* filename);
    static jsonValue* parse_file_mmap(const char* filename);
};

#endif
