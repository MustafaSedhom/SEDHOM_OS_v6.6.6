#ifndef SEDHOM_MATH_H_
#define SEDHOM_MATH_H_
//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
#include "../SEDHOM_Data_Types/SEDHOM_Data_Types.h"
#include <math.h>
//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
class SEDHOM_Math
{
private:
    Area_t Screen_Dimensions;
public:
    SEDHOM_Math();
    SEDHOM_Math(Area_t Screen_Area);
    ~SEDHOM_Math();
    // functions
    static float Degree_to_Radian(float Degree);
    static float Radian_to_Degree(float Radian);
    static Coordinate_t Rotation_Equation(Coordinate_t old_Point ,float Degree_angle);
    int Convert_Coordinates_to_Center_X_Point(int x);
    int Convert_Coordinates_to_Center_Y_Point(int y);
    Coordinate_t Convert_Coordinates_to_Center(Coordinate_t new_point);
    long Convert_Millis_to_Micros(long millis);
    long Convert_Micros_to_Millis(long micros);
    long Convert_Second_to_Millis(long second);
    long Convert_Millis_to_Second(long millis);
    long Convert_Second_to_Micros(long second);
    long Convert_Micros_to_Second(long micros);
};
//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
#endif // !SEDHOM_MATH_H_