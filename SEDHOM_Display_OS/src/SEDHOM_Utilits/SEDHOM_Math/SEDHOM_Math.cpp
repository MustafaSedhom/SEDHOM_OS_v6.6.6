//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
#include "SEDHOM_Math.h"
//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm

SEDHOM_Math::SEDHOM_Math()
{
}
SEDHOM_Math::SEDHOM_Math(Area_t Screen_Area)
{
   Screen_Dimensions = Screen_Area;
}
SEDHOM_Math::~SEDHOM_Math()
{
}
//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
float SEDHOM_Math::Degree_to_Radian(float Degree)
{
    return Degree * 3.14159265359 / 180.0;
}
float SEDHOM_Math::Radian_to_Degree(float Radian)
{
     return Radian * 180.0 / 3.14159265359;
}
Coordinate_t SEDHOM_Math::Rotation_Equation(Coordinate_t old_Point ,float Degree_angle)
{
    float rad_angle = Degree_to_Radian(Degree_angle);
    Coordinate_t return_coordinate_Rotate;
    return_coordinate_Rotate.x = old_Point.x * cos(rad_angle) - old_Point.y * sin(rad_angle);
    return_coordinate_Rotate.y = old_Point.x * sin(rad_angle) + old_Point.y * cos(rad_angle);
    return return_coordinate_Rotate;
}
int SEDHOM_Math::Convert_Coordinates_to_Center_X_Point(int x)
{
    return x + (Screen_Dimensions.w / 2);
}
int SEDHOM_Math::Convert_Coordinates_to_Center_Y_Point(int y)
{
    return (Screen_Dimensions.h / 2) - y;
}
Coordinate_t SEDHOM_Math::Convert_Coordinates_to_Center(Coordinate_t new_point)
{
  Coordinate_t old_coordinate ;
  old_coordinate.x = Convert_Coordinates_to_Center_X_Point(new_point.x);
  old_coordinate.y = Convert_Coordinates_to_Center_Y_Point(new_point.y);
   return old_coordinate;
}
long SEDHOM_Math::Convert_Millis_to_Micros(long millis)
{
    return millis * 1000;
}

long SEDHOM_Math::Convert_Micros_to_Millis(long micros)
{
    return micros / 1000;
}

long SEDHOM_Math::Convert_Second_to_Millis(long second)
{
    return second * 1000;
}

long SEDHOM_Math::Convert_Millis_to_Second(long millis)
{
    return millis / 1000;
}

long SEDHOM_Math::Convert_Second_to_Micros(long second)
{
    return second * 1000000;
}

long SEDHOM_Math::Convert_Micros_to_Second(long micros)
{
    return micros / 1000000;
}
//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
// // Square function
// template <typename T>
// inline T sqr(T value) {
//     return value * value;
// }
    // static long map(long x, long in_min, long in_max, long out_min, long out_max) {
    //     return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
    // }

    // // Map function for float/double values
    // template <typename T>
    // static T map(T x, T in_min, T in_max, T out_min, T out_max) {
    //     return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
    // }
// // Constrain integer values
// static long constrain(long x, long lower, long upper) {
//     if (x < lower) return lower;
//     if (x > upper) return upper;
//     return x;
// }

// // Constrain floating-point values
// template <typename T>
// static T constrain(T x, T lower, T upper) {
//     if (x < lower) return lower;
//     if (x > upper) return upper;
//     return x;
// }

// template <typename T>
// T sqrt_custom(T x) {
//     if (x <= 0) return 0;

//     T guess = x / 2;
//     for (int i = 0; i < 20; ++i) {
//         guess = 0.5 * (guess + x / guess);
//     }

//     return guess;
// }

// template <typename T>
// inline T abs_custom(T value) {
//     return (value < 0) ? -value : value;
// }

// template <typename T>
// T pow_custom(T base, int exp) {
//     T result = 1;
//     bool negative = (exp < 0);
//     if (negative) exp = -exp;

//     while (exp) {
//         if (exp & 1) result *= base;
//         base *= base;
//         exp >>= 1;
//     }

//     if (negative) return 1 / result;
//     return result;
// }
//mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm