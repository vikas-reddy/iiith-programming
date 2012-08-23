#! /usr/bin/python
# 
# Expression Compiler

import sys,math

if len(sys.argv) == 1:
	print "No expression is given as input. Exiting";
	sys.exit();


def precedence(x):
	if x == "+":
		return 1;
	elif x == "-":
		return 2;
	elif x == "*":
		return 3;
	elif x == "/":
		return 4;
	elif x == "(":
		return 0;

def get_name(symb):
	if symb == "+":
		return "ADD";
	elif symb == "-":
		return "SUB";
	elif symb == "*":
		return "MUL";
	elif symb == "/":
		return "DIV";
	else:
		return "$";


symbStack = [];
expression = "";

i=1;
while i < len(sys.argv):
	expression += sys.argv[i];
	i += 1;

for i in expression:
	try:
		num = int(i);
	except:
		num = False;

		if len(symbStack) == 0:
			symbStack.append(i);
		elif i == "(":
			symbStack.append(i);
		elif i == ")":
			while symbStack[-1] != "(":
				print get_name(symbStack.pop());
				if len(symbStack) == 0:
					break;
			if symbStack[-1] == "(":
				symbStack.pop();
		elif precedence(i) > precedence(symbStack[-1]):
			symbStack.append(i);
		elif precedence(i) <= precedence(symbStack[-1]):
			while precedence(i) < precedence(symbStack[-1]):
				print get_name(symbStack.pop());
				if len(symbStack) == 0:
					break;
			symbStack.append(i);
	
	if num:
		print "PUSH", num;

while len(symbStack) > 0:
	print get_name(symbStack.pop());
