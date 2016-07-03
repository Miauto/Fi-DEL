
void LeftToRight(byte red, byte green, byte blue, int SpeedDelay, int ReturnDelay) {
  for (int i = 0; i < NbLED; i++) {
    setAll(red / 100, green / 100, blue / 100);

    setPixel(i, red, green, blue);

    showStrip();
    delay(SpeedDelay);
  }
  delay(ReturnDelay);
}

