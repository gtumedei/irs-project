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
                    <li>Front-facing camera</li>
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
                    <li>An expansion board occupies every mainboard pin, preventing the installation of new modules</li>
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
                    <li>Movable ultrasonic sensor</li>
                    <li>Uses Arduino as its mainboard</li>
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

After careful analysis of the various options the market has to offer, our choice fell on the mBot kit produced by Makeblock.

## Robot kit analysis

The kit provided contains all the components necessary to meet most of the features required to complete the project objectives. The only lack is related to light sensors, which are needed for possible implementation of more complex behaviors such as combining obstacle avoidance and light chasing.
For this reason, we decided to purchase an additional kit that allows to implement three additional modes to the robot:
- Light chasing
- Scorpion (add a rgb-responsive tail)
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
    <thead>
        <tr>
            <th>Kit</th>
            <th>Components list</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td>
                <strong>Makeblock mBot kit</strong><br>
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
            <td>
                <strong>Makeblock mBot Add-on 3-in-1</strong><br>
                <img height="350" src="https://drive.google.com/uc?export=view&id=1sX3-d8Da5P27FlVUPPt8YvPWt6nwU3FW">
            </td>
            <td>
                <ul>
                    <li>Beam and plates</li>
                    <li>Fasteners</li>
                    <li>M5/M7 wrench</li>
                    <li>Me RGB LED</li>
                    <li>Me light sensor</li>
                    <li>Me sound sensor</li>
                    <li>RJ25 cables</li>
                </ul>
            </td>
        </tr>
    </tbody>
</table>

### Software

Most of the robot kits produced by Makeblock, including mBot, support several development modes, which can be chosen according to the desired level of difficulty, making them ideal for any user.

- **mBlock 5**: cooding tool that supports both Python and block programming via a dedicated browser platform. More information available at https://mblock.makeblock.com/en-us/
- **mBlock Blockly**: game-based programmable robot app that supports block programming, specifically designed for younger users. More information available at https://www.makeblock.com/software/mblock-app
- **Makeblock App**: all-in-1 controller for any Makeblock robots that supports multiple control modes and 3D modeling. More information available at https://www.makeblock.com/software/makeblock-app

The above development options have been listed for completeness purposes only. In fact, given the type of project being carried out, the development mode we have chosen is from scratch. In this regard, Makeblock provides a particularly comprehensive GitHub repository, accessible at https://github.com/Makeblock-official/Makeblock-Libraries

## Controller design

## Controller development

### Firmware refactoring

**MeWHeels class**

### Line following behavior

The first behavior that has been implemented is the mode that allows the robot to follow a black line drawn on the ground. The line-follower sensor is placed below the robot and consists of two sensors, both equipped with an infrared emitter, infrared receiver and a detection range of 1 to 2cm. The infrared emitter continually emits infrared light during the mBot moving: if the infrared light is reflected (encountering white or other light color surfaces), the receiver receives the infrared signal and output the value 1, if the infrared light is absorbed or cannot be reflected, the receiver will not receive the infrared signal but output the value 0.
The following table shows all four possible scenarios

| Case 1                                                                                                | Case 2                                                                                                                                  | Case 3                                                                                                                                  | Case 4                                                                                                                 |
| ----------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------- |
| <img height="250" src="https://drive.google.com/uc?export=view&id=1o2HyuJU_8iDzg89Bkogz3yebSaX4aUMc"> | <img height="250" src="https://drive.google.com/uc?export=view&id=1TijwBejeKzvTrgsoi45z_NsPoeojQDUL">                                   | <img height="250" src="https://drive.google.com/uc?export=view&id=1Depcz2jUsGjtVr_5oxeJX2HKvhep5G_z">                                   | <img height="250" src="https://drive.google.com/uc?export=view&id=16jpkEiu_sicN7yhg33FNrm5AUCvpVmyx">                  |
| mBot is on the black line, the value of the line-follower sensor is 0. The robot keeps moving foward  | mBot deviates from the black line to the right, the value of the line-follower sensor is 1. The robot turns left to find the black line | mBot deviates from the black line to the left, the value of the line-follower sensor is 2. The robot turns right to find the black line | mBot is not on the black line, the value of the line-follower sensor is 3. THe robot turns back to find the black line |

The program that allows the robot to assume the behavior of following the line basically consists of a switch that handles the above four cases, moving the wheels according to the value read from the sensors. Regarding the speed, after some tests we identified the following formula as the ideal way to calculate it

$$ speed= MAX\_SPEED * (1-{\vert direction \vert\over 10 }) $$

Where `MAX_SPEED` is a constant representing the maximum value of speed the robot can reach, which is 255. The calculation is done within the `computeSpeed()` method, which returns the minimum between the calculated speed and `MIN_SPEED`, a constant set to 230.

During our tests, we carried out several trials on different tracks to verify that the implementation was working as expected. The first track used was the one bundled with mBot, which is an infinity-shaped line printed on paper. Next, a track was made on cardboard using electrical tape, giving it a rectangular shape to test the robot's behavior in sharp turns. Finally, we turned to the construction of a more complex track that had the properties of the previous ones. The line was at first drawn using an indelible marker, but in this case the sensor was unable to detect it correctly, as the light was not refracted in any way. By redoing the tracing using a can of black paint, the robot was able to walk the line without any hiccups.

| Track 1                                                                                               | Track 2                                                                                                                                | Track 3                                                                                                                                  |
| ----------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------- |
| <img width="650" src="https://drive.google.com/uc?export=view&id=1VVzeHh6uENo4SxQycs6u5JeqdmkOHL9P"> | <img width="650" src="https://drive.google.com/uc?export=view&id=1XGQeXnBC5ACRlYf55nEEAwRyD4rd2x78">                                     | <img width="650" src="https://drive.google.com/uc?export=view&id=1tXyivJEmGDgJU8mMY4VuGNSvYleuGTAw">                                    |
|<a href="https://drive.google.com/file/d/111KmP_mfyQhs-e7-Xhquj9NTwerWya8x/view?usp=sharing">Link to the video</a><br>  | <a href="https://drive.google.com/file/d/1eC8OpXyJH8jLvrJn8K7qu9o_2jx-icFX/view?usp=sharing">Link to the video</a><br>                                     | <a href="https://drive.google.com/file/d/1GKMX8KEeZe8vkeV6XMvj6-Tru8w0QBOJ/view?usp=sharing">Link to the video</a><br>                                  |

### Obstacle avoidance behavior

## Control software analysis

## Conclusions and future work
