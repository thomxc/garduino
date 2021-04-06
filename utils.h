void blink(int ms = 500, int times = 2)
{
  #if defined(LED_BUILTIN)
    for (int i = 0; i < times; i++) {
      digitalWrite(LED_BUILTIN, LOW);
      delay(ms);
      digitalWrite(LED_BUILTIN, HIGH); // LOW is apparently ON on my development board?
      delay(ms);
    }
  #endif
}
