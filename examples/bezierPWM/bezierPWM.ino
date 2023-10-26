#include "BezierPWM.h"

BezierPWM pwm(13); // Create an instance of BezierPWM with the default pin 13

void setup() {
    SoftPWMBegin();
    SoftPWMSet(pwm.getPWMPin(), 0); // Initialize SoftPWM with the pin from your BezierPWM instance
}

void loop() {
    // Using predefined curve "ease," fade from 0 to 1 in 1 second
    pwm.ease(0, 1, 1000);
    
    // // Using predefined curve "easeIn," fade from 1 to 0 in 1 second
    pwm.easeIn(1, 0, 1000);
    
    delay(500);
    
    // // Using predefined curve "easeOut," fade from 0 to 1 in 1 second
    pwm.easeOut(0, 1, 1000);
    
    // // Using predefined curve "easeInOut," fade from 1 to 0 in 2 seconds
    pwm.easeInOut(1, 0, 2000);

    pwm.breathIn(0, 1, 2300);
    delay(200);
    pwm.breathOut(1, 0, 2300);
    delay(800);
    
    // Using custom control points, fade from 1 to 0 in 2 seconds
    float customPoints[] = {0.2, 0.1, 0.6, 0.9};
    pwm.bezierFade(customPoints, 1, 0, 2000);
    
    delay(500);

    pwm.linear(0,1,1000);
    pwm.easeSine(0,1,1000);
    pwm.easeSineIn(0,1,1000);
    pwm.easeSineOut(0,1,1000);
    pwm.easeSineInOut(0,1,1000);
    
}
