#include "BezierPWM.h"
#include "SoftPWM.h"

BezierPWM::BezierPWM(int pin) {
    _pin = pin;
    // Perform any initialization here
}

void BezierPWM::bezierFade(float* points, int startValue, int endValue, unsigned long duration) {
    int steps = 255;
    unsigned long stepTime = duration / steps;

    for (int i = 0; i <= steps; i++) {
        float t = (float)i / steps;
        float brightness = startValue + (endValue - startValue) * cubicBezier(t, points[0], points[1], points[2], points[3]);
        int pwmValue = (int)(brightness * 255); // Convert 0-1 to 0-255 scale if needed
        SoftPWMSet(_pin, pwmValue);
        delay(stepTime);
    }
}

void BezierPWM::ease(int startValue, int endValue, unsigned long duration) {
    float curve[] = {0.25, 0.1, 0.25, 1};
    bezierFade(curve, startValue, endValue, duration);
}

void BezierPWM::easeIn(int startValue, int endValue, unsigned long duration) {
    float curve[] = {0.42, 0, 1, 1};
    bezierFade(curve, startValue, endValue, duration);
}

void BezierPWM::easeOut(int startValue, int endValue, unsigned long duration) {
    float curve[] = {0, 0, 0.58, 1};
    bezierFade(curve, startValue, endValue, duration);
}

void BezierPWM::easeInOut(int startValue, int endValue, unsigned long duration) {
    float curve[] = {0.42, 0, 0.58, 1};
    bezierFade(curve, startValue, endValue, duration);
}

float BezierPWM::cubicBezier(float t, float p0, float p1, float p2, float p3) {
    return pow(1 - t, 3) * p0 + 3 * pow(1 - t, 2) * t * p1 + 3 * (1 - t) * pow(t, 2) * p2 + pow(t, 3) * p3;
}

int BezierPWM::getPWMPin() {
    return _pin;
}
