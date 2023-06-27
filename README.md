# soldam
encoding (and decoding) tools for megasys1 soldam

these operate on a single word as input

update: the encode tool only works some of the time, I'll try to fix it. but in the meantime, you can use the LUT decode to generate a table of entries and encode using that method.

later I will make a tool for an entire decrypted, combined file

for splitting a combined file:

```
objcopy -i 2 --byte 0 -I binary modified-encrypted.bin 2ver1j.bin
objcopy -i 2 --byte 1 -I binary modified-encrypted.bin 1euro.bin```
