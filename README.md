# Embedded System and Internet of Things - Assigments

**77780 - Academic Year 2024/25, Bachelor's Degree in Computer Science and Engineering, University of Bologna - Cesena Campus**  
- **Instructors**: Professors Alessandro Ricci
- **Programming Language**: C/C++

## Overview

This repository contains three assignments focused on Arduino, designed to help you learn and practice using the platform. Each assignment introduces different aspects of Arduino programming and hardware interaction, providing hands-on experience to build your skills step by step.

<details>
  <summary>
    Assignment #1
  </summary>
  
  ## Turn on the Sequence!
  We want to create an embedded system that implements a game called "Turn on the Sequence!" The game board is based on 4 green LEDs (L1, L2, L3, L4), a red LED (LS), 4 tactile buttons (B1, B2, B3, B4) and a potentiometer.
  
  In the initial state, all green LEDs are off, but the LS LED is pulsing (fading in and out), waiting for a player to start the game. If/when button B1 is pressed, the game will start. If button B1 is not pressed within 10 seconds, the system goes into deep sleep. The system can be woken up by pressing any button. Once woken up, the system returns to its initial state and LED Ls starts pulsing again.
  
  During the game, the system repeatedly displays on the LCD a number of 4 distinct digits, each digit in the range between 1 and 4.
  The player must turn on the leds in the order defined by the digits, from left to right, using the corresponding tactile buttons.
  If the player has switched on the lights in time and in the correct order, the game continues by reducing the time by a factor called F.  
  If the player does not switch on the lights in the correct order, the red LED L lights up for 2 second and the game ends, then the game restarts from the beginning.
  
  Before starting the game, the difficulty level can be set with the potentiometer. This can be a value in the range 1..4 (1 being the easiest, 4 being the most difficult). The level must have an effect on the value of the factor F (so the more difficult the game, the higher the factor F must be).
</details>

<details>
  <summary>
    Assignment #2
  </summary>

  ## Drone Hangar System

  This project implements a simple automated hangar for a drone.  
  The system is made of two parts:  
  - an **Arduino subsystem (Drone Hangar)**, which controls sensors, LEDs, the door, and the LCD  
  - a **PC application (Drone Remote Unit, DRU)**, which sends commands and shows system status

  ### Basic Behavior
  At startup, the hangar door is closed and the drone is assumed to be inside.   LED L1 is on, L2 and L3 are off, and the LCD shows **DRONE INSIDE**.

  ### Take-off
  The drone sends a take-off command through the DRU. The door opens, L2 blinks, and the LCD shows **TAKE OFF**. When the distance sensor detects that the drone has left (distance > D1 for T1 seconds), the door closes and the LCD shows **DRONE OUT**.

  ### Landing
  When approaching the hangar, the drone sends an open-door command again. If the presence sensor detects the drone, the door opens and the LCD shows **LANDING**. When the drone is inside (distance < D2 for T2 seconds), the door closes and the LCD shows **DRONE INSIDE**.

  ### Temperature Safety
  When the drone is inside, the hangar monitors temperature:
  - If temperature ≥ Temp1 for T3 seconds → **pre-alarm** (new operations blocked)
  - If temperature ≥ Temp2 for T4 seconds → **ALARM**, the door closes, L3 turns on, and all actions stop  
    The system returns to normal only after pressing **RESET**.

  ### DRU (Remote Unit)
  The PC GUI allows you to:
  - send **take-off** and **landing** commands  
  - see the drone state and the hangar state  
  - view the distance during landing

</details>

<details>
  <summary>
    Assignment #3
  </summary>

  ## Smart Tank Monitoring

  The system monitors and automatically controls the level of a tank and provides tools for supervision, local control, and human intervention in case of anomalies. It periodically measures the level (TMS) and transmits reliable measurement data and heartbeat signals. It evaluates time-based level policies (CUS) and actuates the valve automatically at 50% or 100%, avoiding reactions to transients. Valve commands are executed by the valve control subsystem (WCS) supporting local MANUAL and AUTONOMOUS modes, converting percentage commands into actuator angles and providing acknowledgements and status. A dashboard (DBS) provides a graph of recent measurements, system status, and operator commands via a REST API. Robustness is ensured through timeouts, retry/reconnect mechanisms for MQTT and serial links, propagation of UNCONNECTED/NOT AVAILABLE states, logging, and recovery procedures. The system supports reproducible testing and validation with documented parameters and scenarios for data loss or serial disconnection.

</details>
