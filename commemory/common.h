#pragma once

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>

#define PATHNAME "."
#define PROJ_ID 0X6666

int CreateShm(int size);

int DestroyShm(int shmid);

int GetShm(int size);



