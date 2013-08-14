ofxICMP
=======

ofxICMP is a pure Poco addon for making ICMP (aka PING) requests.  Essentially it is a thin wrapper around `Poco::Net::ICMPClient` to make it play nicely with openFrameworks.

ICMP/Ping requests require raw socket access which usually requires root (aka super user, aka adminstrator) priviledges.

If you run the example without root privileges you will get an exception and nothing will happen.

On Linux, this is easy.  Simply run the app with:

`sudo ./myApp`.

On Windows right click on your app and click "run as administrator".

On OS X, you can enter the application bundle and execute the binary from the command line (just like on Linux).  A step by step guide is here:

http://www.wikihow.com/Open-Applications-With-Root-Privileges-on-a-Mac
