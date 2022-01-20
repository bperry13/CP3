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
#include "../hdr/BMPHandler.h"
#include "../hdr/Image.h"


int main(int argc, char *argv[]) {


    //vars for file names
    char *file_input = argv[0];
    char *file_output = argv[1];
    char *filter = argv[2];

    //open file
    FILE* file_input = fopen(argv[1], "rb");
    if (file_input == NULL) {
        printf("ERROR: File does not exist in your directory.");
        return EXIT_FAILURE;
    }
    struct BMP_Header header;
    struct DIB_Header header_dib;

    //read bitmap header
    fread(&header.signature, sizeof(char) * 2, 1, file_input);
    fread(&header.size, sizeof(int), 1, file_input);
    fread(&header.reserved1, sizeof(short), 1, file_input);
    fread(&header.reserved2, sizeof(short), 1, file_input);
    fread(&header.offset_pixel_array, sizeof(int), 1, file_input);

    //display contents
    printf("signature: %c%c\n", header.signature[0], header.signature[1]);
    printf("size: %d\n", header.size);
    printf("reserved1: %d\n", header.reserved1);
    printf("reserved2: %d\n", header.reserved2);
    printf("offset_pixel_array: %d\n", header.offset_pixel_array);

    fread(&header_dib, sizeof(char), 40, file_input);

    //read a single pixel. (format is BGR)
    unsigned char r, g, b;

    //1st pixel
    fread(&b, sizeof(char), 1, file_input);
    fread(&g, sizeof(char), 1, file_input);
    fread(&r, sizeof(char), 1, file_input);
    printf("color: B=%d, G=%d, R=%d\n", b, g, r);

    //2nd pixel
    fread(&b, sizeof(char), 1, file_input);
    fread(&g, sizeof(char), 1, file_input);
    fread(&r, sizeof(char), 1, file_input);
    printf("color: B=%d, G=%d, R=%d\n", b, g, r);

    //two pixel pad in the file here
    fseek(file_input, sizeof(unsigned char) * 2, SEEK_CUR);

    //3rd pixel
    fread(&b, sizeof(char), 1, file_input);
    fread(&g, sizeof(char), 1, file_input);
    fread(&r, sizeof(char), 1, file_input);
    printf("color: B=%d, G=%d, R=%d\n", b, g, r);

    //4th pixel
    fread(&b, sizeof(char), 1, file_input);
    fread(&g, sizeof(char), 1, file_input);
    fread(&r, sizeof(char), 1, file_input);
    printf("color: B=%d, G=%d, R=%d\n", b, g, r);

    //short writing example wb=write binary
    FILE* file_output = fopen("output.bmp", "wb");
    fwrite(&header.signature, sizeof(char) * 2, 1, file_output);
    fwrite(&header.size, sizeof(int), 1, file_output);
    fwrite(&header.reserved1, sizeof(short), 1, file_output);
    fwrite(&header.reserved2, sizeof(short), 1, file_output);
    fwrite(&header.offset_pixel_array, sizeof(int), 1, file_output);

    fwrite(&header_dib, sizeof(char), 40, file_output);


    fclose(file_input);
    fclose(file_output);

    return 0;
}
