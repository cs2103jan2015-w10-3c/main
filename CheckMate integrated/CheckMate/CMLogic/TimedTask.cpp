#include "TimedTask.h"



TimedTask::TimedTask(string Description,string Category ,string StartDate,string StartTime,string EndDate,string EndTime)
{ :Task( Description, Category);
_Startdate = StartDate;
_Starttime = StartTime;
_Enddate = EndDate;
_Endtime = EndTime;
}


TimedTask::~TimedTask(void)
{
}

