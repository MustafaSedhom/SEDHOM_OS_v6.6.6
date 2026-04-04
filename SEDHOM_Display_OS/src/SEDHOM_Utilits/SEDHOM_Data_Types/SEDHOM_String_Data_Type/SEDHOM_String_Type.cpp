//SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
#include "SEDHOM_String_Type.h"
//SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
//SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
// Constructor من C-string
string::string(const char* str) 
{
    len = 0;
    while (str[len] != '\0' && len < 99) {
        data[len] = str[len];
        len++;
    }
    data[len] = '\0';
}

// Copy Constructor
string::string(const string& other) 
{
    len = (other.len < 99) ? other.len : 99;
    for (unsigned int i = 0; i < len; i++)
        data[i] = other.data[i];
    data[len] = '\0';
}
// Constructor from int
string::string(int value) 
{
    char buffer[12]; // enough for 32-bit int
    itoa(value, buffer, 10); // convert int to string
    len = 0;
    while (buffer[len] != '\0') len++;
    data = new char[len + 1];
    for (unsigned int i = 0; i < len; i++)
        data[i] = buffer[i];
    data[len] = '\0';
}

// Constructor from float
string::string(float value, int precision = 2) 
{
    char buffer[32]; // enough for float with precision
    dtostrf(value, 0, precision, buffer); // convert float to string
    len = 0;
    while (buffer[len] != '\0') len++;
    data = new char[len + 1];
    for (unsigned int i = 0; i < len; i++)
        data[i] = buffer[i];
    data[len] = '\0';
}

// Destructor
string::~string() 
{
    delete[] data;
}

// Length
unsigned int string::length() const { return len; }

// Get C-string
const char* string::c_str() const { return data; }

// Assignment operator
string& string::operator=(const string& other) 
{
    if (this != &other) {
        len = (other.len < 99) ? other.len : 99;
        for (unsigned int i = 0; i < len; i++)
            data[i] = other.data[i];
        data[len] = '\0';
    }
    return *this;
}

string& string::operator=(const char* str) 
{
    len = 0;
    while (str[len] != '\0' && len < 99) {
        data[len] = str[len];
        len++;
    }
    data[len] = '\0';
    return *this;
}

// Concatenate
string& string::concat(const string& other) 
{
    unsigned int i = 0;
    while (len < 99 && i < other.len) {
        data[len++] = other.data[i++];
    }
    data[len] = '\0';
    return *this;
}

string& string::concat(const char* str) 
{
    unsigned int i = 0;
    while (len < 99 && str[i] != '\0') {
        data[len++] = str[i++];
    }
    data[len] = '\0';
    return *this;
}

// Operators
string string::operator+(const string& other) const 
{
    string result(*this);
    result.concat(other);
    return result;
}

string string::operator+(const char* str) const 
{
    string result(*this);
    result.concat(str);
    return result;
}

bool string::operator==(const string& other) const 
{
    if (len != other.len) return false;
    for (unsigned int i = 0; i < len; i++)
        if (data[i] != other.data[i]) return false;
    return true;
}

bool string::operator!=(const string& other) const 
{
    return !(*this == other);
}

// Compare (0=same, <0=this<other, >0=this>other)
int string::compare(const string& other) const 
{
    unsigned int i = 0;
    while (i < len && i < other.len) {
        if (data[i] != other.data[i]) return data[i] - other.data[i];
        i++;
    }
    return len - other.len;
}

// Copy
void string::copy(const string& other) 
{
    *this = other;
}

// Conversions
int string::toInt() const 
{
    int result = 0;
    bool neg = false;
    unsigned int i = 0;
    if (data[0] == '-') { neg = true; i = 1; }
    for (; i < len; i++) {
        if (data[i] < '0' || data[i] > '9') break;
        result = result * 10 + (data[i] - '0');
    }
    return neg ? -result : result;
}

float string::toFloat() const 
{
    float result = 0;
    float frac = 0;
    bool neg = false;
    bool afterDot = false;
    float div = 10.0;
    unsigned int i = 0;
    if (data[0] == '-') { neg = true; i = 1; }
    for (; i < len; i++) {
        if (data[i] == '.') { afterDot = true; continue; }
        if (data[i] < '0' || data[i] > '9') break;
        if (!afterDot) result = result * 10 + (data[i] - '0');
        else { frac += (data[i] - '0') / div; div *= 10; }
    }
    result += frac;
    return neg ? -result : result;
}

bool string::toBool() const
{
    return toInt() != 0;
}

void string::clear() { len = 0; data[0] = '\0'; }

string string::substring(unsigned int start, unsigned int length) const 
{
    string result;
    if (start >= len) return result; 
    if (start + length > len) length = len - start; 

    for (unsigned int i = 0; i < length; i++) {
        result.data[i] = data[start + i];
    }
    result.data[length] = '\0';
    result.len = length;
    return result;
}

int string::indexOf(char c) const 
{
    for (unsigned int i = 0; i < len; i++) {
        if (data[i] == c) return i;
    }
    return -1; 
}
//SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
