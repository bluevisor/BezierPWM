#ifndef BezierPWM_h
#define BezierPWM_h

#include "Arduino.h"
#include "SoftPWM.h" // Include the SoftPWM library

class BezierPWM {
public:
    BezierPWM(int pin = DEFAULT_PIN);

    // Function to perform a Bezier fade with custom points
    void bezierFade(float* points, int startValue, int endValue, unsigned long duration);

    // Predefined Bezier fade functions
    void ease(int startValue, int endValue, unsigned long duration);
    void easeIn(int startValue, int endValue, unsigned long duration);
    void easeOut(int startValue, int endValue, unsigned long duration);
    void easeInOut(int startValue, int endValue, unsigned long duration);

    // Public method to get the PWM pin
    int getPWMPin();

private:
    int _pin;
    static const int DEFAULT_PIN = 13; // Default PWM pin is set to 13

    // Private method to compute the cubic Bezier curve
    float cubicBezier(float t, float p0, float p1, float p2, float p3);
};

#endif
