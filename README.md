Commands 
echo [argument] -classic echo repetition
wc - word count has 2 options -c for num of characters and -w for num of words
touch filename - creating a file with given name
prompt argument - swaps the ready char
time - shows time
date - shows date
truncate filename - deletes everything in the give file
rm filename - removes the file with given name
tr [argument] –what [with] - swaps 
head -ncount [argument] - shows the first ncount lines
batch filename - executes all commands in the given file

CLI supports pipeline using | (for example time | wc will output the num of character in time)
CLI support redirection using < , > , >> (for example using echo "Hello" > input.txt will delete everything in file and put Hello there, using >> will add Hello at the end, and using echo < input.txt will output the file context)
argument with given [] brackets can be given in 3 ways
echo "Hello" - Hello is a argument
echo hello.txt - context of the file hello.txt is the argument
echo - context of the all lines beneath is the argument until EOF char.
Hello World!
Ctrl+Z
