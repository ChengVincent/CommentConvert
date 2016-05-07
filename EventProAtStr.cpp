#include"head.h"
extern STATE_MACHINE  g_state;

void EventProAtStr(char ch)
{
	switch (ch)
	{
	case '\"':
		fputc(ch,g_state.OutputFile);
		g_state.NOW_STATE = NO_COMMENT;
		break;
	default:
		fputc(ch, g_state.OutputFile);
		break;
	}
}