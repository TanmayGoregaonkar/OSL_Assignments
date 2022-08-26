#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

/*
run command:-
gcc POSIXTHREADS.c -o demo.out -lpthread
./demo.out
*/

// nllab24@nllab-24:~/33227$ gcc POSIXTHREADS2.c -o demo.out -lpthread
// nllab24@nllab-24:~/33227$ ./demo.out
void *thread_function(void *arg);
char message[] = "Hello World";

int main()
{
    int res;
    int run_now = 1;
    pthread_t a_thread;
    void *thread_result;
    res = pthread_create(&a_thread, NULL, thread_function, (void *)message);

    int print_count1 = 0;
    while (print_count1++ < 20)
    {
        if (run_now == 1)
        {
            printf("1");
            run_now = 2;
        }
        else
        {
            sleep(1);
        }
    }

    int print_count2 = 0;
    while (print_count2++ < 20)
    {
        if (run_now == 2)
        {
            printf("2");
            run_now = 1;
        }
        else
        {
            sleep(1);
        }
    }

    if (res != 0)
    {
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }
    printf("Waiting for thread to finish...\n");
    res = pthread_join(a_thread, &thread_result);
    if (res != 0)
    {
        perror("Thread join failed");
        exit(EXIT_FAILURE);
    }
    printf("Thread joined, it returned %s\n", (char *)thread_result);
    printf("Message is now %s\n", message);
    exit(EXIT_SUCCESS);
}

void *thread_function(void *arg)
{
    printf("thread_function is running. Argument was %s\n", (char *)arg);
    sleep(3);
    strcpy(message, "Bye!");
    pthread_exit("Thank you for the CPU time");
}