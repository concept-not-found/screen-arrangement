screen-arrangement
==================

Gives the positions and sizes of the screens found under System Preferences -> Displays -> Arrangement for Mac OS X

    usage: screenarrangement

Sample output for a Macbook Pro with a connected Thunderbolt Display:

    > screenarrangement
    {{{0, 0}, {1680, 1050}}, {{1680, 0}, {2560, 1440}}}

The output is intended to be consumed in an AppleScript.  For example:

    on screen_arrangement()
        return run script (do shell script "/usr/local/bin/screenarrangement")
    end screen_arrangement

    set arrangement to screen_arrangement()

installation
------------

Available from [Homebrew](http://mxcl.github.com/homebrew/)

    brew tap concept-not-found/tap
    brew install screenarrangement
