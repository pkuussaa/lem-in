# Lem-in
Max flow algorithmic project.

## Objectives
The goal of this project is to find the most optimal way to get n number of ants across the farm. The farm consists of n number of rooms linked within each other. Most optimal way means the solution with the least number of lines, respecting the output format requested below. Ants are also allowed to move into certain room one at the time.

## Example map file with explanations
```
5          <------------  number of ants
3 2 2 ------------\
##start           |
start_room 5 0    |
##end             |
end_room 5 6      |---->  Room names and coordinates.
4 0 4             |       ##command apply to next row.
9 4 2             |
2 4 4             |
7 8 2             |
6 8 4 ------------/
start_room-1 -----\
3-5               |
2-5               |
9-7               |
6-7               |---->  Links between rooms
end_room-6        |
9-2               |
2-6               |
2-end_room        |
3-start_room -----/
```
This input will translate into:
```
 [start_room] 
    / |
 [3] [9]--[7]
 /    |    | 
[4]--[2]--[6]
      |  /
  [end_room]
```
## Algorithm
Detailed similar [Algorithm explanation](https://github.com/MikeyLHolm/Hive-lem-in/blob/master/lem_in_pdf.pdf) By MikeyLHolm.

## How to use
Clone repo:
```
git clone https://github.com/pkuussaa/Lem-in.git
```
Create executable in Hive-lem-in directory:
```
make
```
Run with premade map:
```
./lem-in [-flags] < [map]
```
Running with map generator:
```
./generator --flow-one | ./lem-in [-flags]
./generator --flow-ten | ./lem-in [-flags]
./generator --flow-thousand | ./lem-in [-flags]
./generator --big | ./lem-in [-flags]
./generator --big-superposition | ./lem-in [-flags]
```
for usage:
```
./lem-in -h
```
Used library functions for this project:
```
* malloc
* free
* read
* write
* strerror
* perror
* exit
```
