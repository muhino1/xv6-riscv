#include "kernel/types.h" //Has typedefs for common types in xv6
#include "user/user.h"

#define bool char
#define true 1
#define false 0

const int ARR_SIZE = 1000;
int* arr;

int main(void)
{
    //int forkpids[3]; 
	
	//Populate array
	arr = malloc(sizeof(int)*ARR_SIZE);
	arr[0] = 1; arr[1] = 2;
	for(int i = 2; i < ARR_SIZE; i++)
		arr[i] = 4*arr[i - 1] - arr[i - 2];

    //TODO: Create the specified number of children using fork()
	//TODO: Write your implementation here desrcibed in the document
    //TODO: Evaluate your metrics here, after the processes have completed their work

  int t0 = uptime();

    for(int i = 0; i < 3; i++){
        int pid = fork();
        if(pid == 0){      // child process
            rude(rudeness[i]);
            int my_start = uptime();

            if(i == 0){                // rudeness 5: sum
                int sum = 0;
                for(int j = 0; j < ARR_SIZE; j++)
                    sum += arr[j];
                printf("Sum: %d\n", sum);
            } else if(i == 1){         // rudeness 15: normalize
                int min = arr[0], max = arr[0];
                for(int j = 1; j < ARR_SIZE; j++){
                    if(arr[j] < min) min = arr[j];
                    if(arr[j] > max) max = arr[j];
                }
                printf("Normalized:\n");
                for(int j = 0; j < ARR_SIZE; j++){
                    int num = arr[j] - min;
                    int denom = max - min;
                    printf("%d/%d ", num, denom); // fraction since no floats
                }
                printf("\n");
            } else {                // rudeness 30: bubble sort
                for(int j = 0; j < ARR_SIZE-1; j++){
                    for(int k = 0; k < ARR_SIZE-j-1; k++){
                        if(arr[k] > arr[k+1]){
                            int tmp = arr[k];
                            arr[k] = arr[k+1];
                            arr[k+1] = tmp;
                        }
                    }
                }
                printf("Sorted:\n");
                for(int j = 0; j < ARR_SIZE; j++)
                    printf("%d ", arr[j]);
                printf("\n");
            }

            int my_end = uptime();
            printf("Child %d (rudeness %d) turnaround: %d ticks\n", i, rudeness[i], my_end - my_start);
            exit(0);
        } else {
            //forkpids[i] = pid;
        }
    }

    for(int i = 0; i < 3; i++){
        wait(0);
    }

    int t_end = uptime();
    printf("Total elapsed: %d ticks\n", t_end - t0);

	free(arr);
}
