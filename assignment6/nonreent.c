#include <stdio.h>
#include <signal.h>
#include <pwd.h>


void
MyAlarmHandler(int signo)
{
	struct passwd	*rootptr;

	//recursive call of MyalarmHandler
	signal(SIGALRM, MyAlarmHandler);
	//send alarm after 1 sec
	alarm(1);

	printf("in signal handler\n");

	//getpwname in root
	//if fail, print error
	if ((rootptr = getpwnam("root")) == NULL)  {
		perror("getpwnam");
		exit(1);
	}

	return;
}

main()
{
	struct passwd	*ptr;

	//if SIGALRM appears, activate MyAlarmHandler
	signal(SIGALRM, MyAlarmHandler);
	//send alarm after 1 sec
	alarm(1);

	for ( ; ; )  {
		//getpwname to ptr
		//if fail, print error
		if ((ptr = getpwnam("cjs")) == NULL)  {
			perror("getpwnam");
			exit(1);
		}

		//if pw_name != "cjs" different process entered to the function
		//so this function should be nonreent
		if (strcmp(ptr->pw_name, "cjs") != 0)  {
			printf("return value corrupted!, pw_name = %s\n", ptr->pw_name);
			exit(0);
		}
	}
}
