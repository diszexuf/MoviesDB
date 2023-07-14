#include "WMainMenu.h"
#include "WGreeting.h"


using namespace MoviesDB;
using namespace System;

[STAThread]
int main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew WMainMenu);
    return 0;
}
