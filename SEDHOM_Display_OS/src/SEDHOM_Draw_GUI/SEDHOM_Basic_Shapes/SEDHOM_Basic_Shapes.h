#ifndef SEDHOM_BASIC_SHAPES_H_
#define SEDHOM_BASIC_SHAPES_H_
//BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB
#include "../../SEDHOM_GUI_Core/SEDHOM_GUI_Core.h"
#include "../../SEDHOM_Utilits/SEDHOM_Data_Types/SEDHOM_Data_Types.h"
#include "../../SEDHOM_Utilits/SEDHOM_Math/SEDHOM_Math.h"
//BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB
//BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB
class SEDHOM_Basic_Shapes : private SEDHOM_GUI_Core
{
    private:
        
    public:
        // define all screen functions
        static void Fill_Screen(Color_t color);
        // define Basic shapes
        void Pixel(Pixel_Data_t pixel);
        void Line(Line_Data_t line);    
        void Rectangle(Rectangle_Data_t rect);
        void Square(Square_Data_t sqrt);  
        void Circle(Circle_Data_t circle); 
        void Circle_Helper(Circle_Helper_Data_t circle_helper);
        void Triangle(Triangle_Data_t tri); 
        void Ellipse(Ellipse_Data_t ellipse);
        // shapes derivative
        void Equilateral_Triangle(Triangle_special_Data_t tri);
        void Right_Triangle(Icon_Data_t Icon,Area_t area,Shape_filled_t filled);
        void Border_Rectangle(Icon_Data_t Border_Rect,Area_t area,int Radius,int Border_size);
        void Container(Rectangle_Data_t container);
        // custom image or font
        void Draw_Custom_int_shape(Icon_Data_t Icon,Area_t area,int arr[]);
        void Draw_Custom_Char(Icon_Data_t Icon,Area_t area,char arr[]);
        // 3D shapes
        void Cube(Cube_Data_t cube);    
};
//BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB
//BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB
#endif // !SEDHOM_BASIC_SHAPES_H_