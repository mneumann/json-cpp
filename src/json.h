#ifndef __YINSPIRE__JSON__
#define __YINSPIRE__JSON__

#include <ostream>
#include <string>

#define jsonArrayIterator_EACH(ary, i) \
  jsonValue *i; \
  for (jsonArrayIterator iter(ary); (i=iter.current()) != NULL; iter.next())

#define jsonHashIterator_EACH(hash, k, v) \
  jsonString *k; \
  jsonValue *v; \
  for (jsonHashIterator iter(hash); (k=iter.current_key(), v=iter.current_value(), k) != NULL; iter.next())

struct jsonArrayItem;
struct jsonHashItem;

/*
 * Forward declarations
 */
class jsonNull;
class jsonTrue;
class jsonFalse;
class jsonNumber;
class jsonString;
class jsonArray;
class jsonHash;

class jsonValue {
  public:
    jsonValue();
    virtual ~jsonValue();
    virtual const char* type();
    bool is_type(const char* t);
    void ref_incr();
    void ref_decr();
    virtual void output(std::ostream& s) = 0;

    jsonNull* asNull();
    jsonTrue* asTrue();
    jsonFalse* asFalse();
    jsonNumber* asNumber();
    jsonString* asString();
    jsonArray* asArray();
    jsonHash* asHash();

  private:
    int ref_count;
};

class jsonNull : public jsonValue 
{
  public:
    virtual void output(std::ostream& s);
    virtual const char* type();
};

class jsonTrue : public jsonValue
{
  public:
    virtual void output(std::ostream& s);
    virtual const char* type();
};

class jsonFalse : public jsonValue
{
  public:
    virtual void output(std::ostream& s);
    virtual const char* type();
};

class jsonNumber : public jsonValue
{
  public:

    double value;

  public:

    jsonNumber(double value);
    virtual void output(std::ostream& s);
    virtual const char* type();
};

class jsonString : public jsonValue
{
  public:

    std::string value;

  public:

    jsonString(std::string& value);
    jsonString(const char* value);
    jsonString(const char* _value, int len);

    virtual void output(std::ostream& s);
    virtual const char* type();
};

class jsonArrayIterator
{
    jsonArray *array;
    jsonArrayItem *pos;

  public:

    jsonArrayIterator(jsonArray *array);
    ~jsonArrayIterator();

    void next();
    jsonValue *current();
};

class jsonArray : public jsonValue
{
  public:

    jsonArrayItem* head;
    jsonArrayItem* tail;

  public:

    jsonArray();
    virtual ~jsonArray();
    virtual void output(std::ostream& s);
    void push(jsonValue* value);
    //void each(void (*iter)(jsonValue*, void*), void* data);
    jsonValue *get(int index);
    virtual const char* type();
};

class jsonHashIterator
{
    jsonHash *hash;
    jsonHashItem *pos;

  public:

    jsonHashIterator(jsonHash *hash);
    ~jsonHashIterator();

    void next();
    jsonString *current_key();
    jsonValue *current_value();
};


class jsonHash : public jsonValue
{
  public:

    jsonHashItem* head;
    jsonHashItem* tail;

  public:

    jsonHash();
    virtual ~jsonHash();
    virtual void output(std::ostream& s);
    //void each(void (*iter)(jsonString*, jsonValue*, void*), void* data);
    jsonValue* get(const char* key);
    jsonValue* get(std::string& key);
    jsonValue* get(jsonString* key);
    bool has_key(const char* key);
    bool has_key(std::string& key);
    bool has_key(jsonString* key);
    bool get_bool(const char* key, bool default_value);
    double get_number(const char* key, double default_value);
    std::string& get_string(const char* key);
    void set(const char* key, jsonValue* value);
    void set(const char* key, double value);
    void set(const char* key, int value);
    void set(const char* key, bool value);
    void set(const char* key, const char* value);
    void set(const char* key, std::string& value);
    void set(jsonString* key, jsonValue* value);
    virtual const char* type();
};

#endif
