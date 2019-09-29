# Midi-Footcontroller
Midi FootController

*Instructions*
==============

Class Switch
--------------
Using this class define your "buttons" 
Usage:
Switch <switch_name>(<pin_number>, 0, 0, 0);

Class MIDImsg
--------------
Using this class constructor define MiDi signals
Usage:
MIDImsg <name>(<status_byte>, <byte1>, <byte2>);

void MIDI_CC_But()
--------------
Using this function assign MiDi commands to buttons:
Usage(write inside void loop()):
MIDI_CC_But(<Switch>, MIDImsg);