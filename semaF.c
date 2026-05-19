#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/wait.h>

int main() {

    // named semaphore create
    sem_t *mutex;

    mutex = sem_open("/mysem", O_CREAT, 0644, 1);

    // create processes
    fork();
    fork();

    // lock
    sem_wait(mutex);

    // critical section
    printf("Hello I am process no %d\n", getpid());
    printf("Hello I am process no %d\n", getpid());

    // unlock
    sem_post(mutex);

    // parent waits
    while(wait(NULL) > 0);

    // close semaphore
    sem_close(mutex);

    // remove semaphore
    sem_unlink("/mysem");

    return 0;
}



