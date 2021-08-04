./coder lorem_ipsum.txt compressed_file.txt
./decoder compressed_file.txt decompressed_file.txt
diff lorem_ipsum.txt decompressed_file.txt
wc compressed_file.txt decompressed_file.txt
rm compressed_file.txt
rm decompressed_file.txt
