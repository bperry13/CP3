/**
* Implementation of several functions to manipulate BMP files.
*
* Completion time: ?
*
* @author Brett Perry, Ruben Acuna
* @version 1.24.22
*/

#include <stdio.h>
#include <stdlib.h>
#include "../hdr/BMPHandler.h"

/**
 * Read BMP header of a BMP file.
 *
 * @param  file: A pointer to the file being read
 * @param  header: Pointer to the destination BMP header
 */
void readBMPHeader(FILE* file, struct BMP_Header* header) {
    fread(&header->signature, sizeof(char) * 2, 1, file);
    fread(&header->size, sizeof(int), 1, file);
    fread(&header->reserved1, sizeof(short), 1, file);
    fread(&header->reserved2, sizeof(short), 1, file);
    fread(&header->offset_pixel_array, sizeof(int), 1, file);

    //display contents
    printf("signature: %c%c\n", header->signature[0], header->signature[1]);
    printf("size: %d\n", header->size);
    printf("reserved1: %d\n", header->reserved1);
    printf("reserved2: %d\n", header->reserved2);
    printf("offset_pixel_array: %d\n", header->offset_pixel_array);
}

/**
 * Write BMP header of a header. Useful for creating a BMP header.
 *
 * @param  header: A pointer to the header being written
 * @param  header: The header to write to the header
 */
void writeBMPHeader(FILE* file, struct BMP_Header* header) {
    fwrite(&header->signature, sizeof(char) * 2, 1, file);
    fwrite(&header->size, sizeof(int), 1, file);
    fwrite(&header->reserved1, sizeof(short), 1, file);
    fwrite(&header->reserved2, sizeof(short), 1, file);
    fwrite(&header->offset_pixel_array, sizeof(int), 1, file);

    printf("output signature: %c%c\n", header->signature[0], header->signature[1]);
    printf("output size: %d\n", header->size);
    printf("output reserved1: %d\n", header->reserved1);
    printf("output reserved2: %d\n", header->reserved2);
    printf("output offset_pixel_array: %d\n", header->offset_pixel_array);
}

/**
 * Read DIB header from a BMP file.
 *
 * @param  file: A pointer to the file being read
 * @param  header: Pointer to the destination DIB header
 */
void readDIBHeader(FILE* file, struct DIB_Header* header) {
    fread(&header->dib_size, sizeof(int), 1, file);
    fread(&header->image_width, sizeof(int), 1, file);
    fread(&header->image_height, sizeof(int), 1, file);
    fread(&header->planes, sizeof(char) * 2, 1, file);
    fread(&header->bits_per_pxl, sizeof(char) * 2, 1, file);
    fread(&header->compression, sizeof(int), 1, file);
    fread(&header->image_size, sizeof(int), 1, file);
    fread(&header->x_pxl_per_m, sizeof(int), 1, file);
    fread(&header->y_pxl_per_m, sizeof(int), 1, file);
    fread(&header->color_table, sizeof(int), 1, file);
    fread(&header->imp_color_count, sizeof(int), 1, file);

    printf("header dib size: %d\n", header->dib_size);
    printf("header dib image width: %d\n", header->image_width);
    printf("header dib image height: %d\n", header->image_height);
    printf("header dib planes: %d\n", header->planes);
    printf("header dib bits per pixel: %d\n", header->bits_per_pxl);
    printf("header dib compression: %d\n", header->compression);
    printf("header dib image size: %d\n", header->image_size);
    printf("header dib x pixel per meter: %d\n", header->x_pxl_per_m);
    printf("header dib y pixel per meter: %d\n", header->y_pxl_per_m);
    printf("header dib color table: %d\n", header->color_table);
    printf("header dib important color count: %d\n", header->imp_color_count);
}

/**
 * Write DIB header of a file. Useful for creating a BMP file.
 *
 * @param  file: A pointer to the file being written
 * @param  header: The header to write to the file
 */
void writeDIBHeader(FILE* file, struct DIB_Header* header) {
    fwrite(&header->dib_size, sizeof(int), 1, file);
    fwrite(&header->image_width, sizeof(int), 1, file);
    fwrite(&header->image_height, sizeof(int), 1, file);
    fwrite(&header->planes, sizeof(char) * 2, 1, file);
    fwrite(&header->bits_per_pxl, sizeof(char) * 2, 1, file);
    fwrite(&header->compression, sizeof(int), 1, file);
    fwrite(&header->image_size, sizeof(int), 1, file);
    fwrite(&header->x_pxl_per_m, sizeof(int), 1, file);
    fwrite(&header->y_pxl_per_m, sizeof(int), 1, file);
    fwrite(&header->color_table, sizeof(int), 1, file);
    fwrite(&header->imp_color_count, sizeof(int), 1, file);

    printf("output header dib size: %d\n", header->dib_size);
    printf("output header dib image width: %d\n", header->image_width);
    printf("output header dib image height: %d\n", header->image_height);
    printf("output header dib planes: %d\n", header->planes);
    printf("output header dib bits per pixel: %d\n", header->bits_per_pxl);
    printf("output header dib compression: %d\n", header->compression);
    printf("output header dib image size: %d\n", header->image_size);
    printf("output header dib x pixel per meter: %d\n", header->x_pxl_per_m);
    printf("output header dib y pixel per meter: %d\n", header->y_pxl_per_m);
    printf("output header dib color table: %d\n", header->color_table);
    printf("output header dib important color count: %d\n", header->imp_color_count);

}

/**
 * Make BMP header based on width and height. Useful for creating a BMP file.
 *
 * @param  header: Pointer to the destination DIB header
 * @param  width: Width of the image that this header is for
 * @param  height: Height of the image that this header is for
 */
//void makeBMPHeader(struct BMP_Header* header, int width, int height);

/**
* Make new DIB header based on width and height.Useful for creating a BMP file.
*
* @param  header: Pointer to the destination DIB header
* @param  width: Width of the image that this header is for
* @param  height: Height of the image that this header is for
*/
//void makeDIBHeader(struct DIB_Header* header, int width, int height);

/**
 * Read Pixels from BMP file based on width and height.
 *
 * @param  file: A pointer to the file being read
 * @param  pArr: Pixel array to store the pixels being read
 * @param  width: Width of the pixel array of this image
 * @param  height: Height of the pixel array of this image
 */
void readPixelsBMP(FILE* file, struct Pixel** pArr, int width, int height) {

}

/**
 * Write Pixels from BMP file based on width and height.
 *
 * @param  file: A pointer to the file being read or written
 * @param  pArr: Pixel array of the image to write to the file
 * @param  width: Width of the pixel array of this image
 * @param  height: Height of the pixel array of this image
 */
void writePixelsBMP(FILE* file, struct Pixel** pArr, int width, int height) {

}

