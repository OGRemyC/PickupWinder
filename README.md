# PickupWinder
Arduino code designed to run on the Digispark Pro board.

Current Features:
<ul>
<li>Basic DC motor control</li>
<li>Open loop speed control</li>
</ul>

Future Features:
<ul>
<li>Full bi-directional control via H-bridge</li>
<li>Tachometer</li>
<li>Closed-loop speed control</li>
</ul>

Possible Extended Features:
<ul>
<li>Automatic tensioner</li>
<li>Closed loop wire tensioner</li>
<li>Linear spool positioning via lead screw</li>
<li>Automatic wrap with various profiles</li>
</ul>

<h1>Installation</h1>
<h2>Windows</h2>
Follow instructions from the <a href="https://digistump.com/wiki/digispark/tutorials/connectingpro">Digistrump Wiki</a>.
In addition, download and install the <a href="https://github.com/micronucleus">Micronucleus</a> bootloader driver installer.

<h3>Key Elements</h3>
<ul>
<li>Arduino 1.6.6 or newer</li>
<li>Digistump <a href="https://github.com/digistump/DigistumpArduino/releases/download/1.6.7/DigistumpDrivers.zip">Drivers</a></li>
<li>Micronucleus driver installer</li>
</ul>

<h3>Steps</h3>
<ol>
<li>Download Digistrump drivers, micronucleus, and Arduino.
<li>Install Arduino.</li>
<li>Unzip Digistump drivers and micronucleus to the Arduino sketchbook folder.</li>
<li>Run [Sketchbook]\micronucleus-master\windows_driver_installer\zadig_2.1.2.exe</li>
<li>In Zadig select Device>Load Preset Device. </li>
<li>Select micronucleus.cfg in the same folder. </li>


<h1>Uploading Sketches to the DigiSpark Pro</h1>
Open \\PickupWinder\digiProPickupWinder\digiProPickupWinder.ino in the Arduino IDE.
Select "Digispark Pro (Default 16 MHz)" from Tools>Board:
Start click Upload.
Connect the DigiSpark board via USB