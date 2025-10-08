/*


functions
- put(key , value) -> O(1)
- get(key) -> O(1)
- remove(key) -> O(1)
- contains(key) -> O(1) #check if the key is present or not
- size() -> total no of element

API

hash_table = HashMap()

hash_table[keys]
keys dtype => int , float , "string"

key -> hash_map -> collision -> 

hash_function -> 
[h1(key) + i * h2(key)] mod m
i -> probe count
m -> current size of hash table
h2(key) ->  R - (key mod R) 
h1(key) -> key mod T 
T and R -> real value


switch(typeof(key)):

case int:
key -> int

case float:
key -> float

case string:
key -> hash_value(string)


hash_value(string):
  value = 0 
  for i in string:
    value += ascii(i) + ascii(ord(ascii(i) + 1)) 

*/
