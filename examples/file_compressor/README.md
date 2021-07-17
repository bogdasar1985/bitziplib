# Description
It is a simple file compression program

# Example of usage
```
$ ./coder lorem_ipsum.txt code_res.txt

$ wc lorem_ipsum.txt code_res.txt 
  200  9275 62631 lorem_ipsum.txt
  117   655 33813 code_res.txt
  317  9930 96444 итого

$ ./decoder code_res.txt decode_res.txt

$ diff decode_res.txt lorem_ipsum.txt 

```
