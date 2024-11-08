# Basic Audio

![Circuit Image](Feather32u4_PiezoBuzzer.png)

A Piezoelectric element (piezo for short) converts electrical to physical energy. Adding current makes it move, and moving it creates a current. Once the piezo is connected, you can create a tone using the tone command.


## Sample Code

```c
const int PIEZO_PIN = 9;

void setup() {
  pinMode(PIEZO_PIN, OUTPUT);
}

void loop() {
  // pin to use, frequency, duration
  tone(PIEZO_PIN, 1000, 500);
}
```

For more complexity, look at the `song` sketch which includes a notes file with constants for standard note names. Using the notes file will make it easier to convert existing music.

If you want something more sophisticated, check out [Mozzi](https://sensorium.github.io/Mozzi/)
Also, checkout [https://github.com/robsoncouto/arduino-songs](https://github.com/robsoncouto/arduino-songs) for more songs of varying complexity.
