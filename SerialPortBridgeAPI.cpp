/**********************************************************\

  Auto-generated SerialPortBridgeAPI.cpp

\**********************************************************/

#include "JSObject.h"
#include "variant_list.h"
#include "DOM/Document.h"
#include "global/config.h"

#include "SerialPortBridgeAPI.h"
#define ERROR_SUCCESS 0

///////////////////////////////////////////////////////////////////////////////
/// @fn SerialPortBridgeAPI::SerialPortBridgeAPI(const SerialPortBridgePtr& plugin, const FB::BrowserHostPtr host)
///
/// @brief  Constructor for your JSAPI object.  You should register your methods, properties, and events
///         that should be accessible to Javascript from here.
///
/// @see FB::JSAPIAuto::registerMethod
/// @see FB::JSAPIAuto::registerProperty
/// @see FB::JSAPIAuto::registerEvent
///////////////////////////////////////////////////////////////////////////////
SerialPortBridgeAPI::SerialPortBridgeAPI(const SerialPortBridgePtr& plugin, const FB::BrowserHostPtr& host) : m_plugin(plugin), m_host(host), m_io()
{
	registerMethod("open", make_method(this, &SerialPortBridgeAPI::open));
	registerMethod("close", make_method(this, &SerialPortBridgeAPI::close));
	registerMethod("write", make_method(this, &SerialPortBridgeAPI::write));
	registerMethod("writeInt", make_method(this, &SerialPortBridgeAPI::writeInt));
	registerMethod("writeFloat", make_method(this, &SerialPortBridgeAPI::writeFloat));
	registerMethod("writeBool", make_method(this, &SerialPortBridgeAPI::writeBool));
    
    // Read-only property
    registerProperty("version",
                     make_property(this,
                                   &SerialPortBridgeAPI::get_version));
}

///////////////////////////////////////////////////////////////////////////////
/// @fn SerialPortBridgeAPI::~SerialPortBridgeAPI()
///
/// @brief  Destructor.  Remember that this object will not be released until
///         the browser is done with it; this will almost definitely be after
///         the plugin is released.
///////////////////////////////////////////////////////////////////////////////
SerialPortBridgeAPI::~SerialPortBridgeAPI()
{
}

///////////////////////////////////////////////////////////////////////////////
/// @fn SerialPortBridgePtr SerialPortBridgeAPI::getPlugin()
///
/// @brief  Gets a reference to the plugin that was passed in when the object
///         was created.  If the plugin has already been released then this
///         will throw a FB::script_error that will be translated into a
///         javascript exception in the page.
///////////////////////////////////////////////////////////////////////////////
SerialPortBridgePtr SerialPortBridgeAPI::getPlugin()
{
    SerialPortBridgePtr plugin(m_plugin.lock());
    if (!plugin) {
        throw FB::script_error("The plugin is invalid");
    }
    return plugin;
}


// Read-only property version
std::string SerialPortBridgeAPI::get_version()
{
    return FBSTRING_PLUGIN_VERSION;
}


long SerialPortBridgeAPI::open(const std::string& port) {
    m_port = new serial_port(m_io,port);
    //TODO: verifiy if port is open.
    if (m_port->is_open()) {
        //TODO HANDLE BAUD RATE as parameter
        boost::asio::serial_port_base::baud_rate baud_option(9600);
        m_port->set_option(baud_option); // set the baud rate after the port has been opened
        read_start();
        boost::thread t(boost::bind(&boost::asio::io_service::run, &m_io));
        return 0;
    }
    //TODO: Handle Exceptions
    return -1;
}

long SerialPortBridgeAPI::close(void) {
	long  lerror = ERROR_SUCCESS;
    //TODO: implement close function
//	StopListener(0);
//	lerror = CSerial::Close();
	return lerror;
}

long SerialPortBridgeAPI::write(const FB::variant& val) {
	try {
//        long lLastError = ERROR_SUCCESS;
        std::string str = val.convert_cast<std::string>();
        boost::asio::write(*m_port,buffer(str,str.length()));
    } catch(boost::exception& e){
        //TODO: Handle Exception
        return -1;
        //return e.what();
    }
//	lLastError = Write(str.c_str());
	return 0;
}

long SerialPortBridgeAPI::writeInt(const long lval) {
	long  lLastError = ERROR_SUCCESS;
//	lLastError = Write(&lval,sizeof(lval));
	return lLastError;
}

long SerialPortBridgeAPI::writeFloat(const double dval) {
	long lLastError = ERROR_SUCCESS;
//	lLastError = Write(&dval,sizeof(dval));
	return lLastError;
}

long SerialPortBridgeAPI::writeBool(const bool bval) {
	long lLastError = ERROR_SUCCESS;
//	lLastError = Write(&bval,sizeof(bval));
	return lLastError;
}

void SerialPortBridgeAPI::read_start(void)
{ // Start an asynchronous read and call read_complete when it completes or fails
    m_port->async_read_some(boost::asio::buffer(m_read_msg, MAX_READ_LENGHT),
                               boost::bind(&SerialPortBridgeAPI::read_complete,
                                           this,
                                           boost::asio::placeholders::error,
                                           boost::asio::placeholders::bytes_transferred));
}

void SerialPortBridgeAPI::read_complete(const boost::system::error_code& error, size_t bytes_transferred)
{ // the asynchronous read operation has now completed or failed and returned an error
    if (!error)
    { // read completed, so process the data
        m_read_msg[bytes_transferred] = '\0';
        read_start(); // start waiting for another asynchronous read again
        fire_received(m_read_msg);
    }
    else
        fire_received("ERROR");
}



