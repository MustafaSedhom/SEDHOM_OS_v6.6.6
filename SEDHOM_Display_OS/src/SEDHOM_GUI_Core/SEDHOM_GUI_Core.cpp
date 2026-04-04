//??????????????????????????????????????????????????????????????????????????????????????????????????
#include "SEDHOM_GUI_Core.h"
//??????????????????????????????????????????????????????????????????????????????????????????????????
// Full screen fill
void SEDHOM_GUI_Core::FullScreen(U_int16_t color)
{
    SEDHOM_Fill_Screen(color);
}
// Draw a pixel
void SEDHOM_GUI_Core::drawPixel(int16_t x, int16_t y, U_int16_t color)
{
    SEDHOM_Draw_Pixel(x, y, color);
}
// Advanced drawing functions built on drawPixel
void SEDHOM_GUI_Core::drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, U_int16_t color)
{
  int16_t steep = abs(y1 - y0) > abs(x1 - x0);
  if (steep) {
    _swap_int16_t(x0, y0);
    _swap_int16_t(x1, y1);
  }

  if (x0 > x1) {
    _swap_int16_t(x0, x1);
    _swap_int16_t(y0, y1);
  }

  int16_t dx, dy;
  dx = x1 - x0;
  dy = abs(y1 - y0);

  int16_t err = dx / 2;
  int16_t ystep;

  if (y0 < y1) {
    ystep = 1;
  } else {
    ystep = -1;
  }

  for (; x0 <= x1; x0++) {
    if (steep) {
      drawPixel(y0, x0, color);
    } else {
      drawPixel(x0, y0, color);
    }
    err -= dy;
    if (err < 0) {
      y0 += ystep;
      err += dx;
    }
  }
}
void SEDHOM_GUI_Core::drawFastVLine(int16_t x, int16_t y, int16_t h, U_int16_t color)
{
    drawLine(x, y, x, y + h - 1, color);
}
void SEDHOM_GUI_Core::drawFastHLine(int16_t x, int16_t y, int16_t w, U_int16_t color)
{
    drawLine(x, y, x + w - 1, y, color);
}
void SEDHOM_GUI_Core::drawRect(int16_t x, int16_t y, int16_t w, int16_t h, U_int16_t color)
{
    drawFastHLine(x, y, w, color);
    drawFastHLine(x, y + h - 1, w, color);
    drawFastVLine(x, y, h, color);
    drawFastVLine(x + w - 1, y, h, color);
}
void SEDHOM_GUI_Core::fillRect(int16_t x, int16_t y, int16_t w, int16_t h, U_int16_t color)
{
  for (int16_t i = x; i < x + w; i++) {
    drawFastVLine(i, y, h, color);
  }
}
void SEDHOM_GUI_Core::drawRoundRect(int16_t x, int16_t y, int16_t w, int16_t h,int r, U_int16_t color)
{
    if(r == 0) {
        drawRect(x, y, w, h, color);
        return;
    }
    int16_t max_radius = ((w < h) ? w : h) / 2; // 1/2 minor axis
    if (r > max_radius)
        r = max_radius;
    // smarter version
    drawFastHLine(x + r, y, w - 2 * r, color);         // Top
    drawFastHLine(x + r, y + h - 1, w - 2 * r, color); // Bottom
    drawFastVLine(x, y + r, h - 2 * r, color);         // Left
    drawFastVLine(x + w - 1, y + r, h - 2 * r, color); // Right
    // draw four corners
    drawCircleHelper(x + r, y + r, r, 1, color);
    drawCircleHelper(x + w - r - 1, y + r, r, 2, color);
    drawCircleHelper(x + w - r - 1, y + h - r - 1, r, 4, color);
    drawCircleHelper(x + r, y + h - r - 1, r, 8, color);
}
void SEDHOM_GUI_Core::fillRoundRect(int16_t x, int16_t y, int16_t w, int16_t h, int16_t r, U_int16_t color)
{
    if (r <= 0) {
        fillRect(x, y, w, h, color);
        return;
    }

    int16_t max_radius = (w < h ? w : h) / 2;
    if (r > max_radius) r = max_radius;

    // الجزء الأوسط
    fillRect(x + r, y, w - 2 * r, h, color);

    // الجوانب
    fillRect(x, y + r, r, h - 2 * r, color);
    fillRect(x + w - r, y + r, r, h - 2 * r, color);

    // الزوايا (دوائر كاملة)
    fillCircle(x + r, y + r, r, color);                     // فوق شمال
    fillCircle(x + w - r - 1, y + r, r, color);             // فوق يمين
    fillCircle(x + r, y + h - r - 1, r, color);             // تحت شمال
    fillCircle(x + w - r - 1, y + h - r - 1, r, color);     // تحت يمين
}
void SEDHOM_GUI_Core::drawCircle(int16_t x0, int16_t y0, int16_t r, U_int16_t color)
{
    // Midpoint circle algorithm
    int16_t f = 1 - r;
    int16_t ddF_x = 1;
    int16_t ddF_y = -2 * r;
    int16_t x = 0;
    int16_t y = r;

    drawPixel(x0, y0 + r, color);
    drawPixel(x0, y0 - r, color);
    drawPixel(x0 + r, y0, color);
    drawPixel(x0 - r, y0, color);

    while (x < y) {
        if (f >= 0) {
            y--;
            ddF_y += 2;
            f += ddF_y;
        }
        x++;
        ddF_x += 2;
        f += ddF_x;

        drawPixel(x0 + x, y0 + y, color);
        drawPixel(x0 - x, y0 + y, color);
        drawPixel(x0 + x, y0 - y, color);
        drawPixel(x0 - x, y0 - y, color);
        drawPixel(x0 + y, y0 + x, color);
        drawPixel(x0 - y, y0 + x, color);
        drawPixel(x0 + y, y0 - x, color);
        drawPixel(x0 - y, y0 - x, color);
    }
}
void SEDHOM_GUI_Core::fillCircle(int16_t x0, int16_t y0, int16_t r, U_int16_t color)
{
    // Midpoint circle algorithm with vertical lines
    int16_t f = 1 - r;
    int16_t ddF_x = 1;
    int16_t ddF_y = -2 * r;
    int16_t x = 0;
    int16_t y = r;

    drawFastVLine(x0, y0 - r, 2 * r + 1, color);

    while (x < y) {
        if (f >= 0) {
            y--;
            ddF_y += 2;
            f += ddF_y;
        }
        x++;
        ddF_x += 2;
        f += ddF_x;

        drawFastVLine(x0 + x, y0 - y, 2 * y + 1, color);
        drawFastVLine(x0 - x, y0 - y, 2 * y + 1, color);
        drawFastVLine(x0 + y, y0 - x, 2 * x + 1, color);
        drawFastVLine(x0 - y, y0 - x, 2 * x + 1, color);
    }
}
void SEDHOM_GUI_Core::drawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1,int16_t x2, int16_t y2, U_int16_t color)
{
    drawLine(x0, y0, x1, y1, color);
    drawLine(x1, y1, x2, y2, color);
    drawLine(x2, y2, x0, y0, color);
}
void SEDHOM_GUI_Core::fillTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1,int16_t x2, int16_t y2, U_int16_t color)
{
    #define SWAP(a,b) { int16_t t = a; a = b; b = t; }
  int16_t a, b, y, last;

  // Sort coordinates by Y order (y2 >= y1 >= y0)
  if (y0 > y1) {
    _swap_int16_t(y0, y1);
    _swap_int16_t(x0, x1);
  }
  if (y1 > y2) {
    _swap_int16_t(y2, y1);
    _swap_int16_t(x2, x1);
  }
  if (y0 > y1) {
    _swap_int16_t(y0, y1);
    _swap_int16_t(x0, x1);
  }

  if (y0 == y2) { // Handle awkward all-on-same-line case as its own thing
    a = b = x0;
    if (x1 < a)
      a = x1;
    else if (x1 > b)
      b = x1;
    if (x2 < a)
      a = x2;
    else if (x2 > b)
      b = x2;
    drawFastHLine(a, y0, b - a + 1, color);
    return;
  }

  int16_t dx01 = x1 - x0, dy01 = y1 - y0, dx02 = x2 - x0, dy02 = y2 - y0,
          dx12 = x2 - x1, dy12 = y2 - y1;
  int32_t sa = 0, sb = 0;

  // For upper part of triangle, find scanline crossings for segments
  // 0-1 and 0-2.  If y1=y2 (flat-bottomed triangle), the scanline y1
  // is included here (and second loop will be skipped, avoiding a /0
  // error there), otherwise scanline y1 is skipped here and handled
  // in the second loop...which also avoids a /0 error here if y0=y1
  // (flat-topped triangle).
  if (y1 == y2)
    last = y1; // Include y1 scanline
  else
    last = y1 - 1; // Skip it

  for (y = y0; y <= last; y++) {
    a = x0 + sa / dy01;
    b = x0 + sb / dy02;
    sa += dx01;
    sb += dx02;
    /* longhand:
    a = x0 + (x1 - x0) * (y - y0) / (y1 - y0);
    b = x0 + (x2 - x0) * (y - y0) / (y2 - y0);
    */
    if (a > b)
      _swap_int16_t(a, b);
    drawFastHLine(a, y, b - a + 1, color);
  }

  // For lower part of triangle, find scanline crossings for segments
  // 0-2 and 1-2.  This loop is skipped if y1=y2.
  sa = (int32_t)dx12 * (y - y1);
  sb = (int32_t)dx02 * (y - y0);
  for (; y <= y2; y++) {
    a = x1 + sa / dy12;
    b = x0 + sb / dy02;
    sa += dx12;
    sb += dx02;
    /* longhand:
    a = x1 + (x2 - x1) * (y - y1) / (y2 - y1);
    b = x0 + (x2 - x0) * (y - y0) / (y2 - y0);
    */
    if (a > b)
      _swap_int16_t(a, b);
    drawFastHLine(a, y, b - a + 1, color);
  }
}
void SEDHOM_GUI_Core::drawEllipse(int16_t x0, int16_t y0, int16_t rx, int16_t ry, U_int16_t color)
{
    // Midpoint ellipse algorithm
    int32_t rx2 = rx * rx, ry2 = ry * ry;
    int32_t two_rx2 = 2 * rx2, two_ry2 = 2 * ry2;
    int32_t x = 0, y = ry;
    int32_t px = 0, py = two_rx2 * y;

    // Region 1
    int32_t p = round(ry2 - (rx2 * ry) + (0.25 * rx2));
    while (px < py) {
        drawPixel(x0 + x, y0 + y, color);
        drawPixel(x0 - x, y0 + y, color);
        drawPixel(x0 + x, y0 - y, color);
        drawPixel(x0 - x, y0 - y, color);
        x++;
        px += two_ry2;
        if (p < 0) {
            p += ry2 + px;
        } else {
            y--;
            py -= two_rx2;
            p += ry2 + px - py;
        }
    }

    // Region 2
    p = round(ry2 * (x + 0.5) * (x + 0.5) + rx2 * (y - 1) * (y - 1) - rx2 * ry2);
    while (y >= 0) {
        drawPixel(x0 + x, y0 + y, color);
        drawPixel(x0 - x, y0 + y, color);
        drawPixel(x0 + x, y0 - y, color);
        drawPixel(x0 - x, y0 - y, color);
        y--;
        py -= two_rx2;
        if (p > 0) {
            p += rx2 - py;
        } else {
            x++;
            px += two_ry2;
            p += rx2 - py + px;
        }
    }
}
void SEDHOM_GUI_Core::fillEllipse(int16_t x0, int16_t y0, int16_t rx, int16_t ry, U_int16_t color)
{
    // Midpoint ellipse algorithm with vertical lines
    int32_t rx2 = rx * rx, ry2 = ry * ry;
    int32_t two_rx2 = 2 * rx2, two_ry2 = 2 * ry2;
    int32_t x = 0, y = ry;
    int32_t px = 0, py = two_rx2 * y;

    // Region 1
    int32_t p = round(ry2 - (rx2 * ry) + (0.25 * rx2));
    while (px < py) {
        drawFastVLine(x0 + x, y0 - y, 2 * y + 1, color);
        drawFastVLine(x0 - x, y0 - y, 2 * y + 1, color);
        x++;
        px += two_ry2;
        if (p < 0) {
            p += ry2 + px;
        } else {
            y--;
            py -= two_rx2;
            p += ry2 + px - py;
        }
    }

    // Region 2
    p = round(ry2 * (x + 0.5) * (x + 0.5) + rx2 * (y - 1) * (y - 1) - rx2 * ry2);
    while (y >= 0) {
        drawFastVLine(x0 + x, y0 - y, 2 * y + 1, color);
        drawFastVLine(x0 - x, y0 - y, 2 * y + 1, color);
        y--;
        py -= two_rx2;
        if (p > 0) {
            p += rx2 - py;
        } else {
            x++;
            px += two_ry2;
            p += rx2 - py + px;
        }
    }
}
void SEDHOM_GUI_Core::drawCircleHelper(int16_t x0, int16_t y0, int16_t r, U_int8_t cordername, U_int16_t color)
{
  int16_t f = 1 - r;
  int16_t ddF_x = 1;
  int16_t ddF_y = -2 * r;
  int16_t x = 0;
  int16_t y = r;

  while (x < y) {
    if (f >= 0) {
      y--;
      ddF_y += 2;
      f += ddF_y;
    }
    x++;
    ddF_x += 2;
    f += ddF_x;
    if (cordername & 0x4) {
      drawPixel(x0 + x, y0 + y, color);
      drawPixel(x0 + y, y0 + x, color);
    }
    if (cordername & 0x2) {
      drawPixel(x0 + x, y0 - y, color);
      drawPixel(x0 + y, y0 - x, color);
    }
    if (cordername & 0x8) {
      drawPixel(x0 - y, y0 + x, color);
      drawPixel(x0 - x, y0 + y, color);
    }
    if (cordername & 0x1) {
      drawPixel(x0 - y, y0 - x, color);
      drawPixel(x0 - x, y0 - y, color);
    }
  }
}
void SEDHOM_GUI_Core::fillCircleHelper(int16_t x0, int16_t y0, int16_t r, U_int8_t cordername, int16_t delta, U_int16_t color)
{
    int16_t f = 1 - r;
    int16_t ddF_x = 1;
    int16_t ddF_y = -2 * r;
    int16_t x = 0;
    int16_t y = r;

    while (x <= y)
    {
        if (f >= 0)
        {
            y--;
            ddF_y += 2;
            f += ddF_y;
        }

        x++;
        ddF_x += 2;
        f += ddF_x;
        if (cordername & 0x4) {
        drawFastVLine(x0 + x, y0, y + delta, color);
        drawFastVLine(x0 + y, y0, x + delta, color);
        }
        if (cordername & 0x2) {
        drawFastVLine(x0 + x, y0 - y, y + delta, color);
        drawFastVLine(x0 + y, y0 - x, x + delta, color);
        }
        if (cordername & 0x8) {
        drawFastVLine(x0 - x, y0, y + delta, color);
        drawFastVLine(x0 - y, y0, x + delta, color);
        }
        if (cordername & 0x1) {
        drawFastVLine(x0 - x, y0 - y, y + delta, color);
        drawFastVLine(x0 - y, y0 - x, x + delta, color);
        }
    }
}

// void Adafruit_GFX::setRotation(U_int8_t x) {
//   rotation = (x & 3);
//   switch (rotation) {
//   case 0:
//   case 2:
//     _width = WIDTH;
//     _height = HEIGHT;
//     break;
//   case 1:
//   case 3:
//     _width = HEIGHT;
//     _height = WIDTH;
//     break;
//   }
// }
// Text functions
void SEDHOM_GUI_Core::Draw_Char(int16_t x, int16_t y, const SEDHOM_GFXfont* font, Color_t color, char c) 
{
  int size_x = 1, size_y = 1; // Default text size
  if (!font) return; 
   // Custom font
    c -= (U_int8_t)pgm_read_byte(&font->first);
    SEDHOM_GFXglyph *glyph = pgm_read_glyph_ptr(font, c);
    U_int8_t *bitmap = pgm_read_bitmap_ptr(font);

    U_int16_t bo = pgm_read_word(&glyph->bitmapOffset);
    U_int8_t w = pgm_read_byte(&glyph->width), h = pgm_read_byte(&glyph->height);
    int8_t xo = pgm_read_byte(&glyph->xOffset),
           yo = pgm_read_byte(&glyph->yOffset);
    U_int8_t xx, yy, bits = 0, bit = 0;
    int16_t xo16 = 0, yo16 = 0;

    if (size_x > 1 || size_y > 1) {
      xo16 = xo;
      yo16 = yo;
    }
    for (yy = 0; yy < h; yy++) {
      for (xx = 0; xx < w; xx++) {
        if (!(bit++ & 7)) {
          bits = pgm_read_byte(&bitmap[bo++]);
        }
        if (bits & 0x80) {
          if (size_x == 1 && size_y == 1) {
            drawPixel(x + xo + xx, y + yo + yy, color);
          } else {
            fillRect(x + (xo16 + xx) * size_x, y + (yo16 + yy) * size_y,
                          size_x, size_y, color);
          }
        }
        bits <<= 1;
      }
    }
}
void SEDHOM_GUI_Core::Draw_String(int16_t x, int16_t y, const SEDHOM_GFXfont* font, U_int16_t color,const char* str)
{
    if (!font || !str) return;

    int16_t cursor_x = x;
    int16_t cursor_y = y;

    while (*str) {
        char c = *str++;
        if (c < pgm_read_byte(&font->first) || 
            c > pgm_read_byte(&font->last)) {
            continue;
        }
        U_int8_t index = c - pgm_read_byte(&font->first);

        SEDHOM_GFXglyph *glyph = pgm_read_glyph_ptr(font, index);

        Draw_Char(cursor_x, cursor_y, font, color, c);

        cursor_x += pgm_read_byte(&glyph->xAdvance);
    }
}
//??????????????????????????????????????????????????????????????????????????????????????????????????