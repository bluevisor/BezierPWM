# Arduino SoftPWM with Custom Bezier Curves

This project is an enhancement of the existing SoftPWM library. It includes support for cubic Bezier curves to create custom fade-in and fade-out effects for LEDs.

## Features

- Supports predefined Bezier curves for common easing effects:
  - Ease
  - Ease In
  - Ease Out
  - Ease In Out
- Accepts custom control points for personalized Bezier curves.
- Supports initial and target brightness parameters.
- Variable total time for fade-in and fade-out effects.

## Installation

1. Download the SoftPWM library.
2. Copy the library to your Arduino `libraries` folder.

## Usage

Include the library at the top of your script:

```arduino
#include "SoftPWM.h"
```

Initialize the SoftPWM library in the `setup` function:

```arduino
void setup() {
  SoftPWMBegin();
  SoftPWMSet(13, 0); // Pin, Initial brightness
}
```

Use the `bezierFade` function in your loop or other parts of the program:

### Predefined Curves

```arduino
bezierFade(easeIn, 0, 1, 1000);  // Ease in from 0 to 1 in 1 second (1000ms)
```

### Custom Curves

```arduino
float customPoints[] = {0.2, 0.1, 0.6, 0.9};
bezierFade(customPoints, 1, 0, 2000);  // Custom curve from 1 to 0 in 2 seconds (2000ms)
```

## Contributing

Feel free to contribute to the project by opening issues or pull requests.

## License

This project is licensed under the MIT License.
