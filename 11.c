#include "stdio.h"
#include "enum.c"
#define N 8
#define scanf_s scanf
#define _countof(array) (sizeof(array) / sizeof(array[0]))

void scanHowMany(int inputCount);
void printArray(int arraySize);
static inline char* enumToString(enum Week week);

Week weekArray[N];

void main() {
	int strings = 0;
	scanf_s("%d", &strings);
	scanHowMany(strings);
	printArray(strings);
}

static inline char* enumToString(enum Week week) {
	static const char* stringArray[] = { "Mon", "Tue", "Wed", "Thur", "Fri", "Sat","Sun" };

	switch (week)
	{
	case Mon: return "Mon";
		break;
	case Tue:return "Tue";
		break;
	case Wed:return "Wed";
		break;
	case Thur:return "Thur";
		break;
	case Fri:return "Fri";
		break;
	case Sat:return "Sat";
		break;
	case Sun:return "Sun";
		break;
	default:
		break;
	}
	return stringArray;
}

void printArray(int arraySize) {
	int i = 0;

	while (i < arraySize)
	{
		char* stringArray = enumToString(weekArray[i]);
		printf("%d: %s ", i, enumToString(weekArray[i]));
		i++;
	}
}

void scanHowMany(int strings) {
	char input[10];

	for (int i = 0; i < strings; i++)
	{
		scanf_s("%s", input, _countof(input));
		if (strcmp(input, "Mon") == 0)
		{
			weekArray[i] = Mon;
		}
		if (strcmp(input, "Tue") == 0)
		{
			weekArray[i] = Tue;
		}
		if (strcmp(input, "Wed") == 0)
		{
			weekArray[i] = Wed;
		}
		if (strcmp(input, "Thur") == 0)
		{
			weekArray[i] = Thur;
		}
		if (strcmp(input, "Fri") == 0)
		{
			weekArray[i] = Fri;
		}
		if (strcmp(input, "Sat") == 0)
		{
			weekArray[i] = Sat;
		}
		if (strcmp(input, "Sun") == 0)
		{
			weekArray[i] = Sun;
		}
	}
}