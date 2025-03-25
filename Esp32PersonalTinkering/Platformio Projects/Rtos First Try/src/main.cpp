// Following https://www.youtube.com/watch?v=LONGI_JcwEQ&t=3s
#include <Arduino.h>

hw_timer_t * timer = NULL;
portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;


void IRAM_ATTR onTimer(){
  portENTER_CRITICAL_ISR(&timerMux);
Serial.println(String("onTimer() ") + String(millis()));
  portEXIT_CRITICAL_ISR(&timerMux);
  // Although he talked about this weird port stuff, he didn't use it in his code. why?
}

void setup(){
  Serial.begin(115200);
  Serial.println("start timer");
  timer = timerBegin(0, 80, true);// timer 0, MWDT clock period = 12.5ns * TIMGn_Tx_WDT_CLK_PRESCALE -> 12.5 ns * 80 - > 1000 ns = 1us
  timerAttachInterrupt(timer, &onTimer, true); // edge (not level) triggered
  timerAlarmWrite(timer, 1000000, true); // 1000000 * 1 us = 1s, autoreload true
  //so, theoretically, every 1 second, the interrupt function is called? Wow.
  timerAlarmEnable(timer);

}

void loop(){
  vTaskDelay(portMAX_DELAY);
  Serial.println("meow"); // Doesn't do anything
  delay(500); // Doesn't do anything
}