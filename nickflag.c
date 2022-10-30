/* Fall 2022 Lab 8
*/

#include <stdio.h>
#include <string.h>


typedef struct {

char type[4]; 
int width, height, maxColor; 

}header; 


typedef struct {

unsigned int r, g, b; 

}pixel;

int getWidth();
void writeHeader(header);
void fillFlagArray(pixel flag[],int width,int height); 
void writePixels(pixel flag[],int width,int height); 

int main (void){
	int width, height, i, j, k = 0;  // k is used for the array
	header dimensions; 
	pixel colors; 

	fprintf(stderr, "\n\nFlag of Ireland");
	fprintf(stderr, "\n\tWhat width do you want the flag to be? ");
	// 1. get the user's input for width
	width = getWidth(); 	
	// 2. calculate the height based on the proportion stated on Wikipedia
	
	height =width/2;
	fprintf(stderr, "\n\nMaking the flag with width %d & height %d ...",width,height);
	fprintf(stderr, "\n\n");

	dimensions.width = width; 
	dimensions.height = height;
	dimensions.maxColor = 255;

	// 3. declare an array of type:  unsigned int
		
	pixel flag[width*height];

	// write to stdout the ppm header values 

	writeHeader(dimensions);

	// 4. nested for loops for writing the pixel data:
	fillFlagArray(flag, width, height);
		

	// 5. print the contents of the array to stdout, so with redirection,
	writePixels(flag, width, height);


	return 0;
}

int getWidth(){
	int width;
	scanf("%d", &width); 	
	return width; 
	}

void writeHeader(header dimensions){
	strcpy(dimensions.type, "P3"); 
	fprintf(stdout, "%s\n", dimensions.type);
	fprintf(stdout, "%d %d %d\n", dimensions.width, dimensions.height, 255);

	}

void fillFlagArray(pixel flag[],int width,int height){
	int k=0; 
	pixel colors;
	for (int i=0; i<height; i++ ) {
		int j;
	   for (j=0; j<width/3; j++ ) {
			colors.r= 0;
			colors.g= 128;
			colors.b= 0; 
			flag[k++]= colors;
		}
		for (; j<width*2/3; j++ ) {
			colors.r= 255;
			colors.g= 255;
			colors.b= 255;
			flag[k++]= colors;
		}
		for (; j<width; j++ ) {
			colors.r= 255;
			colors.g= 165;
			colors.b= 0;
			flag[k++]= colors;
		}
	}

}

void writePixels(pixel flag[],int width,int height){
	for (int i=0; i<width*height; i++) {
		fprintf(stdout, "%i %i %i\n", flag[i].r, flag[i].g, flag[i].b); 
	}
} 
