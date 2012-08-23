#! /usr/bin/python
#
#
# Program to compute the number of squares which are intersected by the line internally 
# =======================
# Works only for positive numbers and lines of all slopes.
# Can be made to work for -ve numbers too.
# =======================

import sys,math

if len(sys.argv) != 5:
    print "Number of command line arguments should be exactly 4";
    sys.exit();


try:
    x1 = int(sys.argv[1]);
    y1 = int(sys.argv[2]);
    x2 = int(sys.argv[3]);
    y2 = int(sys.argv[4]);
except:
    print "All arguments should be integers";
    sys.exit();


if (x1 < 0) or (y1 < 0) or (x2 < 0) or (y2 < 0):
    print "All coordinates should lie between 0 and 10,000";
    sys.exit();

if (x2-x1 == 0) or (y2-y1 == 0):
    print 0;
    sys.exit();




def num_squares(x1, y1, x2, y2):
	count = 0;
	slope = float(y2-y1)/float(x2-x1);

	x,y = x1, y1;
	while (x != x2) and (y != y2):
	    if slope == 1:
	        x += 1;
	        y += 1;
	    elif slope < 1:
	        if (float(x) == int(x)) and (float(y) == int(y)):
	            x += 1;
	            y += slope;
	        elif (float(y) == int(y)):
	            y += (math.ceil(x) - x)*slope;
	            x = math.ceil(x);
	        elif (math.ceil(y) - y)/slope < 1:
	            x += (math.ceil(y) - y)/slope;
	            y  = math.ceil(y);
	        else:
	            x += 1;
	            y += slope;
	    else:
	        if (float(x) == int(x)) and (float(y) == int(y)):
	            x += 1/slope;
	            y += 1;
	        elif (float(x) == int(x)):
	            x += (math.ceil(y) - y)/slope;
	            y  = math.ceil(y);
	        elif (math.ceil(x) - x)*slope < 1:
	            y += (math.ceil(x) - x)*slope;
	            x = math.ceil(x);
	        else:
	            y += 1;
	            x += 1/slope;
	    count = count + 1;
	    #print "(x,y) = (", x, ",", y, ")";
	return count;


# Actual calling of function
if (x2 > x1) and (y2 > y1):
	print num_squares(x1, y1, x2, y2);
elif (x2 > x1) and (y2 < y1):
	print num_squares(x1, y1, x2, 2*y1 - y2);
elif (x2 < x1) and (y2 > y1):
	print num_squares(x2, y2, x1, 2*y2 - y1);
elif (x2 < x1) and (y2 < y1):
	print num_squares(x2, y2, x1, y1);
