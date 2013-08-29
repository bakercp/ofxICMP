// =============================================================================
//
// Copyright (c) 2010-2013 Christopher Baker <http://christopherbaker.net>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
// =============================================================================



#include "ofApp.h"



//------------------------------------------------------------------------------
void ofApp::setup()
{
    ofSetLogLevel(OF_LOG_NOTICE);
    client.RegisterClientEvents(this);
}

//------------------------------------------------------------------------------
void ofApp::draw()
{
    ofBackground(0);
    ofSetColor(255);
    ofDrawBitmapString("Press any key to send ping.",10,16);
}

//------------------------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    client.ping("www.google.com");
}

//------------------------------------------------------------------------------
void ofApp::onPingBegin(ICMPClient::EventArgs& args)
{
    ofLogNotice() << "onPingBegin: " << pingEventArgsToString(args) << endl;
}

//------------------------------------------------------------------------------
void ofApp::onPingReply(ICMPClient::EventArgs& args)
{
    ofLogNotice() << "onPingReply: " << pingEventArgsToString(args) << endl;
}

//------------------------------------------------------------------------------
void ofApp::onPingError(ICMPClient::EventArgs& args)
{
    ofLogNotice() << "onPingError: " << pingEventArgsToString(args) << endl;
}

//------------------------------------------------------------------------------
void ofApp::onPingEnd(ICMPClient::EventArgs& args)
{
    ofLogNotice() << "onPingEnd: " << pingEventArgsToString(args) << endl;
}

//------------------------------------------------------------------------------
std::string ofApp::pingEventArgsToString(const ICMPClient::EventArgs& args)
{
    std::stringstream ss;
    ss << args.dataSize() << " bytes from " << args.hostAddress() << ": ";
    ss << "icmp_seq=" << args.sent() << " ttl=" << args.ttl() << " time=" << args.replyTime();
    return ss.str();
}
