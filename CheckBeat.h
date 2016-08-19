#pragma once

#include "resource.h"
#ifdef WIN32
#include "stdafx.h"
#include "Commdlg.h"
#include <XAudio2.h>
#endif
#define INITGUID
#include "sampledata.h"
#define MAX_LOADSTRING 100

#define NUM_DRUMS 4

class CheckBeat
{
public:
	CheckBeat();
	~CheckBeat();
	void Run();
	bool SetupAudio();
	void PlayNote(int noteNumber);
	void StopNote(int noteNumber);
#ifdef WIN32
	DWORD WINAPI Run( void* arg );
	IXAudio2* _xAudio2;
	IXAudio2MasteringVoice*	_masteringVoice;
	IXAudio2SourceVoice* _sourceVoice[4];
	HWND hWnd;
	LARGE_INTEGER currtime;
	LARGE_INTEGER lasttime;
	LARGE_INTEGER tickspersec;
#endif
	//WaveFile* _sample[NUM_DRUMS];
	SampleData* _sample[NUM_DRUMS];
	bool _playing[NUM_DRUMS];
	bool done;
	bool playing;
	int step; // Keep track of which sequencer step we are on.
	int steps; // Keep track of total steps
	int bpm;
	int division; // Parts of a quarter note per beat. 1 = 1/4, 2 = 1/8, 4 = 1/16, 8 = 1/32.
};
