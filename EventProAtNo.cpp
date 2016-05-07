
#include"head.h"
extern STATE_MACHINE  g_state;

void EventProAtNo(char ch)
{

	char NextChar='0';
	switch (ch)
	{
	case '/':
		NextChar = fgetc(g_state.InputFile);
		if (NextChar == '/') 
		{
			fputc(ch, g_state.OutputFile);
			fputc('*', g_state.OutputFile);
			g_state.NOW_STATE = CPP_COMMEMT;
		}
		else if (NextChar == '*')
		{
			fputc(ch, g_state.OutputFile);
			fputc(NextChar, g_state.OutputFile);
			g_state.NOW_STATE = C_COMMENT;
		}
		else if (NextChar == EOF)
		{
			fputc(ch, g_state.OutputFile);
			g_state.NOW_STATE = END_FILE;
		}
		else
		{
			fputc(ch, g_state.OutputFile);
			fputc(NextChar, g_state.OutputFile);
		}
		break;
	case '\"':
		fputc(ch, g_state.OutputFile);
		g_state.NOW_STATE = STR_COMMENT;
		break;
	case EOF:
		g_state.NOW_STATE = END_FILE;
		break;
	default:
		fputc(ch, g_state.OutputFile);
		break;
	}
}