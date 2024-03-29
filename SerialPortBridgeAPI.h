/**********************************************************\

  Auto-generated SerialPortBridgeAPI.h

\**********************************************************/

#include <string>
#include <sstream>
#include <boost/weak_ptr.hpp>
#include "JSAPIAuto.h"
#include "BrowserHost.h"
#include "SerialPortBridge.h"


#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/asio/serial_port.hpp>
#include <boost/thread.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/regex.hpp>
#include <boost/date_time/posix_time/posix_time_types.hpp>

using namespace  boost::asio;  // save tons of typin


#ifndef H_SerialPortBridgeAPI
#define H_SerialPortBridgeAPI

class SerialPortBridgeAPI : public FB::JSAPIAuto
{
public:
    SerialPortBridgeAPI(const SerialPortBridgePtr& plugin, const FB::BrowserHostPtr& host);
    virtual ~SerialPortBridgeAPI();
    
    SerialPortBridgePtr getPlugin();
    
    // Read-only property ${PROPERTY.ident}
    std::string get_version();
    
	//Serial port Methods
	long open(const std::string& port);
    long write(const FB::variant& val);
	long writeInt(const long val);
	long writeFloat(const double val);
	long writeBool(const bool val);
	long close(void);
    std::string writeReadLine(const FB::variant& val);
    std::string readUntil(const std::string delimiter);
	
	//EVENTS
	FB_JSAPI_EVENT(received, 1, (const FB::variant&));
	FB_JSAPI_EVENT(notify, 0, ());
    
private:
    /**
     * Possible outcome of a read. Set by callbacks, read from main code
     */
    enum ReadResult
    {
        RESULT_IN_PROGRESS,
        RESULT_SUCCESS,
        RESULT_ERROR,
        RESULT_TIMEOUT
    };

    
    SerialPortBridgeWeakPtr m_plugin;
    FB::BrowserHostPtr m_host;
    
    static const int MAX_READ_LENGHT = 512; // maximum amount of data to read in one operation
    char m_read_msg[MAX_READ_LENGHT];
    boost::asio::io_service m_io;
    boost::asio::serial_port *m_port;
//    boost::asio::deadline_timer m_timer; ///< Timer for timeout
//    boost::posix_time::time_duration m_timeout; ///< Read/write timeout
//    boost::asio::streambuf m_read_data;
    enum ReadResult m_read_result;
    
    
    //PRIVATE FUNCTIONS
    void read_start(void);
    void read_complete(const boost::system::error_code& error, size_t bytes_transferred);
    void timeoutExpired(const boost::system::error_code& error);
    void readCompleted(const boost::system::error_code& error,const size_t bytesTransferred);
    
};
#endif // H_SerialPortBridgeAPI

