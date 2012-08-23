#include <stdio.h>
main()
{
	struct emp
	{       char *name;
		int age;
		float sal;
	};
	struct emp e = {"Tiger", 100, 5000};
	printf("name=%s\nage=%d\nsal=%f\n", e.name, e.age, e.sal);
}
