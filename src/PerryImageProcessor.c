/**
 * write a program that applies three different Filters to an image. The image
 * will be loaded from a BMP File, specified by the user, and then be
 * transformed using:
 * 1) a grayscale conversion,
 * 2) a color shift also specified by the user, or
 * 3) a scale operation. The resulting File will be saved back to a
 *    BMP File that can be viewed on the system
*
* Completion time: ?
*
* @author Brett Perry, Ruben Acuna
* @version 1.24.22
*/

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "../hdr/BMPHandler.h"
#include "../hdr/Image.h"


int main(int argc, char *argv[]) {

    //format is ./PerryImageProcessor input_file filter -o output_file
    //i.e. ./PerryImageProcessor test2.bmp -g -o test2_gray.bmp
    //input parameters
    char *input = argv[optind + 1];
    char *output = argv[optind + 2];
    //get filter flag
    char* filters;
    filters = "gcs";
    //g = grayscale, c=color shift, s=scaling
    int filter, gflag = 0, cflag = 0, sflag = 0;
    int height, width;

    //header functionality
    struct BMP_Header bmp_header;
    struct DIB_Header dib_header;

    //open input file
    FILE* input_fp = fopen(input, "rb");
    if (input_fp == NULL) {
        printf("ERROR: File does not exist in your directory.");
        return EXIT_FAILURE;
    }

    //read bitmap bmp_header
    readBMPHeader(input_fp, &bmp_header);

    //read dib bmp_header
    readDIBHeader(input_fp, &dib_header);

    //allocate mem for pixels
    struct Pixel** pixels = (struct Pixel**)malloc(sizeof(struct Pixel*) * dib_header.image_width);
    for (int p = 0; p < dib_header.image_width; p++) {
        pixels[p] = (struct Pixel*)malloc(sizeof(struct Pixel) * dib_header.image_width);
    }

    //read pixel array
    readPixelsBMP(input_fp, pixels, dib_header.image_width, dib_header.image_height);

    fclose(input_fp);

    Image* img = image_create(pixels, dib_header.image_width, dib_header.image_height);

    while ((filter = getopt(argc, argv, filters)) != -1) {
        //confirm only one filter
        switch (filter) {
            case 'g':
                gflag = 1;
                printf("applying grayscale filter...\n");
                //image_apply_bw(img);
                break;
            case 'c':
                cflag = 1;
                printf("applying color shift filter...\n");
                break;
            case 's':
                sflag = 1;
                printf("applying scaling filter...\n");
                break;
            case '?':
                printf("Error: unknown filter -%c.\n", optopt);
                break;
            default:
                printf( "Error: default switch case.\n");
        }
    }

    //open output file
    FILE* output_fp = fopen(output, "wb");
    if (output_fp == NULL) {
        printf("ERROR: Output file not created.");
        return EXIT_FAILURE;
    }

    writeBMPHeader(output_fp, &bmp_header);
    writeDIBHeader(output_fp, &dib_header);
    writePixelsBMP(output_fp, pixels, dib_header.image_width, dib_header.image_height);
    image_destroy((Image **) img);
    fclose(output_fp);

    return 0;
}
