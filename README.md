# RexP1-Drive-Wheel

<img src="images/rexp1.png" alt="isolated" width="200"/>
Drive wheel for my RexP1 Astro Droid Project based on a RP2040Zero board. This Repo repreents the drive wheel subsystem for RexP1.

Checkout the [videos guides](https://www.youtube.com/playlist?list=PLspDyukWAtRUPNdlktaOdk7os9TfTEFh1) to the project over on my [YouTube Channel DrJonEA](https://youtube.com/@drjonea).
 
## RexP1 Intro
RexP1 is a reimagined Star War's inspired Astro Droid based on the R series Droids. It is based on Raspberry PI 5, RP2040 and RP2350 boards. It's control system is a distributed net based on ROS2 and MicroROS frameworks.

All my work on RexP1 is available to  my sponsors. That includes not just this submodule but all the submodules, the build instructions, PCB designs, STL files, CAD designs and most important acess to me to ask questions. Take a look at the sponsorship button on the github repo.

## The Repo
This repo includes the PCB design for the drive wheels and assoicated documentation. It also includes the firmware for a RP2040Zero which acts as a ROS2 Node to control the Wheel and some other sensors.

## Libraries
Note libraries have not been included as submodules in this repo. That is because I wanted just a single copy of the libraries in the master repo for RexP1. So take note of the [lib documentation](docs/Libraries.md).

## Build process
The firmware should build like most *complex* Pico SDK firmware projects. Normal procedure:
```
mkdir build
cd build
cmake ..
make
```
If you have ninja use that instead of make for Windows. Just make sure you update the CMakelists.txt to point to your libraries and that the environment variable PICO_SDK_PATH is defined to point to the SDK.


