#include "parentheses.h"
#include <stdlib.h>

void rem_dupes(char *str, int str_len) {
	int array_max = (str_len / 2) + 1;
	int x = 0;
	int i, open, close, plist[2][array_max];

	// Make an array of the pairs
	for (i = str_len - 1; i>=0;) {
		open = seek_bk(str, str_len, i);
		close = seek_fwd(str, str_len, open);

		while(close_found(plist[1], x, close)) {
			close++;
			close = seek_fwd(str, str_len, close);
		}

		plist[0][x] = open;
		plist[1][x] = close;
		x++;
		i = open - 1;
	}

	// Set duplicates to spaces
	// Remove spaces from string
}

int seek_fwd(char *str, int str_len, int start) {
	int i;

	// Seek forwards from start till you find ')'
	for (i = start; i < str_len; i++) {
		if (str[i] == ')')
			return i;
	}

	return -1;
}

int seek_bk(char *str, int str_len, int start) {
	int i;

	// Seek backwards from start till you find '('
	for (i = start; i >= 0; i--) {
		if (str[i] == '(')
			return i;
	}

	return -1;
}

int close_found(int list[], int list_len, int close) {
	int i;

	// Look for close in the list array
	for (i = 0; i < list_len; i++) {
		if (list[i] == close)
			return 1;
	}

	// Return false if it doesn't find it
	return 0;
}
