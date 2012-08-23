#! /usr/bin/python

import re;

string = raw_input("Enter String: ");

Reg = re.search(r"<([^> ]+)( ([a-zA-Z0-9]+=\".*\")*)?>", string);

if Reg:
	print Reg.group(1);
	print Reg.group(3);
else:
	print "No match";
