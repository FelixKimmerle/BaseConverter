cp build/x64/baseconverter Packagex64/bin/base
cd PackageOutput/x64/
rm *.deb
dpkg-deb -b ../../Packagex64/ bcx64.deb

cd ../../

cp build/x86/baseconverter Packagex86/bin/base
cd PackageOutput/x86/
rm *.deb
dpkg-deb -b ../../Packagex86/ bcx86.deb
