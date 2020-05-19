#define KEY 0x1111
#include "mysem.h"
/*union semun {
    int val;
    struct semid_ds *buf;
    unsigned short  *array;
};*/

int id;
union semun u;
void myseminit( int val)
{
    id = semget(KEY, 1, 0666 | IPC_CREAT);
    if(id < 0)
    {
        perror("semget"); exit(11);
    }
    u.val = val;
    if(semctl(id, 0, SETVAL, u) < 0)
    {
        perror("semctl"); exit(12);
    }
    return;
}
void mysemp(unsigned short nthsems)
{
	struct sembuf p = { nthsems, -1, SEM_UNDO};
	if(semop(id, &p, 1) < 0)
	{
		perror("semop p"); exit(13);
	}
    return;
}

void mysemv(unsigned short nthsems)
{
	struct sembuf v = { nthsems, +1, SEM_UNDO};
	if(semop(id, &v, 1) < 0)
	{
		perror("semop p"); exit(14);
	}
    return;
}

int mysemval(int semNum)
{
    return semctl(id, semNum, GETVAL, u);
}
