# Collection of Embedded Systems Assignments

This repository contains projects developed for the course "Προγραμματισμός Ενσωματωμένων Συστημάτων σε περιβάλλοντα Edge" (Embedded Systems Programming in Edge Environments).

## Project Overview

This repository consists of three main projects that demonstrate different aspects of embedded systems programming:

1. **HLS Project**: High-Level Synthesis implementation of a Debayering filter for image processing
2. **Arduino Project**: Client service system using Arduino with buttons and LED indicators
3. **Verilog Project**: Hardware description language implementation of the client service system

### Files
- **`transform_image.ipynb`**: Jupyter notebook containing three scripts:
  - Script 1: Converts RGB images to Bayer pattern format
  - Script 2: Implements debayering algorithm in Python
  - Script 3: Reconstructs images from processed RGB values
- **`debayering_filter.c`**: C implementation with HLS pragmas for hardware synthesis
- **`debayering_filter.h`**: Header file defining the filter interface
- **`debayering_filter_test.c`**: Test program for the C implementation
- **Sample Images**: `mountains.jpg` and `ravi.jpg` for testing

## Arduino Project - Client Service System

### Description
An Arduino-based client service system that manages a queue of clients using buttons and LED indicators. The system tracks the current client being served and the total number of clients in the queue.

### Features
- **Buttons**: New Client, Done, Reset
- **LED Indicators**: 
  - 7 LEDs for total clients count
  - 7 LEDs for current client number
  - 1 LED for "full" status
- **Serial Output**: Debug information via Serial Monitor

### Hardware Requirements
- Arduino board
- 3 push buttons (connected to A0, A1, A2)
- 15 LEDs (7 for total clients, 7 for current client, 1 for full status)
- Appropriate resistors

## Verilog Project - Client Service System

### Description
Hardware description language implementation of the same client service system, designed for FPGA synthesis and simulation.

### Files
- **`design.sv`**: SystemVerilog module implementing the client service logic
- **`testbench.sv`**: Comprehensive testbench for simulation and verification

### Features
- Same functionality as the Arduino version
- Hardware-optimized design
- Comprehensive testbench with multiple test scenarios
- Support for up to 100 clients (configurable)
