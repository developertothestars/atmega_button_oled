/* button_oled.ino */

#include <Arduino.h>
#include <U8x8lib.h>

U8X8_SSD1306_128X64_NONAME_4W_SW_SPI u8x8(/* clock=*/ 10, /* data=*/ 16, /* cs=*/ 0, /* dc=*/ 15, /* reset=*/ 14);

void setup(void)
{
  u8x8.begin();
  u8x8.setPowerSave(0);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
}

int x;
int y;
int oldx;
int oldy;

void loop(void)
{
  char s[3];
  s[1] = 0;
  s[2] = 0;
  u8x8.setFont(u8x8_font_chroma48medium8_r);
  u8x8.drawString(oldx, oldy, " ");
      u8x8.drawString(8, 1, "Y=");
  s[0] = '0' + y;
  u8x8.drawString(10, 1, s);
  u8x8.drawString(8, 0, "X=");
  if (x > 9)
  {
      s[0] = '1';
      s[1] = '0' + x - 10;
  }
  else
  {
      s[0] = '0' + x;
      s[1] = ' ';
  }
  u8x8.drawString(10, 0, s);

  u8x8.drawString(x, y, "*");

  oldx = x;
  oldy = y;
  if (digitalRead(9))
      y += 1;
  if (digitalRead(8))
      y -= 1;
  if (digitalRead(7))
      x += 1;
  if (digitalRead(6))
      x -= 1;
  if (x < 0) x = 0;
  if (x > 15) x = 15;
  if (y < 0) y = 0;
  if (y > 7) y = 7;
  delay(200);
}
