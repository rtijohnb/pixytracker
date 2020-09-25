# pixytracker
Tracking demo for use w/ PixyCam and Shapes

NOTE: PixyTracker now uses Connext DDS 6.0.1  Pixyshapes as of this writing, uses Connext DDS 5.3.1. By default 6.0.1 uses XCDR2 (efficient compressed encoding). To ensure interoperabilty, the pixytracker writer has been configure to use XCDR (uncompressed encoding) via a <discovery_config><endpoint_type_object_lb_serialization_threshold>(wasn't that easy) QoS directive in .xml file.

https://community.rti.com/static/documentation/connext-dds/current/doc/manuals/connext_dds/getting_started_extras/html_files/RTI_ConnextDDS_CoreLibraries_GettingStarted_ExtensibleAddendum/Content/ExtensibleTypesAddendum/Data_Representation.htm


This is an additional demo for use with the PixyShapes demo.  It is a network-based control app that tracks one colored ball and attempts to keep it in the center of the screen.

You specify the color of the ball to track on the command line.  The app subscribes to the Circle topic while applying a content filter based on the color you selected on the command line.  It then runs a simple tracking algorithm that publishes a ServoControl topic to move the PixyCam in such a way as to keep the ball centered in the field of view of the camera.

The application is built for Mac OS using Eclipse.

