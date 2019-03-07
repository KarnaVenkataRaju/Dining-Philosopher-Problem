# Objective
Objective of this lab is to practice POSIX thread API and synchronization. Another objective is to learn more about multithreaded
application design.
# Basic APIs
int pthread_create(pthread_t *threadid, const pthread_attr_t *attr, void *(*start_routine)(void*), void *arg)
int pthread_join(pthread_t threadid, void **value_ptr)
int pthread_mutex_lock(pthread_mutex_t *mutex);
int pthread_mutex_unlock(pthread_mutex_t *mutex);
# How to compile
1. Include required header file
Include<pthread.h>
2. Linking pthread library is also needed
gcc progname.c –o progname -lpthread
# Background

Assume a dining table which has five chairs as shown in the figure on right side. The table has 5 plates full of something to eat. All five chairs
are occupied by 5 philosophers, commonly known as Dining Philosophers. These dining philosophers are sitting on the table since they
want to eat. A philosopher cannot eat until he has two forks (one on his right and other on left.) The objective here is that none of the philosophers remain
hungry.

# Task
1. Write a C program that simulates the situation mentioned above. Five philosophers can be represented by 05 threads where
each thread thinks for some time and then tries to eat something.

2. After implementing the program, run it several times and try to do some philosophical activity i.e., ponder these results. 
