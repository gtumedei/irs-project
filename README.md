![](https://drive.google.com/uc?export=view&id=1E8WtqZvkqsAqdkPyTNI4E6NSMvSlagp9)

<h1 align="center">
  Possibilities and Limitations of Switching from a Robot Simulator to a Real-World Scenario
</h1>

![](https://drive.google.com/uc?export=view&id=1lmTIVMaEcnv2D_NmNa49LbAqFAn7RR0O)

## Project report

This is a project for the [Intelligent Robotics Systems](https://www.unibo.it/it/didattica/insegnamenti/insegnamento/2020/447106) 2021/22 course of the University of Bologna.\
The project's report is included in this repository in [markdown format](./docs/report.md) and uploaded as a release in [PDF format](https://github.com/gtumedei/irs-project/releases/download/1.0.0/report.pdf).

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