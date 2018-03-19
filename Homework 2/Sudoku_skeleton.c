/**
 * A skeleton for checking a Sudoku puzzle through multithread

 */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>


#define NUMBER_OF_THREADS 	9 // we use 9 threads in this project
#define PUZZLE_SIZE 		9  // it is a 9x9 puzzle


/* example puzzle */

// this is a sample table, the values will be replaced by those read from the input file, except -1
int puzzle[PUZZLE_SIZE+1][PUZZLE_SIZE+1] = {
			{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
			{-1,5,3,4,6,7,8,9,1,2},
			{-1,6,7,2,1,9,5,3,4,8},
			{-1,1,9,8,3,4,2,5,6,7},
			{-1,8,5,9,7,6,1,4,2,3},
			{-1,4,2,6,8,5,3,7,9,1},
			{-1,7,1,3,9,2,4,8,5,6},
			{-1,9,6,1,5,3,7,2,8,4},
			{-1,2,8,7,4,1,9,6,3,5},
			{-1,3,4,5,2,8,6,1,7,9}
		};


int status_map[NUMBER_OF_THREADS] = {0};

/* data structure for passing data to threads */
typedef struct
{
	int thread_number;
	int x;
	int y;
} parameters;

int main(int argc, char *argv[])
{
	// get a puzzle from a txt file, which needs to be input from command line
	char filename[100];
	printf("Please enter your filename:\n");
	scanf("%s",filename);

  FILE *myFile;
  myFile = fopen(filename, "r");

   //read file into array
   int i,j;

   if (myFile == NULL)
   {
       printf("Error Reading File\n");
       exit (0);
   }
   for (i = 1; i < PUZZLE_SIZE + 1; i++)
   {
		for (j =1; j < PUZZLE_SIZE + 1; j++)
		{
			fscanf(myFile, "%d,", &puzzle[i][j] );
		}

   }

	pthread_t workers[NUMBER_OF_THREADS];

    //create the 3 threads for row check


    //create the 3 threads for column check


    //create the 9 threads for the 9 subfields


	//wait for the threads to exit and check the result and print


	return 0;
}


