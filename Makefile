all: clean release

clean:
	rm build/screenarrangement.tar.gz
	xcodebuild clean

release:
	xcodebuild -configuration Release

install: release
	cp build/Release/screenarrangement /usr/local/bin

package: release
	tar -czf build/screenarrangement.tar.gz Makefile screenarrangement/main.c screenarrangement.xcodeproj/project.pbxproj

