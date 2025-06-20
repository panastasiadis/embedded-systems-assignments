#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "debayering_filter.h"
//enum RGB {Red = 0, Green = 1, Blue = 2};
#define N 256

int main() {
    unsigned char pixels[N][N];

    // open txt file
    FILE *file = fopen("image_8bit.txt", "r"); // Open the text file for reading
    if (file == NULL) {
        printf("Error opening image_8bit file.\n");
        return 1;
    }

    int row = 0;
    int column = 0;

    char ch;
    int count = 0;
    char pixel[9];

    // transform 8-bit to int and save in array
    while ((ch = fgetc(file)) != EOF) {

        if(ch == '\n'){
            row += 1;
            column = 0;
            continue;
        }

        if(ch == ' '){
            pixel[count] = '\0';

            unsigned char val = strtol(pixel, NULL, 2);

            pixels[row][column] = val;
            column += 1;
            count = 0;

            continue;
        }

        pixel[count] = ch;
        count += 1;
    }

    // close file, not needed anymore
    if (fclose(file)) 
        perror("fclose error");
    else printf("File image_8bit closed successfully.\n");


    unsigned char output_pixels[N][N][3];

    // get calculated RGB values
    debayering_filter(pixels, output_pixels);

    // open file to save the output
    FILE *outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    // pass the new values in txt
    for(int r = 0; r < N; r++){
        for(int c = 0; c < N; c++){

            fprintf(outputFile, "%c", '(');
            fprintf(outputFile, "%d",  output_pixels[r][c][0]);
            fprintf(outputFile, "%c", ',');
            fprintf(outputFile, "%d",  output_pixels[r][c][1]);
            fprintf(outputFile, "%c", ',');
            fprintf(outputFile, "%d",  output_pixels[r][c][2]);
            fprintf(outputFile, "%c", ')');
            fprintf(outputFile, "%c", ' ');

        }

        fprintf(outputFile, "%c", '\n');
    }

    // close file, not needed anymore
    if (fclose(outputFile))   
      perror("fclose error");
    else printf("File output closed successfully.\n");


    return 0;
}
