#include <stdio.h>
#include <signal.h>

static unsigned int	AlarmSecs;


void
SigAlarmHandler(int signo)
{
	//if SIGALRM sig appears, activate SigAlarmHandler
	//if error print error
	if (signal(SIGALRM, SigAlarmHandler) == SIG_ERR)  {
		perror("signal");
		exit(1);
	}

	//send sigalarm after Alarmsecs
	alarm(AlarmSecs);

	/* Do something */
	printf(".");
	//flush stdout to print
	fflush(stdout);

	return;
}

int
SetPeriodicAlarm(unsigned int nsecs)
{
	//if SIGALRM sig appears, activate SigAlarmHandler
	if (signal(SIGALRM, SigAlarmHandler) == SIG_ERR)  {
		return -1;
	}

	//set AlarmSecs
	AlarmSecs = nsecs;

	//git sigalarm agter nsecs
	alarm(nsecs);

	return 0;
}

main()
{
	printf("Doing something every one seconds\n");

	//set Alarmsecs 1
	SetPeriodicAlarm(1);

	for ( ; ; )
		pause();
}
