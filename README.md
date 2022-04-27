# \_transcribe\_

### midi to rs232 bridge - for performance control of old video mixers and switchers

![image](https://user-images.githubusercontent.com/12017938/155063426-edec505d-e370-440a-b1c2-ed1fbf227e34.png)

- this circuit is distributed by __UNDERSCORES__ - _an open video hardware label_ : it is available to purchase - as a pcb, kit or assembled unit - at [underscores.shop](https://underscores.shop/_transcribe_/)
- the schematic for the circuit can be found [here](/hardware/schematic.pdf)
- the pcb gerber files for the lastest version can be found [here](/hardware/gerber_latest.zip)
- consider [donating](https://liberapay.com/underscores/) to the underscores project to help us continue creating for the commons

## description

people in the video-art community are performing with old hardware video-mixers such as the Pansonic_WJ_AVE55 and Pansonic_WJ_MX30/50. some of these mixers have a RS232 serial port for interfacing with them digitally. this is especially useful for live performance where sequencing can assist physical actions. there are some cool examples of software specifically written to interface with these mixers (such as [Freds excel app](https://a2m2.ch/fred/wj-ave55.htm) and  [Klifs MaxPatch](https://vimeo.com/161662975) ) , but there many more programs and devices that are made to interface digitally using MIDI.

the aim of this project is to create a small utility module that can __\_transcribe\___ _MIDI_, a protocol used commonly in live&performance instruments to the specific _RS-232 video-device specification_ , to better equip these retired workstations for their new life of glamour on stage

- input USB-midi from a USB-HOST such as a computer or rpi
- input serial-midi from older midi devices (din5)
- input USB-midi for a USB-DEVICE such as a korg nanokontroller or otherwise
- output RS232-serial commands over 3.5mm jack or dsub9 socket to control panasonic video-mixers and other devices
- all these interfaces are bi-directional and so can be modified with firmware to do other useful things (eg like a USB-DEVICE -> SERIAL midi converter)

## demo video

[![image](https://user-images.githubusercontent.com/12017938/161842450-5e7714f2-3f4f-4ca7-a6d0-f1c522a89308.png)](https://videos.scanlines.xyz/w/iJpDAtjqwNczxP9pRJbMGW)


# documentation

this project is fully _open-source hardware_ - all the files required to build it are included in this repo for free. if you have the time and/or skill you can contribute back by collaborating on / testing new designs, improving these docs, making demo videos/other creative content etc. you can also support the project financially by [donating directing](https://liberapay.com/underscores/), or purchasing through the [web shop](https://underscores.shop).

depending on whether you are going fully diy or buying an assembled and tested unit, some of the following guides will be relavent to you. the flow would be:

## ordering parts

<details><summary><b>parts sourcing guide (w/ notes on pcb fabracation )</b> - start here if you are building fully from scatch or have purchased a pcb</summary>

i try to source all the parts i can from either:
- [tayda](https://www.taydaelectronics.com/) ; cheaper for common parts like resistors etc, also good for mechanical parts like switches and buttons
- [mouser](https://www.mouser.de/) ; has lots more options, speciality video ic's, can sometimes cost more (free shipping on orders over 50euros)
- other ; ocationally there will be parts which will need to be sourced elsewhere - usaully either aliexpress, ebay or amazon etc...

take a look at the [full_bom](/hardware/bom/full_bom.csv) for this project to see where i am sourcing each part from
  
## omitting parts
  
if you know exactly how you will use your _transcribe_ some parts of this circuit build can be omitted. the pcb is divided into sections that are marked on silk-screen:

- __A - micro-conntroller - centre__ : this is the brain of the circuit and is required to make it do anything. its also where USB_MIDI is received from(/sent to) usb-hosts (eg computer or raspberry pi)
- __B - rs232 serial - output(/input)__ : for sending(/receiving) serial at rs232 levels - only omit if you are not using this board for its default / intended purpose
- __C - serial midi - input(/output)__ : for receiving(/sending) midi messages over serial (usually on older hardware over din5 or 3.5mm jack) - can omit if you are only using (newer) hardware with USB-MIDI
- __D USB-midi HOST__: adds circuitry so that micro-controller can act as USB-HOST. for receiving midi messages from(/sending to) usb-devices (eg korg nanokontrol2) - can omit this if not interested in controlling from usb-devices


## import into tayda

- go to the [tayda quick order](https://www.taydaelectronics.com/quick-order/) and in bottom corner choose _add from file_
- select the file [tayda_bom.csv](../hardware/bom/tayda_bom.csv) in the BOM folder (you will have to download it first or clone this repo)
- after importing select _add to cart_
- __NOTE:__ the minimum value for resistors is 10, so you may need to modify these values to add to cart (or if they are already modified here you will need to see the  full_bom for actual part QTY) 

- OPTIONAL: it is a good idea to add some dip-ic sockets and 2.54pin headers/sockets to your tayda order if you dont have them around already
  
## import into mouser

- go to [mouser bom tool](https://nz.mouser.com/Bom/) and click _upload spreadsheet_
- select the file [mouser_bom.csv](../hardware/bom/mouser_bom.csv) in this folder (you will have to download it first or clone this repo), then _upload my spreadsheet_ and _next_
- ensure that __Mouser Part Number__ is selected in the dropdown above the first row, then _next_, _process_
- if everything looks correct can now put _add to basket_

# ordering pcbs

you can support this project by buying individual pcbs from the [shop](https://underscores.shop). if you would rather have pcbs fabricated from gerbers directly the file you need is [here](/hardware/gerber_latest.zip) 

- i get my pcbs fabricated from [jlcpcb](https://cart.jlcpcb.com/quote) - 5 is the minumum order per design
- upload the zip file with the `add gerber file` button
- the default settings are mostly fine - set the __PCB Qty__ and __PCB Color__ settings (you can check that the file looks correct with pcb veiwer)
- it may be best to combine orders with other pcbs you want to have fab'd since the shipping can cost more than the items - also orginising group buys is a good way to distribute the extra pcbs /costs 
  
i often use jlcpcb because they are reliable, cheap and give you an option of colours. remember though that the cheapest Chinese fab houses are not always the most ethical or environmently friendly - if you can afford it consider supporting local companies. 

</details>

## assembly guide

<details><summary><b>assembly guide</b> - start here if you have purchased a diy kit</summary>
  

## interactive BOM for build guiding

follow this link to view the [interactive BOM](https://htmlpreview.github.io/?https://github.com/cyberboy666/_transcribe_/blob/main/hardware/bom/ibom.html)
  


## general solder advices

- remember to heat pad first (2-3seconds), then add solder, then continue to heat (1-2seconds)

- Checkout the web-comic [soldering is easy](https://mightyohm.com/files/soldercomic/FullSolderComic_EN.pdf) for more soldering advice

## general order of assembly

- in general while assembling i start placing resistors and capacitors first. placing 5 - 10 components at a time and then flipping the board to solder them and trim the legs etc.
- next i would do diodes, transistors and ic's - taking care that these are placed in the right direction (using a ic socket can be useful)
- finally i place the interface parts - rca jacks, power jack, pots and switches - make sure these have lots of solder on for structural stablity

## interface choice / double footprint
  
_serial-midi_ is most commonly sent over __din5__ (older hardware) J5 & J7 or __trs 3.5mm jack__ (newer hardware) J4 & J6 - footprints for both are overlayed on the pcb so you can choose which one you would like to have
  
## Usb-host shield

__IMPORTANT: A trace needs to be cut on the usb-host-shield to allow it to be powered by 5v__ – _see the diagram below_ – this is best done with a craft knife – take care not to cut any other traces accidentally.
  
![image](https://user-images.githubusercontent.com/12017938/98587955-32bec280-22cb-11eb-93e5-89b337cc7d75.png)
![image](https://user-images.githubusercontent.com/12017938/98587933-2a668780-22cb-11eb-9844-af73e18d9543.png)
  
all pins on the outer vertical lines need to be soldered to the board. In addition to this the single topmost inner pin (labeled 5v in diagram) needs to be soldered to pcb also
  
## specific assembly advice

Start by soldering the smallest parts first: resistors, diodes, capacitors and regulators - take note of the direction on the diodes - black bar on component matching black bar on footprint

Next lets do the ic’s/sockets - make sure the direction is correct! place in and fold two corner pins to hold in place, then solder all pins. you can place the ic in now too

Now lets do the micro-controller and usb-host-shield - if you want to be able to remove them from the board you will need to solder header sockets to the board first – otherwise can directly solder the header pins

for the usb-host-shield right_row I would do a 1x2 header horizontally at the top to catch that 5v pin and then 1x11 row vertically for the rest – the left_row can just be a single 1x12 vertical header

Finally place the interface parts (eg jacks and sockets) be generous with the solder here -> this is to strengthen the mechanical connections as well as making electrical ones

Leave j8 header unpopulated – this just exposes the bootloader pins so firmware can be reset in the rare case that the pro-micro gets bricked – also leave j1 header unpopulated unless you want to power from a euro-power-header
  
</details>

## firmware guide

<details><summary><b>firmware guide</b> - for editing the code & flashing it to your micro-controller</summary>
  
## flashing firmware onto the micro-controller
  
if you have got a kit from the shop the default firmware will be pre-configured - still you probably will want to follow this so you can edit the code and update the mappings.
  
### install guide
  
all _underscores_ projects with micro-controllers use [platformio](https://platformio.org/) with [visual studio code](https://code.visualstudio.com/) to edit, flash and monitor the code.
  
- first download (and unzip) the code in this repo - easiest is [as a zip](https://github.com/cyberboy666/_transcribe_/archive/refs/heads/main.zip) or you can clone using git if you are comfortable with this
- next download, install and open [visual studio code](https://code.visualstudio.com/#alt-downloads)
- now open the extension tab within vscode on left vertical menu (or press ctrl-shift-x) and search for `platformio` to install this extension
  
![image](https://user-images.githubusercontent.com/12017938/158495161-7c3114fc-814b-4acc-b142-4a9522370473.png)

- connect the micro-controller to computer via usb, open the _transcribe_ software folder (ctrl-k ctrl-o) in vscode and find the _platformio_ commands (either in left vertical menu under _platformio_ or little tick/arrow symbols along bottom blue bar) - `PlatformIO: Upload` should flash the default code to your micro-controller
  
![image](https://user-images.githubusercontent.com/12017938/158495844-99466196-086a-47d2-b803-2b5941d33ac5.png)

### mapping edit guide
  
this guide is just an overview to get you started. the two files that you might want to look at are: 
- [software/src/commands.h](software/src/commands.h) - where the specific serial protocol commands are defined
- [software/src/main.cpp](software/src/main.cpp) - all the code that handles receiving midi and writing serial is - including the _mapping function_
  
open the `src/main.cpp` file in vscode and fold all functions by pressing `ctrl-k, ctrl-0` - this makes reading it a bit easier:

![image](https://user-images.githubusercontent.com/12017938/158500187-9222c7e7-a8f3-4ff5-b663-3d6d90e5ee68.png)

open and take a look at the `setAVE55nanokontrolMap` method - we will first look at these lines:
  
```cpp
    else if(midiParam1 == 64){setCmd(A55_A_BUS_SOURCE_1);}
    else if(midiParam1 == 65){setCmd(A55_A_BUS_SOURCE_2);}
```
  
the first line is saying: __if the incoming midi message has `midiParam1` set to 64, then send the `A55_A_BUS_SOURCE_1` command over rs232 serial__ - since we can see from above that this line is within the conditional: `if(midiCommand == MIDICOMMAND::CC)` , then we know that `midiParam1` is refering to the cc channel. we can also see in the __commands.h__ file  that `A55_A_BUS_SOURCE_1` is set to the command from that panasonic ave55 specification that switches the a-bus source to input 1:
```cpp
  #define A55_A_BUS_SOURCE_1 "VCP:200"
```

this line is mapping a midi message on cc channel 64 to the rs232 message for ave55 that switches the input source. this is the simplest kind of mapping - a discrete BUTTON press. however there are also mappings to functions that take parameter values also. for example the `A55_A_B_MIX_LEVEL` command that wipes between the a-bus to b-bus on the mixer:
  
 ```cpp
 if(midiParam1 == 0){setCmd(A55_A_B_MIX_LEVEL, midiParam2);}
 else if(midiParam1 == 1){setCmd(A55_THRESHOLD_LUM_KEY, midiParam2);}
 else if(midiParam1 == 2){setCmd(A55_CENTER_WIPE_X, midiParam2);}
 else if(midiParam1 == 3){setCmd(A55_CENTER_WIPE_Y, midiParam2);}
```

we can see that on these mappings also the __midiParam2__ value is passed into the _setCmd_ function - this is the _cc value_ of the channel - on my controller - the position of the slider that is sending on cc channel 0. the rs232 command for this function also takes a varible input to set position of the mix:
```cpp
#define A55_A_B_MIX_LEVEL "VMM:179~0"
```
where the `~0` is a placeholder that is replaced with the hex-converted value of `midiParam2`. there are other ways to map midi notes to rs232 commands. there are more 'advanced' mapping functions in the code for this - for example:
```cpp
else if(midiParam1 == 35){setCmdParamRandom(A55_A_B_MIX_LEVEL);}
```
takes a button press and converts it to a random mix level. another useful mapping is taking continuous inputn (eg slider on midi controller)  and convert this to a STEP of different discrete commands - for example:
```cpp
else if(midiParam1 == 17){setCmdStepAVE55(A55_A_BUS_MOSAIC_OFF, midiParam2, 76, 6);}
else if(midiParam1 == 18){setCmdStepAVE55(A55_A_BUS_PAINT_OFF, midiParam2, 82, 6);}
```
these mappings STEP between sending 6 different rs232 commands on a single slider - so you can set all the mosaic/paint effect levels in one turn. another useful 'advanced' mapping function is the SWITCH:
  
```cpp
else if(midiParam1 == 50){setCmdSwitch(MX50_A_BUS_EFFECT_ON, MX50_A_BUS_EFFECT_OFF, 3);}
```

this will SWITCH between sending the _on_ and _off_ commands when the same midi command is send (the third parameter input `3` is a unique index reference to store the on/off state in memory between messages)
  
these are just some examples of the ways that code can be used to perform these mappings. if you are interested can see more in the code directly or write your own mapping functions!
  

  
</details>
  
## operating guide
  
<details><summary><b>operating guide</b> - start here if you have purchased an assembled unit</summary>

![image](https://user-images.githubusercontent.com/12017938/158474325-491af7d0-d0d1-4446-a689-3c4a773478fd.png)


</details>

### more info

<details><summary><b>how the circuit works</b></summary>
  
[coming soon]
                                                                                                                             
</details>

<details><summary><b>contributing guide</b></summary>
  
if you would like to contribute back to these projects in some way but dont know how the best thing (for now) would be to reach out to me directly ( tim@cyberboy666.com or @cyberboy666 on scanlines forum) - i will be happy to help
  
</details>


## credits & more info


This circuit is distributed through UNDERSCORES – open video hardware label – visit [underscores.shop](https://underscores.shop) for more info

The pcb was designed using KICAD

Everything from gerbers, cad files, panels and documentation is freely available online and distributed under CC-BY-SA / open-source licenses – help us contribute to the commons !

Ask any questions or start discussions related to this project on the [scanlines.xyz](https://scanlines.xyz) forum – an online community space dedicated to diy av / electronic media art

You can contact me directly at tim (at) cyberboy666 (dot) com 
Please get in touch if you are interested in hosting a workshop !

![image](https://user-images.githubusercontent.com/12017938/158493552-49a106d9-8a07-45a7-9833-da2faddb7406.png)


Thanks to Gilbert Sinnott for helping with initial experiments. to Bastien Lavaud for circuit advice, always. To Ben Caldwell for project advice. To everyone who has or will contribute ♥♥♥

