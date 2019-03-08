# DRV 8880 Polulu Stepper Driver
[Link to product page](https://www.pololu.com/product/2971)

This stepper motor driver lets you control one bipolar stepper motor at up to 1.6 A output current per coil.

### Power connections
The driver requires a motor supply voltage of 6.5 V to 45 V to be connected across VMOT and GND. This supply should have appropriate decoupling capacitors close to the board, and it should be capable of delivering the expected stepper motor current.

```
Warning: This carrier board uses low-ESR ceramic capacitors, which makes it susceptible to destructive LC voltage spikes, especially when using power leads longer than a few inches. Under the right conditions, these spikes can exceed the 50 V maximum voltage rating for the DRV8880 and permanently damage the board, even when the motor supply voltage is as low as 12 V. One way to protect the driver from such spikes is to put a large (at least 47 µF) electrolytic capacitor across motor power (VMOT) and ground somewhere close to the board.
```

A 3.3 V output from the DRV8880’s internal regulator is made available on the V3P3 pin. This output can supply up to 10mA to external loads. When the driver is in sleep mode the 3.3 V output is disabled, so it cannot be used to pull up the sleep pin.

### Wiring

![Basic wiring diagram](DRV_8880_Stepper_Driver/DRV8880_basic_wiring.png)

![Breadboard wiring diagram](DRV_8880_Stepper_Driver/DRV8880_bb.png)

### Microstep configuration
DRV8880 will move one "microstep" for every pulse on the `STEP` pin. 
Pins `M0` and `M1` are used to set microstepping between Full-step and 1/16 step.
**If no jumpers are connected to M0/M1 the value will default to 1/8.**

| M0 | M1 | Microstep Resolution |
| --- | --- | --- |
| Low |Low | Full step |
| High | Low | Non-circular half step |
| Low | High | Half step |
| High | High | 1/4 step |
| Floating | Low | 1/8 step |
| Floating | High | 1/16 step |


### Control inputs
Each pulse to the STEP input corresponds to one microstep of the stepper motor in the direction selected by the DIR pin. These inputs are both pulled low by default through internal 100 kΩ pull-down resistors. If you just want rotation in a single direction, you can leave DIR disconnected.

The chip has two different inputs for controlling its power states: SLEEP and ENABLE. For details about these power states, see the datasheet. Please note that the driver pulls the SLEEP pin low through an internal 100 kΩ pull-down resistor, and the carrier board pulls the ENABLE pin high through an on-board 10 kΩ pull-up resistor. The default SLEEP state prevents the driver from operating; this pin must be high to enable the driver (it can be connected directly to a logic “high” voltage between 1.8 and 5.3 V, or it can be dynamically controlled by connecting it to a digital output of an MCU). The default state of the ENABLE pin is to enable the driver, so this pin can be left disconnected.
