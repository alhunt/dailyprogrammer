#include "parentheses.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
	for (i = 0; i < x; i++) {
		int this_o = plist[0][i];
		int next_o = plist[0][i+1];
		int this_c = plist[1][i];
		int next_c = plist[1][i+1];

		if (this_o == next_o + 1 && this_c == next_c - 1) {
			str[this_o] = ' ';
			str[this_c] = ' ';
		}
	}

	// Remove spaces from string
	int chr;
	for (chr = 0; chr < strlen(str) && str[chr] != '\0'; chr++) {
		if (str[chr] == ' ')
			memmove(&str[chr], &str[chr + 1], strlen(str) - chr);
	}
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
