// Reverses a .wav audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int main(int argc, char *argv[])
{
    // Ensure proper program usage
    if (argc != 3)
    {
        printf("Usage: ./volume input.wav output.wav\n");
        return 1;
    }

    // Open files
    FILE *input = fopen(argv[1], "rb");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "wb");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // Copy header from input file to output file
    WAVHEADER header;
    fread(&header, 1, sizeof(WAVHEADER), input);

    if (fwrite(&header, 1, sizeof(WAVHEADER), output) != sizeof(WAVHEADER))
    {
        printf("Error writing header.\n");
        return 1;
    }

    // Get the size of the audio file
    if (fseek(input, 0, SEEK_END) != 0) {
        printf("Could not determine file size.\n");
        return 1;
    }

    int total_size = ftell(input) - sizeof(WAVHEADER);

    // Allocate memory for an array that stores the audio data
    int16_t *buffer = malloc(total_size);
    if (buffer == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Set the file pointer to the start of the audio data
    fseek(input, sizeof(WAVHEADER), SEEK_SET);

    // Read the audio data into the buffer
    if (fread(buffer, sizeof(int16_t), total_size / sizeof(int16_t), input) < total_size / sizeof(int16_t))
    {
        printf("Could not read all audio data.\n");
        return 1;
    }

    // Reverse the audio data array
    int start = 0;
    int end = total_size / sizeof(int16_t) - 1;

    while (start < end)
    {
        int16_t tmp = buffer[start];
        buffer[start] = buffer[end];
        buffer[end] = tmp;
        start++;
        end--;
    }

    // Write reversed audio data to output file
    if (fwrite(buffer, sizeof(int16_t), total_size / sizeof(int16_t), output) < total_size / sizeof(int16_t))
    {
        printf("Could not write all audio data.\n");
        return 1;
    }

    // Close files and free memory
    fclose(input);
    fclose(output);
    free(buffer);
}