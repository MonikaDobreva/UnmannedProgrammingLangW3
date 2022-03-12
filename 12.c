#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

extern char** environ;

int main(int argc, char* argv[]) {
	char* home, * path;

	// last element of envp array is a nullptr
	// hence iterating is as follows:
	printf("\nall environment variables\n");
	printf("=========================\n");
	int i = 0;
	while (environ[i] != NULL) {
		printf("envp[%d]=%s\n", i, environ[i]);
		i++;
	}

	printf("\nsome examples of standard environment variables\n");
	//"HOME" and "PATH" are a standard environment variable, see for more:
	//https://www.gnu.org/software/libc/manual/html_node/Environment-Variables.html

	home = getenv("HOME");
	printf("home dir is: %s\n", home);
	printf("PATH=%s\n", getenv("PATH"));
	return 0;
}
char* getenv(const char* name) {
	char* result = "";

	for (int i = 0; i < sizeof(environ); i++)
	{
		char** test = environ[i];

		if (strstr(environ[i], name)) {
			result = environ[i];
			printf("%d", i);
		}
	}

	return result;
}

int setenv(const char* name, const char* value, int replace) {
	if (replace != 0)
	{
		name = value;
		return 0; 
	}

	return -1; 
}