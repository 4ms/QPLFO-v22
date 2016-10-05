#QPLFO v2.2
(also known as QPLFO v3)

This code runs on the STM32F030 version of the QPLFO, which is the factory-assembled version after March 2016. This code will not work on any kit versions of the QPLFO, nor any PCBs labeled version 1.x (green PCBs).

Note that one of the SWD programming pins is also used for the UI, so once the code has been flashed, it is difficult to re-flash it. The best technique I've found is to hit the reset button on the PCB at the right moment just before flashing.

This project was began using the [STM32F030x4 Application Template] (https://github.com/MrSpock/stm32f030x-gcc-template) from Martin Jurczuk, which is highly based on Mike Szczys [STM32F0-DISCOVERY template] (https://github.com/szczys/stm32f0-discovery-basic-template)

