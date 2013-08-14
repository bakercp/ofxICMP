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


#pragma once


#include "Poco/Net/SocketAddress.h"
#include "Poco/Net/ICMPClient.h"
#include "ofEvents.h"
#include "ofLog.h"


namespace ofx {
namespace Net {


class ICMPClient
{
public:
    typedef Poco::Net::ICMPEventArgs EventArgs;

    ICMPClient(Poco::Net::IPAddress::Family family = Poco::Net::IPAddress::IPv4);
    ~ICMPClient();

    int ping(Poco::Net::SocketAddress& address, int repeat = 1) const;
	int ping(const std::string& address, int repeat = 1) const;

    template<class ListenerClass>
    void RegisterClientEvents(ListenerClass* listener);

    template<class ListenerClass>
    void UnregisterClientEvents(ListenerClass* listener);

private:
    Poco::Net::ICMPClient _client;

};

template<class ListenerClass>
void ICMPClient::RegisterClientEvents(ListenerClass* listener)
{
    ofAddListener(_client.pingBegin, listener, &ListenerClass::onPingBegin);
    ofAddListener(_client.pingReply, listener, &ListenerClass::onPingReply);
    ofAddListener(_client.pingError, listener, &ListenerClass::onPingError);
    ofAddListener(_client.pingEnd, listener, &ListenerClass::onPingEnd);
}

template<class ListenerClass>
void ICMPClient::UnregisterClientEvents(ListenerClass* listener)
{
    ofRemoveListener(_client.pingBegin, listener, &ListenerClass::onPingBegin);
    ofRemoveListener(_client.pingReply, listener, &ListenerClass::onPingReply);
    ofRemoveListener(_client.pingError, listener, &ListenerClass::onPingError);
    ofRemoveListener(_client.pingEnd, listener, &ListenerClass::onPingEnd);
}
    

} } // namespace ofx::Net
