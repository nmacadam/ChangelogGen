#pragma warning(disable : 4996)

#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <iomanip>
#include <ctime>

using namespace std;

int main()
{
	bool running = true;
	bool cmdFlag = false;

	ofstream changelog;
	changelog.open("changelog.txt", ios::out | ios::app);
	if (changelog.is_open())
	{
		string newChange;
		while (running)
		{
			cmdFlag = false;

			cout << ">>";
			getline(cin, newChange);

			std::time_t const time = std::time(NULL);

			if (newChange.compare(0, 1, "~") == 0)
			{
				cmdFlag = true;
			}
			if (newChange == "~quit") running = false;
			//if (newChange == "~undo") changelog << "\r";

			if (running && !cmdFlag) changelog << std::put_time(std::localtime(&time), "%D %T") << " | " << newChange << std::endl;
		}
		changelog.close();
	}
}