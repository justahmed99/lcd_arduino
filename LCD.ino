#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int screen_width = 16;
int screen_length = 2;

int start_string, stop_string = 0;
int scroll_cursor = screen_width;

String line1 = "Awesome Newbie";
String line2 = "Follow @awesomenewbie";

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  lcd.setCursor(1, 0);
  lcd.print(line1);
  
  lcd.setCursor(scroll_cursor, 1);
  lcd.print(line2.substring(start_string, stop_string));

  delay(400);

  lcd.clear();

  if(start_string == 0 && scroll_cursor > 0) {
    scroll_cursor--;
    stop_string++;
  } else if(start_string == stop_string) {
    start_string = stop_string = 0;
    scroll_cursor = screen_width;
  } else if(stop_string == line2.length() && scroll_cursor == 0) {
    start_string++;
  } else {
    start_string++;
    stop_string++;
  }
}