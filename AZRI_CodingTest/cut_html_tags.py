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


#def check_using_regex(OpenTag, CloseTag):
#	print OpenTag, CloseTag;
#	regone = re.search("(\<[^> ]+?\>)", OpenTag);
#	regtwo = re.search("(\</)([^> ]+?)(\>)", CloseTag);
#	print regone.group(2), regtwo.group(2);

def check(Stack, tag):
	if len(Stack) == 0:
		return 0;

	r1 = "";
	r2 = "";

	i=1;
	while i<len(Stack[-1]) and Stack[-1][i] != " " and Stack[-1][i] != ">":
		r1 += Stack[-1][i];
		i += 1;

	i=2;
	while i<len(tag) and tag[i] != ">":
		r2 += tag[i];
		i += 1;

	if r1 == r2:
		return 1;
	else:
		return 0;


#==========================================
#check_using_regex("<vikas span=\"ksldjfla\">", "</vikas>");
#sys.exit();
#==========================================

string = raw_input("Enter String: ");
TagStack = [];

j = 0;
length = len(string); 
output_string = "";

i = 0;
j = 0;
while i<length:
	if string[i] == "<":
		r1 = re.search("(<[^>]+?>)", string[i:]);
		tag = r1.group(1);
		output_string += tag;
		i += len(r1.group(1));
		

		if check(TagStack, tag):
			TagStack.pop();
		else:
			TagStack.append(tag);

	else:
		output_string += string[i];
		j += 1;
		if j >= count:
			break;
		i += 1;


while i<length and len(TagStack):
	if string[i] == "<":
		# non-greedy match to extract tag
		r1 = re.search("(<[^>]+?>)", string[i:]);
		tag = r1.group(1);
		output_string += tag;
		i += len(r1.group(1));
		
		if check(TagStack, tag):
			TagStack.pop();
	else:
		i += 1;

print output_string;
