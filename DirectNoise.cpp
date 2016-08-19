// DirectNoise.cpp : Defines the entry point for the application.
//

#include "DirectNoise.h"
#include <stdio.h>
#include <stdlib.h>

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

// Global application object.
CheckBeat* g_checkBeat;

// Forward declarations of functions included in this code module:
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK DrumPanelDialog( HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
DWORD WINAPI gRunThread( void* arg )
{	return g_checkBeat->Run( arg ); }

CheckBeat::CheckBeat()
{
	done = false;
	playing = false;
	step = 1; // Keep track of which sequencer step we are on.
	steps = 16; // Keep track of total steps
	bpm = 120;
	division = 1; // Parts of a quarter note per beat. 1 = 1/4, 2 = 1/8, 4 = 1/16, 8 = 1/32.
	for( int i = 0; i < NUM_DRUMS; i++ )
	{
		_sample[i] = NULL;
	}
}

CheckBeat::~CheckBeat()
{
}

DWORD WINAPI CheckBeat::Run( void * arg )
{
	while( !done )
	{
		if( playing == true )
		{
			QueryPerformanceCounter( &currtime );
			// BPM / 60 = Beats per second.
			// Ticks per second / beats per second = ticks per beat.
			// Ticks per beat / beat division ratio of note = ticks per note.
			if( (currtime.QuadPart - lasttime.QuadPart) >
				( tickspersec.QuadPart / ((bpm * division) / 60.0f )))
			{

				// Increment the current step and wrap it at our max steps count.
				// We're using 1 to N for our step count.
				step = step % steps + 1;
				// Now, play our sounds that are set to be on that beat.
				// This gets a little stupid because we have to know our checkbox names.
				HWND checkbox;
				switch( step )
				{
				case 1:
  					checkbox = GetDlgItem( hWnd, IDC_CHECK1 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						Mix_PlayChannel(-1, _sample[0], 0);
					checkbox = GetDlgItem( hWnd, IDC_CHECK17 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						Mix_PlayChannel(-1, _sample[1], 0);
					checkbox = GetDlgItem( hWnd, IDC_CHECK33 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						Mix_PlayChannel(-1, _sample[2], 0);
					checkbox = GetDlgItem( hWnd, IDC_CHECK49 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						Mix_PlayChannel(-1, _sample[3], 0);
					break;
				case 2:
					checkbox = GetDlgItem( hWnd, IDC_CHECK2 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						Mix_PlayChannel(-1, _sample[0], 0);
					checkbox = GetDlgItem( hWnd, IDC_CHECK18 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						Mix_PlayChannel(-1, _sample[1], 0);
					checkbox = GetDlgItem( hWnd, IDC_CHECK34 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						Mix_PlayChannel(-1, _sample[2], 0);
					checkbox = GetDlgItem( hWnd, IDC_CHECK50 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						Mix_PlayChannel(-1, _sample[3], 0);
					break;
				case 3:
					checkbox = GetDlgItem( hWnd, IDC_CHECK3 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						Mix_PlayChannel(-1, _sample[0], 0);
					checkbox = GetDlgItem( hWnd, IDC_CHECK19 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						Mix_PlayChannel(-1, _sample[1], 0);
					checkbox = GetDlgItem( hWnd, IDC_CHECK35 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						Mix_PlayChannel(-1, _sample[2], 0);
					checkbox = GetDlgItem( hWnd, IDC_CHECK51 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						Mix_PlayChannel(-1, _sample[3], 0);
					break;
				case 4:
					checkbox = GetDlgItem( hWnd, IDC_CHECK4 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						Mix_PlayChannel(-1, _sample[0], 0);
					checkbox = GetDlgItem( hWnd, IDC_CHECK20 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						Mix_PlayChannel(-1, _sample[1], 0);
					checkbox = GetDlgItem( hWnd, IDC_CHECK36 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						Mix_PlayChannel(-1, _sample[2], 0);
					checkbox = GetDlgItem( hWnd, IDC_CHECK52 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						Mix_PlayChannel(-1, _sample[3], 0);
					break;
				case 5:
					checkbox = GetDlgItem( hWnd, IDC_CHECK5 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						Mix_PlayChannel(-1, _sample[0], 0);
					checkbox = GetDlgItem( hWnd, IDC_CHECK21 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						Mix_PlayChannel(-1, _sample[1], 0);
					checkbox = GetDlgItem( hWnd, IDC_CHECK37 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						Mix_PlayChannel(-1, _sample[2], 0);
					checkbox = GetDlgItem( hWnd, IDC_CHECK53 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						Mix_PlayChannel(-1, _sample[3], 0);
					break;
				case 6:
					checkbox = GetDlgItem( hWnd, IDC_CHECK6 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						Mix_PlayChannel(-1, _sample[0], 0);
					checkbox = GetDlgItem( hWnd, IDC_CHECK22 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						Mix_PlayChannel(-1, _sample[1], 0);
					checkbox = GetDlgItem( hWnd, IDC_CHECK38 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						Mix_PlayChannel(-1, _sample[2], 0);
					checkbox = GetDlgItem( hWnd, IDC_CHECK54 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						Mix_PlayChannel(-1, _sample[3], 0);
					break;
				case 7:
					checkbox = GetDlgItem( hWnd, IDC_CHECK7 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						Mix_PlayChannel(-1, _sample[0], 0);
					checkbox = GetDlgItem( hWnd, IDC_CHECK23 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						Mix_PlayChannel(-1, _sample[1], 0);
					checkbox = GetDlgItem( hWnd, IDC_CHECK39 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						Mix_PlayChannel(-1, _sample[2], 0);
					checkbox = GetDlgItem( hWnd, IDC_CHECK55 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						Mix_PlayChannel(-1, _sample[3], 0);
					break;
				case 8:
					checkbox = GetDlgItem( hWnd, IDC_CHECK8 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						Mix_PlayChannel(-1, _sample[0], 0);
					checkbox = GetDlgItem( hWnd, IDC_CHECK24 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						Mix_PlayChannel(-1, _sample[1], 0);
					checkbox = GetDlgItem( hWnd, IDC_CHECK40 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						Mix_PlayChannel(-1, _sample[2], 0);
					checkbox = GetDlgItem( hWnd, IDC_CHECK56 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						Mix_PlayChannel(-1, _sample[3], 0);
					break;
				case 9:
					checkbox = GetDlgItem( hWnd, IDC_CHECK9 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						Mix_PlayChannel(-1, _sample[0], 0);
					checkbox = GetDlgItem( hWnd, IDC_CHECK25 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						Mix_PlayChannel(-1, _sample[1], 0);
					checkbox = GetDlgItem( hWnd, IDC_CHECK41 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						Mix_PlayChannel(-1, _sample[2], 0);
					checkbox = GetDlgItem( hWnd, IDC_CHECK57 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						Mix_PlayChannel(-1, _sample[3], 0);
					break;
				case 10:
					checkbox = GetDlgItem( hWnd, IDC_CHECK10);
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						Mix_PlayChannel(-1, _sample[0], 0);
					checkbox = GetDlgItem( hWnd, IDC_CHECK26 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						Mix_PlayChannel(-1, _sample[1], 0);
					checkbox = GetDlgItem( hWnd, IDC_CHECK42 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						Mix_PlayChannel(-1, _sample[2], 0);
					checkbox = GetDlgItem( hWnd, IDC_CHECK58 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						Mix_PlayChannel(-1, _sample[3], 0);
					break;
				case 11:
					checkbox = GetDlgItem( hWnd, IDC_CHECK11 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						Mix_PlayChannel(-1, _sample[0], 0);
					checkbox = GetDlgItem( hWnd, IDC_CHECK27 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						Mix_PlayChannel(-1, _sample[1], 0);
					checkbox = GetDlgItem( hWnd, IDC_CHECK43 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						Mix_PlayChannel(-1, _sample[2], 0);
					checkbox = GetDlgItem( hWnd, IDC_CHECK59 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						Mix_PlayChannel(-1, _sample[3], 0);
					break;
				case 12:
					checkbox = GetDlgItem( hWnd, IDC_CHECK12 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						Mix_PlayChannel(-1, _sample[0], 0);
					checkbox = GetDlgItem( hWnd, IDC_CHECK28 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						Mix_PlayChannel(-1, _sample[1], 0);
					checkbox = GetDlgItem( hWnd, IDC_CHECK44 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						Mix_PlayChannel(-1, _sample[2], 0);
					checkbox = GetDlgItem( hWnd, IDC_CHECK60 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						Mix_PlayChannel(-1, _sample[3], 0);
					break;
				case 13:
					checkbox = GetDlgItem( hWnd, IDC_CHECK13 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						Mix_PlayChannel(-1, _sample[0], 0);
					checkbox = GetDlgItem( hWnd, IDC_CHECK29 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						Mix_PlayChannel(-1, _sample[1], 0);
					checkbox = GetDlgItem( hWnd, IDC_CHECK45 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						Mix_PlayChannel(-1, _sample[2], 0);
					checkbox = GetDlgItem( hWnd, IDC_CHECK61 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						Mix_PlayChannel(-1, _sample[3], 0);
					break;
				case 14:
					checkbox = GetDlgItem( hWnd, IDC_CHECK14 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						Mix_PlayChannel(-1, _sample[0], 0);
					checkbox = GetDlgItem( hWnd, IDC_CHECK30 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						Mix_PlayChannel(-1, _sample[1], 0);
					checkbox = GetDlgItem( hWnd, IDC_CHECK46 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						Mix_PlayChannel(-1, _sample[2], 0);
					checkbox = GetDlgItem( hWnd, IDC_CHECK62 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						Mix_PlayChannel(-1, _sample[3], 0);
					break;
				case 15:
					checkbox = GetDlgItem( hWnd, IDC_CHECK15 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						Mix_PlayChannel(-1, _sample[0], 0);
					checkbox = GetDlgItem( hWnd, IDC_CHECK31 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						Mix_PlayChannel(-1, _sample[1], 0);
					checkbox = GetDlgItem( hWnd, IDC_CHECK47 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						Mix_PlayChannel(-1, _sample[2], 0);
					checkbox = GetDlgItem( hWnd, IDC_CHECK63 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						Mix_PlayChannel(-1, _sample[3], 0);
					break;
				case 16:
					checkbox = GetDlgItem( hWnd, IDC_CHECK16 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						Mix_PlayChannel(-1, _sample[0], 0);
					checkbox = GetDlgItem( hWnd, IDC_CHECK32 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						Mix_PlayChannel(-1, _sample[1], 0);
					checkbox = GetDlgItem( hWnd, IDC_CHECK48 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						Mix_PlayChannel(-1, _sample[2], 0);
					checkbox = GetDlgItem( hWnd, IDC_CHECK64 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						Mix_PlayChannel(-1, _sample[3], 0);
					break;
				default:
					break;
				}
				// Set our time so we know when to play the next beat.
				lasttime = currtime;
			}
			else
			{
				Sleep(1);
			}
		}
	}
	return 0;
}

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	MSG msg;
	HACCEL hAccelTable;

	g_checkBeat = new CheckBeat;

	// SDL Init
    // Initialize the SDL library with the Video subsystem
    SDL_Init(SDL_INIT_AUDIO);
    atexit(SDL_Quit);
    // Set up the audio stream
    int result = Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 512);
    if( result < 0 )
    {
        fprintf(stderr, "Unable to open audio: %s\n", SDL_GetError());
        exit(-1);
    }

    result = Mix_AllocateChannels(8);
    if( result < 0 )
    {
        fprintf(stderr, "Unable to allocate mixing channels: %s\n", SDL_GetError());
        exit(-1);
    }
	// End SDL Init

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_DIRECTNOISE, szWindowClass, MAX_LOADSTRING);

	hAccelTable = LoadAccelerators(hInstance, (LPCTSTR)IDC_DIRECTNOISE);

	HWND hWnd = CreateDialog(hInst, (LPCTSTR)IDD_DRUMPANEL, NULL, (DLGPROC)DrumPanelDialog);
	g_checkBeat->hWnd = hWnd;
	ShowWindow( hWnd, nCmdShow );

	// Set default Values
	HWND DlgItem = GetDlgItem( hWnd, IDC_BPM );
	SetWindowText( DlgItem, "120" );
	DlgItem = GetDlgItem( hWnd, IDC_BEATS );
	SetWindowText( DlgItem, "16" );
	DlgItem = GetDlgItem( hWnd, IDC_KICK_FILENAME );
	SetWindowText( DlgItem, "kick.wav" );
	DlgItem = GetDlgItem( hWnd, IDC_SNARE_FILENAME );
	SetWindowText( DlgItem, "snare.wav" );
	DlgItem = GetDlgItem( hWnd, IDC_HIHAT_FILENAME );
	SetWindowText( DlgItem, "hihat.wav" );
	DlgItem = GetDlgItem( hWnd, IDC_C_HIHAT_FILENAME );
	SetWindowText( DlgItem, "c_hihat.wav" );
	DlgItem = GetDlgItem( hWnd, IDC_RESOLUTION );
	SendMessage( DlgItem, CB_ADDSTRING, 0, (LPARAM)(LPCSTR)"1/32" );
	SendMessage( DlgItem, CB_ADDSTRING, 1, (LPARAM)(LPCSTR)"1/16" );
	SendMessage( DlgItem, CB_ADDSTRING, 2, (LPARAM)(LPCSTR)"1/8" );
	SendMessage( DlgItem, CB_ADDSTRING, 3, (LPARAM)(LPCSTR)"1/4" );
	SendMessage( DlgItem, CB_SETCURSEL, 1, 0 );
	// Kick on first beat default when starting.
	DlgItem = GetDlgItem( hWnd, IDC_CHECK1 );
	SendMessage( DlgItem, BM_SETCHECK, BST_CHECKED, 0);
	DlgItem = GetDlgItem( hWnd, IDC_STOP );
	EnableWindow( DlgItem, false );

	QueryPerformanceFrequency( &g_checkBeat->tickspersec );
	QueryPerformanceCounter( &g_checkBeat->currtime );
	g_checkBeat->lasttime = g_checkBeat->currtime;

	DWORD t;
	CreateThread( NULL, 0, gRunThread, NULL, 0, &t );

	// Main message loop:
	while (!g_checkBeat->done ) 
	{
		if( PeekMessage(&msg, NULL, 0, 0, PM_REMOVE ))
		{
			if( !IsDialogMessage( hWnd, &msg ))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
	}

    for( int i = 0; i < NUM_DRUMS; i++ )
    {
        Mix_FreeChunk(g_checkBeat->_sample[i]);
    }
	Mix_CloseAudio();
	SDL_Quit();

	return 0;
}


//
//  FUNCTION: WndProc(HWND, unsigned, WORD, LONG)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message) 
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam); 
		wmEvent = HIWORD(wParam); 
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code here...
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
LRESULT CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_INITDIALOG:
		return TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) 
		{
			EndDialog(hDlg, LOWORD(wParam));
			return TRUE;
		}
		break;
	}
	return FALSE;
}

BOOL CALLBACK DrumPanelDialog( HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	OPENFILENAME file;
	char szFile[MAX_PATH];
	char szGetFilename[MAX_PATH];
	HWND TextCtrl;
	char bpmtext[12];
	char beats[12];

	switch( message )
	{
	case WM_INITDIALOG:
		return TRUE;

	case WM_COMMAND:
		switch( LOWORD(wParam))
		{
		case IDM_ABOUT:
			DialogBox(hInst, (LPCTSTR)IDD_ABOUTBOX, hDlg, (DLGPROC)About);
			break;
		case IDC_HELP:
			MessageBox(hDlg, TEXT("CheckBeat is a basic drum machine and is pretty simple to use.\n\nIt creates sound by playing .wav files based on a pattern you create.\nYou create patterns by checking the boxes below each .wav file to turn the sound on for that beat.\nEach box corresponds to a beat of a 16-beat sequence.\nYou can make the sequences shorter by changing the 'Beats/Pattern' to a number below 16 and can change the tempo and note duration per beat.\nYou can only make changes to the speed and select different .wav files while the beat is not playing.\nThe start and stop buttons let you control that.\nYou can, however, edit the pattern while the beat is playing."), TEXT("CheckBeat Help"), MB_OK);
			break;
		case IDEXIT:
			DestroyWindow( hDlg );
			g_checkBeat->done = true;
			return TRUE;
			break;
		case WM_QUIT:
			DestroyWindow( hDlg );
			g_checkBeat->done = true;
			return TRUE;
			break;
		case WM_DESTROY:
			PostQuitMessage(0);
			g_checkBeat->done = true;
			return TRUE;
			break;
		case IDC_STOP:
			g_checkBeat->playing = false;
			TextCtrl = GetDlgItem( hDlg, IDC_RESOLUTION );
			EnableWindow( TextCtrl, true );
			TextCtrl = GetDlgItem( hDlg, IDC_BEATS );
			EnableWindow( TextCtrl, true );
			TextCtrl = GetDlgItem( hDlg, IDC_BPM );
			EnableWindow( TextCtrl, true );
			TextCtrl = GetDlgItem( hDlg, IDC_KICK_FILENAME );
			EnableWindow( TextCtrl, true );
			TextCtrl = GetDlgItem( hDlg, IDC_SNARE_FILENAME );
			EnableWindow( TextCtrl, true );
			TextCtrl = GetDlgItem( hDlg, IDC_C_HIHAT_FILENAME );
			EnableWindow( TextCtrl, true );
			TextCtrl = GetDlgItem( hDlg, IDC_HIHAT_FILENAME );
			EnableWindow( TextCtrl, true );
			TextCtrl = GetDlgItem( hDlg, IDC_KICK_BROWSE );
			EnableWindow( TextCtrl, true );
			TextCtrl = GetDlgItem( hDlg, IDC_SNARE_BROWSE );
			EnableWindow( TextCtrl, true );
			TextCtrl = GetDlgItem( hDlg, IDC_C_HIHAT_BROWSE );
			EnableWindow( TextCtrl, true );
			TextCtrl = GetDlgItem( hDlg, IDC_HIHAT_BROWSE );
			EnableWindow( TextCtrl, true );
			TextCtrl = GetDlgItem( hDlg, IDC_STOP );
			EnableWindow( TextCtrl, false );
			TextCtrl = GetDlgItem( hDlg, IDC_START );
			EnableWindow( TextCtrl, true );
			return TRUE;
			break;
		case IDC_START:
			{
			TextCtrl = GetDlgItem( hDlg, IDC_BPM );
			GetWindowText( TextCtrl, bpmtext, 10 );
			TextCtrl = GetDlgItem( hDlg, IDC_BEATS );
			GetWindowText( TextCtrl, beats, 10 );
			g_checkBeat->steps = atoi( beats );
			g_checkBeat->bpm = atoi( bpmtext );
			if( g_checkBeat->steps == 0 )
			{
				MessageBox( hDlg, "I refuse to play with 0 beats per pattern.", "Stupid Human", MB_OK );
				return TRUE;
			}
			if( g_checkBeat->bpm == 0 )
			{
				MessageBox( hDlg, "I refuse to play with 0 beats per minute.", "Stupid Human", MB_OK );
				return TRUE;
			}

			// Free drums to prevent memory leaks.
			for( int i = 0; i < NUM_DRUMS; i++ )
			{
				if( g_checkBeat->_sample[0] != NULL )
				{
					Mix_FreeChunk(g_checkBeat->_sample[i]);
				}
			}

			// Get our "kick" sound
			TextCtrl = GetDlgItem( hDlg, IDC_KICK_FILENAME );
			GetWindowText( TextCtrl, szGetFilename, MAX_PATH );
			g_checkBeat->_sample[0] = Mix_LoadWAV(szGetFilename);
			if (!g_checkBeat->_sample[0])    // Pointer that receives interface.
			{		
				MessageBox( hDlg, "Wave file 1 not found.", szGetFilename, MB_OK );
				return 0;
			}

			// Get our "snare" sound
			TextCtrl = GetDlgItem( hDlg, IDC_SNARE_FILENAME );
			GetWindowText( TextCtrl, szGetFilename, MAX_PATH );
			g_checkBeat->_sample[1] = Mix_LoadWAV(szGetFilename);
			if (!g_checkBeat->_sample[1])    // Pointer that receives interface.
			{		
				MessageBox( hDlg, "Wave file 2 not found.", szGetFilename, MB_OK );
				return 0;
			}

			// Get our "closed hihat" sound
			TextCtrl = GetDlgItem( hDlg, IDC_C_HIHAT_FILENAME );
			GetWindowText( TextCtrl, szGetFilename, MAX_PATH );
			g_checkBeat->_sample[2] = Mix_LoadWAV(szGetFilename);
			if (!g_checkBeat->_sample[2])    // Pointer that receives interface.
			{		
				MessageBox( hDlg, "Wave file 3 not found.", szGetFilename, MB_OK );
				return 0;
			}

			// Get our "open hihat" sound
			TextCtrl = GetDlgItem( hDlg, IDC_HIHAT_FILENAME );
			GetWindowText( TextCtrl, szGetFilename, MAX_PATH );
			g_checkBeat->_sample[3] = Mix_LoadWAV(szGetFilename);
			if (!g_checkBeat->_sample[3])    // Pointer that receives interface.
			{		
				MessageBox( hDlg, "Wave file 4 not found.", szGetFilename, MB_OK );
				return 0;
			}

			TextCtrl = GetDlgItem( hDlg, IDC_RESOLUTION );
			// Get note division size.
			int selection = (int)SendMessage( TextCtrl, CB_GETCURSEL, 0, 0 );
			switch( selection )
			{
				case 0: g_checkBeat->division = 8; break; // 1/32
				case 1: g_checkBeat->division = 4; break; // 1/16
				case 2: g_checkBeat->division = 2; break; // 1/8
				case 3: g_checkBeat->division = 1; break; // 1/4
			}
			EnableWindow( TextCtrl, false );
			TextCtrl = GetDlgItem( hDlg, IDC_BEATS );
			EnableWindow( TextCtrl, false );
			TextCtrl = GetDlgItem( hDlg, IDC_BPM );
			EnableWindow( TextCtrl, false );
			TextCtrl = GetDlgItem( hDlg, IDC_KICK_FILENAME );
			EnableWindow( TextCtrl, false );
			TextCtrl = GetDlgItem( hDlg, IDC_SNARE_FILENAME );
			EnableWindow( TextCtrl, false );
			TextCtrl = GetDlgItem( hDlg, IDC_C_HIHAT_FILENAME );
			EnableWindow( TextCtrl, false );
			TextCtrl = GetDlgItem( hDlg, IDC_HIHAT_FILENAME );
			EnableWindow( TextCtrl, false );
			TextCtrl = GetDlgItem( hDlg, IDC_KICK_BROWSE );
			EnableWindow( TextCtrl, false );
			TextCtrl = GetDlgItem( hDlg, IDC_SNARE_BROWSE );
			EnableWindow( TextCtrl, false );
			TextCtrl = GetDlgItem( hDlg, IDC_C_HIHAT_BROWSE );
			EnableWindow( TextCtrl, false );
			TextCtrl = GetDlgItem( hDlg, IDC_HIHAT_BROWSE );
			EnableWindow( TextCtrl, false );
			TextCtrl = GetDlgItem( hDlg, IDC_STOP );
			EnableWindow( TextCtrl, true );
			TextCtrl = GetDlgItem( hDlg, IDC_START );
			EnableWindow( TextCtrl, false );
			g_checkBeat->playing = true;
			g_checkBeat->step = 1;
			return TRUE;
			}
			break;
		case IDC_KICK_BROWSE:
			ZeroMemory( &file, sizeof(file));
			file.lStructSize = sizeof(file);
			file.hwndOwner = hDlg;
			file.lpstrFile = szFile;
			file.lpstrFile[0] = '\0';
			file.nMaxFile = sizeof( szFile );
			file.lpstrFilter = "WAV Files\0*.WAV\0";
			file.nFilterIndex = 1;
			file.lpstrFileTitle = NULL;
			file.nMaxFileTitle = 0;
			file.lpstrInitialDir = NULL;
			file.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

			// Should call g_pSegment1->Unload if we have one in memory already.

			if( GetOpenFileName( &file ))
			{
				TextCtrl = GetDlgItem( hDlg, IDC_KICK_FILENAME );
				SetWindowText( TextCtrl, file.lpstrFile );
			}
			else if( CommDlgExtendedError() )
			{
				return TRUE;
			}

			return TRUE;
			break;
		case IDC_SNARE_BROWSE:
			ZeroMemory( &file, sizeof(file));
			file.lStructSize = sizeof(file);
			file.hwndOwner = hDlg;
			file.lpstrFile = szFile;
			file.lpstrFile[0] = '\0';
			file.nMaxFile = sizeof( szFile );
			file.lpstrFilter = "WAV Files\0*.WAV\0";
			file.nFilterIndex = 1;
			file.lpstrFileTitle = NULL;
			file.nMaxFileTitle = 0;
			file.lpstrInitialDir = NULL;
			file.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
					
			if( GetOpenFileName( &file ))
			{
				TextCtrl = GetDlgItem( hDlg, IDC_SNARE_FILENAME );
				SetWindowText( TextCtrl, file.lpstrFile );
			}
			else if( CommDlgExtendedError() )
			{
				return TRUE;
			}
			return TRUE;
			break;
		case IDC_C_HIHAT_BROWSE:
			ZeroMemory( &file, sizeof(file));
			file.lStructSize = sizeof(file);
			file.hwndOwner = hDlg;
			file.lpstrFile = szFile;
			file.lpstrFile[0] = '\0';
			file.nMaxFile = sizeof( szFile );
			file.lpstrFilter = "WAV Files\0*.WAV\0";
			file.nFilterIndex = 1;
			file.lpstrFileTitle = NULL;
			file.nMaxFileTitle = 0;
			file.lpstrInitialDir = NULL;
			file.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
					
			if( GetOpenFileName( &file ))
			{
				TextCtrl = GetDlgItem( hDlg, IDC_C_HIHAT_FILENAME );
				SetWindowText( TextCtrl, file.lpstrFile );
			}
			else if( CommDlgExtendedError() )
			{
				return TRUE;
			}
			return TRUE;
			break;
		case IDC_HIHAT_BROWSE:
			ZeroMemory( &file, sizeof(file));
			file.lStructSize = sizeof(file);
			file.hwndOwner = hDlg;
			file.lpstrFile = szFile;
			file.lpstrFile[0] = '\0';
			file.nMaxFile = sizeof( szFile );
			file.lpstrFilter = "WAV Files\0*.WAV\0";
			file.nFilterIndex = 1;
			file.lpstrFileTitle = NULL;
			file.nMaxFileTitle = 0;
			file.lpstrInitialDir = NULL;
			file.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
					
			if( GetOpenFileName( &file ))
			{
				TextCtrl = GetDlgItem( hDlg, IDC_HIHAT_FILENAME );
				SetWindowText( TextCtrl, file.lpstrFile );
			}
			else if( CommDlgExtendedError() )
			{
				return TRUE;
			}
			return TRUE;
			break;
		case IDC_RESOLUTION:
			{
				// TODO: React to resolution setting if item in list is changed.
			}
		default:
			return FALSE;
			break;
		}
		return TRUE;
		break;
	}

	return FALSE;
}
