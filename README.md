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
