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
                <img height="250" src="https://drive.google.com/uc?export=view&id=1fV3h-D6ATuJwflhDP8jxG3BIhxFH27jf">
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
                <img height="250" src="https://drive.google.com/uc?export=view&id=1KF2s55cbdmwdAdRxurueLzvAnRS-Si5j">
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
                <img height="250" src="https://drive.google.com/uc?export=view&id=1WOvLLYx-pIQsI6A6rFICLVA0HmraIE_E">
            </td>
            <td>
                <ul>
                    <li>Uses Arduino as its mainboard</li>
                    <li>Very solid chassis that protects every sensor</li>
                    <li>asdasd</li>
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
                <img height="250" src="https://drive.google.com/uc?export=view&id=1ROB8XoqZokn4gsE7J6WCTK1rMLIp6gml">
            </td>
            <td>
                <ul>
                    <li>Uses Arduino as its mainboard</li>
                    <li>Very solid chassis that protects every sensor</li>
                    <li>asdasd</li>
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
                <strong>OSOYOO V2.1 Smart Robot Car Kit for Arduino</strong><br>
                <a href="https://amzn.to/3tc00Sb">https://amzn.to/3tc00Sb</a><br>
                <img height="250" src="https://drive.google.com/uc?export=view&id=1G1MLzwOc9xPzwSLPTIT6QSm9QR1fnFY6">
            </td>
            <td>
                <ul>
                    <li>asdasd</li>
                    <li>asdasd</li>
                    <li>asdasd</li>
                </ul>
            </td>
            <td>
                <ul>
                    <li>asdasd</li>
                    <li>asdasd</li>
                    <li>asdasd</li>
                </ul>
            </td>
        </tr>
        <tr>
            <td>
                <strong>OSOYOO Robotic Car for Raspberry Pi 4 3B + 3B</strong><br>
                <a href="https://amzn.to/3yMlRmF">https://amzn.to/3yMlRmF</a><br>
                <img height="250" src="https://drive.google.com/uc?export=view&id=1fujrBIhGpEm7pkfz3-Egj0sEaiDUlt3j">
            </td>
            <td>
                <ul>
                    <li>asdasd</li>
                    <li>asdasd</li>
                    <li>asdasd</li>
                </ul>
            </td>
            <td>
                <ul>
                    <li>asdasd</li>
                    <li>asdasd</li>
                    <li>asdasd</li>
                </ul>
            </td>
        </tr>
    </tbody>
</table>

### Our choice

## Robot kit analysis

### Hardware

### Software

## Controller design

## Controller development

### Firmware refactoring

**MeWHeels class**

### Line following behavior

### Obstacle avoidance behavior

## Control software analysis

## Conclusions and future work