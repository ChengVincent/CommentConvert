
#include"head.h"
extern STATE_MACHINE  g_state;
void EventProAtC(char ch)
{
	char NextChar='0';
	switch (ch)
	{
	case '/':
		NextChar = fgetc(g_state.InputFile);
		if (NextChar == '/')
		{
			fputc(' ',g_state.OutputFile);
			fputc(' ', g_state.OutputFile);
		}
		else if (NextChar=='*')
		{
			fputc(' ', g_state.OutputFile);
			fputc(' ', g_state.OutputFile);
		}
		else
		{
			fputc(ch, g_state.OutputFile);
			fputc(NextChar, g_state.OutputFile);
		}
		break;
	case '*':
		NextChar = fgetc(g_state.InputFile);
		if (NextChar == '/')
		{
			fputc(ch, g_state.OutputFile);
			fputc(NextChar, g_state.OutputFile);
			g_state.NOW_STATE = NO_COMMENT;
		}
		else
		{
			fputc(ch, g_state.OutputFile);
			fputc(NextChar, g_state.OutputFile);
		}
		break;
	case '\n':
		fputc(ch, g_state.OutputFile);
		break;
	case EOF:
		fputc('*', g_state.OutputFile);
		fputc('/', g_state.OutputFile);
		g_state.NOW_STATE = END_FILE;
		break;
	default:
		fputc(ch, g_state.OutputFile);
		break;
	}
}
