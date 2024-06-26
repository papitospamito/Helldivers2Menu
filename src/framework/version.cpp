#include "version.h"
#include "main.hpp"
#include <filesystem>
#include "oxorany.h"
#include <iostream>

HMODULE version_dll = nullptr;

#define WRAPPER_FUNC(name) o##name = GetProcAddress(version_dll, ###name)

#pragma warning (disable: 4081)
#define STRINGIFY(name) #name
#define EXPORT_FUNCTION comment(linker, oxorany("/EXPORT:" __FUNCTION__ "=" __FUNCDNAME__))
#define WRAPPER_GENFUNC(name) \
    FARPROC o##name; \
    __declspec(dllexport) void WINAPI _##name() \
    { \
        __pragma(STRINGIFY(EXPORT_FUNCTION)); \
        o##name(); \
    }

WRAPPER_GENFUNC(GetFileVersionInfoA)
WRAPPER_GENFUNC(GetFileVersionInfoByHandle)
WRAPPER_GENFUNC(GetFileVersionInfoExW)
WRAPPER_GENFUNC(GetFileVersionInfoExA)
WRAPPER_GENFUNC(GetFileVersionInfoSizeA)
WRAPPER_GENFUNC(GetFileVersionInfoSizeExA)
WRAPPER_GENFUNC(GetFileVersionInfoSizeExW)
WRAPPER_GENFUNC(GetFileVersionInfoSizeW)
WRAPPER_GENFUNC(GetFileVersionInfoW)
WRAPPER_GENFUNC(VerFindFileA)
WRAPPER_GENFUNC(VerFindFileW)
WRAPPER_GENFUNC(VerInstallFileA)
WRAPPER_GENFUNC(VerInstallFileW)
WRAPPER_GENFUNC(VerLanguageNameA)
WRAPPER_GENFUNC(VerLanguageNameW)
WRAPPER_GENFUNC(VerQueryValueA)
WRAPPER_GENFUNC(VerQueryValueW)

void load_proxy() {
	char systemPath[MAX_PATH];
	GetSystemDirectoryA(systemPath, MAX_PATH);

	strcat_s(systemPath, oxorany("\\version.dll"));
	version_dll = LoadLibraryA(systemPath);

	if (!version_dll) {
		return;
	}

	WRAPPER_FUNC(GetFileVersionInfoA);
	WRAPPER_FUNC(GetFileVersionInfoByHandle);
	WRAPPER_FUNC(GetFileVersionInfoExW);
	WRAPPER_FUNC(GetFileVersionInfoExA);
	WRAPPER_FUNC(GetFileVersionInfoSizeA);
	WRAPPER_FUNC(GetFileVersionInfoSizeExW);
	WRAPPER_FUNC(GetFileVersionInfoSizeExA);
	WRAPPER_FUNC(GetFileVersionInfoSizeW);
	WRAPPER_FUNC(GetFileVersionInfoW);
	WRAPPER_FUNC(VerFindFileA);
	WRAPPER_FUNC(VerFindFileW);
	WRAPPER_FUNC(VerInstallFileA);
	WRAPPER_FUNC(VerInstallFileW);
	WRAPPER_FUNC(VerLanguageNameA);
	WRAPPER_FUNC(VerLanguageNameW);
	WRAPPER_FUNC(VerQueryValueA);
	WRAPPER_FUNC(VerQueryValueW);
}

DWORD WINAPI Load(LPVOID lpParam) {
	load_proxy();
	if (!version_dll) {
		return 0;
	}

	Run(lpParam);

	return 0;
}
