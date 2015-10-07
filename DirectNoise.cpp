// DirectNoise.cpp : Defines the entry point for the application.
//


#include "DirectNoise.h"

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
	_pLoader = NULL;
	_pPerformance = NULL;
	_pSegment1 = NULL;
	_pSegment2 = NULL;
	_pSegment3 = NULL;
	_pSegment4 = NULL;
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
						_pPerformance->PlaySegment( _pSegment1, 0, 0, NULL );
					checkbox = GetDlgItem( hWnd, IDC_CHECK17 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						_pPerformance->PlaySegment( _pSegment2, 0, 0, NULL );
					checkbox = GetDlgItem( hWnd, IDC_CHECK33 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						_pPerformance->PlaySegment( _pSegment3, 0, 0, NULL );
					checkbox = GetDlgItem( hWnd, IDC_CHECK49 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						_pPerformance->PlaySegment( _pSegment4, 0, 0, NULL );
					break;
				case 2:
					checkbox = GetDlgItem( hWnd, IDC_CHECK2 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						_pPerformance->PlaySegment( _pSegment1, 0, 0, NULL );
					checkbox = GetDlgItem( hWnd, IDC_CHECK18 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						_pPerformance->PlaySegment( _pSegment2, 0, 0, NULL );
					checkbox = GetDlgItem( hWnd, IDC_CHECK34 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						_pPerformance->PlaySegment( _pSegment3, 0, 0, NULL );
					checkbox = GetDlgItem( hWnd, IDC_CHECK50 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						_pPerformance->PlaySegment( _pSegment4, 0, 0, NULL );
					break;
				case 3:
					checkbox = GetDlgItem( hWnd, IDC_CHECK3 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						_pPerformance->PlaySegment( _pSegment1, 0, 0, NULL );
					checkbox = GetDlgItem( hWnd, IDC_CHECK19 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						_pPerformance->PlaySegment( _pSegment2, 0, 0, NULL );
					checkbox = GetDlgItem( hWnd, IDC_CHECK35 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						_pPerformance->PlaySegment( _pSegment3, 0, 0, NULL );
					checkbox = GetDlgItem( hWnd, IDC_CHECK51 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						_pPerformance->PlaySegment( _pSegment4, 0, 0, NULL );
					break;
				case 4:
					checkbox = GetDlgItem( hWnd, IDC_CHECK4 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						_pPerformance->PlaySegment( _pSegment1, 0, 0, NULL );
					checkbox = GetDlgItem( hWnd, IDC_CHECK20 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						_pPerformance->PlaySegment( _pSegment2, 0, 0, NULL );
					checkbox = GetDlgItem( hWnd, IDC_CHECK36 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						_pPerformance->PlaySegment( _pSegment3, 0, 0, NULL );
					checkbox = GetDlgItem( hWnd, IDC_CHECK52 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						_pPerformance->PlaySegment( _pSegment4, 0, 0, NULL );
					break;
				case 5:
					checkbox = GetDlgItem( hWnd, IDC_CHECK5 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						_pPerformance->PlaySegment( _pSegment1, 0, 0, NULL );
					checkbox = GetDlgItem( hWnd, IDC_CHECK21 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						_pPerformance->PlaySegment( _pSegment2, 0, 0, NULL );
					checkbox = GetDlgItem( hWnd, IDC_CHECK37 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						_pPerformance->PlaySegment( _pSegment3, 0, 0, NULL );
					checkbox = GetDlgItem( hWnd, IDC_CHECK53 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						_pPerformance->PlaySegment( _pSegment4, 0, 0, NULL );
					break;
				case 6:
					checkbox = GetDlgItem( hWnd, IDC_CHECK6 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						_pPerformance->PlaySegment( _pSegment1, 0, 0, NULL );
					checkbox = GetDlgItem( hWnd, IDC_CHECK22 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						_pPerformance->PlaySegment( _pSegment2, 0, 0, NULL );
					checkbox = GetDlgItem( hWnd, IDC_CHECK38 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						_pPerformance->PlaySegment( _pSegment3, 0, 0, NULL );
					checkbox = GetDlgItem( hWnd, IDC_CHECK54 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						_pPerformance->PlaySegment( _pSegment4, 0, 0, NULL );
					break;
				case 7:
					checkbox = GetDlgItem( hWnd, IDC_CHECK7 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						_pPerformance->PlaySegment( _pSegment1, 0, 0, NULL );
					checkbox = GetDlgItem( hWnd, IDC_CHECK23 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						_pPerformance->PlaySegment( _pSegment2, 0, 0, NULL );
					checkbox = GetDlgItem( hWnd, IDC_CHECK39 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						_pPerformance->PlaySegment( _pSegment3, 0, 0, NULL );
					checkbox = GetDlgItem( hWnd, IDC_CHECK55 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						_pPerformance->PlaySegment( _pSegment4, 0, 0, NULL );
					break;
				case 8:
					checkbox = GetDlgItem( hWnd, IDC_CHECK8 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						_pPerformance->PlaySegment( _pSegment1, 0, 0, NULL );
					checkbox = GetDlgItem( hWnd, IDC_CHECK24 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						_pPerformance->PlaySegment( _pSegment2, 0, 0, NULL );
					checkbox = GetDlgItem( hWnd, IDC_CHECK40 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						_pPerformance->PlaySegment( _pSegment3, 0, 0, NULL );
					checkbox = GetDlgItem( hWnd, IDC_CHECK56 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						_pPerformance->PlaySegment( _pSegment4, 0, 0, NULL );
					break;
				case 9:
					checkbox = GetDlgItem( hWnd, IDC_CHECK9 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						_pPerformance->PlaySegment( _pSegment1, 0, 0, NULL );
					checkbox = GetDlgItem( hWnd, IDC_CHECK25 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						_pPerformance->PlaySegment( _pSegment2, 0, 0, NULL );
					checkbox = GetDlgItem( hWnd, IDC_CHECK41 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						_pPerformance->PlaySegment( _pSegment3, 0, 0, NULL );
					checkbox = GetDlgItem( hWnd, IDC_CHECK57 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						_pPerformance->PlaySegment( _pSegment4, 0, 0, NULL );
					break;
				case 10:
					checkbox = GetDlgItem( hWnd, IDC_CHECK10);
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						_pPerformance->PlaySegment( _pSegment1, 0, 0, NULL );
					checkbox = GetDlgItem( hWnd, IDC_CHECK26 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						_pPerformance->PlaySegment( _pSegment2, 0, 0, NULL );
					checkbox = GetDlgItem( hWnd, IDC_CHECK42 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						_pPerformance->PlaySegment( _pSegment3, 0, 0, NULL );
					checkbox = GetDlgItem( hWnd, IDC_CHECK58 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						_pPerformance->PlaySegment( _pSegment4, 0, 0, NULL );
					break;
				case 11:
					checkbox = GetDlgItem( hWnd, IDC_CHECK11 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						_pPerformance->PlaySegment( _pSegment1, 0, 0, NULL );
					checkbox = GetDlgItem( hWnd, IDC_CHECK27 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						_pPerformance->PlaySegment( _pSegment2, 0, 0, NULL );
					checkbox = GetDlgItem( hWnd, IDC_CHECK43 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						_pPerformance->PlaySegment( _pSegment3, 0, 0, NULL );
					checkbox = GetDlgItem( hWnd, IDC_CHECK59 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						_pPerformance->PlaySegment( _pSegment4, 0, 0, NULL );
					break;
				case 12:
					checkbox = GetDlgItem( hWnd, IDC_CHECK12 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						_pPerformance->PlaySegment( _pSegment1, 0, 0, NULL );
					checkbox = GetDlgItem( hWnd, IDC_CHECK28 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						_pPerformance->PlaySegment( _pSegment2, 0, 0, NULL );
					checkbox = GetDlgItem( hWnd, IDC_CHECK44 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						_pPerformance->PlaySegment( _pSegment3, 0, 0, NULL );
					checkbox = GetDlgItem( hWnd, IDC_CHECK60 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						_pPerformance->PlaySegment( _pSegment4, 0, 0, NULL );
					break;
				case 13:
					checkbox = GetDlgItem( hWnd, IDC_CHECK13 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						_pPerformance->PlaySegment( _pSegment1, 0, 0, NULL );
					checkbox = GetDlgItem( hWnd, IDC_CHECK29 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						_pPerformance->PlaySegment( _pSegment2, 0, 0, NULL );
					checkbox = GetDlgItem( hWnd, IDC_CHECK45 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						_pPerformance->PlaySegment( _pSegment3, 0, 0, NULL );
					checkbox = GetDlgItem( hWnd, IDC_CHECK61 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						_pPerformance->PlaySegment( _pSegment4, 0, 0, NULL );
					break;
				case 14:
					checkbox = GetDlgItem( hWnd, IDC_CHECK14 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						_pPerformance->PlaySegment( _pSegment1, 0, 0, NULL );
					checkbox = GetDlgItem( hWnd, IDC_CHECK30 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						_pPerformance->PlaySegment( _pSegment2, 0, 0, NULL );
					checkbox = GetDlgItem( hWnd, IDC_CHECK46 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						_pPerformance->PlaySegment( _pSegment3, 0, 0, NULL );
					checkbox = GetDlgItem( hWnd, IDC_CHECK62 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						_pPerformance->PlaySegment( _pSegment4, 0, 0, NULL );
					break;
				case 15:
					checkbox = GetDlgItem( hWnd, IDC_CHECK15 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						_pPerformance->PlaySegment( _pSegment1, 0, 0, NULL );
					checkbox = GetDlgItem( hWnd, IDC_CHECK31 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						_pPerformance->PlaySegment( _pSegment2, 0, 0, NULL );
					checkbox = GetDlgItem( hWnd, IDC_CHECK47 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						_pPerformance->PlaySegment( _pSegment3, 0, 0, NULL );
					checkbox = GetDlgItem( hWnd, IDC_CHECK63 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						_pPerformance->PlaySegment( _pSegment4, 0, 0, NULL );
					break;
				case 16:
					checkbox = GetDlgItem( hWnd, IDC_CHECK16 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						_pPerformance->PlaySegment( _pSegment1, 0, 0, NULL );
					checkbox = GetDlgItem( hWnd, IDC_CHECK32 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						_pPerformance->PlaySegment( _pSegment2, 0, 0, NULL );
					checkbox = GetDlgItem( hWnd, IDC_CHECK48 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						_pPerformance->PlaySegment( _pSegment3, 0, 0, NULL );
					checkbox = GetDlgItem( hWnd, IDC_CHECK64 );
					if ( SendMessage( checkbox, BM_GETCHECK, 0, 0 ) == BST_CHECKED )
						_pPerformance->PlaySegment( _pSegment4, 0, 0, NULL );
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

	// Dmusic and COM setup
	CoInitialize( NULL );

	CoCreateInstance( CLSID_DirectMusicLoader, NULL, CLSCTX_INPROC,
						IID_IDirectMusicLoader8, (void **)&g_checkBeat->_pLoader );
	CoCreateInstance( CLSID_DirectMusicPerformance, NULL, CLSCTX_INPROC,
						IID_IDirectMusicPerformance8, (void **)&g_checkBeat->_pPerformance );
	// End Dmusic and COM setup

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_DIRECTNOISE, szWindowClass, MAX_LOADSTRING);

	hAccelTable = LoadAccelerators(hInstance, (LPCTSTR)IDC_DIRECTNOISE);

	// init audio
	g_checkBeat->_pPerformance->InitAudio( 
	NULL,                  // IDirectMusic interface not needed.
	NULL,                  // IDirectSound interface not needed.
	NULL,                  // Window handle.
	DMUS_APATH_SHARED_STEREOPLUSREVERB,  // Default audiopath type.
	64,                    // Number of performance channels.
	DMUS_AUDIOF_ALL,       // Features on synthesizer.
	NULL                   // Audio parameters; use defaults.
	);
	// end init audio

	// Set the search directory.
	g_checkBeat->_pLoader->SetSearchDirectory( 
		GUID_DirectMusicAllTypes,   // Types of files sought.
		L".\\Debug", // Where to look. Null for default
		FALSE                       // Don't clear object data.
	); // This function has a lot of stuff I did to it, explained below

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

	g_checkBeat->_pPerformance->Stop(
	NULL,   // Stop all segments.
	NULL,   // Stop all segment states.
	0,      // Do it immediately.
	0       // Flags.
	);

	g_checkBeat->_pPerformance->CloseDown();

	if( g_checkBeat->_pLoader) g_checkBeat->_pLoader->Release();
	if( g_checkBeat->_pSegment1) g_checkBeat->_pSegment1->Unload(g_checkBeat->_pPerformance);
	if( g_checkBeat->_pSegment2) g_checkBeat->_pSegment2->Unload(g_checkBeat->_pPerformance);
	if( g_checkBeat->_pSegment3) g_checkBeat->_pSegment3->Unload(g_checkBeat->_pPerformance);
	if( g_checkBeat->_pSegment4) g_checkBeat->_pSegment4->Unload(g_checkBeat->_pPerformance);
	if( g_checkBeat->_pPerformance ) g_checkBeat->_pPerformance->Release();
	if( g_checkBeat->_pSegment1) g_checkBeat->_pSegment1->Release();
	if( g_checkBeat->_pSegment2) g_checkBeat->_pSegment2->Release();
	if( g_checkBeat->_pSegment3) g_checkBeat->_pSegment3->Release();
	if( g_checkBeat->_pSegment4) g_checkBeat->_pSegment4->Release();
	CoUninitialize();

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
	WCHAR wszLoadFile[MAX_PATH];
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
			g_checkBeat->_pPerformance->Stop( 0, NULL, 0, DMUS_SEGF_BEAT );	
			TextCtrl = GetDlgItem( hDlg, IDC_RESOLUTION );
			EnableWindow( TextCtrl, true );
			TextCtrl = GetDlgItem( hDlg, IDC_BEATS );
			EnableWindow( TextCtrl, true );
			TextCtrl = GetDlgItem( hDlg, IDC_BPM );
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

			// Get our "kick" sound
			TextCtrl = GetDlgItem( hDlg, IDC_KICK_FILENAME );
			GetWindowText( TextCtrl, szGetFilename, MAX_PATH );
			MultiByteToWideChar( CP_ACP, MB_PRECOMPOSED, szGetFilename, -1, wszLoadFile, MAX_PATH );
			if (FAILED(g_checkBeat->_pLoader->LoadObjectFromFile(
				CLSID_DirectMusicSegment,   // Class identifier.
				IID_IDirectMusicSegment8,   // ID of desired interface.
				wszLoadFile,               // Filename.
				(LPVOID*) &g_checkBeat->_pSegment1)))    // Pointer that receives interface.
			{		
				MessageBox( hDlg, "Wave file 1 not found.", szGetFilename, MB_OK );
				return 0;
			}
			g_checkBeat->_pSegment1->Download(g_checkBeat->_pPerformance);

			// Get our "snare" sound
			TextCtrl = GetDlgItem( hDlg, IDC_SNARE_FILENAME );
			GetWindowText( TextCtrl, szGetFilename, MAX_PATH );
			MultiByteToWideChar( CP_ACP, MB_PRECOMPOSED, szGetFilename, -1, wszLoadFile, MAX_PATH );
			if (FAILED(g_checkBeat->_pLoader->LoadObjectFromFile(
				CLSID_DirectMusicSegment,   // Class identifier.
				IID_IDirectMusicSegment8,   // ID of desired interface.
				wszLoadFile,               // Filename.
				(LPVOID*) &g_checkBeat->_pSegment2)))    // Pointer that receives interface.
			{		
				MessageBox( hDlg, "Wave file 2 not found.", szGetFilename, MB_OK );
				return 0;
			}
			g_checkBeat->_pSegment2->Download(g_checkBeat->_pPerformance);

			// Get our "closed hihat" sound
			TextCtrl = GetDlgItem( hDlg, IDC_C_HIHAT_FILENAME );
			GetWindowText( TextCtrl, szGetFilename, MAX_PATH );
			MultiByteToWideChar( CP_ACP, MB_PRECOMPOSED, szGetFilename, -1, wszLoadFile, MAX_PATH );
			if (FAILED(g_checkBeat->_pLoader->LoadObjectFromFile(
				CLSID_DirectMusicSegment,   // Class identifier.
				IID_IDirectMusicSegment8,   // ID of desired interface.
				wszLoadFile,               // Filename.
				(LPVOID*) &g_checkBeat->_pSegment3)))    // Pointer that receives interface.
			{		
				MessageBox( hDlg, "Wave file 3 not found.", szGetFilename, MB_OK );
				return 0;
			}
			g_checkBeat->_pSegment3->Download(g_checkBeat->_pPerformance);

			// Get our "open hihat" sound
			TextCtrl = GetDlgItem( hDlg, IDC_HIHAT_FILENAME );
			GetWindowText( TextCtrl, szGetFilename, MAX_PATH );
			MultiByteToWideChar( CP_ACP, MB_PRECOMPOSED, szGetFilename, -1, wszLoadFile, MAX_PATH );
			if (FAILED(g_checkBeat->_pLoader->LoadObjectFromFile(
				CLSID_DirectMusicSegment,   // Class identifier.
				IID_IDirectMusicSegment8,   // ID of desired interface.
				wszLoadFile,               // Filename.
				(LPVOID*) &g_checkBeat->_pSegment4)))    // Pointer that receives interface.
			{		
				MessageBox( hDlg, "Wave file 4 not found.", szGetFilename, MB_OK );
				return 0;
			}
			g_checkBeat->_pSegment4->Download(g_checkBeat->_pPerformance);

			if( !g_checkBeat->_pSegment1 )
			{
				MessageBox( hDlg, "Specify the first wave sound first.", "Stupid Human", MB_OK );
				return TRUE;
			}
			if( !g_checkBeat->_pSegment2 )
			{
				MessageBox( hDlg, "Specify the second wave sound first.", "Stupid Human", MB_OK );
				return TRUE;
			}
			if( !g_checkBeat->_pSegment3 )
			{
				MessageBox( hDlg, "Specify the third wave sound first.", "Stupid Human", MB_OK );
				return TRUE;
			}
			if( !g_checkBeat->_pSegment4 )
			{
				MessageBox( hDlg, "Specify the fourth wave sound first.", "Stupid Human", MB_OK );
				return TRUE;
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
