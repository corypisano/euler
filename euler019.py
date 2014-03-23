# Project Euler Problem 19 - Counting Sundays
# Simple solution using datetime

import datetime
import time
start = time.time();
sundayCount = 0;
for year in range(1901,2001):
    for month in range(1,13):
        d = datetime.date(year,month,1);
        if (d.weekday()==6):
            sundayCount+=1;
elapsed_time = time.time() - start;

print "Number of starting sundays: %d" %sundayCount;
print "Elapsed time: %s seconds" %elapsed_time;
