#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

pthread_mutex_t	mutex;
int				cnt = 0;

void *f_count(void *arg);

int main(void)
{
	pthread_t thread1;
	pthread_t thread2;

	pthread_mutex_init(&mutex, NULL);

	pthread_create(&thread1, NULL, f_count, (void *)"thread1");
	pthread_create(&thread2, NULL, f_count, (void *)"thread2");

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	pthread_mutex_destroy(&mutex);

	return (0);
}

void *f_count(void *arg)
{
	int  i;
	char *name;

	name = (char *)arg;

	pthread_mutex_lock(&mutex);
	/* Critical Section: START */
	cnt = 0;
	printf("[%s]\n", name);
	for (i = 0; i < 10; i++)
	{
		printf("%s cnt: %d\n", name, cnt);
		cnt++;
		usleep(1);
	}
	/* Critical Section: END */
	pthread_mutex_unlock(&mutex);

	return (0);
}
