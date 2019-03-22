
Debian
====================
This directory contains files used to package axel_utility_tokend/axel_utility_token-qt
for Debian-based Linux systems. If you compile axel_utility_tokend/axel_utility_token-qt yourself, there are some useful files here.

## axel_utility_token: URI support ##


axel_utility_token-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install axel_utility_token-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your axel_utility_tokenqt binary to `/usr/bin`
and the `../../share/pixmaps/axel_utility_token128.png` to `/usr/share/pixmaps`

axel_utility_token-qt.protocol (KDE)
