#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <limits.h>

pthread_mutex_t myMutex = PTHREAD_MUTEX_INITIALIZER;

void	*function(void *args)
{
	int i = 0;
	int d = 0;

	pthread_mutex_lock(&myMutex);
	while (d <= 10)
	{
		usleep(50000);
		printf("%d\n", i);
		i++;
		d++;
	}
	pthread_mutex_unlock(&myMutex);
	return (NULL);
}

void	*print_me(void	*args)
{
	int i = 0;
	while (i < 1000)
	{
		sleep(1);
		printf("%d\n", i);
		i++;
	}
	return (NULL);
}

void	*print_you(void	*args)
{
	int i = 0;
	while (i < 5)
	{
		sleep(1);
		printf("%d\n", i);
		i++;
	}
	return (NULL);
}

int main()
{
	pthread_t	thread;
	pthread_t	thread2;

	int	*args;
	pthread_create(&thread, NULL, function, NULL);
	//printf("thread finish\n");
	pthread_create(&thread2, NULL, function, NULL);
	pthread_join(thread, NULL);
	printf("thread finish\n");
	pthread_join(thread2, NULL);
	printf("thread finish\n");
	//print_me(args);
	//print_you();
	return (0);
}