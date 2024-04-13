#ifndef ACTIONTYPEPICKER_H
#define ACTIONTYPEPICKER_H

enum ActionType
{
	AT_READ = 1,
	AT_GENERATE = 2
};

class ActionTypePicker
{
public:
	static ActionType pick();
};

#endif