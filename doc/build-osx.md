Mac OS X Build Instructions and Notes
====================================
This guide will show you how to build axel_utility_tokend (headless client) for OSX.

Notes
-----

* Tested on OS X 10.7 through 10.10 on 64-bit Intel processors only.

* All of the commands should be executed in a Terminal application. The
built-in one is located in `/Applications/Utilities`.

Preparation
-----------

You need to install XCode with all the options checked so that the compiler
and everything is available in /usr not just /Developer. XCode should be
available on your OS X installation media, but if not, you can get the
current version from https://developer.apple.com/xcode/. If you install
Xcode 4.3 or later, you'll need to install its command line tools. This can
be done in `Xcode > Preferences > Downloads > Components` and generally must
be re-done or updated every time Xcode is updated.

There's also an assumption that you already have `git` installed. If
not, it's the path of least resistance to install [Github for Mac](https://mac.github.com/)
(OS X 10.7+) or
[Git for OS X](https://code.google.com/p/git-osx-installer/). It is also
available via Homebrew.

You will also need to install [Homebrew](http://brew.sh) in order to install library
dependencies.

The installation of the actual dependencies is covered in the Instructions
sections below.

Instructions: Homebrew
----------------------

#### Install dependencies using Homebrew

        brew install autoconf automake berkeley-db4 libtool boost miniupnpc openssl pkg-config protobuf qt5 libzmq

### Building `axel_utility_tokend`

1. Clone the github tree to get the source code and go into the directory.

        git clone https://github.com/AXEL_Utility_Token-Core/AXEL_Utility_Token.git
        cd AXEL_Utility_Token

2.  Build axel_utility_tokend:

        ./autogen.sh
        ./configure --with-gui=qt5
        make

3.  It is also a good idea to build and run the unit tests:

        make check

4.  (Optional) You can also install axel_utility_tokend to your path:

        make install

Use Qt Creator as IDE
------------------------
You can use Qt Creator as IDE, for debugging and for manipulating forms, etc.
Download Qt Creator from http://www.qt.io/download/. Download the "community edition" and only install Qt Creator (uncheck the rest during the installation process).

1. Make sure you installed everything through homebrew mentioned above
2. Do a proper ./configure --with-gui=qt5 --enable-debug
3. In Qt Creator do "New Project" -> Import Project -> Import Existing Project
4. Enter "axel_utility_token-qt" as project name, enter src/qt as location
5. Leave the file selection as it is
6. Confirm the "summary page"
7. In the "Projects" tab select "Manage Kits..."
8. Select the default "Desktop" kit and select "Clang (x86 64bit in /usr/bin)" as compiler
9. Select LLDB as debugger (you might need to set the path to your installtion)
10. Start debugging with Qt Creator

Creating a release build
------------------------
You can ignore this section if you are building `axel_utility_tokend` for your own use.

axel_utility_tokend/axel_utility_token-cli binaries are not included in the axel_utility_token-Qt.app bundle.

If you are building `axel_utility_tokend` or `axel_utility_token-qt` for others, your build machine should be set up
as follows for maximum compatibility:

All dependencies should be compiled with these flags:

 -mmacosx-version-min=10.7
 -arch x86_64
 -isysroot $(xcode-select --print-path)/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.7.sdk

Once dependencies are compiled, see release-process.md for how the AXEL_Utility_Token-Qt.app
bundle is packaged and signed to create the .dmg disk image that is distributed.

Running
-------

It's now available at `./axel_utility_tokend`, provided that you are still in the `src`
directory. We have to first create the RPC configuration file, though.

Run `./axel_utility_tokend` to get the filename where it should be put, or just try these
commands:

    echo -e "rpcuser=axel_utility_tokenrpc\nrpcpassword=$(xxd -l 16 -p /dev/urandom)" > "/Users/${USER}/Library/Application Support/AXEL_Utility_Token/axel_utility_token.conf"
    chmod 600 "/Users/${USER}/Library/Application Support/AXEL_Utility_Token/axel_utility_token.conf"

The next time you run it, it will start downloading the blockchain, but it won't
output anything while it's doing this. This process may take several hours;
you can monitor its process by looking at the debug.log file, like this:

    tail -f $HOME/Library/Application\ Support/AXEL_Utility_Token/debug.log

Other commands:
-------

    ./axel_utility_tokend -daemon # to start the axel_utility_token daemon.
    ./axel_utility_token-cli --help  # for a list of command-line options.
    ./axel_utility_token-cli help    # When the daemon is running, to get a list of RPC commands
