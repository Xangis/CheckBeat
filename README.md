# CheckBeat

A simple checkbox-based drum machine. It was originally released on http://zetacentauri.com

![CheckBeat Screenshot](https://github.com/Xangis/CheckBeat/blob/master/images/CheckBeat.png)

A prebuilt installer is in the installer directory.

CheckBeat uses XAudio2 and requires the DirectX runtime to be installed.

# Changelog

Changes For CheckBeat Version 3.1:

- Switched to SDL for sound playback because it's easier to use and more cross-platform friendly.

Changes For CheckBeat Version 3:

- Now uses XAudio2 for sound playback.  Versions before 3 used DirectMusic, which Microsoft no longer supports.
- Interface now has the rounded button styles.
- Added a help button.
- Controls that don't affect the beat while it's playing are grayed out during playback.
- Includes 18 drum samples instead of the basic 4.

Changes For CheckBeat Version 2:

- Now allows the selection of division length (1/4 to 1/32 note).
- Multithreaded to allow interaction with dialog without disrupting currently playing beat.
