This project looked completly different because it was only for interview purporses and didn't hold any meaning to me
But i thought that it looked really bad on my github as it was lazy programming of simple task 
So i got some renovation to this code so it looks better.
 
How to build it?
1. Everythings works
It propably won't happen but everything will work if you have 
  - Make installed and ready to use in this project directory
  - Boost and environment variable BOOST_ROOT set on your boost dir also boost libraries compiled with mig13 
  - libboost_filesystem-mgw13-mt-d-x64-1_85.dll, libboost_log-mgw13-mt-d-x64-1_85.dll, libboost_thread-mgw13-mt-d-x64-1_85.dll in folder with your .exe that you somehow made and knew it 
    
2. You don't have Boost package copiled as i do
If you have boost package compiled differently than i do then you can use it instead
but you have to change build completly and connect different files in premake5.lua then generate it again

Download current package version, mine version is 1.85.0 
https://www.boost.org/users/history/version_1_85_0.html
Now hard part
In this package there should be file bootstrap.sh(or .bat) run it
It will install b2.exe we run it like this "b2 toolset=gcc-13 address-model=64 variant=debug --with-log" 
if it doesn't work i surrender
