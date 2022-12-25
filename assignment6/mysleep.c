#include <stdio.h>
#include <signal.h>

void
SigAlarmHandler(int signo)
{
	/* nothing to do, just return to wake up the pause */
	return;
}

unsigned int
mysleep(unsigned int nsecs)
{
	//if SIGALRM signal appears, activate SigAlarmHandler
	//if error, return nsecs
	if (signal(SIGALRM, SigAlarmHandler) == SIG_ERR)  {
		return nsecs;
	}

	//send alarmsignal after nsecs
	alarm(nsecs);

	pause();

	//return alarm(0)
	//if alarm(0) == 0 it is well done
	//if alarm(0) != 0 it is not done well
	return alarm(0);
}

main()
{
	printf("Wait for 5 seconds...\n");

	mysleep(5);
}
