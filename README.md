# _transcribe_
for midi control of panasonic video mixers

## idea / overview

.... some links here, explaining ...

- take midi in (see different ways below)
- send serial out (for ave55)
- convert to r232 with max232 chip
- connect to 3.5 trs jack

https://arduinodiy.wordpress.com/2012/03/19/serial-connection-for-your-arduino-atmega

wiring max232n : 

![image](https://user-images.githubusercontent.com/12017938/71270713-8d1d0080-2352-11ea-840d-7a46f05c743f.png)

![image](https://user-images.githubusercontent.com/12017938/71270767-ade55600-2352-11ea-8631-5f2e28ae7bb4.png)

![image](https://user-images.githubusercontent.com/12017938/71274322-665fc980-2354-11ea-928c-a6fc264001fb.png)

![image](https://user-images.githubusercontent.com/12017938/71272599-edf90880-2353-11ea-89b8-90c52024c4e5.png)

![image](https://user-images.githubusercontent.com/12017938/71275155-a030d000-2354-11ea-98e1-16ea6839eb72.png)

![image](https://user-images.githubusercontent.com/12017938/71272877-02d59c00-2354-11ea-83bd-ee6de3375d65.png)


## want to support for : 

### usb midi device

usb midi from a host ie computer, pi etc

### serial midi

from din midi devices

### usb midi host

from things like nano control - needs a host shield - maybe like [this](https://www.aliexpress.com/item/32942427334.html) one : 
