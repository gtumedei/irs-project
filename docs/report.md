# Report

## Introduction

## Choosing the robot kit

Choosing the right kit is an important step because its components will define what can and can't be done in the project. As such, we have started by defining a set of features that a kit must match in order to be a valid candidate.

### Required features

The main criteria used to identify the robot kit that best fits our needs are the following:

- **Reasonably priced**: since this is a self-funded project, the cost to purchase the kit should not exceed 100€ so that it can a viable solution for similar activities made by other students
- **Preferably equipped with two wheels**: any other solution involves the usage of more than two motors, thus increasing the price and making any movement related code harder to write
- **Presence of ultrasonic sensor**: since obstacle avoidance is the main behavior that the robot must be able to adopt as the project goal, this sensor is indispensable
- **Preferably equipped with some light sensors**: not mandatory, but it opens up to interesting behaviors such as combining obstacle avoidance and light chasing
- **Programmable in a known language**: the main complexities when dealing with a robot acting in a real environment lie in the physical limitations of both the agent and its surroundings. Therefore, using an already known programming language gives a certain level of confidence that anomalies are related to the physical environment and not to the development one
- **Presence of documentation to support programming**: the development phase is going to be much straightforward if the robot is based on a well documented and/or popular board
- **Good level of modularity**: the more the kit is modular, the more possibilities open up, from buying replacement parts in case of damage to the existing ones, to adding sensors and actuators and implementing new, complex controllers

### The market of programmable robot kits

<table>
    <thead>
        <tr>
            <th>Kit</th>
            <th>Pros</th>
            <th>Cons</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td>
                <strong>Makeblock mBot Kit</strong><br>
                <a href="https://amzn.to/3lsxlnw">https://amzn.to/3lsxlnw</a><br>
                <img height="200" src="https://drive.google.com/uc?export=view&id=1fV3h-D6ATuJwflhDP8jxG3BIhxFH27jf">
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
            <td>
                <strong>Freenove Micro: Rover Kit</strong><br>
                <a href="https://amzn.to/3MzPews">https://amzn.to/3MzPews</a><br>
                <img height="200" src="https://drive.google.com/uc?export=view&id=1KF2s55cbdmwdAdRxurueLzvAnRS-Si5j">
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
            <td>
                <strong>ELEGOO UNO Project Kit</strong><br>
                <a href="https://amzn.to/3luxFC3">https://amzn.to/3luxFC3</a><br>
                <img height="200" src="https://drive.google.com/uc?export=view&id=1WOvLLYx-pIQsI6A6rFICLVA0HmraIE_E">
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
            <td>
                <strong>ELEGOO Smart Owl Robot Car Kit</strong><br>
                <a href="https://amzn.to/3sJYs1p">https://amzn.to/3sJYs1p</a><br>
                <img height="200" src="https://drive.google.com/uc?export=view&id=1ROB8XoqZokn4gsE7J6WCTK1rMLIp6gml">
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
            <td>
                <strong>OSOYOO V2.1 Smart Robot Car Kit for Arduino</strong><br>
                <a href="https://amzn.to/3tc00Sb">https://amzn.to/3tc00Sb</a><br>
                <img height="200" src="https://drive.google.com/uc?export=view&id=1G1MLzwOc9xPzwSLPTIT6QSm9QR1fnFY6">
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
            <td>
                <strong>OSOYOO Robotic Car for Raspberry Pi 4 3B + 3B</strong><br>
                <a href="https://amzn.to/3yMlRmF">https://amzn.to/3yMlRmF</a><br>
                <img height="200" src="https://drive.google.com/uc?export=view&id=1fujrBIhGpEm7pkfz3-Egj0sEaiDUlt3j">
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

After a careful analysis of the various options the market has to offer, our choice fell on the mBot kit produced by Makeblock. The only real downside is that we had to buy the light sensors separately, bringing the total cost just shy of the 100€ price limit.

## Robot kit analysis

The provided kit contains all the components necessary to meet most of the features required to complete the project objectives. The only lack is related to light sensors, which are needed for the implementation of more complex behaviors such as combining obstacle avoidance and light chasing.
For this reason, we decided to purchase an additional kit that allows to setup the robot in three additional configurations:
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
        <tr>
            <td>
                <img height="200" src="https://drive.google.com/uc?export=view&id=1iIHip_pIJdKip6pugbEDiucPwCZXv268">
                <img height="300" src="https://drive.google.com/uc?export=view&id=1te4AjnjjeQa8E3wZ79ZFdrNh0Z49Befm">
            </td>
            <td>
                <img height="300" src="https://drive.google.com/uc?export=view&id=1REbNeqX91fLJRQoElLyLo-WaTCKrCl7D">
            </td>
        </tr>
    </tbody>
</table>

### Hardware

<table>
    <tr>
        <td colspan="2">Makeblock mBot kit</td>
    </tr>
    <tr>
        <td>
            <img height="350" src="https://drive.google.com/uc?export=view&id=1DoDd6_Jf0MZ20qUcL1Fyng-e5RsvFIkV">
        </td>
        <td>
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
    <tr>
        <td colspan="2">Makeblock mBot Add-on 3-in-1</td>
    </tr>
    <tr>
        <td>
            <img height="350" src="https://drive.google.com/uc?export=view&id=1sX3-d8Da5P27FlVUPPt8YvPWt6nwU3FW">
        </td>
        <td>
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

### Software

Most of the robot kits produced by Makeblock, including mBot, support several development platforms, which can be chosen according to the desired level of difficulty, making them ideal for any user.

- **mBlock 5**: cooding tool that supports both Python and block programming via a dedicated browser platform. More information available at https://mblock.makeblock.com/en-us/
- **mBlock Blockly**: game-based robot app that supports block programming, specifically designed for younger users. More information available at https://www.makeblock.com/software/mblock-app
- **Makeblock App**: all-in-1 controller for any Makeblock robots that supports multiple control modes and 3D modeling. More information available at https://www.makeblock.com/software/makeblock-app
- **Arduino IDE**: it's just like programming a normal Arduino board, but with additional resources provided by Makeblock through their official GitHub repository, accessible at https://github.com/Makeblock-official/Makeblock-Libraries

We obviously chose the latter.

## Firmware analysis and refactor

### Working with sensors and actuators

**Wheels**

<img height="250" src="https://drive.google.com/uc?export=view&id=1lmTIVMaEcnv2D_NmNa49LbAqFAn7RR0O">
<img height="250" src="https://drive.google.com/uc?export=view&id=1vR-N5KxgLyByGvqCfQ3w9mc65ZqfHbHI">

Each of the two wheels equipped to mBot are attached to a servo motor and connected to the motherboard via two RJ45 connectors. These are mapped inside Arduino to PWM pins, enabling the rotation speed for each wheel to be specified using values between 0 and 255.

**Line follower sensor**

The line-follower module placed below the robot consists of two sensors, both equipped with an infrared emitter and infrared receiver, with a detection range of 1 to 2cm. The infrared emitters continually generate infrared light. If the light is reflected (encountering white or other light color surfaces), the corresponding receiver gets the infrared signal back and outputs the value 1; if the infrared light is absorbed or cannot be reflected, the receiver will not get the infrared signal back and output the value 0.
Given that the robot has two sensors, the resulting combinations are the following:
- Both sensors read 0
- The left sensor reads 0, while the right reads 1
- The left sensor reads 1, while the right reads 0
- Both sensors read 1

**Ultrasonic sensor**

![](https://drive.google.com/uc?export=view&id=1zHcr1mlZDDbEsbjadmiXVXWqKQDyeZ0C)

mBot is equipped with a classic ultrasonic sensor, similar to those found in standard Arduino kits, which allows it to detect obstacles in a range from 1cm to 400cm.

The basic operation of the sensor is quite simple, it emits an ultrasound at high frequency (~40kHz) which travels through the air and if there is an object or obstacle on its path it will bounce back to the module. Considering the travel time of the signal (back and forth) and the speed of the sound you can calculate the distance.

$$ distance = {34cm/ms * time \over 2} $$

**Light sensor**

![](https://drive.google.com/uc?export=view&id=1Da553WpNjLGmU8zdvgYw9QoRmWK8_EYs)

<!-- Immagine unica (?) -->
<!-- <img height="350" src="https://drive.google.com/uc?export=view&id=18eIrnUq6Gfmd-ySeTzisakrXYeK7wyba"> -->

The two light sensors available in the add-on kit for mBot are connected to the motherboard via RJ45 connectors, and must use ports 3 and 4 as shown in the picture.

![](https://drive.google.com/uc?export=view&id=112d1gGe8w4nuZTNu0aPKUfR9teqG-ZaD)

These sensors are based on the photoelectric effect principle in semiconductors and can be used to detect the intensity of ambient light.

The photosensitive wavelength range varies between 400 and 1100nm, the analog value of the output goes from 0 to 1000. According to the documentation provided by Makeblock these values can be interpreted as follows:
- \[0-100]: evening
- \[100-500]: indoor lighting condition
- \>500: exposure to sunlight

### Refactoring the default firmware

#### MeWheels class

To simplify the use of the wheels, we created an additional class, called MeWheels, found within the libraries that make up the robot's firmware. The class contains the following functions:
- `spinRight`: spins the right wheel at a given speed
- `spinLeft`: spins the left wheel at a given speed
- `stopRight`: stops the right wheel
- `stopLeft`: stops the left wheel
- `forward`: moves forward at a given speed
- `backward`: moves backward at a given speed
- `turn`: turns toward the direction specified as a parameter, at the given speed, multiplied by a factor set to 0.8 by default
- `turnLeft`: turns to the left at the given speed, multiplied by a factor set to 0.8 by default
- `turnRight`: turns to the right at the given speed, multiplied by a factor set to 0.8 by default
- `forwardAndTurn`: turns toward the direction specified as a parameter, while keep going forward at the given speed, multiplied by a factor set to 0.8 by default
- `forwardAndTurnLeft`: turns to the left while keep going forward at the given speed, multiplied by a factor set to 0.2 by default
- `forwardAndTurnRight`: turns to the right while keep going forward at the given speed, multiplied by a factor set to 0.2 by default
- `backwardAndTurn`: turns toward the direction specified as a parameter, while keep going backward at the given speed, multiplied by a factor set to 0.8 by default
- `backwardAndTurnLeft`: turns to the left while keep going backward at the given speed, multiplied by a factor set to 0.333 by default
- `backwardAndTurnRight`: turns to the right while keep going backward at the given speed, multiplied by a factor set to 0.333 by default
- `stop`: stops both wheels

In addition, to more intuitively specify the direction in which to proceed, there is an enum in the .h file, named `TurnDirection`, which can assume the following values:
- DIR_RIGHT
- DIR_LEFT
- DIR_NONE

## Controller development

### Line following

The first behavior that has been implemented is the mode that allows the robot to follow a black line drawn on the ground.

When the line-follower module has two sensors there are basically two methodologies for constructing the path that the robot has to follow. Based on the distance between the two sensors (in our case 1.5cm) it is possible to decide to draw a line with a thickness less than the aforementioned distance, or greater, which is the solution we opted for.

#### Design

| Case 1                                                                                                | Case 2                                                                                                                                  | Case 3                                                                                                                                  | Case 4                                                                                                                 |
| ----------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------- |
| <img height="250" src="https://drive.google.com/uc?export=view&id=1o2HyuJU_8iDzg89Bkogz3yebSaX4aUMc"> | <img height="250" src="https://drive.google.com/uc?export=view&id=1TijwBejeKzvTrgsoi45z_NsPoeojQDUL">                                   | <img height="250" src="https://drive.google.com/uc?export=view&id=1Depcz2jUsGjtVr_5oxeJX2HKvhep5G_z">                                   | <img height="250" src="https://drive.google.com/uc?export=view&id=16jpkEiu_sicN7yhg33FNrm5AUCvpVmyx">                  |
| mBot is on the black line, the value of the line-follower sensor is 0. The robot should keep moving forward.  | mBot deviates from the black line to the right, the value of the line-follower sensor is 1. The robot should turn left to find the black line. | mBot deviates from the black line to the left, the value of the line-follower sensor is 2. The robot should turn right to find the black line. | mBot is not on the black line, the value of the line-follower sensor is 3. The robot should move backwards to find the black line. |

#### Implementation

The line following controller is very simple and basically consists of a switch that handles the above four cases, moving the wheels according to the value read from the sensors. Regarding the speed, after some tests we identified the following formula as the ideal way to compute it:

$$ speed= maxSpeed * (1-{\vert direction \vert\over 10 }) $$

Where $maxSpeed$ is a constant representing the maximum value of speed the robot can reach, which is 255. The calculation is done within the `computeSpeed()` function, which returns the minimum between the calculated speed and $minSpeed$, a constant set to 230.

<!-- Add flowchart -->

<!-- Talk about the direction value in the code -->

#### Tests and experiments

The goal of our tests was to demonstrate that the robot is able to follow the drawn black line. To carry out the verification of our hypotheses, we created three tracks of increasing difficulty and tested the behavior of the robot ten times each.

- **Infinity-shaped track**: this is the track bundled with the robot kit, characterized by an infinity-shaped line printed on paper, so we expected the robot to be able to follow the line without particular difficulty. After adjusting our parameters to optimize the robot's movements, the success rate was 100%.
- **Rectangular track**: hand-built track using electrical tape on cardboard, the rectangular shape allowed us to test the robot's behavior in sharp turns. In the first tests, the robot was able to properly follow about 1 turn every 3. We then realized that the sharp turns needed to be slightly cut off on the outside. This is because otherwise the sensors of the line-following module reached the white background roughly at the same time, causing the robot to: go backwards if it detected white on both sensors simultaneously, turn 90° (correct behavior) or turn 270° if a sensor read white before the other. By making the above change, the outermost sensor always detects the white background first, allowing the robot to curve correctly and obtain a success rate of 100%.
- **Mixed track**: a more complex track that had the properties of both the previous ones. The line was at first drawn using an indelible marker, but in this case the sensor was unable to detect it correctly, as the ink probably contained some reflective substances. After recreating the track using a black spray can, we were able to make the ten attempts. Despite the difficulty of the path, our experiments yielded good results: the robot was able to complete the path without deviations 80% of the time.

| Infinity-shaped track                                                                                               | Rectangular track                                                                                                                               | Mixed track                                                                                                                                  |
| ----------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------- |
| <img width="650" src="https://drive.google.com/uc?export=view&id=1VVzeHh6uENo4SxQycs6u5JeqdmkOHL9P"> | <img width="650" src="https://drive.google.com/uc?export=view&id=1XGQeXnBC5ACRlYf55nEEAwRyD4rd2x78">                                     | <img width="650" src="https://drive.google.com/uc?export=view&id=1tXyivJEmGDgJU8mMY4VuGNSvYleuGTAw">                                    |
|<a href="https://drive.google.com/file/d/111KmP_mfyQhs-e7-Xhquj9NTwerWya8x/view?usp=sharing">Link to the video</a><br>  | <a href="https://drive.google.com/file/d/1eC8OpXyJH8jLvrJn8K7qu9o_2jx-icFX/view?usp=sharing">Link to the video</a><br>                                     | <a href="https://drive.google.com/file/d/1GKMX8KEeZe8vkeV6XMvj6-Tru8w0QBOJ/view?usp=sharing">Link to the video</a><br>                                  |

### Obstacle avoidance

The second and last behavior that we could realize using only the basic kit is obstacle avoidance.

When approaching this type of problem using a single frontal ultrasonic sensor there are basically two possibilities, which depend on the type of robot kit being used. In the case where the sensor is mobile, an algorithm can be implemented that periodically checks the state of the environment around the agent, which can then more effectively avoid obstacles since it is, potentially, free of blind spots. Otherwise, as in our case, the robot is equipped with a single ultrasonic sensor placed in a fixed position, which, as we will see later, leads to some disadvantages and problems that can hardly be avoided.

#### Design

As mentioned earlier, using such a sensor to implement an obstacle avoidance algorithm has some limitations, represented below.

![](https://drive.google.com/uc?export=view&id=1zgV7ugPvJHh_1fsA5jEyatoL0PbdOlHX)

In our case, these limitations may result in scenarios where the robot is unable to detect the obstacle, especially because the body width is significantly wider (11cm) than the sensor size (4.5cm).
The sound waves emitted by the transmitter, therefore, may not be wide enough, especially when the robot is at certain angles to the obstacle, to ensure that the passage area is actually free.

Below are graphically depicted the two most frequent scenarios in which the robot may find itself when it needs to avoid an obstacle.

| Case 1                                                                                                | Case 2                                                                                                                                  |
| ----------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------- |
| <img width="250" src="https://drive.google.com/uc?export=view&id=1Gs2VW1mq0hzX0DMY-CrnlymQ-Vmf7eMO"> | <img width="250" src="https://drive.google.com/uc?export=view&id=1GWq5lqiK97Tg18xkevRsV39O56XcMEFy">                                   |
| The ultrasonic sensor correctly detects the presence of an obstacle, mBot should then change its direction.  | The ultrasonic sensor is unable to detect any obstacle, since it is in the blind zone. mBot does won't change direction and will inevitably collide with the object. |

#### Implementation

Our obstacle avoidance algorithm is based on two different behaviors: wander and, indeed, obstacle avoidance. The program uses the following constants:
- `HIGH_DISTANCE`: distance beyond which the robot remains in wander mode
- `LOW_DISTANCE`: distance within which the robot changes direction to avoid the obstacle
And the following global variables:
- `distance`: current distance detected by the ultrasonic sensor
- `avoiding`: boolean set to true if the robot is in obstacle avoidance mode
- `changedDirection`: boolean set to true if the robot has already tried to change direction
- `lastTurnTimestamp`: timestamp of the last turn
- `turnDirection`: enum value representing the direction in which to turn

The robot remains in wander mode until the sensor detects an obstacle at a shorter distance than `HIGH_DISTANCE`, three possibilities can occur during this phase:
- The robot makes a left turn with a probability of 3.33%
- The robot makes a right turn with a probability of 3.33%
- The robot proceeds straight with a probability of 93.34%

For a direction change to occur, a minimum time, identified in the `TURN_DELAY` constant, must have elapsed since the last direction change.

If an obstacle is detected, the robot enters the obstacle avoidance mode, which consists of the following steps:
1. The robot tries to turn, staying in place, to the right or left with a probability of 50% each
2. If the robot remains in obstacle avoidance mode and the distance to the obstacle is less than `LOW_DISTANCE`, then it turns from the opposite direction than the previous attempt
3. The robot proceeds in the selected direction

<!-- Add flowchart -->

#### Test and experiments

The goal of our tests was to demonstrate that the robot is able to avoid obstacle in a controlled environment. To carry out the verification of our hypotheses, we created two different cases of increasing difficulty and let the robot running on the field for a minute, testing the scenarios ten times each.

- **Controlled perimeter**: limited area defined by a perimeter composed of cardboard boxes, in this test the robot was able to easily detect obstacles, staying within the area and generating few collisions during out tests. All collisions happened upon the occurrence of the conditions that highlight the limitations of the ultrasonic sensor, mentioned in the previous design section
- **Open environment**: large space of about 12sqm with some cardboard boxes, again used as obstacles. Although the collision avoidance algorithm worked correctly as expected, collisions were more frequent during our tests than in the previous case study, but still dictated by the limitations of the ultrasonic sensor. The frequency of collisions is obviously higher as the probability of the robot finding an obstacle in a blind spot increases

| Controlled perimeter                                                                                  | Open environment                                                                                                                        |
| ----------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------- |
| <img width="550" src="https://drive.google.com/uc?export=view&id=1STkrO68TkiODY0vH1kDabf1mb7bMYvvm">  | <img width="550" src="https://drive.google.com/uc?export=view&id=1fWpy0qN9GY-kqCCeTJhIj2dzgjNzAFvq">                                    |
|<a href="https://drive.google.com/file/d/16hjmNWZJci_vfP-aY5fA5w3V-6P3VM1W/view?usp=sharing">Link to the video</a><br>  | <a href="https://drive.google.com/file/d/1_O2Lzs7QVdZh8MXopDFHaz6QkgEBlsgZ/view?usp=sharing">Link to the video</a><br> |

### Light chasing with obstacle avoidance

As mentioned earlier, thanks to the purchase of the add-on kit we were able to equip the robot with two side light sensors.

Since this is a dual behavior, all the assumptions made earlier for obstacle avoidance apply again, to which some considerations regarding light chasing must be added.

#### Design

| Basic setup                                                                                  | Light chasing mode                                                                                                                        |
| ----------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------- |
| <img width="550" src="https://drive.google.com/uc?export=view&id=1qMO4-wElRXtY-NxhLOUwxygP2Br04wmg">  | <img width="550" src="https://drive.google.com/uc?export=view&id=1Lq25r8le4_N1_qDS35i15WzghULaKOzO">                                    |

As soon as the assembly phase of the two light sensors was completed, it was immediately clear that combining light chasing with obstacle avoidance has a strong limitation due to the size of the robot. The two side sensors bring the width of the mBot to 168mm compared to 126mm in the basic configuration (+33%) which, as mentioned earlier, caused problems when obstacles were in the blind zone of the ultrasonic sensor.

#### Implementation

<!-- Add flowchart -->

#### Test and experiments

<!-- Add video -->

## Control software analysis

## Conclusions and future work
