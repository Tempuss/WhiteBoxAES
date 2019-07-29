# WhiteBoxAES


* plain text :bestbestbestbest
* key : goodgoodgoodgood

```
#Generate You Own Tbox
./tbox_gen > tboxes.h

./wbc_tbox 
c525386be3442f1a4e95dcce6bf986cb

echo "bestbestbestbest" > plain

#HexString KEY
echo -n "goodgoodgoodgood" | xxd -c 256 -ps


# Decrypt With Open SSL
openssl aes-128-ecb -e -K 676f6f64676f6f64676f6f64676f6f64 -in plain -out enc

#View in hex
hexdump -C enc

#padding Error Your Need Fix it
00000000  c5 25 38 6b e3 44 2f 1a  4e 95 dc ce 6b f9 86 cb  |.%8k.D/.N...k...|
00000010  c8 fc 1e c4 d3 21 71 9a  a4 ea 7c 7f a9 0d f7 2d  |.....!q...|....-|
```
