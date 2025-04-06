# miniLightShow

**A RGB light with various patterns and effects based on Arduino and Duinotech 40 LEDs matrix shield**

A nice weekend project for beginners, affordable, fun and no soldering required.

![miniLightShow Demo](./assets/miniLightShow_demo.gif "miniLightShow Demo")

## Parts

- 1 x Arduino Uno/Leonardo
- 1 x Duinotech XC3730 40 RGB LED Matrix Shield
- 1 x Duratech XC4406 acrylic enclosure for Arduino Uno
- 1 x weekend
- 1 x fresh banana

## Assembly

1. Gather the parts

![arduino](./assets/arduino.jpg "Arduino") ![enclosure](./assets/enclosure.jpg "Enclosure") ![led](./assets/LEDs.jpg "RGB LEDs")
![overview](./assets/overview.jpg "Overview")

2. Test the Arduino Uno/Leonardo

Plug your Arduino on a USB port, open Arduino IDE and go to Tools | Get Board Info. You should see the BN, VID, PID and Serial Number. If not, go to Troubleshooting.

3. Assemble the enclosure

4. Plug the RGB LED hat on top of the Arduino

5. Upload the code

In Arduino IDE, open [this file](./miniLightShow.ino), then go to Sketch | Upload. If it doesn't work, go to Troubleshooting.

6. Test

Plug the Arduino to a USB power source, you should see RGB patterns and effects

7. Prepare a light diffuser

   7.1. 3D print the light diffuser (optional)

The Blender file is available [here](./assets/minilightshowv1.blend). The STL file is available [here](./assets/minilightshowv1.stl).
If you own a EasyThreed K1, K2, K7, K9, X1 or X2 3D printer (the cheap ones from Ali Express), you can use [this GCode file](./assets/CFFFP_minilightshowv1.gcode).

The STL file must be turned into a GCode file; this must be done on a per-printer basis, as GCode is specific to the brand and model of every 3D printer.

I use [UltiMaker Cura](https://ultimaker.com/software/ultimaker-cura/), it is for free and easy to use. Follow [this YouTube tutorial](https://youtu.be/L6ijXqF0rMg?feature=shared) if you need help.

Once printed, simply glue it on the header so that it covers the RGB matrix. It will act as a light diffuser, making the effects nicer.

   7.2. Use a 6x6 piece of tracing paper (optional)

If you don't own a 3D printer, cut a 6x6 centimeters square in a sheet of tracing paper. Once ready, simply glue it on the header so that it covers the RGB matrix. It will act as a light diffuser, making the effects nicer.

8. Eat the banana

Fruits and vegetables are not boring, they are the natural fuel made for your body.

## Troubleshooting

### Arduino is not detected by Arduino IDE

1. Make sure the USB cable you use is Power + Data. You can find cheap testing devices on Ali Express for that. Some cables only do power and won't work at all
2. Unplug, replug, retry
3. In Tools | Board, double-check you selected the right Arduino model
4. In Tools | Port, make sure a USB device is selected

You can also unplug the Arduino, keep the reset button pressed, plug it, go to Sketch | Upload and release the reset button.

These steps should cover most cases. If you can't make it work, go to the [Arduino Sub-Reddit](https://www.reddit.com/r/arduino/).

