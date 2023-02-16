
#include "stdio.h"
#include "stdlib.h"

int main(int argc, char** argv)
{
	if (argc == 3)
	{
		FILE* fp1 = fopen(argv[1], "rb");
		FILE* fp2 = fopen(argv[2], "wb");

		int len1 = 0;
		int len2 = 0;

		fseek(fp1, 0-sizeof(long), SEEK_END);
		fread(&len2, sizeof(long), 1, fp1);

		fseek(fp1, 0-2*sizeof(long), SEEK_END);
		fread(&len1, sizeof(long), 1, fp1);

		fseek(fp1, len1, SEEK_SET);
		for(int i=0; i<len2; i++)
			fputc((~fgetc(fp1)), fp2);

		fclose(fp2);
		fclose(fp1);
	}
}
