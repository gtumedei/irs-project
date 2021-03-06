# Intelligent Robotic Systems - Report

- [Intelligent Robotic Systems - Report](#intelligent-robotic-systems---report)
  - [Introduction](#introduction)
  - [Choosing the robot kit](#choosing-the-robot-kit)
    - [Requirements](#requirements)
    - [The market of programmable robot kits](#the-market-of-programmable-robot-kits)
    - [Our choice](#our-choice)
  - [Robot kit analysis](#robot-kit-analysis)
    - [Bundle](#bundle)
    - [Sensors and actuators](#sensors-and-actuators)
    - [Software](#software)
  - [Firmware analysis and refactor](#firmware-analysis-and-refactor)
    - [Makeblock library](#makeblock-library)
    - [Default firmware](#default-firmware)
    - [Our firmware](#our-firmware)
  - [Controller development](#controller-development)
    - [Line following](#line-following)
    - [Obstacle avoidance](#obstacle-avoidance)
    - [Light chasing with obstacle avoidance](#light-chasing-with-obstacle-avoidance)
  - [Conclusions and future work](#conclusions-and-future-work)

## Introduction

The Intelligent Robotic Systems course includes a number of laboratory sessions in which students approach the design of robot controllers using the scientific method and testing their implementations in a simulated environment. While robot simulators offer a number of advantages, they are the result of an abstraction, that only preserves the most relevant aspects of the physical environment and agent. The goal of this project is to compare the experience of programming a robot controller in a simulated environment against a real world one. To do this, we set out to find a good robot kit that enables us to implement a series of control programs, similar to the ones created in laboratory. As in that case, we are going to apply a scientific approach to development and testing, by formulating hypotheses, checking them against actual behaviors and making adjustments when needed.

The initial plan is to complete the implementation of four behaviors: wandering, line following, obstacle avoidance and phototaxis. We are then going to combine them in order to create slightly more complex, multi-behavior control programs. The actual outcome depends on the hardware characteristics of the robot kit we will choose, along with challenges that may arise in a real environment and cannot be predicted in the preliminary stages (e.g. sensor noise).

## Choosing the robot kit

The first step to carry out the project is to choose a robot kit with the required features to implement the aforementioned behaviors. The obvious solution would be to use a foot-bot, in order to have the same robot as the one in ARGoS, the simulator we used in laboratory. Unfortunately, due to the high price tag of similarly equipped robots, we had to settle for a more economic, consumer-oriented solution. As a consequence, the selected kit will inevitably have some hardware limitations that will influence the implementation of behaviors, defining what can and can't be done in the project.

### Requirements

To identify the robot kit to pick, we initially defined a set of features that it must match in order to be a valid candidate.

- **Reasonably priced**: since this is a self-funded project, the cost to purchase the kit should not exceed 100???; this also makes it a viable solution for similar activities made by other students
- **Preferably equipped with two wheels**: any solution that involves the usage of more than two motors increases the price and makes any movement-related code harder to write
- **Presence of ultrasonic sensor**: since obstacle avoidance is the main behavior that the robot must be able to adopt as the project goal, this sensor is indispensable
- **Preferably equipped with some light sensors**: not mandatory, but opens up the possibility to create a phototaxis behavior, that can then be combined with obstacle avoidance
- **Programmable in a known language**: using an already known programming language speeds up the implementation and gives a certain level of confidence that anomalies are related to the physical environment and/or agent and not to the development one
- **Presence of documentation to support programming**: the development phase is going to be much straightforward if the robot is based on a well documented and/or popular board
- **Good level of modularity**: the more the kit is modular, the more possibilities open up, from buying replacement parts in case of damage to the existing ones, to adding sensors and actuators and implementing new, more complex controllers

### The market of programmable robot kits

<table>
  <thead>
    <tr>
      <th style="width: 10%"></th>
      <th style="width: 30%">Kit</th>
      <th style="width: 30%">Pros</th>
      <th style="width: 30%">Cons</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>1</td>
      <td>
        <strong>Makeblock mBot Kit</strong><br>
        <a href="https://amzn.to/3lsxlnw">https://amzn.to/3lsxlnw</a><br>
        <div><img height="200" src="https://drive.google.com/uc?export=view&id=1fV3h-D6ATuJwflhDP8jxG3BIhxFH27jf"></div>
      </td>
      <td>
        <ul>
          <li>Has two wheels</li>
          <li>Uses Arduino as its mainboard</li>
          <li>Makeblock is the biggest manufacturer out of all the analyzed kits</li>
          <li>Very modular thanks to a suite of first party expansion modules</li>
          <li>Open source firmware, along with a wide range of examples, provided by the manufacturer on GitHub</li>
        </ul>
      </td>
      <td>
        <ul>
          <li>Light sensors are sold separately</li>
          <li>Drop-in replacements are only available via first party modules</li>
          <li>Battery replacement requires unscrewing the mainboard</li>
        </ul>
      </td>
    </tr>
    <tr>
      <td>2</td>
      <td>
        <strong>Freenove Micro: Rover Kit</strong><br>
        <a href="https://amzn.to/3MzPews">https://amzn.to/3MzPews</a><br>
        <div><img height="200" src="https://drive.google.com/uc?export=view&id=1KF2s55cbdmwdAdRxurueLzvAnRS-Si5j"></div>
      </td>
      <td>
        <ul>
          <li>Pluggable BBC micro:bit board to program the robot with Python</li>
          <li>Equipped with light sensors</li>
          <li>Open source examples available provided by the manufacturer on GitHub</li>
          <li>Has two wheels</li>
          <li>Offers additional pins for expansion</li>
        </ul>
      </td>
      <td>
        <ul>
          <li>The mainboard is proprietary</li>
          <li>Every component is soldered to the mainboard, so replacement of a broken part is very hard</li>
          <li>Very limited expansion possibilities</li>
        </ul>
      </td>
    </tr>
    <tr>
      <td>3</td>
      <td>
        <strong>ELEGOO UNO Project Kit</strong><br>
        <a href="https://amzn.to/3luxFC3">https://amzn.to/3luxFC3</a><br>
        <div><img height="200" src="https://drive.google.com/uc?export=view&id=1WOvLLYx-pIQsI6A6rFICLVA0HmraIE_E"></div>
      </td>
      <td>
        <ul>
          <li>Uses Arduino as its mainboard</li>
          <li>Very solid chassis that protects every sensor</li>
          <li>Front-facing servo motor helps with obstacle avoidance</li>
        </ul>
      </td>
      <td>
        <ul>
          <li>Has four wheels</li>
          <li>An expansion board occupies every mainboard pin, preventing the installation of new modules</li>
          <li>No light sensors</li>
        </ul>
      </td>
    </tr>
    <tr>
      <td>4</td>
      <td>
        <strong>ELEGOO Smart Owl Robot Car Kit</strong><br>
        <a href="https://amzn.to/3sJYs1p">https://amzn.to/3sJYs1p</a><br>
        <div><img height="200" src="https://drive.google.com/uc?export=view&id=1ROB8XoqZokn4gsE7J6WCTK1rMLIp6gml"></div>
      </td>
      <td>
        <ul>
          <li>Uses Arduino as its mainboard</li>
          <li>Very solid chassis that protects every sensor</li>
          <li>Cheaper compared to the other options</li>
          <li>Has two wheels</li>
        </ul>
      </td>
      <td>
        <ul>
          <li>Offers expansion ports, but we were unable to find first party additional modules</li>
          <li>No light sensors</li>
        </ul>
      </td>
    </tr>
    <tr>
      <td>5</td>
      <td>
        <strong>OSOYOO V2.1 Smart Robot Car Kit for Arduino</strong><br>
        <a href="https://amzn.to/3tc00Sb">https://amzn.to/3tc00Sb</a><br>
        <div><img height="200" src="https://drive.google.com/uc?export=view&id=1G1MLzwOc9xPzwSLPTIT6QSm9QR1fnFY6"></div>
      </td>
      <td>
        <ul>
          <li>Uses Arduino as its mainboard</li>
          <li>Front-facing servo motor helps with obstacle avoidance</li>
        </ul>
      </td>
      <td>
        <ul>
          <li>Has four wheels</li>
          <li>No light sensors</li>
          <li>Exposed sensors and wires</li>
          <li>Poor documentation</li>
        </ul>
      </td>
    </tr>
    <tr>
      <td>6</td>
      <td>
        <strong>OSOYOO Robotic Car for Raspberry Pi 4 3B + 3B</strong><br>
        <a href="https://amzn.to/3yMlRmF">https://amzn.to/3yMlRmF</a><br>
        <div><img height="200" src="https://drive.google.com/uc?export=view&id=1fujrBIhGpEm7pkfz3-Egj0sEaiDUlt3j"></div>
      </td>
      <td>
        <ul>
          <li>Has two wheels</li>
          <li>Uses Raspberry Pi as its mainboard</li>
        </ul>
      </td>
      <td>
        <ul>
          <li>No light sensors</li>
          <li>Exposed sensors and wires</li>
          <li>Poor documentation</li>
        </ul>
      </td>
    </tr>
  </tbody>
</table>

### Our choice

After a careful analysis of the various options that the market has to offer, our choice fell on the mBot kit produced by Makeblock. The only real downside is that we had to buy the light sensors separately, bringing the total cost just shy of the 100??? price limit. The upside is that, by choosing this kit, we'll have the necessary hardware to implement all the controllers we set out to create.

## Robot kit analysis

The provided kit contains all the necessary components to meet most of the features required to complete the project objectives. The only lack is related to light sensors, which are needed for the implementation of more complex behaviors such as combining obstacle avoidance and light chasing.
For this reason, we decided to purchase an expansion kit that allows to setup the robot in three additional configurations:
- Light chasing (the one we were interested in)
- Scorpion (with a rgb-responsive tail)
- Intelligent desk light

<table>
  <thead>
    <tr>
      <th>Makeblock mBot kit</th>
      <th>Makeblock mBot Add-on 3-in-1</th>
    </tr>
  </thead>
  <tbody>
    <tr  style="width: 50%">
      <td>
        <div style="text-align: center"><img height="360" src="https://drive.google.com/uc?export=view&id=1vUQNjRXqfnBdAtmm-Mr8u8QshHHZdc5j"></div>
      </td>
      <td  style="width: 50%">
        <div style="text-align: center"><img height="360" src="https://drive.google.com/uc?export=view&id=1aIdJ8qSwMl8YfgHFhuWhS2GfVq6JZ_si"></div>
      </td>
    </tr>
  </tbody>
</table>

### Bundle

<table>
  <tr>
    <th colspan="2" style="text-align: left">Makeblock mBot kit</th>
  </tr>
  <tr>
    <td style="width: 60%">
      <div><img height="350" src="https://drive.google.com/uc?export=view&id=1DoDd6_Jf0MZ20qUcL1Fyng-e5RsvFIkV"></div>
    </td>
    <td style="width: 40%">
      <ul>
        <li>AA battery holder</li>
        <li>Chassis</li>
        <li>Fasteners</li>
        <li>IR remote</li>
        <li>Line-follower sensor</li>
        <li>Mainboard mCore</li>
        <li>Mini screwdriver</li>
        <li>Mini wheel</li>
        <li>Motors</li>
        <li>RJ25 cables</li>
        <li>Screwdriver</li>
        <li>USB cable</li>
        <li>Ultrasonic sensor</li>
        <li>Velcro sticker</li>
        <li>Wheels</li>
      </ul>
    </td>
  </tr>
</table>
<table>
  <tr>
    <th colspan="2" style="text-align: left">Makeblock mBot Add-on 3-in-1</th>
  </tr>
  <tr>
    <td style="width: 60%">
      <div><img height="350" src="https://drive.google.com/uc?export=view&id=1sX3-d8Da5P27FlVUPPt8YvPWt6nwU3FW"></div>
    </td>
    <td style="width: 40%">
      <ul>
        <li>Beams and plates</li>
        <li>Fasteners</li>
        <li>M5/M7 wrench</li>
        <li>Me RGB LED</li>
        <li>Me light sensor</li>
        <li>Me sound sensor</li>
        <li>RJ25 cables</li>
      </ul>
    </td>
  </tr>
</table>

### Sensors and actuators

**Wheels**

<img height="250" src="https://drive.google.com/uc?export=view&id=1GT9KO9y2CCT283IapBGvkIVHU9n0GFbd"/>

Each of the two wheels equipped to mBot are attached to a servo motor and connected to the motherboard via RJ45 plugs. These are mapped inside Arduino to an analog and a PWM pin each, enabling the speed for each wheel to be specified using values between 0 and 255 and the direction to be set using the analog pin.

**Line follower sensor**

The line-follower module placed below the robot consists of two sensors, both equipped with an infrared emitter and infrared receiver, with a detection range of 1 to 2cm. The infrared emitters continually generate infrared light. If the light is reflected (encountering white or other light color surfaces), the corresponding receiver gets the infrared signal back and outputs the value 1; if the infrared light is absorbed or cannot be reflected, the receiver will not get the infrared signal back and output the value 0.
Given that the robot has two sensors, the resulting combinations are the following:
- Both sensors read 0
- The left sensor reads 0, while the right reads 1
- The left sensor reads 1, while the right reads 0
- Both sensors read 1

**Ultrasonic sensor**

<img height="300" src="https://drive.google.com/uc?export=view&id=1ARwDU6DPP9NWOH2ngFRBv_E2p8zUbbtO" />

mBot is equipped with a classic ultrasonic sensor, similar to those found in standard Arduino kits, which allows it to detect obstacles in a range from 1cm to 400cm.

The way the sensor works is quite simple: it emits an ultrasound at high frequency (~40kHz) which travels through the air and bounces back to the module if there is an obstacle on its path. The distance from the object can be calculated considering the travel time of the signal (roundtrip) and the speed of the sound.

$$ distance = {34cm/ms * time \over 2} $$

**Light sensor**

<img height="250" src="https://drive.google.com/uc?export=view&id=1a_Pch011lZ-WZ2W_39cGYLjfP5Gro2tG" />

The two light sensors available in the add-on kit for mBot are connected to the motherboard via RJ45 plugs, and must use ports 3 and 4 as shown in the figure.

These sensors are based on the photoelectric effect principle in semiconductors and can be used to detect the intensity of ambient light.

The photosensitive wavelength range varies between 400 and 1100nm, the analog value of the output goes from 0 to 1000. According to the documentation provided by Makeblock these values can be interpreted as follows:
- \[0-100]: evening
- \[100-500]: indoor lighting condition
- \>500: exposure to sunlight

### Software

Most of the robot kits produced by Makeblock, including mBot, support several development platforms, which can be chosen according to the desired level of difficulty, making them ideal for any user.

- **mBlock 5**: coding tool that supports both Python and block programming via a dedicated browser platform (https://mblock.makeblock.com/en-us/)
- **mBlock Blockly**: game-based robot app that supports block programming, specifically designed for younger users (https://www.makeblock.com/software/mblock-app)
- **Makeblock App**: all-in-1 controller for any Makeblock robots that supports multiple control modes and 3D modeling (https://www.makeblock.com/software/makeblock-app)
- **Arduino IDE**: it's the option we chose, since it's just like programming a normal Arduino board, but with additional resources provided by Makeblock through their official GitHub repository, accessible at https://github.com/Makeblock-official/Makeblock-Libraries

## Firmware analysis and refactor

This section presents an analysis of the default firmware that comes preinstalled with mBot, highlighting its strong and weak points. It then goes on to explain the preparation work we did to get started developing our own controllers.

### Makeblock library

The default mBot firmware is written in C++ and based on the open source Makeblock library that the producer makes available on GitHub ([https://github.com/Makeblock-official/Makeblock-Libraries](https://github.com/Makeblock-official/Makeblock-Libraries)). While not required for development with the Arduino IDE, its installation is needed to compile the firmware, which we wanted to do. Futhermore, the library offers simple utility classes to interface with all the sensor and actuator modules sold by Makeblock, so it's a good starting point for writing custom control programs.

### Default firmware

The default firmware that comes with mBot allows to put the robot in one of three modes, either through the button that's builtin to the board or via the included IR remote. The first mode is fully manual, with the robot that stays completely still unless the IR remote is used to make it go forward, go backward, turn or adjust its speed. The other two modes offer a basic implementation of line following and obstacle avoidance respectively, with the latter having the robot always proceed forward unless it encounters an obstacle (no wandering). The robot lights its LEDs and rings its buzzer every time it receives a command via IR, which is a nice touch. The firmware is based on the Makeblock library, is open source and can be downloaded from the official Makeblock repository on GitHub:\
[https://github.com/Makeblock-official/Makeblock-Libraries/blob/master/examples/Firmware_For_mBlock/mbot_factory_firmware/mbot_factory_firmware.ino](https://github.com/Makeblock-official/Makeblock-Libraries/blob/master/examples/Firmware_For_mBlock/mbot_factory_firmware/mbot_factory_firmware.ino).

**Line Following**

The line following implementation of the default firmware is relatively simple, but effective. A variable, called `lineFollowFlag`, which can assume values from 1 to 20, is used to indicate the direction that the robot should take.
The algorithm is basically built on a switch construct, which considers the four possible scenarios:
- Both sensors detect the line: `lineFollowFlag` is set to 10
- Only the right sensor detects the line: `lineFollowFlag` is decremented
- Only the left sensor detects the line: `lineFollowFlag` is incremented
- No sensor detects the line: the robot acts based on the value of `lineFollowFlag` to get back on track:
  - If it's 10, it goes backward
  - If it's below 10, it turns to the left
  - If it's above 10, it turns to the right

This implementation has the peculiarity of making the robot turn only when both sensors leave the line.

**Obstacle avoidance**

The implementation of the obstacle avoidance algorithm in the base firmware is extremely simple. The robot's movement is based on the value detected by the ultrasonic sensor (`d`): if it's above the `AVOID_DISTANCE` value (15cm), the robot proceeds forward, otherwise it picks a side with a 50% probability and turns in that direction until no obstacle is detected.

This type of solution leads to a very inefficient behavior, and in some cases, causes the robot to collide with obstacles.

**Pros and cons**

From a feature standpoint, the default control program is great and offers usage examples to control pretty much any part of the robot kit. However, it has two main issues that made us choose to go for a big refactor before starting to write our own controllers. The first one is that the entire firmware consists of a single `.ino` file with 1300+ lines of code, with no separation of concerns. It was probably made this way to simplify compilation and deployment, but it makes it really hard to understand and modify any part of it. Some example features that could have been decoupled into their own separate files include: handling movement, reading from the IR receiver, reacting to the builtin button being pressed. The other issue is that, by looking at the code, it is evident that the firmware had initially been written for compatibility with multiple kits, and then modified to make it fully work with mBot. As a consequence, the code is full of conditional branches that are never going to be executed, and contains dozens of unused variables.

### Our firmware

In order to overcome the limitations of the default firmware, we decided to refactor it, creating a new one in the form of an Arduino library, called MeMBotFirmware. The firmware should:
- Include the Makeblock library
- Implement all the features of the default firmware that are common among the different controllers we are going to implement, to avoid code duplication
- Declare an `autoMode` function that the final controller has to implement with the actual behaviors of the robot

**Makeblock library bug**

Importing the Makeblock library more than once and compiling the code shows an error in the output, related to multiple definitions of the variable specifying the mBot Board's GPIO Map. This is because the definition is placed in the `MeMCore.h` file, that, as all headers, should only contain declarations. To avoid having to worry about this bug, it was sufficient to move the definition to a `.cpp` file. We uploaded the modified library to [https://github.com/gtumedei/irs-project/releases/download/0.0.0/Makeblock-Libraries-master.zip](https://github.com/gtumedei/irs-project/releases/download/0.0.0/Makeblock-Libraries-master.zip)

**Refactoring the default firmware**

Starting from the single file that composes the basic firmware provided by Makeblock, we have divided its features into the following files:
- `BuiltinButton.cpp`: handles the button on the motherboard (used to change from automatic to manual mode and vice versa)
- `BuzzerTones.h`: contains the definitions of all tones that can be played by the buzzer
- `IRCommand.cpp`: handles the inputs of the remote
- `ManualMode.cpp`: handles the operations of the manual mode
- `MeMBotFirmware.h`: imports all the other files and declares global variables for sensors, actuators and state
- `MeWheels.h` and `MeWheels.cpp`: custom class for wheel management
- `StartingBuzz.cpp`: performs robot power-up sounds and lighting

The structure of the `.ino` file for a controller that uses the MeMBotFirmware consists of the standard Arduino `setup` and `loop` functions. To simplify testing, we decided to keep the manual mode, where the robot can be controller via the IR remote, and integrate it in the library. As such, the `loop` function that executes the Arduino loop contains a switch that allows the usage of both manual and automatic modes.

This is the structure of a controller that uses the MeMBotFirmware:

```cpp
#include "MeMBotFirmware.h"

// Sensors initialization

// Global variables initialization

void setup() {
  // Sensors setup
}

void loop() {
  handleIRCommand();
  handleBuiltinButton();
  // Execute the selected mode
  switch (mode)
  {
    case MANUAL_MODE:
      manualMode(); // Implemented by MeMBotFirmware
      break;
    case AUTO_MODE:
      autoMode(); // Implemented by the controller
      break;
 }
}

```

**MeWheels class**

The default firmware does not handle the usage of the wheels in a very intuitive way. The main issue is that, since the left motor is identical to the right, but mounted in a flipped way, to go forward the robot needs to spin the two wheels in opposite directions. To overcome this limitation and simplify operations like turning, we added a new class to the firmware, called `MeWheels`. The class contains the following functions:
- `spinRight`: spins the right wheel at a given speed
- `spinLeft`: spins the left wheel at a given speed
- `stopRight`: stops the right wheel
- `stopLeft`: stops the left wheel
- `stop`: stops both wheels
- `forward`: moves forward at a given speed
- `backward`: moves backward at a given speed
- `turn`: stops the robot and turns itself in the direction specified as a parameter, at the given speed, multiplied by a factor set to 0.8 by default
  - `turnLeft`: calls `turn` with left as the direction
  - `turnRight`: calls `turn` with right as the direction
- `forwardAndTurn`: turns toward the given direction, while going forward at the given speed, multiplied by a factor set to 0.8 by default
  - `forwardAndTurnLeft`: calls `forwardAndTurn` with left as the direction
  - `forwardAndTurnRight`: calls `forwardAndTurn` with right as the direction
- `backwardAndTurn`: turns toward the given direction, while keep going backward at the given speed, multiplied by a factor set to 0.8 by default
  - `backwardAndTurnLeft`: calls `backwardAndTurn` with left as the direction
  - `backwardAndTurnRight`: calls `backwardAndTurn` with left as the direction

To specify the direction in which to proceed, turning functions accept a value from the `TurnDirection` enum, which can be: `DIR_RIGHT`, `DIR_LEFT`, `DIR_NONE`.

## Controller development

As mentioned in the introduction, we wanted to experiment with the creation of three different controllers: line following, obstacle avoidance and light chasing. Each one will consist of a dedicated folder inside the `src` directory and will include two files:
- `ControllerName.ino`: entry point of the control program, following the structure shown in [Refactoring the default firmware](#refactoring-the-default-firmware)
- `ControllerName.cpp`: contains the implementation of the `autoMode` function declared by the firmware library, along with the behaviors of which it's composed

Given the fact that the obstacle avoidance and light chasing controllers are going to include multiple behaviors, we have opted for a simplified version of the subsumption architecture to orchestrate them. Each behavior will be represented by a function, and each Arduino tick will decide, based on state and sensor measurements, what behavior to execute. This differs from a standard subsumption in that selecting a behavior means completely subsuming the others, so there is no partial takeover.

### Line following

The first controller that has been implemented allows the robot to follow a black line drawn on the ground. This is the simplest control program and only includes a single behavior to perform line following.

**Design**

Having a line-follower module with two sensors we had two possibilities of programming the robot. The first was to make it follow a line that is thinner than the distance between the two sensors, by keeping it between them. The second was to use a line that is thicker than the sensors distance, with the robot trying to keep both sensors inside it. Given the small 1.5cm distance between our sensors, we chose the latter. Combining this decision with the four possible states in which the line follower module can be, we obtain the following cases.

<table>
  <tr>
    <th style="width: 25%">Case 1</th>
    <th style="width: 25%">Case 2</th>
    <th style="width: 25%">Case 3</th>
    <th style="width: 25%">Case 4</th>
  </tr>
  <tr>
    <td style="width: 25%">
      <div><img src="https://drive.google.com/uc?export=view&id=1BTqCKWXz_7mLkJK8eYkz5NmWEZskXvUB"/></div>
    </td>
    <td style="width: 25%">
      <div><img src="https://drive.google.com/uc?export=view&id=1wyQnW15pNeGB_2P0_aw40o3ZbKMKv5GX"/></div>
    </td>
    <td style="width: 25%">
      <div><img src="https://drive.google.com/uc?export=view&id=1tvtMdM0ly2idXh7crXF_4skmQTvb1mbp"/></div>
    </td>
    <td style="width: 25%">
      <div><img src="https://drive.google.com/uc?export=view&id=1gJ3VRI_dy6ozp6RnOyIrduZ67TyoF7Av"/></div>
    </td>
  </tr>
  <tr>
    <td style="width: 25%">mBot is on the black line, the value of the line-follower sensor is 0. The robot should keep moving forward.</td>
    <td style="width: 25%">mBot deviates from the black line to the right, the value of the line-follower sensor is 1. The robot should turn left to find the black line.</td>
    <td style="width: 25%">mBot deviates from the black line to the left, the value of the line-follower sensor is 2. The robot should turn right to find the black line.</td>
    <td style="width: 25%">mBot is not on the black line, the value of the line-follower sensor is 3. The robot should move in order to find the line again.</td>
  </tr>
</table>

Case 1 to 3 are pretty simple, but handling case 4 requires some considerations. If, while the robot is following the line, both sensors suddenly detect white, moving backward is surely going to place the robot back on track, but is far from the optimal solution. It would be ideal to give it some kind of "memory", so that if it leaves the line while turning, it continues the maneuver and probably finds the track again. To accomplish this, we used a *direction* value to indicate what movement the robot is performing:
- If the robot is moving forward, *direction* is 0
- If the robot is turning to the left, each Arduino tick decreases *direction* by 1, down to -10
- If the robot is turning to the right, each Arduino tick increases *direction* by 1, up to 10

When both sensors detect white, the robot acts based on the value of *direction*:
- $direction < 0$: the robot was turning to the left, so it should continue in that direction
- $direction > 0$: the robot was turning to the right, so it should continue in that direction
- $direction = 0$: the robot has left the track with the left and right sensor at the same instant, so it should move backwards

This solution handles all edge cases quite well, from sharp turns to crossroads in the track.

<img height="290" src="https://drive.google.com/uc?export=view&id=1jOotZ9m6YItNjzIvtuXrMmJJMTrpB3fE"/>

The described behavior is shown in the flow chart below. To stay true to the actual implementation, it represents a single Arduino loop and gets run on each tick.

<img height="700" src="https://drive.google.com/uc?export=view&id=1kqMFumo0dSmUO7Oh--htYUrAk-0GZuP2"/>

**Implementation**

The line following controller is very simple and basically consists of a switch that handles the above four cases, moving the wheels according to the value read by the sensors. To regulate the speed, making the robot go faster in straight tracks and slower during turns, we made some tests and identified the following formula:

$$ speed= maxSpeed * (1-{\vert direction \vert\over 10 }) $$

Where $maxSpeed$ is a constant representing the maximum value of speed the robot can reach, which is 255. The calculation is done within the `computeSpeed()` function, which returns the minimum between the calculated speed and $minSpeed$, a constant set to 230.

**Testing**

The goal of our tests was to demonstrate that the robot is able to follow the drawn black line. To carry out the verification of our hypotheses, we created three tracks of increasing difficulty and tested the behavior of the robot ten times on each one.

- **Infinity-shaped track**: this is the track bundled with the robot kit, characterized by an infinity-shaped line printed on paper, so we expected the robot to be able to follow the line without any particular difficulty. After adjusting our parameters to optimize the robot's movements, the success rate was 100%.
- **Rectangular track**: hand-built track using electrical tape on cardboard, the rectangular shape allowed us to test the robot's behavior in sharp turns. In the first tests, the robot was able to properly follow about 1 turn every 3. We then realized that the sharp turns needed to be slightly cut off on the outside. This is because otherwise the sensors of the line-following module reached the white background roughly at the same time, causing the robot to: go backwards if it detected white on both sensors simultaneously, turn 90?? (correct behavior) or turn 270?? if a sensor read white before the other. By making the above change, the outermost sensor always detects the white background first, allowing the robot to curve correctly and obtain a success rate of 100%.
- **Mixed track**: a more complex track that had the properties of both the previous ones. The line was at first drawn using an indelible marker, but in this case the sensor was unable to detect it correctly, as the ink probably contained some reflective substances. After recreating the track using a black spray paint, we were able to make the ten attempts. Despite the difficulty of the path, our experiments yielded good results: the robot was able to complete the path without deviations 80% of the time; performed a wrong turn, but was able to get back on track 10% of the time; wrongly took the crossroad and started following the line in the wrong senses in the last case.

<table>
  <tr>
    <th style="width: 33%">Infinity-shaped track</th>
    <th style="width: 33%">Rectangular track</th>
    <th style="width: 33%">Mixed track</th>
  </tr>
  <tr>
    <td style="width: 33%"><div><img src="https://drive.google.com/uc?export=view&id=1VVzeHh6uENo4SxQycs6u5JeqdmkOHL9P"/></div></td>
    <td style="width: 33%"><div><img src="https://drive.google.com/uc?export=view&id=1XGQeXnBC5ACRlYf55nEEAwRyD4rd2x78"/></div></td>
    <td style="width: 33%"><div><img src="https://drive.google.com/uc?export=view&id=1tXyivJEmGDgJU8mMY4VuGNSvYleuGTAw"/></div></td>
  </tr>
  <tr>
    <td style="width: 33%"><a href="https://drive.google.com/file/d/111KmP_mfyQhs-e7-Xhquj9NTwerWya8x/view?usp=sharing">Video</a></td>
    <td style="width: 33%"><a href="https://drive.google.com/file/d/1eC8OpXyJH8jLvrJn8K7qu9o_2jx-icFX/view?usp=sharing">Video</a></td>
    <td style="width: 33%"><a href="https://drive.google.com/file/d/1GKMX8KEeZe8vkeV6XMvj6-Tru8w0QBOJ/view?usp=sharing">Video</a></td>
  </tr>
</table>

**Limitations**

The only limitation that emerged during our tests is related to the line thickness being greater than the distance between the two sensors of the line-following module. In fact, as shown in the image below, using a thinner line and making the robot keep it between the two sensors, enables to place a black line parallel to the module that, when detected by both sensors, triggers some action. This is indeed impossible in our case, where if both sensors detect the black line, then it means the robot is inside the track, while if they both detect the white background then the robot has simply left the track.

<img height="200" src="https://drive.google.com/uc?export=view&id=1LTR8Dhzb9fuKJJoVDFW4FLSavmwRBYY4"/>

### Obstacle avoidance

The second control program, and the last that we were able to realize using only the basic kit, is the obstacle avoidance one. This controller consists of two behaviors, one for randomly wandering around the environment, and the other to actually avoid detected obstacles.

**Design**

When approaching this type of problem using a single frontal ultrasonic sensor there are basically two possibilities, which depend on the type of robot kit being used. If the sensor can be moved through a servo motor, we can use an algorithm that periodically scans the environment around the agent, which can then more effectively avoid obstacles since it is, potentially, free of blind spots. In our case, the ultrasonic sensor is mounted directly to the robot's chassis, which, as pointed out below, leads to some disadvantages and problems that can hardly be avoided.

The control program we designed is structured in two behaviors, one for wandering and the other for obstacle avoidance. The first one is the default and has a simple random check that, on each loop, gives the robot a 3,33% chance of turning to the left, 3,33% to the right, and the rest of going forward. To give the robot a more human-like wandering behavior, there is also an additional check, that for simplicity is not shown in the flow chart below, which prevents the robot from turning more than once every 5 seconds.

The obstacle avoidance behavior gets activated when the robot detects an object at a distance lower than 20cm. Given that the robot is unable to know where the obstacle is, it chooses a random direction (left or right) and turns towards it. While turning, if the distance gets reduces below 5cm, then it means that the robot chose the wrong direction, so it should turn in the opposite one to avoid a collision.

Based on the move that the robot performs on each Arduino loop, it then runs a delay, that can assume the following values:
- 100ms if the robot is in wandering mode and going forward
- 500ms if the robot is turning during wandering mode
- 300ms if the robot is in obstacle avoidance mode

Delays reduce the responsiveness of the robot to external inputs, but are necessary to prevent it from stuttering too much. The above values were chosen as a good compromise.

Below is a flow chart of the obstacle avoidance behavior. To stay true to the actual implementation, it represents a single Arduino loop and gets run on each tick.

<img height="650" src="https://drive.google.com/uc?export=view&id=1w58Jq3fCCD80KcHEr5lQ3paJpgp5f1f_"/>

**Implementation**

The program uses the following constants:
- `AVOID_DISTANCE`: distance beyond which the robot remains in wandering mode
- `CRITICAL_DISTANCE`: distance within which the robot changes direction to avoid a collision
- `TURN_DELAY`: minimum time (ms) that must elapse between turns in wandering mode

And the following global variables:
- `distance`: current distance detected by the ultrasonic sensor
- `avoiding`: boolean set to true if the robot is in obstacle avoidance mode
- `changedDirection`: boolean set to true if the robot has already tried to change direction
- `lastTurnTimestamp`: timestamp of the last turn
- `turnDirection`: enum value representing the direction in which to turn

The robot stays in wandering mode by default, switching to obstacle avoidance if an object is detected at a shorter distance than `AVOID_DISTANCE`.

Obstacle avoidance consists of the following steps:
1. The robot randomly chooses a direction and turns toward it with the `turn` function, until no obstacle is detected
2. If, while turning, the distance to the obstacle gets reduced even further, going below `CRITICAL_DISTANCE`, then it means the chosen direction was probably wrong, so the robot tries turning in the opposite one to avoid the imminent collision. This can only happen once per obstacle

**Testing**

The goal of our tests was to demonstrate that the robot is able to avoid obstacles in a controlled environment. To carry out the verification of our hypotheses, we created two different cases of increasing difficulty and left the robot running on the field for a minute, testing the scenarios ten times each.

- **Controlled perimeter**: limited area defined by a perimeter composed of cardboard boxes. In this test the robot was able to easily detect obstacles, staying within the area and avoiding them in most cases.
- **Open environment**: large space of about 12sqm with some cardboard boxes, again used as obstacles. Although the collision avoidance algorithm worked correctly as expected, collisions were more frequent during our tests than in the previous case study, due to the limitations of the ultrasonic sensor. The frequency of collisions is higher as the probability of the robot finding an obstacle in a blind spot increases.

<table>
  <tr>
    <th style="width: 50%">Controlled perimeter</th>
    <th style="width: 50%">Open environment</th>
  </tr>
  <tr>
    <td style="width: 50%"><div><img src="https://drive.google.com/uc?export=view&id=1STkrO68TkiODY0vH1kDabf1mb7bMYvvm"/></div></td>
    <td style="width: 50%"><div><img src="https://drive.google.com/uc?export=view&id=1fWpy0qN9GY-kqCCeTJhIj2dzgjNzAFvq"/></div></td>
  </tr>
  <tr>
    <td style="width: 50%"><a href="https://drive.google.com/file/d/16hjmNWZJci_vfP-aY5fA5w3V-6P3VM1W/view?usp=sharing">Video</a></td>
    <td style="width: 50%"><a href="https://drive.google.com/file/d/1_O2Lzs7QVdZh8MXopDFHaz6QkgEBlsgZ/view?usp=sharing">Video</a></td>
  </tr>
</table>

**Limitations**

During our tests two types of limitations emerged. The first is related to how the ultrasonic sensor works, as shown in the following table. The second is related to the fact that the sensor in a fixed position.

<table>
  <tr>
    <th style="width: 25%">Case 1</th>
    <th style="width: 25%">Case 2</th>
    <th style="width: 25%">Case 3</th>
    <th style="width: 25%">Case 4</th>
  </tr>
  <tr>
    <td><div><img src="https://drive.google.com/uc?export=view&id=16kooovh31j4DQnbAM3kn7G11GxGvpA4g"/></div></td>
    <td><div><img src="https://drive.google.com/uc?export=view&id=18YU7aSQEpP7PTzHXBFM_6VAx9ueZWK-3"/></div></td>
    <td><div><img src="https://drive.google.com/uc?export=view&id=1eG2G0QueXjrFfH94hWbEoyokIe3z_2Mu"/></div></td>
    <td><div><img src="https://drive.google.com/uc?export=view&id=1dTI569X0yYUjTHgPQYNSMDranEnox6-m"/></div></td>
  </tr>
  <tr>
    <td>The object is too far away.</td>
    <td>The object is too inclined with respect to the sensor.</td>
    <td>The object is too small.</td>
    <td>The object is not dense enough.</td>
  </tr>
</table>

In our case, these limitations may result in scenarios where the robot is unable to detect the obstacle, mainly because its body is significantly wider (11cm) than the area covered by the sensor (4.5cm).
The sound waves emitted by the transmitter, therefore, may not be wide enough, especially when the robot is at certain angles to the obstacle, to ensure that the passage area is actually free.

The images below show the two most frequent scenarios in which the robot may find itself when it needs to avoid an obstacle.

<table>
  <tr>
    <th style="width: 50%">Case 1</th>
    <th style="width: 50%">Case 2</th>
  </tr>
  <tr>
    <td style="width: 50%; text-align: center;"><div><img height="300" src="https://drive.google.com/uc?export=view&id=18PD91ICMCLwP-xcBV95xYP_PEEE7c7lB"/></div></td>
    <td style="width: 50%; text-align: center;"><div><img height="300" src="https://drive.google.com/uc?export=view&id=1hkFE7fOAA53xs0imC8cmVnX9EkE_HcbP"/></div></td>
  </tr>
  <tr>
    <td style="width: 50%">The ultrasonic sensor correctly detects the presence of an obstacle, so the robot can change its direction and avoid it with no issues.</td>
    <td style="width: 50%">The ultrasonic sensor is unable to detect the obstacle, since it is in the blind zone. The robot won't change direction and will inevitably collide with the object.</td>
  </tr>
</table>

### Light chasing with obstacle avoidance

As mentioned earlier, thanks to the purchase of the add-on kit we were able to equip the robot with two light sensors. This allowed us to create a new controller for light chasing with obstacle avoidance. This is an extension of the previous control program and implements, in addition to wandering and obstacle avoidance, an new behavior for phototaxis.

**Design**

The control program, in this case, is composed by three behaviors: wandering, obstacle avoidance and light chasing. The first two are identical to the obstacle avoidance controller (see the [dedicated section](#obstacle-avoidance)). The third one is, from a high level perspective, pretty simple: if the two sensors detect the same light level, the robot moves forward, otherwise it turns toward the direction of the sensor with the highest light value. There are however some of complications that need to be dealt with:
- At what light level should the robot start chasing the source?
- At what light level should the robot stop, considering the source to be reached?
- Left and right sensor measurement will rarely be exactly the same, so what is the threshold below which the detected values should be considered equal?

To establish the light levels at which the robot starts ($chase$) and stops ($done$) chasing the source, we decided to make it perform a preliminary check on startup. In this phase, the robot moves in a 360?? spin and saves the highest detected light level ($value$). It then uses the following formulas to compute the required values:

$$ chase = value * 1,1 $$

$$ done = -50 + 155 * ln(chase) $$

$chase$ is simply a 10% increment over the maximum value detected during the initial spin. Given that the sensors can detect a wavelength between 400 and 1100nm, we assumed $chase$ to be roughly between 10 and 850nm. We were unable to detect values below this range, and values above it mean the environment is too bright for the robot to properly detect the light source. With this consideration, we opted to compute $done$ with a logarithmic function that generates the following output.

<img height="300" src="https://drive.google.com/uc?export=view&id=14fvxmEm2TdkPRqa2W7wqIJpkt-Iv53qT"/>

Since left and right sensor measurement will rarely be exactly the same, some kind of threshold is needed, below which the brightness values ??????read by the two sensors are considered equal. Choosing the right threshold is not trivial. If the value is too high, the robot may miss the light source, while if it's too low it could continuously turn left and right. Furthermore, if the light is far away from the robot, the values detected by the two sensors are going to be very similar. On the contrary, when the robot gets in close proximity to the light source, a small turn means a large difference in the detected light level. As a consequence, the threshold should be dynamic and become higher when the robot is approaching the light, to prevent it from continuously turning left and right. To do this, we have selected the following formula during the testing phase:

$$
  threshold = \begin{cases}
  maxValue * {thresholdRange \over lightRange} &\text{if } maxValue > chase + lightRange * 0.75 \\
  minThreshold &\text{otherwise}
  \end{cases}
$$

- $maxValue$ is the maximum between the two values detected by sensors
- $lightRange = done - chase$
- $thresholdRange = maxThreshold - minThreshold$ is the difference between the maximum and minimum allowed thresholds. During testing, we identified the values of 40nm and 10nm respectively

With the above formula, the threshold value remains constant at $minThreshold$ until the robot detects a light value that is 25% below the $done$ level, then it starts growing linearly. In our tests, this has shown to grant a good sensitivity independently from the distance to the light source.

![](https://drive.google.com/uc?export=view&id=1FvFivZ4CvPCGH7KgCPzZbIGjm4Ln662R)

As can be seen in the flowchart below, the obstacle avoidance behavior is the one with the highest priority, followed by the light chasing one and defaulting to wandering when no light or obstacle is detected.

<img height="800" src="https://drive.google.com/uc?export=view&id=1zCMchMLzemYs8JGSNj77jgc3ixaLlWbr"/>

**Implementation**

Our light chasing algorithm is based on three different behaviors: wandering, obstacle avoidance and light chasing. The program uses the following constants:
- `AVOID_DISTANCE`: distance beyond which the robot remains in wandering mode
- `CRITICAL_DISTANCE`: distance within which the robot changes direction to avoid a collision
- `MIN_THRESHOLD`: minimum level of light threshold
- `MAX_THRESHOLD`: maximum level of light threshold
- `TURN_DELAY`: minimum time (ms) that must elapse between turns

And the following global variables:
- `distance`: current distance detected by the ultrasonic sensor
- `avoiding`: boolean set to true if the robot is in obstacle avoidance mode
- `changedDirection`: boolean set to true if the robot has already tried to change direction
- `lastTurnTimestamp`: timestamp of the last turn
- `turnDirection`: enum value representing the direction in which the robot is turning
- `lightRight`: light level detected by the right sensor
- `lightLeft`: light level detected by the left sensor
- `lightThreshold`: margin below which the brightness values ??????read by the two sensors are considered equal. Computed on each loop by the `computeThreshold` function
- `chaseLightLevel`: light level beyond which the robot enters light chasing mode. Computed after the initial spin by the `computeChaseLightLevel` function
- `doneLightLevel`: light level beyond which the robot stops because it has reached the light source. Computed after the initial spin by the `computeDoneLightLevel` function

The basic mechanism that guides the robot in choosing which mode to execute works as follows:
- If the distance detected by the ultrasonic sensor is less than `AVOID_DISTANCE` and neither the right nor the left light sensor detects a light level higher than `doneLightLevel`, the robot enters obstacle avoidance mode
- If the right or left sensor detects a brightness level higher than `chaseLightLevel`, the robot enters chase light mode. In this case, the robot moves accordingly based on the light level read by the two sensors
- Otherwise, wandering mode is activated

Both wandering and obstacle avoidance modes have been ported with no modifications from the obstacle avoidance firmware (see [Obstacle avoidance](#obstacle-avoidance)).

**Testing**

For testing, we placed a flashlight that the robot has to reach in four different environments, running the test 10 times in each one and changing the position of the light between runs. During each test, the robot had a time of 60 seconds to find and reach the flashlight.

1. **Room lit by the sunlight coming from a window**\
   Here, if the flashlight was in direct contact with the sunlight, the robot was never able to detect it. Placing the source in the shadow helped, but the high ambient light level meant the robot was still unable to consistently reach the flashlight, leading to a final success rate of only 30%.
2. **Room lit by a ceiling light**\
   In this test, the room was lit by a single, ceiling-mounted 600lm@6000K LED bulb, providing a uniform illumination on the entire environment. The robot always reached the flashlight, provided it was able to detect it in the first place. Due to the quite high ambient light level, it had to wander very close (< 1m) to the flash light to detect it. The end result was a 50% success rate, due to the limited amount of time the robot had at its disposal to find the light source.
3. **Room with no light sources**\
   Having an almost completely dark environment, the robot was able to easily detect the flashlight from a 2m+ distance, achieving a success factor of 100%.
4. **Room with no light sources and some cardboard boxes scattered around**\
   The final test was carried out in the environment with the most ideal illumination, adding some cardboard boxes as obstacles. In this situation, the robot reached the flashlight within 60 seconds in 80% of the cases, but was able to avoid any collision only in half of them, leading to a final success rate of 40%. Albeit using the same code as before, the obstacle avoidance behavior was substantially worse compared to previous testing (see [Limitations](#limitations-2))

<table>
  <tr>
    <th>Room with no light sources and some cardboard boxes scattered around</th>
  </tr>
  <tr>
    <td><div><img width="400" src="https://drive.google.com/uc?export=view&id=18eIrnUq6Gfmd-ySeTzisakrXYeK7wyba"/></div></td>
  </tr>
  <tr>
    <td><a href="https://drive.google.com/file/d/1JbtrB1WWwk3pahGgJ0Arb4F_gqmo_BuQ/view?usp=sharing">Video</a></td>
  </tr>
</table>

**Limitations**

As a result of the tests we carried out, it was evident that the robot could only operate properly when the room was deprived of any natural light source. Otherwise, both sensors detected such high baseline values that the robot could only enter light chasing mode when very near to the flashlight.

As soon as the assembly phase of the two light sensors was completed, it was immediately clear that combining light chasing with obstacle avoidance has a strong limitation due to the size of the robot. The light sensors mounted to the front brought the width of the mBot to 168mm, up from the initial 126mm of the basic configuration. This 33% increase amplified the blind zone of the ultrasonic sensor, weakening the ability of the robot to detect and avoid obstacles even more.

<table>
  <tr>
    <th style="width: 50%">Basic setup</th>
    <th style="width: 50%">With light sensors</th>
  </tr>
  <tr>
    <td style="width: 50%"><div><img src="https://drive.google.com/uc?export=view&id=1qMO4-wElRXtY-NxhLOUwxygP2Br04wmg" /></div></td>
    <td style="width: 50%"><div><img src="https://drive.google.com/uc?export=view&id=1Lq25r8le4_N1_qDS35i15WzghULaKOzO" /></div></td>
  </tr>
</table>

## Conclusions and future work

This project's goal was to experience programming a robot controller in a real world environment, in order to compare it against the simulated one that has been used in laboratory sessions. From a control program point of view, we are quite satisfied with the behaviors we were able to create, and we think that the results we obtained during our experiments can't be improved by much due to the nature and the limitations of the robot kit we chose. The experience of programming a controller on a physical robot is very different from the usage of a simulator. On one side, testing directly in a real world environment has allowed us to catch more errors, fine tune parameters to prevent problems related to sensor noise, and feel more secure of having a successful implementation - after all, we already tested it on physical hardware. On the other side, however, testing in a simulator is way more efficient from a time and resource point of view: setting up a virtual environment is faster, and testing is even more, thanks to the ability to run multiple instances of the controller in parallel. In the end, the ideal setup would be to have both a simulator and a real environment to test with, and adopt an iterative **plan** - **implement** - **test** - **validate** approach, like shown in the figure below.

![](https://drive.google.com/uc?export=view&id=19gQlYBuoI68eXopMGo1DMop018Z2qZQA)

The nature of this project lends itself particularly well to future development. For one, the chosen kit can be easily expanded with additional modules, offering the possibility to implement new and more advanced controllers. Another interesting activity would be to purchase more kits and test the usage of robot swarms, a scenario that we were unable to take into account due to time and budget constraints. During testing, we would have been interested in directly comparing the results we got in the real world against the ones obtained within a simulator. However, in order to make a 1:1 comparison, it is obviously necessary to use a robot with the same characteristics as the agent running on the virtual environment. In our case this was not possible, but as previously highlighted this approach would have offered the best developer experience and should be considered for any advanced robot programming project.
