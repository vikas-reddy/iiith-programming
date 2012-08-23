#include<stdio.h>
/* Program to replace all occurrences of "India" with "bharat"
*/

main()
{
	FILE *fptr=NULL;
	char file_name[50], ch='\0', temp_ch='\0';
	int i=0;

	while(scanf("%s",file_name) != EOF)
	{
		fptr = fopen(file_name, "r");
		// If the file doesn't exist
		if(fptr == NULL)
		{
			printf("'%s' DOESN'T EXIST. ENTER AN EXISTING FILE NAME\n", file_name);
			continue;
		}
		while(fscanf(fptr, "%c", &ch) != EOF)
		{
			if(ch == 'I' || ch == 'i')
			{
				fscanf(fptr, "%c", &ch);
				if(ch == 'N' || ch == 'n')
				{
					fscanf(fptr, "%c", &ch);
					if(ch == 'D' || ch == 'd')
					{
						fscanf(fptr, "%c", &ch);
						if(ch == 'I' || ch == 'i')
						{
							fscanf(fptr, "%c", &ch);
							if(ch == 'A' || ch == 'a')
							{
								printf("bharat");
							}
							else
							{
								fseek(fptr, -5, SEEK_CUR);
								for(i=0; i<4; fscanf(fptr,"%c",&temp_ch), 
										printf("%c",temp_ch), i++);
							}
						}
						else
						{
							fseek(fptr, -4, SEEK_CUR);
							for(i=0; i<3; fscanf(fptr,"%c",&temp_ch), 
									printf("%c",temp_ch), i++);
						}
					}
					else
					{
						fseek(fptr, -3, SEEK_CUR);
						for(i=0; i<2; fscanf(fptr,"%c",&temp_ch), 
								printf("%c",temp_ch), i++);
					}
				}
				else
				{
					fseek(fptr, -2, SEEK_CUR);
					for(i=0; i<1; fscanf(fptr,"%c",&temp_ch), 
							printf("%c",temp_ch), i++);
				}
			}
			else
				printf("%c", ch);
		}
		fclose(fptr);
	}
	return;
}
