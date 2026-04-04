//DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD
#ifndef SEDHOM_DYNAMIC_DATA_TYPE_H
#define SEDHOM_DYNAMIC_DATA_TYPE_H
//DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD
#include <string.h>   // for strncpy, strcmp
#include <stdlib.h>   // for atoi, atof
#include <stdio.h>    // for snprintf
//DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD
typedef enum 
{
    Data_Type_none,
    Data_Type_char,
    Data_Type_int,
    Data_Type_float,
    Data_Type_double,
    Data_Type_bool,
    Data_Type_string,
}Data_Type_t;
//DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD
#define max_Dynamic_variable_size_by_byte      40
//DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD
class SEDHOM_Dynamic_Data_Type
{
private:
   Data_Type_t Data_Type;
   union Value
   {
       Value(){}
       char c; 
       int i;
       float f;
       double d;
       bool b;
       char s[max_Dynamic_variable_size_by_byte]; // String
   }value;
public:
    SEDHOM_Dynamic_Data_Type();
    SEDHOM_Dynamic_Data_Type(Data_Type_t init_type);
    ~SEDHOM_Dynamic_Data_Type();
    // functions to set Data type for this Dynamic variable
    void set_Data_Type(Data_Type_t type) { Data_Type = type; }
    // functions to get Data type for this Dynamic variable
    Data_Type_t get_Data_Type()  { return Data_Type; }
    // functions to set value for this Dynamic variable
    void set_Value(char val);
    void set_Value(int val);
    void set_Value(float val);
    void set_Value(double val);
    void set_Value(const char* val);
    void set_Value(bool val);
    // functions to can assign value for this Dynamic variable
    SEDHOM_Dynamic_Data_Type& operator=(const SEDHOM_Dynamic_Data_Type& other);
    SEDHOM_Dynamic_Data_Type& operator=(char val);
    SEDHOM_Dynamic_Data_Type& operator=(int val);
    SEDHOM_Dynamic_Data_Type& operator=(float val);
    SEDHOM_Dynamic_Data_Type& operator=(double val);
    SEDHOM_Dynamic_Data_Type& operator=(bool val);
    SEDHOM_Dynamic_Data_Type& operator=(const char* val);
    bool operator==( SEDHOM_Dynamic_Data_Type& other);
    bool operator!=( SEDHOM_Dynamic_Data_Type& other);
    // functions for can change from data type to another
    int    to_Int();
    float  to_Float();
    double to_Double();
    bool   to_Bool();
    char*  to_String(int float_precision = 2);
};
//DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD
//DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD
#endif //SEDHOM_DYNAMIC_DATA_TYPE_H
//DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD