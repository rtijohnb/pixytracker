# pixytracker
Tracking demo for use w/ PixyCam and Shapes

This is an additional demo for use with the PixyShapes demo.  It is a network-based control app that tracks one colored ball and attempts to keep it in the center of the screen.

You specify the color of the ball to track on the command line.  The app subscribes to the Circle topic while applying a content filter based on the color you selected on the command line.  It then runs a simple tracking algorithm that publishes a ServoControl topic to move the PixyCam in such a way as to keep the ball centered in the field of view of the camera.

The application is built for Mac OS using Eclipse.

