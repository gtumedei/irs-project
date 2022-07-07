![](https://drive.google.com/uc?export=view&id=1E8WtqZvkqsAqdkPyTNI4E6NSMvSlagp9)

<h1 align="center">
  Possibilities and Limitations of Switching from a Robot Simulator to a Real-World Scenario
</h1>

<center>
  Mattia Rossi (<a href="mailto:mattia.rossi15@studio.unibo.it">mattia.rossi15@studio.unibo.it</a>)<br/>
  Gianni Tumedei (<a href="mailto:gianni.tumedei@studio.unibo.it">gianni.tumedei@studio.unibo.it</a>)<br/>
  <br/>
</center>

![](https://drive.google.com/uc?export=view&id=1lmTIVMaEcnv2D_NmNa49LbAqFAn7RR0O)

## Introduction

This is a project for the [Intelligent Robotics Systems](https://www.unibo.it/it/didattica/insegnamenti/insegnamento/2020/447106) 2021/22 course of the University of Bologna.

The goal of this project is to compare the experience of programming a robot controller in a simulated environment against a real world one. To do this, we have chosen [mBot](https://www.makeblock.com/mbot-3), a robot kit by [Makeblock](https://www.makeblock.com) that enabled us to implement a series of control programs, similar to the ones created in the course's laboratory sessions. As in that case, we applied a scientific approach to development and testing, by formulating hypotheses, checking them against actual behaviors and making adjustments when needed.

This repository includes the implementation of four behaviors: wandering, line following, obstacle avoidance and phototaxis, which have been combined in order to create slightly more complex, multi-behavior control programs (see [Control programs](#control-programs)).

The full report, with more details about the project topics and an analysis of the robot kits market, can be accessed in [markdown](./docs/report.md) or [PDF](https://github.com/gtumedei/irs-project/releases/download/1.0.0/report.pdf) format.

## Getting started for development

### Requirements

- Arduino IDE ([download here](https://www.arduino.cc/en/software))

### Setup

- Download the patched Makeblock library* from [here](https://github.com/gtumedei/irs-project/releases/download/0.0.0/Makeblock-Libraries-master.zip) and the MeMBotFirmware library from [here](https://github.com/gtumedei/irs-project/releases/download/0.0.0/MeMBotFirmware.zip)
- Import both libraries from Arduino IDE: for each one, select "Sketch" -> "Include Library" -> "Add .ZIP Library..." and choose the downloaded `.zip` file
- Clone the repo
  ```
  git clone https://github.com/gtumedei/irs-project
  ```
- Open one of the sketches from `src/<SKETCH_FOLDER>/<SKETCH_NAME>.ino` with Arduino IDE

\* The official Makeblock library ([repo](https://github.com/Makeblock-official/Makeblock-Libraries)) includes a variable initialization in a `.h` file, resulting in problems if that file gets imported more than once.

## Firmware
`lib/MeMBotFirmware`

To ease controller development and reduce code duplication among different control programs, we have created a MeMBotFirmware Arduino library, that:
- includes the Makeblock library;
- implements the following features that are common among controllers: handling the builtin button, the IR receiver, and the two wheels, emitting tones from the buzzer, manually controlling the robot with the IR remote;
- declares an `autoMode` function that the final controller has to implement with the actual behaviors of the robot.

## Control programs

Each control program is composed by:
- a `.ino` file: standard Arduino program with `setup` and `loop` functions
- a `.cpp` file: includes a function for each behavior, plus an `autoMode` function that decides what to execute on each Arduino tick

### Line following
`src/LineFollowingMode`

This is the simplest control program and only includes a single behavior to perform line following. The controller allows the robot to follow a black track drawn on the ground, using the two infrared sensors of the line following module included in the kit.

**Design and development**

The controller is designed to follow a line that is wider than the distance between the two infrared sensors, trying to keep both of them within the track. It handles the following four scenarios:
- both sensors detect the black line: the robot proceeds straight ahead
- only the left sensor detects the black line: the robot turns to the left
- only the right sensor detects the black line: the robot turns to the right
- no sensor detects the black line: the robot uses a variable, whose value is based on previous measurements, as a compass to decide how to move

To regulate the speed, making the robot go faster in straight tracks and slower during turns, the following formula is used:

$$ speed= maxSpeed * (1-{\vert direction \vert\over 10 }) $$

Where $maxSpeed$ is a constant representing the maximum value of speed the robot can reach, which is 255. The calculation is done within the `computeSpeed()` function, which returns the minimum between the calculated speed and $minSpeed$, a constant set to 230.

**Testing and results**

This behavior has been tested by running the robot on the following three tracks of increasing difficulty:
- Infinity-shaped track: bundled with the robot kit, includes a crossroad and has no sharp turns. During testing, the robot was consistently able to follow the line with no errors.
- Rectangular track: hand crafted with electrical tape to test the robot's behavior on sharp turns. We needed to slightly cut off the turns' corners on the outside, in order to prevent both sensors from reaching the white background at the same time. After this modification, the robot was able to follow the line 100% of the time.
- Mixed track: has properties of both the previous ones, including sharp turns, non-sharp turns and a crossroad. Testing showed a success rate of 80%. In 10% of the cases the robot performed a wrong turn, but was able to get back on track, while in the remaining 10% it wrongly took the crossroad and started following the line in the opposite sense.

### Obstacle avoidance
`src/ObstacleAvoidanceMode`

The second control program, and the last that we were able to realize using only the basic kit, is the obstacle avoidance one. This controller consists of two behaviors, one for randomly wandering around the environment, and the other to actually avoid detected obstacles using the front-mounted ultrasonic sensor.

**Design and development**

Wandering is the default behavior, during which the robot has a 3,33% chance of either turning left or right, but without being able to make more than one consecutive turn within 5 seconds from the last one, to give it a less hesitant, more human-like wandering behavior.

The obstacle avoidance behavior gets activated when the robot detects an object at a distance lower than 20cm (defined by `AVOID_DISTANCE`). Due to the static placement of the single ultrasonic sensor, the robot is unable to know where the obstacle is exactly, so it chooses a random direction (left or right) and turns towards it. While turning, if the distance gets reduced below 5cm (`CRITICAL_DISTANCE`), then it means that the robot chose the wrong direction, so it should turn in the opposite one to avoid a collision.

**Testing and results**

To demonstrate the operativity of the obstacle avoidance mode, we created two different testing scenarios where the robot was left free to roam for one minute. The first was an area enclosed by a perimeter of cardboard boxes, where the robot was able to detect and avoid most collisions. The second was a larger space, where cardboard boxes were scattered around as obstacles. Here, although the collision avoidance algorithm worked as expected, collisions were more frequent.

Most of the limitations that came up during our tests are related to having a single ultrasonic sensor in a fixed position, resulting in scenarios where the robot is unable to to detect the obstacle, mainly because its body is significantly wider (11cm) than the area covered by the sensor (4.5cm). The sound waves emitted by the transmitter, therefore, may not be wide enough, especially when the robot is at certain angles to the obstacle, to ensure that the passage area is actually free.

### Light chasing with obstacle avoidance
`src/LightChasingMode`

The last control program is an extension of the previous one and implements, in addition to wandering and obstacle avoidance, an new behavior for phototaxis/light chasing. In order to implement this behavior, we purchased an [extension kit](https://www.makeblock.com/mbot-add-on-packs-interactive-light-sound) by Makeblock and equipped the robot with two light sensors included in it.

**Design and development**

The wandering and obstacle avoidance implementation is identical to the previous controller. A for phototaxis, it is, from a high level perspective, pretty simple: if the two sensors detect the same light level, the robot moves forward, otherwise it turns toward the direction of the sensor with the highest light value.

To establish the light levels at which the robot starts ($chase$) and stops ($done$) chasing the source, we decided to make it perform a preliminary check on startup. In this phase, the robot moves in a 360° spin and saves the highest detected light level ($value$). It then uses the following formulas to compute the required values:

$$ chase = value * 1,1 $$

$$ done = -50 + 155 * ln(chase) $$

Given that the light sensors detect wavelength values in a 400-1100nm range, a threshold is needed below which the two measurements are considered to be the same. The threshold should be higher the closer the robot is to the light, to prevent it from continuously turning left and right. To compute it, we have perfected the following formula during the testing phase:

$$
  threshold = \begin{cases}
  maxValue * {thresholdRange \over lightRange} &\text{if } maxValue > chase + lightRange * 0.75 \\
  minThreshold &\text{otherwise}
  \end{cases}
$$

- $maxValue$ is the maximum between the two values detected by sensors
- $lightRange = done - chase$
- $thresholdRange = maxThreshold - minThreshold$ is the difference between the maximum and minimum allowed thresholds. During testing, we identified the values of 40nm and 10nm respectively

With the above formula, the threshold value remains constant at $minThreshold$ until the robot detects a light value that is 25% below the $done$ level, then it starts growing linearly.

For more details on the $chase$, $done$ and $threshold$ formulas, see the [full report](./docs/report.md).

**Testing and results**

This controller was tested by placing in four different environments a flashlight that the robot has to reach, and then letting it roam 10 times in each one and changing the position of the light between runs. During each test, the robot had a time of 60 seconds to find and reach the flashlight.

1. **Room lit by the sunlight coming from a window**: due to the high ambient light level, the robot was unable to consistently reach the flashlight, leading to a final success rate of only 30%.
2. **Room lit by a ceiling light**: the robot always reached the flashlight, provided it was able to detect it in the first place. Due to the quite high ambient light level, it had to wander very close (< 1m) to the flashlight to detect it. The end result was a 50% success rate, due to the limited amount of time the robot had at its disposal to find the light source.
3. **Room with no light sources**: the robot was able to easily detect the flashlight from a 2m+ distance, achieving a success factor of 100%.
4. **Room with no light sources and some cardboard boxes scattered around**: the robot reached the flashlight within 60 seconds in 80% of the cases, but was able to avoid any collision only in half of them, leading to a final success rate of 40%. Here, the obstacle avoidance behavior was also impaired by the additional bulk that the light sensors add to the robot's chassis.
