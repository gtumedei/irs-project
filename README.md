![](https://drive.google.com/uc?export=view&id=1E8WtqZvkqsAqdkPyTNI4E6NSMvSlagp9)

<h1 align="center">
  Possibilities and Limitations of Switching from a Robot Simulator to a Real-World Scenario
</h1>

![](https://drive.google.com/uc?export=view&id=1lmTIVMaEcnv2D_NmNa49LbAqFAn7RR0O)

## Project report

This is a project for the [Intelligent Robotics Systems](https://www.unibo.it/it/didattica/insegnamenti/insegnamento/2020/447106) 2021/22 course of the University of Bologna.\
The project's report is included in this repository in [markdown format](./docs/report.md) and uploaded as a release in [PDF format](#).

## Getting started for local development

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

## Project summary

The goal of this project is to compare the experience of programming a robot controller in a simulated environment against a real world one. To do this, we started by choosing a good robot kit that enabled us to implement a series of control programs, similar to the ones created in laboratory. As in that case, we applied a scientific approach to development and testing, by formulating hypotheses, checking them against actual behaviors and making adjustments when needed.

We therefore completed the implementation of four behaviors: wandering, line following, obstacle avoidance and phototaxis, combining them in order to create slightly more complex, multi-behavior control programs.

### Line following

The first controller that has been implemented allows the robot to follow a black track drawn on the ground, using just the line following module, composed by two infrared sensors. This is the simplest control program and only includes a single behavior to perform line following.

#### Design and developing

We opted for a design that kept both sensors within the track to allow the robot to follow it, resulting in the following four scenarios:
- both sensors detect the black line, the robot then proceeds straight ahead
- only the left sensor detects the black line, the robot then curves to the left
- only the right sensor detects the black line, the robot then curves to the right
- neither sensor detects the black line, in which case the controller tells the robot how to move based on a value used as a compass

The line following controller is very simple and basically consists of a switch that handles the above four cases, moving the wheels according to the value read by the sensors. To regulate the speed, making the robot go faster in straight tracks and slower during turns, we made some tests and identified the following formula:

$$ speed= maxSpeed * (1-{\vert direction \vert\over 10 }) $$

Where $maxSpeed$ is a constant representing the maximum value of speed the robot can reach, which is 255. The calculation is done within the `computeSpeed()` function, which returns the minimum between the calculated speed and $minSpeed$, a constant set to 230.

#### Testing and results

We tested the behavior of the robot by running it on the following three tracks, increasing the difficulty each time:
- Infinity-shaped track: bundled with the robot kit, mBot was able to follow the line without any particular difficulty. The success rate was 100%
- Rectangular track: hand crafted with electrical tape to test the robot's behavior on sharp turns. We needed to slightly cut off the sharp turns on the outside, in order to avoid that both sensor reach the white background at the same time. After this change the success rate was 100%
- Mixed track: track that has properties of both the previous ones. The success rate was 80%, the robot performed a wrong turn, but was able to get back on track 10% of the time; wrongly took the crossroad and started following the line in the wrong senses in the last case

### Obstacle avoidance

The second control program, and the last that we were able to realize using only the basic kit, is the obstacle avoidance one. This controller consists of two behaviors, one for randomly wandering around the environment, and the other to actually avoid detected obstacles using the frontal ultrasonic sensor.

#### Design and developing

Wandering is the default behavior, during which the robot has a 3,33% chance of either turning left or right, but without being able to make more than one consecutive turn within 5 seconds from the last one, giving it a more human-like wandering behavior.

The obstacle avoidance behavior gets activated when the robot detects an object at a distance lower than 20cm. Given that the robot is unable to know where the obstacle is, it chooses a random direction (left or right) and turns towards it. While turning, if the distance gets reduces below 5cm, then it means that the robot chose the wrong direction, so it should turn in the opposite one to avoid a collision.

#### Testing and results

To demonstrate the operation of the obstacle avoidance mode, we created two different case histories where the robot was left free to run for one minute. The first one was limited area defined by a perimeter composed of cardboard boxes, where the robot was able to easily detect obstacles. The second was a larger space, where cardboard boxes were used as obstacles; although the collision avoidance algorithm worked correctly as expected, collisions were more frequent.

Most of the limitations that arose during our tests are related to having the ultrasonic sensor in a fixed position, resulting in scenarios where the robot is unable to to detect the obstacle, mainly because its body is significantly wider (11cm) than the area covered by the sensor (4.5cm). The sound waves emitted by the transmitter, therefore, may not be wide enough, especially when the robot is at certain angles to the obstacle, to ensure that the passage area is actually free.

### Light chasing with obstacle avoidance

#### Testing and results