<img src="https://www.raspberrypi.org/homepage-9df4b/static/hero-shot-33d83b8c5fa0933373dabcc9462b32a3.png" width="75%">



The Raspberry Pi is a British micro-computer that can run an OS (Linux by default) and has USB, HDMI, and audio ports to boot! 

For a quick intro, these are the tasks/projects I've been able to accomplish thus far:
* Run RetroPie; a video game emulator OS - so much fun!
* Run a desktop image (OS) similar to a laptop
* Run Python scripts and Wolfram Alpha/Mathematica app
* Control analog and digital circuits
* Surf the internet


## Installing Python 3.7 and making default:
* https://www.ramoonus.nl/2018/06/30/installing-python-3-7-on-raspberry-pi/

## Installing Libre Office (if not already installed):
* https://raspberrypi.stackexchange.com/questions/1800/how-do-i-install-libreoffice

## Cheat Sheet:
https://www.raspberrypistarterkits.com/guide/raspberry-pi-commands-cheat-sheet/

## Screen Capture via Scrot:
* https://www.imore.com/how-take-screenshot-raspberry-pi

## Change dropdown menu items?
* https://www.raspberrypi.org/forums/viewtopic.php?p=901536

## Reformating SD card that doesn't show full memory:
#### For Mac 
* https://mycyberuniverse.com/how-reclaim-full-capacity-flash-memory-card-usb-flash-drive.html

#### My SD card was only showing 268mb even after a disk utility erase and refromat, but these instructions helped get all the available memeory back

List out our drives:
* !! Make sure not to erase your actual hard drive or other external HDs. BEWARE of which /dev/diskXX is your SD card !!

```
$ diskutil list
/dev/disk0 (internal, physical):
   #:                       TYPE NAME                    SIZE       IDENTIFIER
   0:      GUID_partition_scheme                        *251.0 GB   disk0
   1:                        EFI EFI                     209.7 MB   disk0s1
   2:                  Apple_HFS Macintosh HD            250.1 GB   disk0s2
   3:                 Apple_Boot Recovery HD             650.0 MB   disk0s3

/dev/disk2 (internal, physical):
   #:                       TYPE NAME                    SIZE       IDENTIFIER
   0:     FDisk_partition_scheme                        *30.9 GB    disk2
   1:                  Apple_HFS Untitled                268.2 MB   disk2s1
```

Need to run as root (sudo); named the SD card RPI with format for RPi

```
$ sudo diskutil eraseDisk FAT32 MYSD MBRFormat /dev/disk2
Started erase on disk2
Unmounting disk
Creating the partition map
Waiting for partitions to activate
Formatting disk2s1 as MS-DOS (FAT32) with name MYSD
512 bytes per physical sector
/dev/rdisk2s1: 60329152 sectors in 1885286 FAT32 clusters (16384 bytes/cluster)
bps=512 spc=32 res=32 nft=2 mid=0xf8 spt=32 hds=255 hid=8192 drv=0x80 bsec=60358656 bspf=14729 rdcl=2 infs=1 bkbs=6
Mounting disk
Finished erase on disk2
```

Check to make sure it worked

```
$ diskutil list
/dev/disk0 (internal, physical):
   #:                       TYPE NAME                    SIZE       IDENTIFIER
   0:      GUID_partition_scheme                        *251.0 GB   disk0
   1:                        EFI EFI                     209.7 MB   disk0s1
   2:                  Apple_HFS Macintosh HD            250.1 GB   disk0s2
   3:                 Apple_Boot Recovery HD             650.0 MB   disk0s3

/dev/disk2 (internal, physical):
   #:                       TYPE NAME                    SIZE       IDENTIFIER
   0:     FDisk_partition_scheme                        *30.9 GB    disk2
   1:                 DOS_FAT_32 RPI                    30.9 GB    disk2s1

```
