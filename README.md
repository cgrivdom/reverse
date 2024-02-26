# Reverse

<img src="https://socialify.git.ci/cgrd1/reverse/image?font=Source%20Code%20Pro&language=1&name=1&owner=1&pattern=Floating%20Cogs&theme=Dark" alt="project-image">

## Description:
**Reverse** is a C program that reverses a WAV audio file.

## Usage:

With `gcc`,`clang` or any C programming IDE or compiler running on a local machine, the user should compile the program and enter the command `./reverse input.wav output.wav` on a terminal window to execute the program, making sure to enter the command after moving into the program directory via `cd reverse` and making sure to rename the desired WAV file to reverse exactly as `input.wav`, which should also be stored inside the `reverse` directory.

The program will handle any errors that may arise like failling to properly execute or failling to read any audio data.

## Contents of the project:

**Reverse** is comprised of three different files:

`reverse.c` -> This is the main file that runs the program, it contains the logic for reversing the desired WAV audio file.

`wav.h` -> The purpose of this header file is to provide a struct called `WAVHEADER` that can be used to read and rewrite the header of the WAV audio file.

`README.md` -> Provides an overview of the project.

## Generated files: 

**Reverse** outputs a WAV audio file called `output.wav` that contains the same audio data as `input.wav` but in reverse order.

## Design choices:

**The following section discusses the implementation of the project and it does not contain any relevant information about the usage of the program.**

`reverse.c:`

When the user runs the program, standard and `wav.h` libraries are loaded.

The program continues by starting its `main` function which makes sure to properly provide its command-line arguments to run.

`main` continues by opening the corresponding `input.wav` audio file and creating the resulting `output.wav` audio file which will be created upon execution.

The next steps that `main` handles are copying the header from the input file to the output file and getting the size of the `input.wav` audio file.

Afterwards, `main` allocates memory for an array that stores the audio data and sets the file pointer to the start of the audio data in `input.wav`, as well as reading the audio data into a `buffer`

The program finally ends with the reversing of the audio data array by using a temporary variable approach and incrementing/decrementing a start/end set of variables, to finally write the reversed audio data to the output file as well as properly closing the audio files and freeing the allocated memory for the `buffer`