#include <iostream>
#include <Windows.h>

typedef int(__thiscall* _PrintChat)(DWORD* self, const char* text, int arg3);
_PrintChat printChat;

struct GlobalOffsets {
	//Objects
	uintptr_t oLocalPlayer = 0x31090E8;

	//Functions
	uintptr_t fPrintChat = 0x599D90;
}off;


void Log(const char* text) {
	printChat(NULL, text, 5);
}


DWORD WINAPI MainThread(LPVOID param)
{

	AllocConsole();   
	FILE* f = new FILE();
	freopen_s(&f, "CONOUT$", "w", stdout);     
												

	printf("Console open!\n");   

	uintptr_t modBase = (uintptr_t)GetModuleHandle(NULL);

	// Assign Objects
	uintptr_t* LocalPlayerPtr = (uintptr_t*)(modBase + off.oLocalPlayer);
	uintptr_t LocalPlayer = *LocalPlayerPtr;


	// Assign Functions
	printChat = (_PrintChat)(modBase + off.fPrintChat);
	Log("DLL Injected!");
	
	while (!GetAsyncKeyState(VK_END))
	{
		if (GetAsyncKeyState(VK_F1) & 1)
		{
			Log("Pressed F1!");

		}
		if (GetAsyncKeyState(VK_F2) & 1)
		{
			printChat(NULL, "Pressed F2!", 12);
		}
	}
	FreeLibraryAndExitThread((HMODULE)param, 0);
	return 0;
}




BOOL WINAPI DllMain(HINSTANCE hModule, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		CreateThread(0, 0, MainThread, hModule, 0, 0);
		break;
	default:
		break;
	}
	return TRUE;
}
