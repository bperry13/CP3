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

    //g = grayscale, c=color shift, s=scaling
    int filter, gflag = 0, cflag = 0, sflag = 0;
    char* filters;

    
    //get filter flag
    filters = "gcs";
    while ((filter = getopt(argc, argv, filters)) != -1) {
        //confirm only one filter
        switch (filter) {
            case 'g':
                gflag = 1;
                printf("applying grayscale filter...\n");
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

    //vars for file names
    char *input = argv[optind];
    char *output = argv[optind + 1];

    //open input file
    FILE* input_fp = fopen(input, "rb");
    if (input_fp == NULL) {
        printf("ERROR: File does not exist in your directory.");
        return EXIT_FAILURE;
    }

    //open output file
    FILE* output_fp = fopen(output, "w");
    if (output_fp == NULL) {
        printf("ERROR: Output file not created.");
        return EXIT_FAILURE;
    }

    struct BMP_Header bmp_header;
    struct DIB_Header dib_header;

    //read bitmap bmp_header
    readBMPHeader(input_fp, &bmp_header);

    //read dib bmp_header
    readDIBHeader(input_fp, &dib_header);

    //read a single pixel. (format is BGR)
    unsigned char r, g, b;

    //1st pixel
    fread(&b, sizeof(char), 1, input_fp);
    fread(&g, sizeof(char), 1, input_fp);
    fread(&r, sizeof(char), 1, input_fp);
    printf("color: B=%d, G=%d, R=%d\n", b, g, r);

    //2nd pixel
    fread(&b, sizeof(char), 1, input_fp);
    fread(&g, sizeof(char), 1, input_fp);
    fread(&r, sizeof(char), 1, input_fp);
    printf("color: B=%d, G=%d, R=%d\n", b, g, r);

    //two pixel pad in the file here
    fseek(input_fp, sizeof(unsigned char) * 2, SEEK_CUR);

    //3rd pixel
    fread(&b, sizeof(char), 1, input_fp);
    fread(&g, sizeof(char), 1, input_fp);
    fread(&r, sizeof(char), 1, input_fp);
    printf("color: B=%d, G=%d, R=%d\n", b, g, r);

    //4th pixel
    fread(&b, sizeof(char), 1, input_fp);
    fread(&g, sizeof(char), 1, input_fp);
    fread(&r, sizeof(char), 1, input_fp);
    printf("color: B=%d, G=%d, R=%d\n", b, g, r);

    //short writing example wb=write binary
    /*
    FILE* outptr = fopen(output, "wb");
    fwrite(&bmp_header.signature, sizeof(char) * 2, 1, outptr);
    fwrite(&bmp_header.size, sizeof(int), 1, outptr);
    fwrite(&bmp_header.reserved1, sizeof(short), 1, outptr);
    fwrite(&bmp_header.reserved2, sizeof(short), 1, outptr);
    fwrite(&bmp_header.offset_pixel_array, sizeof(int), 1, outptr);

    fwrite(&dib_header, sizeof(char), 40, outptr);
    */

    fclose(input_fp);
    fclose(output_fp);

    return 0;
}
