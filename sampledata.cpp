#include "sampledata.h"

/**
* Constructor.
*/
SampleData::SampleData()
{
	_waveFile = NULL;
    _keyboardNote = 64;
    _sampleNote = 64;
    _volume = 127;
	_userSpecified = false;
	_looping = false;
	_sourceVoice = NULL;
	_buffer = NULL;
}

/**
* Destructor.  Cleans up pointers.
*/
SampleData::~SampleData()
{
	DestroySource();
	if( _waveFile != NULL )
	{
		delete _waveFile;
	}
}

/**
* Creates an XAudio2 source from the wavefile data.
*/
void SampleData::CreateSource(IXAudio2* xAudio2)
{
	if( _waveFile == NULL )
		return;
	if( _buffer != NULL || _sourceVoice != NULL )
	{
		DestroySource();
	}
	HRESULT hr = xAudio2->CreateSourceVoice( &_sourceVoice, _waveFile->GetWaveFormatEx(), XAUDIO2_VOICE_USEFILTER, 64.0, NULL, NULL, NULL );
	if( FAILED( hr ))
	{
		MessageBox(NULL, TEXT("Unable to create source voice: %d (%x) [%s]"), TEXT("Create Source Error"), MB_OK);
	}
	_buffer = _waveFile->GetXAudio2Buffer();
	if( _looping )
		_buffer->LoopCount = XAUDIO2_LOOP_INFINITE;
}

/**
* Destroys the source associated with this sample and clears the audio data buffer.
*/
void SampleData::DestroySource()
{
	if( _buffer != NULL )
	{
		if( _buffer->pAudioData != NULL )
			delete[] _buffer->pAudioData;
		delete _buffer;
		_buffer = NULL;
	}
	if( _sourceVoice != NULL )
	{
		_sourceVoice->DestroyVoice();
		_sourceVoice = NULL;
	}
}

/**
* Gets the XAudio error string from an HRESULT.
*/
std::string SampleData::GetXAudioErrorString(HRESULT hr)
{
	switch( hr )
	{
		case XAUDIO2_E_INVALID_CALL:
			return "Invalid XAudio2 API call.";
			break;
		case XAUDIO2_E_XMA_DECODER_ERROR:
			return "The Xbox 360 XMA hardware suffered an unrecoverable error.";
			break;
		case XAUDIO2_E_XAPO_CREATION_FAILED:
			return "An effect failed to instantiate.";
			break;
		case XAUDIO2_E_DEVICE_INVALIDATED:
			return "An audio device became unusable through being unplugged or some other event.";
			break;
		default:
			return "";
	}
}