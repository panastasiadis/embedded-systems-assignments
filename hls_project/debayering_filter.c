#include "debayering_filter.h"

#define N 256

void debayering_filter(unsigned char pixels[N][N], unsigned char output_pixels[N][N][3]){

#pragma HLS ARRAY_PARTITION variable=pixels cyclic factor=2 dim=0

    unsigned char r,g,b;
    enum RGB color = Red;

    // we ignore row = 0, column = 0, row = 256, column = 256
    // we can't get 3x3 for these rows and columns
    for(int row = 1; row < N-1; row++){
		#pragma HLS unroll factor=2
        for(int column = 1; column < N-1; column++){
			#pragma HLS pipeline II=3
            // identify which value was stored from {R, G, B}
            if((row % 2) == 0 && (column % 2) == 0){
                color = Green;
            }
            else if((row % 2) == 0 && (column % 2) == 1){
                color = Blue;
            }
            else if((row % 2) == 1 && (column % 2) == 0){
            	color = Red;
            }
            else if((row % 2) == 1 && (column % 2) == 1){
            	color = Green;
            }

            // get 3x3 neighbors, our pixel is the middle one [1][1]
            unsigned char matrix[3][3];

            matrix[0][0] = pixels[row-1][column-1];
            matrix[0][1] = pixels[row-1][column];
            matrix[0][2] = pixels[row-1][column+1];

            matrix[1][0] = pixels[row][column-1];
            matrix[1][1] = pixels[row][column];
            matrix[1][2] = pixels[row][column+1];

            matrix[2][0] = pixels[row+1][column-1];
            matrix[2][1] = pixels[row+1][column];
            matrix[2][2] = pixels[row+1][column+1];

            // Calculate RGB values based on color
            if(color == Red){
			// #pragma HLS occurrence cycle=4
                r =  matrix[1][1];
                g = (matrix[0][1] + matrix[1][0] + matrix[1][2] + matrix[2][1]) / 4;
                b = (matrix[0][0] + matrix[0][2] + matrix[2][0] + matrix[2][2]) / 4;
            }
            else if(color == Green){
            // #pragma HLS occurrence cycle=2
            	r = (matrix[1][0] + matrix[1][2]) / 2;
                g = matrix[1][1];
                b = (matrix[0][1] + matrix[2][1]) / 2;
            }
            else if(color == Blue){
			// #pragma HLS occurrence cycle=4
            	r = (matrix[0][0] + matrix[0][2] + matrix[2][0] + matrix[2][2]) / 4;
                g = (matrix[0][1] + matrix[1][0] + matrix[1][2] + matrix[2][1]) / 4;
                b = matrix[1][1];
            }

            // Store RGB values in output_pixels
            output_pixels[row][column][0] = r;
            output_pixels[row][column][1] = g;
            output_pixels[row][column][2] = b;
        }
        // Calculate perimeter RGB values for col = 0 and col = N-1
        output_pixels[row][0][0] = output_pixels[row][1][0];
        output_pixels[row][0][1] = output_pixels[row][1][1];
        output_pixels[row][0][2] = output_pixels[row][1][2];

        output_pixels[row][N - 1][0] =  output_pixels[row][N - 2][0];
        output_pixels[row][N - 1][1] =  output_pixels[row][N - 2][1];
        output_pixels[row][N - 1][2] =  output_pixels[row][N - 2][2];


    }

    // Calculate perimeter RGB values for the first and last row
    for (int column = 0; column < N; column++) {
//		 #pragma HLS pipeline II=1
//		 #pragma HLS  unroll factor=2

        output_pixels[0][column][0] = output_pixels[1][column][0];
        output_pixels[0][column][1] = output_pixels[1][column][1];
        output_pixels[0][column][2] = output_pixels[1][column][2];

        output_pixels[N - 1][column][0] = output_pixels[N - 2][column][0];
        output_pixels[N - 1][column][1] = output_pixels[N - 2][column][1];
        output_pixels[N - 1][column][2] = output_pixels[N - 2][column][2];
    }

}
