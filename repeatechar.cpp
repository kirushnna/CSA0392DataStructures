#include <stdio.h>
#include <string.h>

int findRepeatFirstN2(char* s)
{
	int p = -1, i, j;
	for (i = 0; i < strlen(s); i++) {
		for (j = i + 1; j < strlen(s); j++) {
			if (s[i] == s[j]) {
				p = i;
				break;
			}
		}
		if (p != -1)
			break;
	}

	return p;
}

int main()
{
	char str[] = "apple";
	int pos = findRepeatFirstN2(str);
	if (pos == -1)
		printf("Not found");
	else
		printf("%c", str[pos]);
	return 0;
}

