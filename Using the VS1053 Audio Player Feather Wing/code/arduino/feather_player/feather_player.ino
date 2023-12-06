// Specifically for use with the Adafruit Feather, the pins are pre-set here!

// include SPI, MP3 and SD libraries
#include <SPI.h>
#include <SD.h>
#include <Adafruit_VS1053.h>


#define VS1053_CS       6     // VS1053 chip select pin (output)
#define VS1053_DCS     10     // VS1053 Data/command select pin (output)
#define CARDCS          5     // Card chip select pin
#define VS1053_DREQ     9     // VS1053 Data request, ideally an Interrupt pin

Adafruit_VS1053_FilePlayer musicPlayer =
  Adafruit_VS1053_FilePlayer(-1, VS1053_CS, VS1053_DCS, VS1053_DREQ, CARDCS);

void setup() {
  if (! musicPlayer.begin()) { // initialise the music player
     while (1);
  }
  musicPlayer.sineTest(0x44, 500);    // Make a tone to indicate VS1053 is working

  // connect to SD card
  if (!SD.begin(CARDCS)) {
    while (1);  // don't do anything more
  }

  // Set volume for left, right channels. lower numbers == louder volume!
  musicPlayer.setVolume(10,10);
  musicPlayer.useInterrupt(VS1053_FILEPLAYER_TIMER0_INT); // timer int for 32u4 board

  // play the file, names must have 8 letters or numbers in the name, then a '.' then the extension
  musicPlayer.playFullFile("/track001.mp3");
}

void loop() {
  // File is playing in the background
  if (musicPlayer.stopped()) {
    delay(100);
    musicPlayer.playFullFile("/track002.mp3");
  }
  delay(100);
}

