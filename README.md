# Arduino LED Fader using SoftPWM and Bezier Curves

This project is an extension of the [SoftPWM Library](https://github.com/bhagman/SoftPWM) to control the brightness of LEDs on Arduino. It allows for more elegant, non-linear fading through the use of cubic Bezier curves. Works on any pin, including the built-in LED.

## Features

- Linear and non-linear LED fading
- Customizable Bezier curves for intricate light effects
- Predefined easing functions like easeIn, easeOut, easeInOut
- Highly customizable with options for initial and target brightness, total fade time, and more

### Installation

1. Clone or download the BezierPWM library repository to your local machine.

```shell
$ git clone https://github.com/bluevisor/BezierPWM.git
```
2. Open the Arduino IDE.
3. Go to `Sketch` -> `Include Library` -> `Add .ZIP Library` and select the downloaded repository.

## Usage

### Predefined Curves

The BezierPWM library comes with four predefined curves that you can use for smooth fading transitions:

- ease (0.25, 0.1, 0.25, 1)
- easeIn (0.42, 0, 1, 1)
- easeOut (0, 0, 0.58, 1)
- easeInOut (0.42, 0, 0.58, 1)

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
}
```

### Custom Curves
You can also create custom curves by defining your control points:
```cpp
float customPoints[] = {0.2, 0.1, 0.6, 0.9};
pwm.bezierFade(customPoints, 1, 0, 2000); // Using custom control points, fade from 1 to 0 in 2 seconds
```

### Planned updates
- Breath light similar to [this](https://avital.ca/notes/a-closer-look-at-apples-breathing-light)

### Contributing
We welcome contributions from the community! If you find issues, have feature requests, or want to contribute code, please follow our Contribution Guidelines.

### License
This project is licensed under the MIT License - see the LICENSE.md file for details.

### Acknowledgements
SoftPWM library for Arduino: https://github.com/bhagman/SoftPWM
