#include "12days.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char OPENING[] = "On the %s day of Christmas\nmy true love sent to me:";

char *ORDINALS[] = {
	NULL,
	"first",
	"second",
	"third",
	"fourth",
	"fifth",
	"sixth",
	"seventh",
	"eighth",
	"nineth",
	"tenth",
	"eleventh",
	"twelfth"
};

char *GIFTS[] = {
	NULL,
	"1 Partridge in a Pear Tree",
	"2 Turtle Doves",
	"3 French Hens",
	"4 Calling Birds",
	"5 Golden Rings",
	"6 Geese a Laying",
	"7 Swans a Swimming",
	"8 Maids a Milking",
	"9 Ladies Dancing",
	"10 Lords a Leaping",
	"11 Pipers Piping",
	"12 Drummers Drumming"
};

char *fopening(int day) {
	if (day > 0 && day <= 12) {
		char *retbuf = malloc(sizeof(OPENING) + sizeof(ORDINALS[day]));

		if (retbuf == NULL)
			return NULL;

		sprintf(retbuf, OPENING, ORDINALS[day]);

		return retbuf;
	}
	else
		return NULL;
}

char *fday(int day) {
	if (day > 0 && day <= 12) {
		char *retbuf = malloc(sizeof(GIFTS[day]));

		if (retbuf == NULL)
			return NULL;

		sprintf(retbuf, "%s", GIFTS[day]);

		return retbuf;
	}
	else
		return NULL;
}
