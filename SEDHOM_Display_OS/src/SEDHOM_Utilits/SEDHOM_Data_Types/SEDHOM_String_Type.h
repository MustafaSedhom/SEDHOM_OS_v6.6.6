//SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
#ifndef SEDHOM_STRING_TYPE_H_
#define SEDHOM_STRING_TYPE_H_
//SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
#include <stdlib.h>  // لدوال itoa, dtostrf
#include <string.h>  // لدوال strlen, strcpy
//SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS

class string {
    private:
        char* data;
        unsigned int len;
    public:
        // Constructor from C-string
        string(const char* str = "");
        // Copy constructor
        string(const string& other);
        // Constructor from int
        string(int value);
        // Constructor from float
        string(float value, int precision = 2);
        // Destructor
        ~string();
        // Get length
        unsigned int length() const;
        // Get C-string
        const char* c_str() const;
        // Assignment operators
        string& operator=(const string& other);
        string& operator=(const char* str);
        // Concatenation operators
        string operator+(const string& other) const;
        string operator+(const char* str) const;
        // Equality
        bool operator==(const string& other) const;
        bool operator!=(const string& other) const;       
        // Compare
        int compare(const string& other) const;
        void copy(const string& other);      
        // Concatenate
        string& concat(const string& other);
        string& concat(const char* str);       
        // Clear string
        void clear();       
        // Substring
        string substring(unsigned int start, unsigned int length) const;       
        // Find index of char
        int indexOf(char c) const;
        // Conversions
        int toInt() const;
        float toFloat() const;
        bool toBool() const;
};
//SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
#endif // SEDHOM_STRING_TYPE_H_
//SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS