#include "command.h"

Command* Command::m_instance = nullptr;

Command::Command()
{
}

Command::~Command()
{
}

Command* Command::Instance()
{
	if (m_instance) return m_instance;

	m_instance = new Command();
	return m_instance;
}

void Command::KillInstance()
{
	if (m_instance) {
		delete m_instance;
		m_instance = nullptr;
	}
}

void Command::SetCommand(const std::string& command)
{
	m_command = command;
}

std::string& Command::LastCommand()
{
	return m_command;
}
