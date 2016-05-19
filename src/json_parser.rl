%%{
  machine jsonParser;

  jnull = "null" %{ PB(new jsonNull()); };

  true = "true" %{ PB(new jsonTrue()); };

  false = "false" %{ PB(new jsonFalse()); };

  exp = ("e"|"E") ("+"|"-")? [0-9]+;
  number = (("+" | "-")? ([0-9] | [1-9] [0-9]*) ("." [0-9]*  )? exp?) >{ tstart=p; } %{
    PB(json_number(tstart, p, numbuf, numbufsz));
  };

  pos_inf = (("+")? "Infinity") %{ PB(new jsonNumber(INFINITY)); };

  neg_inf = "-Infinity" %{ PB(new jsonNumber(-INFINITY)); };

  string = ('"' [^"]* '"' | "'" [^']* "'") >{ tstart=p; } %{
    PB(json_string(tstart+1, p-1));
  };

  label = (("_" | alpha) ("_" | alnum)*) >{ tstart=p; } %{
    PB(json_string(tstart, p));
  };

  whitespace = space | "//" [^\n\r]* [\n\r];

  any_value = (jnull | true | false | number | pos_inf | neg_inf 
              | string 
              | ("{" @{ fcall hash; })
              | ("[" @{ fcall array; }) 
              );

  main := whitespace* any_value whitespace*;

  kv = (whitespace* (label|string) whitespace* ":" whitespace* any_value) %{ 
    if (values.size() < 3) throw "invalid format";
    jsonValue* v = values.back();
    values.pop_back();
    jsonString* k = (jsonString*) values.back(); 
    values.pop_back();
    jsonHash* h = (jsonHash*) values.back();
    h->set(k, v);
  };

  hash := (
    (kv whitespace* ("," kv whitespace*)*)? whitespace* "}"
  ) >{ PB(new jsonHash());} @{ fret; };

  array := (
    whitespace* ( (any_value (whitespace* "," whitespace* any_value)*)? whitespace* "]" )
  ) >{ array_i.push_back(values.size()); } @{ 
    jsonArray* a = new jsonArray();
    for (int i=array_i.back(); i<values.size(); i++) a->push(values[i]);
    while (values.size() > array_i.back()) values.pop_back();
    PB(a);
    array_i.pop_back();
    fret;
  };

}%%

#include <vector>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "json_parser.h"

#define PB(x) values.push_back(x)

inline static jsonString* json_string(char* from, char* to)
{
  return new jsonString(from, to-from);
}

inline static jsonNumber* json_number(char* from, char* to, char* buf, int maxsz)
{
  const int sz = to-from; 

  if (sz > maxsz) throw "fatal";

  memcpy(buf, from, sz);
  buf[sz] = '\000';
 
  return new jsonNumber(strtod(buf, NULL));
}

%% write data;

jsonValue* jsonParser::parse(char* content, int size)
{
  int cs;
  int top;
  int stack[20];
  char numbuf[61];
  const int numbufsz = 60;

  char *ps = content;
  char *p = ps;
  char *pe = content + size;

  // user defined
  char* tstart = NULL; 
  std::vector<jsonValue*> values; 
  std::vector<int> array_i;

  %%write init;
  %%write exec;

  if (p != pe)
  {
    int err_pos = (int)(p-ps);
    std::cout << "error at: " << err_pos << std::endl;
    throw "error occured while parsing";
  }

  if (values.size() != 1)
  {
    throw "error occured while parsing";
  }

  return values[0];
}

#include <fcntl.h>
#include <unistd.h>

jsonValue* jsonParser::parse_file(const char* filename)
{
  int fh;
  void *mem;
  int size;
  jsonValue* res;

  fh = open(filename, O_RDONLY);
  if (fh < 0)
  {
    throw "cannot open file";
  }

  size = lseek(fh, 0, SEEK_END);
  if (size < 0)
  {
    throw "error";
  }
  lseek(fh, 0, SEEK_SET);

  mem = malloc(size);

  if (mem == NULL)
  {
    throw "malloc failed";
  }

  int c = read(fh, mem, size);

  if (c != size)
  {
    throw "couldn't read entire file";
  }

  res = jsonParser::parse((char*)mem, size);

  free(mem);
  close(fh);

  return res;
}

#ifdef WITHOUT_MMAP
jsonValue* jsonParser::parse_file_mmap(const char* filename)
{
  return parse_file(filename);
}
#else
#include <sys/mman.h>
jsonValue* jsonParser::parse_file_mmap(const char* filename)
{
  int fh;
  void *mem;
  int size;
  jsonValue* res;

  fh = open(filename, O_RDONLY);
  if (fh < 0)
  {
    throw "cannot open file";
  }

  size = lseek(fh, 0, SEEK_END);
  if (size < 0)
  {
    throw "error";
  }
  lseek(fh, 0, SEEK_SET);

  mem = mmap(NULL, size, PROT_READ, MAP_SHARED, fh, 0);

  if (mem == MAP_FAILED)
  {
    throw "mmap failed";
  }

  res = jsonParser::parse((char*)mem, size);

  munmap(mem, size);
  close(fh);

  return res;
}
#endif
