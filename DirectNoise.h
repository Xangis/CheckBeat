#pragma once

#include "resource.h"
#ifdef WIN32
#include "stdafx.h"
#include "Commdlg.h"
#define INITGUID
//#include <dmusici.h>
#endif
#define MAX_LOADSTRING 100

class CheckBeat
{
public:
	CheckBeat();
	~CheckBeat();
	void Run();
	DWORD WINAPI Run( void* arg );
	IDirectMusicLoader8*		_pLoader;
	IDirectMusicPerformance8*	_pPerformance;
	IDirectMusicSegment8*		_pSegment1;
	IDirectMusicSegment8*		_pSegment2;
	IDirectMusicSegment8*		_pSegment3;
	IDirectMusicSegment8*		_pSegment4;
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
