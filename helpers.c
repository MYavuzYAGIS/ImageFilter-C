#include "helpers.h"
#include <math.h>

// image is a 2D array where Dimensions are height and width. the image is height rows long and witdh columns wide. Width is array within height.

// We have to make sure that the RGB does not overflow!


int NoFlow(int rounded){
    if(rounded> 255){
        rounded=255;
    }
    return rounded;
}

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float average;
        // so since all the gray tones are RGBs that are close to each other, I took the mean value and reassigned to each channel of colors.
    for(int i = 0; i < width; i++ ){
        for(int j =0; j<height;j++){
            average = round((image[j][i].rgbtBlue + image[j][i].rgbtGreen +image[j][i].rgbtRed)/3.00);
            image[j][i].rgbtBlue = average;
            image[j][i].rgbtGreen = average;
            image[j][i].rgbtRed = average;
        }
    }
}


// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
      // lets introduce the new values
        int sBlue; 
        int sRed;
        int sGreen;

        for(int i=0; i<width; i++){
            for(int j=0; j<height; j++){
                sBlue = NoFlow(round(0.272 * image[j][i].rgbtRed + 0.534 * image[j][i].rgbtGreen + 0.131*image[j][i].rgbtBlue));
                sGreen = NoFlow(round(0.349 * image[j][i].rgbtRed + 0.686 * image[j][i].rgbtGreen + 0.168*image[j][i].rgbtBlue));
                sRed = NoFlow(round(0.393 * image[j][i].rgbtRed + 0.769 * image[j][i].rgbtGreen + 0.189*image[j][i].rgbtBlue));

                image[j][i].rgbtBlue = sBlue;
                image[j][i].rgbtGreen = sGreen;
                image[j][i].rgbtRed = sRed;

            }
        }        



}

// Reflect image horizontally
 void reflect(int height, int width, RGBTRIPLE image[height][width])
 {
     //here task is to keep height in its order but convert each element wihthin the height into reverse.
     // if there is odd amount of elememts, then middle should stay stable
     // else, all of them should switch places.

     // took some help from here :https://www.techiedelight.com/reverse-array-c/

  int tmp[3];
    
    for (int i =0; i<height;i++){
        for(int j=0; j<width/2;j++) // we are not interested with the one in the middle.
        {   

            tmp[0] = image[i][j].rgbtBlue;
            tmp[1] = image[i][j].rgbtGreen;
            tmp[2] = image[i][j].rgbtRed;


            // now instead of swapping the pixels themselves, we can simply copy the corresponding pixel

            image[i][j].rgbtBlue = image[i][width-j-1].rgbtBlue;
            image[i][j].rgbtGreen = image[i][width-j-1].rgbtGreen;
            image[i][j].rgbtRed = image[i][width-j-1].rgbtRed;

            // Soo the pixel colors are swapped. Now it is time to rebuild the image

            image[i][width-j-1].rgbtBlue = tmp[0];
            image[i][width-j-1].rgbtGreen = tmp[1];
            image[i][width-j-1].rgbtRed = tmp[2];


        }
    }    






 }

// Blur image

// tough Part :D
 void blur(int height, int width, RGBTRIPLE image[height][width])
 {
     // Could not handle, Skipping!
 }
