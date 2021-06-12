# thread-safe-counter
## Project #2 (thread-safety by semaphore)

## OS: Ubuntu Linux

### Compare performance

#### Mutex

![mutex](https://user-images.githubusercontent.com/84131675/121779929-02c8fc00-cbd9-11eb-9a88-8e316f330d0b.PNG)

#### Semaphore

![semaphore](https://user-images.githubusercontent.com/84131675/121779936-09f00a00-cbd9-11eb-8957-97fb9de8a655.PNG)

#### the performance measurement result
In this case Mutex is faster than Semaphore

### Analasys

Mutex can be synchronized between threads of multiple processes.
Semaphores can synchronize a specified number of threads to run simultaneously.
Semaphores allow threads to run until they are less than or equal to a specified number, and prevent threads from running when they attempt to run beyond a specified number.
So in this case Mutex faster than Semaphore
