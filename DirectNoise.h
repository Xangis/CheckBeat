#ifndef _DIRECTNOISE_H_
#define _DIRECTNOISE_H_

// Used to enable modern control styles. No clue whether this works.
#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

#include "resource.h"
#ifdef WIN32
#include "stdafx.h"
#include "Commdlg.h"
#define INITGUID
#endif
#define MAX_LOADSTRING 100
#define NUM_DRUMS 4

#include "SDL.h"
#include "SDL_mixer.h"

class CheckBeat
{
public:
	CheckBeat();
	~CheckBeat();
	void Run();
	DWORD WINAPI Run( void* arg );
	Mix_Chunk* _sample[NUM_DRUMS];
	bool done;
	bool playing;
	int step; // Keep track of which sequencer step we are on.
	int steps; // Keep track of total steps
	int bpm;
	int division; // Parts of a quarter note per beat. 1 = 1/4, 2 = 1/8, 4 = 1/16, 8 = 1/32.
	LARGE_INTEGER currtime;
	LARGE_INTEGER lasttime;
	LARGE_INTEGER tickspersec;
	HWND hWnd;
};

#endif