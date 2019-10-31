#include "Task.h"

std::vector<Eigen::MatrixXf> Task::get() const {
    return stack;
}

std::vector<Eigen::MatrixXf> Task::getStack() const {
	std::vector<Eigen::MatrixXf> temp{stack};
	for (int i = 0; i < static_cast<int>(stack.size()); ++i) {
		temp[i] = stack[indices[i]];
	}
	return temp;
}

std::vector<int> Task::getInd() const {
	return indices;
}

int Task::size() const {
	return static_cast<int>(indices.size());
}

void Task::set(const std::vector<Eigen::MatrixXf>& stack_) {
	stack = stack_;
}

void Task::goUpTo(int start, int end) {
	int temp{indices[start]};
	for (int i = start; i > end; --i) {
		indices[i] = indices[i-1];
	}
	indices[end] = temp;
}

void Task::swapTask(int i, int j) {
    int temp{indices[i]};
    indices[i] = indices[j];
    indices[j] = temp;
}

Eigen::MatrixXf Task::operator[](int k) const {
	//Prioritized access
    return stack[indices[k]];
}

Eigen::MatrixXf Task::operator()(int k) const {
	//Standard access
	return stack[k];
}
