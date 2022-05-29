#ifndef SDDS_TIMEDTASK_H
#define SDDS_TIMEDTSK_H
#include <chrono>
#include <cstring>
#include <iostream>
namespace sdds {
	class Task {
		std::string m_taskName;
		std::string m_unitTime;
		std::chrono::steady_clock::duration m_taskDuration;
	};
	class TimedTask
	{
		int m_recordNum;
		std::chrono::steady_clock::time_point m_startTime;
		std::chrono::steady_clock::time_point m_endTime;
		Task m_tasks[10];
	public:
		TimedTask();
		void startClock();
		void stopClock();
		void addTask(const char* taskName);
		~TimedTask();
		std::ostream& operator << (std::ostream& os);
	};
}
#endif

