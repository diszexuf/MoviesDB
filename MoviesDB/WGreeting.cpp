#include "WGreeting.h"

using namespace MoviesDB;
using namespace System;

int greet(array<String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	Application::Run(gcnew WGreeting);
	return 0;
}
