#ifndef DEBAYERING_FILTER
#define DEBAYERING_FILTER
#define N 256

enum RGB {Red = 0, Green = 1, Blue = 2};

void debayering_filter(unsigned char pixels[N][N],unsigned char output_pixels[N][N][3]);

#endif
