#include "kernel/types.h" //Has typedefs for common types in xv6
#include "user/user.h"

#define bool char
#define true 1
#define false 0

const int ARR_SIZE = 1000;
int* arr;

int main(void)
{
    int forkpids[3]; 
	
	//Populate array
	arr = malloc(sizeof(int)*ARR_SIZE);
	arr[0] = 1; arr[1] = 2;
	for(int i = 2; i < ARR_SIZE; i++)
		arr[i] = 4*arr[i - 1] - arr[i - 2];

    //TODO: Create the specified number of children using fork()
	//TODO: Write your implementation here desrcibed in the document
    //TODO: Evaluate your metrics here, after the processes have completed their work

	free(arr);
}
