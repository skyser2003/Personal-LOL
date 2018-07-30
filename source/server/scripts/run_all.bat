pushd %~dp0

start "" ..\..\solution\x64\Debug\Generator.exe

cd ../DataApi
start "" cmd /k "npm run env DEBUG=true	&& node app.js"

exit

popd