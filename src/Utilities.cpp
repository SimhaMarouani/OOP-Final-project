#include "Utilities.h"

void calcTime(int& sec, int& min)
{
	if (sec >= 60)
	{
		min = sec / 60;
		sec = sec % 60;
	}
}