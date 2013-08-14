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


#include "ofxICMP.h"


namespace ofx {
namespace Net {


ICMPClient::ICMPClient(Poco::Net::IPAddress::Family family): _client(family)
{
}

ICMPClient::~ICMPClient()
{
}

int ICMPClient::ping(Poco::Net::SocketAddress& address, int repeat) const
{
    int n = 0;

    try {
        n = _client.ping(address,repeat);
    } catch(Poco::IOException e) {
        ofLogError("ICMPClient::ping") << e.what() << " (Are you running with root privileges?)" << endl;
    }

    return n;
}

int ICMPClient::ping(const std::string& address, int repeat) const
{
    int n = 0;

    try {
        n = _client.ping(address,repeat);
    } catch(Poco::IOException e) {
        ofLogError("ICMPClient::ping") << e.what() << " (Are you running with root privileges?)" << endl;
    }

    return n;
}


} } // namespace ofx::Net
