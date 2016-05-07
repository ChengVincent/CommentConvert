
#include"head.h"
STATE_MACHINE  g_state = { 0 };
 int main()
{
	 FILE *fpIn;
	 FILE *fpOut;
	 char InputFileName[20];
	 char OutputFileName[20];
	 printf("please input the route of  source file>");
	 scanf("%s",InputFileName);
	 printf("please input the route of  destination file>");
	 scanf("%s", OutputFileName);
	 printf("converting......\n");
	 fpIn = fopen(InputFileName, "r");
	 if (NULL == fpIn)
	 {
		 printf("Error: Open input.c file fail!\n");
		 system("pause");
		 return -1;
	 }
	 fpOut = fopen(OutputFileName, "w");
	 if (NULL == fpOut)
	 {
		 printf("Error: Open output.c file fail!\n");
		 system("pause");
		 return -1;
	 }
	 CommentConvert(fpIn, fpOut);

	 fclose(fpIn);
	 fclose(fpOut);
	 printf("convert success!!!");
	 system("pause");
	 return 0;
}