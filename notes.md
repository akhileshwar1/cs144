# Unix context:

* A program is a text file and a process is an instance of it. Every process has an id.

* The Kernel provides the processes with sys call interface to manage or talk to hardware
  and other processes.

* Every process has file descriptors(basically numbers) pertaining to each resource that it
  is using.

* A file is an abstraction consisting of a pointer to the v node which then has pointer to 
  inode. Vnode holds the general functions to perform ops on the file and the inode holds 
  the disk block addresses.

* Every file has permission bits and they should match the bits of the process. Basically 
  process also has a user id and group id.

* I feel like when they say socket is also a file referenced via a file descriptor, I feel
  like the bytes do end up but this time on another computer. or maybe temporarily in a file
  on the local, from where the OS fetches it and sends it.

* Nah man, so we have these sys calls called read, write, etc which identify or remember things by ints called file descriptors. SO hidden behind an int fd can be an actual file made up of disk blocks or internal kernal memory state like socket, in the socket's case you can have info like host address, port and othe stuff. 
