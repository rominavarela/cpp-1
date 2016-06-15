#include <cstdlib>//legacy stdlib.h and time.h
#include <iostream>
#include <unistd.h>
#include <pthread.h>

using namespace std;

const int NTHREADS= 10;

void *threadRoutine(void *arg) {
  int i = *(int*)arg;
  std::cout << "thread " << i << " running" << endl;
}

int main() {
  pthread_t threads[NTHREADS];
  int thread_n[NTHREADS];

  for(int i=0; i<NTHREADS; i++)
  {
    thread_n[i]= i;
    //std::cout << "thread running " << thread_n[i] << endl;

    pthread_create(
       &threads[i], //pthread_t *thread
       NULL, //const pthread_attr_t *attr
       &threadRoutine, //void *(*start_routine) (void *)
       &thread_n[i] //void *arg
     );
  }

  sleep(3);// wait 3 seconds
}
