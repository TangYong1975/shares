
#include "stdio.h"
#include "stdlib.h"

int main(int argc, char** argv)
{
	if (argc == 4)
	{
		FILE* fp1 = fopen(argv[1], "rb");
		FILE* fp2 = fopen(argv[2], "rb");
		FILE* fp3 = fopen(argv[3], "wb");

		long len1 = 0;
		while (!feof(fp1))
		{
			fputc(fgetc(fp1), fp3);
			len1++;
		}
		long len2 = 0;
		while (!feof(fp2))
		{
			fputc((~fgetc(fp2)), fp3);
			len2++;
		}

		fwrite(&len1, sizeof(long), 1, fp3);
		fwrite(&len2, sizeof(long), 1, fp3);

		fclose(fp3);
		fclose(fp2);
		fclose(fp1);
	}
}
