#ifndef TFTPianoDisplay_h
#define TFTPianoDisplay_h

#ifdef build_for_arduino
#include "Arduino.h"


#include <SD.h>
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library

class TFTPianoDisplay
{
  public:
    TFTPianoDisplay(Adafruit_GFX &tft, byte octaves, byte startOctave, byte x, byte y);
    void setPosition(byte x, byte y);
    void keyDown(byte key);
    void keyUp(byte key);
    void drawPiano();
    bool displayNeedsUpdating();
    
  private:
    Adafruit_GFX *_tft;
    byte _x, _y;
    byte _height, _width;
    byte _offsetKeyZero;
    unsigned int _octaves, _startOctave; 
    
    bool _shouldUpdatePiano = true;
    byte _keysWhichArePressed[22];

    bool isKeyPressed(byte key);
    bool isAnyKeyPressed(byte key);
};
#else
#include "tests/mock_arduino.h"
#endif

#endif