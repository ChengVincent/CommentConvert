#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

typedef enum
{
	NO_COMMENT,
	C_COMMENT,
	CPP_COMMEMT,
	STR_COMMENT,
	END_FILE
}COMMENT_STATE;

typedef struct
{
	FILE *InputFile;
	FILE *OutputFile;
	COMMENT_STATE NOW_STATE;
}STATE_MACHINE;

int CommentConvert(FILE *inputfile, FILE *outputfile);
void EventPro(char ch);
void EventProAtNo(char ch);
void EventProAtC(char ch);
void EventProAtCpp(char ch);
void EventProAtStr(char ch);
//STATE_MACHINE  g_state = { 0 };
