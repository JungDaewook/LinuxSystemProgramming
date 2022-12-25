void del(char *src, char c) {
	while (*src) {
		if (*src == c) {
			//shift 시켜야 함(null 나올 때까지)
			strcpy(scr, src+1);
		}
		++src;
	}
}
