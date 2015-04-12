#include "CMHistory.h"


CMHistory :: CMHistory(void) {
}


void CMHistory :: updateCopy( std::vector<Task*> _allTasks) {
	_allTasksCopy=_allTasks;
}



std::vector<Task*> CMHistory:: swapCopy(std::vector<Task*> _allTasks){

	std::vector<Task*> _previousTaskCopy;
	_previousTaskCopy= _allTasksCopy;
	_allTasksCopy=	_allTasks;
	return _previousTaskCopy;

}
