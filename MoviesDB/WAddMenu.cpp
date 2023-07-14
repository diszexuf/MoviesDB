#include "WAddMenu.h"

using namespace System;
using namespace MoviesDB;

int add(array<String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	Application::Run(gcnew WAddMenu);
	return 0;
}
