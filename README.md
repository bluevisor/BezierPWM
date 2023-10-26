# Arduino LED Fader using SoftPWM and Bezier Curves

This project is an extension of the [SoftPWM Library](https://github.com/bhagman/SoftPWM) to control the brightness of LEDs on Arduino. It allows for more elegant, non-linear fading through the use of cubic Bezier curves. Works on any pin, including the built-in LED.

## Features

- Non-linear LED fading on any pin
- Customizable Bezier curves for intricate light effects
- Predefined easing functions like easeIn, easeOut, easeInOut, and more
- Highly customizable with options for initial and target brightness, total fade time, and more

## Installation

1. Clone or download the BezierPWM library repository to your local machine.

```shell
$ git clone https://github.com/bluevisor/BezierPWM.git
```
2. Open the Arduino IDE.
3. Go to `Sketch` -> `Include Library` -> `Add .ZIP Library` and select the downloaded repository.

## Usage

### Predefined Curves

The BezierPWM library comes with four predefined curves that you can use for smooth fading transitions:

- ease: Smooth ease curve.
- easeIn: Ease-in curve.
- easeOut: Ease-out curve.
- easeInOut: Ease-in-out curve.
- easeSine: Sine-like ease curve.
- easeSineIn: Sine-like ease-in curve.
- easeSineOut: Sine-like ease-out curve.
- easeSineInOut: Sine-like ease-in-out curve.
- breathIn: Natural human breathing in curve.
- breathOut: Natural human breathing out curve.
- linear: Straight line.

```cpp
#include "BezierPWM.h"

BezierPWM pwm(13); // Create an instance of BezierPWM with the default pin 13

void setup() {
    SoftPWMBegin();
    SoftPWMSet(pwm.getPWMPin(), 0); // Initialize SoftPWM with the pin from your BezierPWM instance
}

void loop() {
    // Using predefined curve "ease," fade from 0 to 1 in 1 second
    pwm.ease(0, 1, 1000);
    
    // Using predefined curve "easeIn," fade from 1 to 0 in 1 second
    pwm.easeIn(1, 0, 1000);
    
    delay(500);
    
    // Using predefined curve "easeOut," fade from 0 to 1 in 1 second
    pwm.easeOut(0, 1, 1000);
    
    // Using predefined curve "easeInOut," fade from 1 to 0 in 2 seconds
    pwm.easeInOut(1, 0, 2000);
    
    delay(500);

    // Using predefined curve "easeSine," fade from 0 to 1 in 1 second
    pwm.easeSine(0, 1, 1000);

    // Using predefined curve "easeSineIn," fade from 1 to 0 in 1 second
    pwm.easeSineIn(1, 0, 1000);

    delay(500);

    // Using predefined curve "easeSineOut," fade from 0 to 1 in 1 second
    pwm.easeSineOut(0, 1, 1000);

    // Using predefined curve "easeSineInOut," fade from 1 to 0 in 2 seconds
    pwm.easeSineInOut(1, 0, 2000);

    delay(500);

    // Using predefined curve "breathIn," fade from 0 to 1 in 2 seconds
    pwm.breathIn(0, 1, 2000);

    // Using predefined curve "breathOut," fade from 1 to 0 in 2 seconds
    pwm.breathOut(1, 0, 2000);

    delay(500);

    // Using predefined curve "linear," fade from 0 to 1 in 1 second
    pwm.linear(0, 1, 1000);

    // Using predefined curve "linear," fade from 1 to 0 in 1 second
    pwm.linear(1, 0, 1000);

    delay(500);
}

```

### Custom Curves
You can also create custom curves by defining your control points:
```cpp
float customPoints[] = {0.2, 0.1, 0.6, 0.9};
pwm.bezierFade(customPoints, 1, 0, 2000); // Using custom control points, fade from 1 to 0 in 2 seconds
```

### Planned updates
- Add linear option
- Add more predefined curves such as easeSineIn, easeSineOut
- Add breath light similar to [this](https://avital.ca/notes/a-closer-look-at-apples-breathing-light)

### Contributing
We welcome contributions from the community! If you find issues, have feature requests, or want to contribute code, please follow our Contribution Guidelines.

### License
This project is licensed under the MIT License - see the LICENSE.md file for details.

### Links
SoftPWM library for Arduino: https://github.com/bhagman/SoftPWM
Online visualizer for Bézier curve: https://cubic-bezier.com/
