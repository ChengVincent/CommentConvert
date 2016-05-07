#include"head.h"
extern STATE_MACHINE  g_state;

int CommentConvert(FILE *inputfile, FILE *outputfile)
{
	if (inputfile == NULL || outputfile == NULL)
	{
		printf("Error: Argument Invalid!\n");
		return -1;
	}

	////////////////////////////////////////////////
	//
	g_state.InputFile = inputfile;
	g_state.OutputFile = outputfile;
	g_state.NOW_STATE = NO_COMMENT;

	char ch;
	while (g_state.NOW_STATE != END_FILE)
	{
		ch = fgetc(g_state.InputFile);
		EventPro(ch);
	}
	return 0;
}
