# Collection of Embedded Systems Projects

This repository contains projects developed for the course "Προγραμματισμός Ενσωματωμένων Συστημάτων σε περιβάλλοντα Edge" (Embedded Systems Programming in Edge Environments).

## Project Overview

This repository consists of three main projects that demonstrate different aspects of embedded systems programming:

1. **HLS Project**: High-Level Synthesis implementation of a Debayering filter for image processing
2. **Arduino Project**: Client service system using Arduino with buttons and LED indicators
3. **Verilog Project**: Hardware description language implementation of the client service system

## HLS Project - Debayering Filter for Image Processing

### Description
A High-Level Synthesis (HLS) project that implements a Debayering filter for image processing. The project demonstrates the conversion of a Bayer-patterned image to a full RGB image using both Python and C, with the C implementation optimized for hardware synthesis using HLS pragmas.

### Workflow
- **Step 1:** Use the Jupyter notebook (`transform_image.ipynb`) to:
  - Convert an RGB image to a Bayer pattern and save it as a binary text file (`image_8bit.txt`).
  - (Optional) Reconstruct the RGB image in Python for verification.
- **Step 2:** The C implementation (`debayering_filter.c` and `debayering_filter.h`) reads the Bayer-patterned image, applies the Debayering algorithm, and reconstructs the RGB image. HLS pragmas are used to optimize the code for hardware synthesis.
- **Step 3:** The test program (`debayering_filter_test.c`) automates reading the input, running the filter, and saving the output RGB values to `output.txt`.
- **Step 4:** The notebook can also reconstruct and visualize the output image from the C implementation for comparison.

### Features
- Implements a 3x3 neighborhood Debayering algorithm
- HLS pragmas for loop unrolling and pipelining to optimize for FPGA/ASIC synthesis
- Python scripts for data preparation and verification
- Supports 256x256 pixel images (configurable in code)
- Sample images (`mountains.jpg`, `ravi.jpg`) provided for testing

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
