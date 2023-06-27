# soldam
encoding (and decoding) tools for megasys1 soldam

these only operate on a single word as input

later I will make a tool for an entire decrypted, combined file

for splitting a combined file:

```
objcopy -i 2 --byte 0 -I binary modified-encrypted.bin 2ver1j.bin
objcopy -i 2 --byte 1 -I binary modified-encrypted.bin 1euro.bin```
