/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/

int convert(char *, int);
int check(int, int);
int leapyear(int, int, int);

int isOlder(char *dob1, char *dob2) {
	int dt1, dt2, mn1, mn2, yr1, yr2,l1,l2;
	for (l1 = 0; dob1[l1]; l1++);
	for (l2 = 0; dob2[l2]; l2++);
	if (l1 == 10 && l2 == 10)
	{
		dt1 = convert(dob1, 2);
		dt2 = convert(dob2, 2);
		mn1 = convert(&dob1[3], 2);
		mn2 = convert(&dob2[3], 2);
		yr1 = convert(dob1+6, 4);
		yr2 = convert(dob2+6, 4);
		
		l1 = leapyear(yr1, mn1, dt1);
		l2 = leapyear(yr2, mn2, dt2);
		if (l1 == -1 || l2 == -1)
			return -1;
		else if (mn1 <= 12 && mn2 <= 12)
		{
			l1 = check(mn1, dt1);
			l2 = check(mn2, dt2);
			if (l1 == -1 || l2 == -1)
				return -1;
			else if (yr1 > yr2)
				return 2;
			else if (yr2 > yr1)
				return 1;
			else if (mn1 > mn2)
				return 2;
			else if (mn2 > mn1)
				return 1;
			else if (dt1 > dt2)
				return 2;
			else if (dt2 > dt1)
				return 1;
			else
				return 0;

		}
		else
			return -1;
		
		
	}
	else
		return -1;
}
int convert(char *c, int l)
{
	int x,i;
	
	for (x = 0,i=0; i < l; i++)
	{
		//printf("\n%c\t%d\t%d", c[l], l, u);
		x = x * 10 + (c[i] - '0');
	}
	return x;
}
int leapyear(int yr, int mn, int dt)
{
	if ((yr % 4 == 0 && yr % 100 != 0) || yr % 400 == 0)
	{
		if (mn == 2)
		{
			if (dt <= 29)
				return 3;
			else
				return -1;
		}
		else
			return 4;


	}
	else if (mn == 2)
	{
		if (dt <= 28)
			return 3;
		else
			return -1;
	}
	else
		return 4;
}
int check(int mn, int dt)
{
	if (mn == 4 || mn == 6 || mn == 9 || mn == 11)
	{
		if (dt <= 30)
			return 1;
		else
			return -1;
	}
	else if (dt <= 31)
		return 1;
	else
		return -1;
}


