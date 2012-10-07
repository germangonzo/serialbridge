#/**********************************************************\ 
#
# Auto-Generated Plugin Configuration file
# for Serial Port Bridge
#
#\**********************************************************/

set(PLUGIN_NAME "SerialPortBridge")
set(PLUGIN_PREFIX "SPB")
set(COMPANY_NAME "Lab140")

# ActiveX constants:
set(FBTYPELIB_NAME SerialPortBridgeLib)
set(FBTYPELIB_DESC "SerialPortBridge 1.0 Type Library")
set(IFBControl_DESC "SerialPortBridge Control Interface")
set(FBControl_DESC "SerialPortBridge Control Class")
set(IFBComJavascriptObject_DESC "SerialPortBridge IComJavascriptObject Interface")
set(FBComJavascriptObject_DESC "SerialPortBridge ComJavascriptObject Class")
set(IFBComEventSource_DESC "SerialPortBridge IFBComEventSource Interface")
set(AXVERSION_NUM "1")

# NOTE: THESE GUIDS *MUST* BE UNIQUE TO YOUR PLUGIN/ACTIVEX CONTROL!  YES, ALL OF THEM!
set(FBTYPELIB_GUID 4b592057-a78b-5563-9bd5-9839d109618e)
set(IFBControl_GUID 0667daf6-ba2f-52e5-9c57-baba84220384)
set(FBControl_GUID 6f4faf0a-d8ea-5516-a5e4-152d2fcc314b)
set(IFBComJavascriptObject_GUID 1de8e501-07f2-540b-9f97-7db3d6aebc79)
set(FBComJavascriptObject_GUID b9e0b468-faea-5db8-b82f-79dac03a0ba8)
set(IFBComEventSource_GUID 6160b6ba-d3b6-592b-be53-14a362704dd5)

# these are the pieces that are relevant to using it from Javascript
set(ACTIVEX_PROGID "Lab140.SerialPortBridge")
set(MOZILLA_PLUGINID "lab140.com/SerialPortBridge")

# strings
set(FBSTRING_CompanyName "Lab140")
set(FBSTRING_FileDescription "Serial Port Bridge")
set(FBSTRING_PLUGIN_VERSION "1.0.0.0")
set(FBSTRING_LegalCopyright "Copyright 2012 Lab140")
set(FBSTRING_PluginFileName "np${PLUGIN_NAME}.dll")
set(FBSTRING_ProductName "Serial Port Bridge")
set(FBSTRING_FileExtents "")
set(FBSTRING_PluginName "Serial Port Bridge")
set(FBSTRING_MIMEType "application/x-serialportbridge")

# Uncomment this next line if you're not planning on your plugin doing
# any drawing:

set (FB_GUI_DISABLED 1)

# Mac plugin settings. If your plugin does not draw, set these all to 0
set(FBMAC_USE_QUICKDRAW 0)
set(FBMAC_USE_CARBON 0)
set(FBMAC_USE_COCOA 0)
set(FBMAC_USE_COREGRAPHICS 0)
set(FBMAC_USE_COREANIMATION 0)
set(FBMAC_USE_INVALIDATINGCOREANIMATION 0)

# If you want to register per-machine on Windows, uncomment this line
#set (FB_ATLREG_MACHINEWIDE 1)
