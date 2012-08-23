#! /usr/bin/python
#
# Program to cut HTML tags

import sys,re

if len(sys.argv) != 2:
	print "Number of command-line arguments should be one";
	sys.exit();

#num of characters to consider
try:
	count = int(sys.argv[1]);
except:
	print "Command-line argument should be an integer";
	sys.exit();


def check(Stack, tag):
	if len(Stack) == 0:
		return False;
	r1 = re.search('<([^>]+)(.*)>', Stack[-1]);
	r2 = re.search('</?([^>]+?)>', tag);
	if r1.group(1) == r2.group(1):
		return True;
	else:
		return False;


string = raw_input("Enter String: ");

TagStack = [];
length = len(string); 
output_string = "";

i = 0;
j = 0;
while i<length:

	if string[i] == "<":
		# non-greedy match to extract tag
		regex = re.search("(<[^>]+?>)", string[i:]);
		if regex:
			tag = regex.group(1);
			output_string += tag;
			i += len(regex.group(1));
		else:
			print "Invalid HTML tag at position %s" % (i);
			sys.exit();
		
		if check(TagStack, tag):
			TagStack.pop();
		else:
			TagStack.append(tag);

	else:
		output_string += string[i];
		j += 1;
		i += 1;
		if j >= count:
			break;


while i<length and len(TagStack):
	if string[i] == "<":
		# non-greedy match to extract tag
		regex = re.search("(<[^>]+?>)", string[i:]);
		if regex:
			tag = regex.group(1);
			output_string += tag;
			i += len(regex.group(1));
		else:
			print "Invalid HTML tag at position %s" % (i);
			sys.exit();
		
		
		if check(TagStack, tag):
			TagStack.pop();
	else:
		i += 1;

print output_string;
