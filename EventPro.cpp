
#include"head.h"
extern STATE_MACHINE  g_state;

void EventPro(char ch)
{
	switch (g_state.NOW_STATE)
	{
	case NO_COMMENT:
		EventProAtNo(ch);
		break;
	case C_COMMENT:
		EventProAtC(ch);
		break;
	case CPP_COMMEMT:
		EventProAtCpp(ch);
		break;
	case STR_COMMENT:
		EventProAtStr(ch);
		break;
	case END_FILE:
		break;
	default:
		break;
	}
}