#include "test.h"
#include <Arduino.h>


void Test::sequenceTest(bool &led_n, bool &led_e,bool &led_w,bool &led_s, bool &mot, bool (&bargraph)[4][10]){
    int testNo = (millis() / 500) % 19;

  led_n = false;
  led_e = false;
  led_w = false;
  led_s = false;

  

  mot = false;

  switch (testNo)
  {
  case 0:
    led_n =true;
    break;
  case 1:
    led_s =true;
    break;
  case 2:
    led_e =true;
    break;
  case 3:
    led_w =true;
    break;
  case 4:
    mot =true;
    break;
  case 5:
    for(int i =0; i<4;i++){
      for (int j = 0; j < 3; j++)
      {
        bargraph[i][j] = true;
      }
      
    }
    break;
  case 6:
    for(int i =0; i<4;i++){
      for (int j = 0; j < 3; j++)
      {
        bargraph[i][j] = false;
      }
      
    }
    break;



  default: {
              int ledNo = testNo - 6;
              int barNo = ledNo / 3;
              int posNo = ledNo - (barNo * 3);
              bargraph[barNo][posNo] = true;
              break;
           }
    
  }
}