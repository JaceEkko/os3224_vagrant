#include "types.h"
#include "user.h"
#include "date.h"

int
main(int argc, char *argv[])
{
	struct rtcdate r;
	
	if (date(&r)) {
		printf(2, "date failed\n");
		exit();
	}

	if (r.hour < 5) {
		r.hour = r.hour + 24;
		r.day = r.day - 1;
	}
	r.hour = r.hour - 5; //makes the time EST, if it was day-light savings I would subtarct by 4

	printf(1, "%d-%d-%d %d:%d:%d\n", r.year, r.month, r.day, r.hour, r.minute, r.second);
	exit();
}