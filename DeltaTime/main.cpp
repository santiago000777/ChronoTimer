#include "common.h"

int main() {
	std::chrono::time_point<std::chrono::high_resolution_clock> first, second;
	std::chrono::milliseconds duration;

	bool isRunning = false;

	while(!isRunning) {
		if (GetAsyncKeyState(VK_SPACE)) {
			first = std::chrono::high_resolution_clock::now();
			isRunning = true;
			Sleep(100);
		}
		while (isRunning) {
			if (GetAsyncKeyState(VK_SPACE)) {
				second = std::chrono::high_resolution_clock::now();
				break;
			}
		}
	}

	duration = std::chrono::duration_cast<std::chrono::milliseconds>(second - first);

	int deltaTime = duration.count();
	std::cout << deltaTime << std::endl;
}