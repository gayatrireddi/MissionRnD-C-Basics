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

int isOlder(char *dob1, char *dob2) {
	int date1, mon1, year1, i = 0;
	int date2, mon2, year2; date1 = mon1 = year1 = 0;
	while (dob1[i] != '\0')
	{
		if (dob1[i]<'0' || dob1[i]>'9')
			if (dob1[i] != '-')
				return -1;
		i++;
	}
	i = 0;
	while (dob2[i] != '\0')
	{
		if (dob2[i]<'0' || dob2[i]>'9')
			if (dob2[i] != '-')
				return -1;
		i++;
	}
	i = 0;

	while (dob1[i] >= '0'&&dob1[i] <= '9')
	{
		date1 = date1 * 10 + (dob1[i] - '0');
		i++;
	}
	i++;

	while (dob1[i] >= '0'&&dob1[i] <= '9')
	{
		mon1 = mon1 * 10 + (dob1[i] - '0');
		i++;
	}
	i++;
	while (dob1[i] >= '0'&&dob1[i] <= '9')
	{
		year1 = year1 * 10 + (dob1[i] - '0');
		i++;
	}
	if (date1<1 || date1>31){
		return -1;
	}
	if (mon1<1 || mon1>12)
	{
		return -1;
	}
	if (year1<1000 || year1>9999)
	{
		return -1;
	}

	date2 = mon2 = year2 = 0;
	i = 0;
	while (dob2[i] >= '0'&&dob2[i] <= '9')
	{
		date2 = date2 * 10 + (dob2[i] - '0');
		i++;
	}
	i++;
	while (dob2[i] >= '0'&&dob2[i] <= '9')
	{
		mon2 = mon2 * 10 + (dob2[i] - '0');
		i++;
	}
	i++;
	while (dob2[i] >= '0'&&dob2[i] <= '9')
	{
		year2 = year2 * 10 + (dob2[i] - '0');
		i++;
	}
	if (date2<1 || date2>31 || mon2<1 || mon2>12 || year2<1000 || year2>9999)
	{
		return -1;
	}

	if (mon1 != 01 || mon1 != 03 || mon1 != 05 || mon1 != 07 || mon1 != 8 || mon1 != 10 || mon1 != 12)
	{
		if (date1>30)
		{
			return -1;
		}
	}

	if (mon2 != 01 || mon2 != 03 || mon2 != 05 || mon2 != 07 || mon2 != 8 || mon2 != 10 || mon2 != 12)
	{
		if (date2>30)
		{
			return -1;
		}
	}
	if (year1 % 4 != 0 && year1 % 400 != 0)
		if (mon1 = 2)
			if (date1 > 28)
				return -1;

	if (year2 % 4 != 0 && year2 % 400 != 0)
		if (mon2 = 2)
			if (date2 > 28)
				return -1;


	if (year1 > year2)
		return 2;
	if (year1 < year2)
		return 1;

	if (year1 == year2)
	{
		if (mon1 > mon2)
			return 2;
		if (mon1 < mon2)
			return 1;
		if (mon1 == mon2)
		{
			if (date1 > date2)
				return 2;
			if (date1 < date2)
				return 1;
			if (date1 == date2)
				return 0;
		}
	}

}




