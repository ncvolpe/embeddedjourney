#include <Arduino.h>

hw_timer_t * timer = NULL;
portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;


void IRAM_ATTR onTimer(){
  portENTER_CRITICAL_ISR(&timerMux);
Serial.println(String("onTimer() ") + String(millis()));
  portEXIT_CRITICAL_ISR(&timerMux);
}

void setup(){
  Serial.begin(115200);
  Serial.println("start timer");
  timer = timerBegin(0, 80, true);
  timerAttachInterrupt(timer, &onTimer, true); // edge (not level) triggered
  timerAlarmWrite(timer, 1000000, true);
  timerAlarmEnable(timer);

}

void loop(){
  vTaskDelay(portMAX_DELAY);
}