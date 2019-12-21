#pragma once

#include <map>
#include <string>

struct Cmd
{

};

class Command
{
private:
	Command();
	~Command();

public:
	static Command* Instance();
	static void KillInstance();
	void SetCommand(const std::string& command);
	std::string& LastCommand();

private:
	static Command* m_instance;
	std::string m_command;

};